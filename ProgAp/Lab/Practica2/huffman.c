// Incluimos las librerias
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definicion de las estructuras
typedef struct defLista{
  char simbolo, codigo[100];
  int probabilidad, status, tipo;
  struct defLista* sig, *izq, *der;
}TipoLista;
// Prototipos de funciones
void menu();
void creditos();
void agregar(TipoLista**);
void listar(TipoLista*);
void borrar(TipoLista**);
void modificarSimbolo(TipoLista*);
void guardarenArchivo(TipoLista*);
void leerdeArchivo(TipoLista**);
int validaGeneracion(TipoLista*);
void generarArbol(TipoLista*, TipoLista**);
void generarCodigos(TipoLista*, char[], int);
void imprime(TipoLista* p);
void codificar(TipoLista*);
void decodificar(TipoLista*, char[], char[], TipoLista*);
void validarDecodificacion(TipoLista*, int*, char[]);
int validarCodificacion(TipoLista*, char[]);
void quitarPorcentaje(TipoLista* Inicio);
void liberarMemoria(TipoLista*);
// Funcion principal
int main() {
  int opcion, i = 0, flag = 0, generado = 0, flag2 = 0;
  TipoLista* Inicio = NULL, *temp;
  TipoLista* Raiz = NULL;
  char codigo[200], linea[200], nombre[200], decodificado[200];
  FILE* Archivo, *Archivo2;
  creditos();
  do {
    menu();
    scanf("%d", &opcion);
    switch (opcion) {
      case 1:
        agregar(&Inicio);
        generado = 0;
        break;
      case 2:
        listar(Inicio);
        break;
      case 3:
        borrar(&Inicio);
        generado = 0;
        break;
      case 4:
        modificarSimbolo(Inicio);
        generado = 0;
        break;
      case 5:
        guardarenArchivo(Inicio);
        break;
      case 6:
        leerdeArchivo(&Inicio);
        generado = 0;
        break;
      case 7:
        if(validaGeneracion(Inicio) == 0){
          printf("No se pueden generar los codigos, ya que la suma de probabilidades no es igual a 100%%\n");
        }
        else{
          if(generado == 1)
            printf("Ya se han generado los codigos\n");
          else{
            generarArbol(Inicio, &Raiz);
            generarCodigos(Raiz, codigo, 0);
            printf("Codigos generados con exito: \n");
            imprime(Raiz);
            generado = 1;
            flag = 0;
          }
        }
        break;
      case 8:
        system("clear");
          if(generado == 1){
            codificar(Inicio);
          }else{
            printf("Aun no se han generado los codigos\n");
          }
        break;
      case 9:
        flag2 = 0;
        system("clear");
          if(generado == 1){
            printf("Ingresar archivo a decodificar: ");
            __fpurge(stdin);
            gets(nombre);
            Archivo = fopen(nombre, "rb");
            if (Archivo == NULL)
              printf("No se ha encontrado el archivo\n");
            else{
              fgets(linea, 200, Archivo);

              if(flag2 == 0){
                printf("Ingresar nombre del archivo donde se decodificara el texto: ");
                gets(nombre);
                Archivo2 = fopen(nombre, "wt");
                decodificar(Raiz, linea, decodificado, Raiz);
                fprintf(Archivo2, "%s\n", decodificado);
                fclose(Archivo2);
                fclose(Archivo);
                printf("Se ha decodificado con exito el archivo\n");
              }else{
                printf("Algunos valores codificados no se encuentran en la lista\n");
              }

            }
          }else{
            printf("Debes generar los codigos\n");
          }
        break;
      case 10:
        printf("Saliendo del programa...\n");
        liberarMemoria(Inicio);
        exit(0);
        break;
      default:
        printf("Ingresa una opcion valida!\n");
    }
    printf("Presiona enter para continuar...");
    __fpurge(stdin);
    getchar();
  } while(opcion != 10);
  return 0;
}

// Desarrollando las funciones
void menu(){
  system("clear");
  printf("\t\t\t Codificacion de Huffman\n");
  printf("\t1.- Introducir simbolo\n");
  printf("\t2.- Listar simbolos\n");
  printf("\t3.- Borrar simbolo\n");
  printf("\t4.- Modificar simbolo\n");
  printf("\t5.- Guardar simbolos en archivo\n");
  printf("\t6.- Leer simbolos de archivo\n");
  printf("\t7.- Generar códigos\n");
  printf("\t8.- Codificar mensaje\n");
  printf("\t9.- Decodificar mensaje\n");
  printf("\t10.- Salir\n");
  printf("\nDel anterior menu, selecciona la opcion deseada-> ");
}
void creditos(){
  system("clear");
  printf("\t\t\t Codificacion de Huffman\n");
  printf("Desarrollado por:\n\tCesar Mauricio Arellano Velasquez\n\tRaul Gonzalez Portillo\n\tAllan Jair Escamilla Hernandez\n\n");
  printf("Presione una tecla para continuar...");
  getchar();
  system("clear");
  printf("Objetivo: Codificar y decodificar mensajes usando la codificacion de Huffman.\n");
  printf("Presione una tecla para continuar...");
  getchar();
}
void agregar(TipoLista** Inicio){
  char caracter;
  int probabilidad, flag = 0;
  TipoLista* Nuevo = (TipoLista*)malloc(sizeof(TipoLista));
  TipoLista* temp, *temp2 = *Inicio;
  system("clear");
  printf("Ingresar un caracter: ");
  __fpurge(stdin);
  caracter = getchar();
  while(temp2 != NULL){
    if(temp2->tipo == 0 && temp2->simbolo == caracter)
      flag = 1;
    temp2 = temp2->sig;
  }
  if(flag == 1)
    printf("El simbolo ingresado ya existe en la lista, por lo que no puedes volver a agregarlo\n");
  else{
    printf("Ingresar la probabilidad de aparicion: ");
    scanf("%d", &probabilidad);
    Nuevo->simbolo = caracter;
    Nuevo->probabilidad = probabilidad;
    Nuevo->status = 0;
    Nuevo->tipo = 0;
    Nuevo->sig = NULL;
    Nuevo->izq = NULL;
    Nuevo->der = NULL;
    if(*Inicio == NULL){
      *Inicio = Nuevo;
    }else{
      temp = *Inicio;
      while(temp->sig != NULL){
        temp = temp->sig;
      }
      temp->sig = Nuevo;
    }
  }
}
void listar(TipoLista* Inicio){
  system("clear");
  printf("\t\t\t Codificacion de Huffman\n");
  TipoLista* temp = Inicio;
  while (temp != NULL) {
    if(temp != NULL && temp->tipo == 0)
      printf("\tSimbolo: %c. Probabilidad: %d.\n", temp->simbolo, temp->probabilidad);
    temp = temp->sig;
  }
  printf("\n");
}
void borrar(TipoLista** Inicio){
  system("clear");
  char simbolo;
  int flag = 0;
  TipoLista* aux = *Inicio, *ant = NULL, *temp = *Inicio;
  printf("Ingresar el simbolo a borrar: ");
  __fpurge(stdin);
  simbolo = getchar();
  while(temp != NULL){
    if(temp->tipo == 0 && temp->simbolo == simbolo)
      flag = 1;
    temp = temp->sig;
  }
  if(flag == 0)
    printf("No se encontro el simbolo\n");
  else
    printf("Simbolo eliminado\n");
  while ((aux != NULL) && (aux->simbolo != simbolo)) {
    ant = aux;
    aux = aux->sig;
  }
  if (aux!=NULL) {
    if (ant!=NULL) {
      ant->sig = aux->sig;
    }else{
      *Inicio = aux->sig;
    }
    free(aux);
  }
}
void modificarSimbolo(TipoLista* Inicio){
  system("clear");
  char simbolo;
  int flag = 0, probabilidad;
  TipoLista* temp = Inicio, *temp2;
  printf("Ingresar el simbolo a modificar: ");
  __fpurge(stdin);
  simbolo = getchar();
  while(temp != NULL && flag == 0){
    if(temp->simbolo == simbolo){
      flag = 1;
      temp2 = temp;
    }
    temp = temp->sig;
  }
  if(flag == 0)
    printf("No se puede modificar el simbolo introdicido, ya que no se encuentra en la lista\n");
  else{
    printf("Ingresa la nueva probabilidad de aparicion del simbolo: ");
    scanf("%d", &probabilidad);
    temp2->probabilidad = probabilidad;
    printf("Se ha modificado correctamente\n");
  }
}
void guardarenArchivo(TipoLista* Inicio){
  system("clear");
  TipoLista* temp = Inicio;
  FILE* Archivo;
  char nombreArchivo[200];
  if(temp == NULL)
    printf("La lista de simbolos se encuentra vacia, no puedes guardarla en un archivo\n");
  else{
    printf("Ingresar el nombre del archivo donde se desea guardar: ");
    __fpurge(stdin);
    gets(nombreArchivo);
    Archivo = fopen(nombreArchivo, "wt");
    if(Archivo == NULL)
      printf("No se ha podido crear el archivo\n");
    else{
      while (temp != NULL) {
        if(temp->tipo == 0)
          fprintf(Archivo, "%d/%c\n", temp->probabilidad, temp->simbolo);
        temp = temp->sig;
      }
      printf("Se ha guardado con exito\n");
      fclose(Archivo);
    }
  }
}
void leerdeArchivo(TipoLista** Inicio){
  system("clear");
  FILE* Archivo;
  TipoLista* temp = *Inicio, *temp2;
  char nombre[200], simbolo;
  int probabilidad;
  printf("Ingresar nombre del archivo a ser cargado: ");
  __fpurge(stdin);
  gets(nombre);
  Archivo = fopen(nombre, "rb");
  if (Archivo == NULL) {
    printf("Ha ocurrdo un error al abrir el archivo\n");
  }else{
    while(*Inicio != NULL){
      temp = (*Inicio)->sig;
      free(*Inicio);
      *Inicio = temp;
    }
    while (fscanf(Archivo, "%d/%c\n", &probabilidad, &simbolo) == 2) {
      temp = (TipoLista*)malloc(sizeof(TipoLista));
      temp->probabilidad = probabilidad;
      temp->simbolo = simbolo;
      temp->status = 0;
      temp->tipo = 0;
      temp->sig = NULL;
      temp->izq = NULL;
      temp->der = NULL;
      if(*Inicio == NULL){
        *Inicio = temp;
      }else{
        temp2 = *Inicio;
        while(temp2->sig != NULL)
          temp2 = temp2->sig;
        temp2->sig = temp;
      }
    }
    fclose(Archivo);
    printf("Se ha leido correctamente la lista del archivo\n");
  }
}
int validaGeneracion(TipoLista* Inicio){
  system("clear");
  TipoLista* temp = Inicio;
  int sum = 0;
  while (temp != NULL) {
    if(temp != NULL && temp->tipo == 0)
      sum += temp->probabilidad;
    temp = temp->sig;
  }
  if (sum != 100) {
    return 0;
  }else{
    return 1;
  }

}
void generarArbol(TipoLista* Inicio, TipoLista** Raiz){
  int suma = 0;
  TipoLista* temp = Inicio;
  TipoLista* men = temp, *men2 = temp, *temp3 = Inicio;
  TipoLista* temp2;
  while(suma != 100){
    temp = Inicio;
    while(temp != NULL && temp->status != 0)
      temp = temp->sig;
    men = temp;
    temp = Inicio;
    while(temp != NULL){
      if((temp->probabilidad < men->probabilidad) && (temp->status == 0)){
        men = temp;
      }
      temp = temp->sig;
    }
    men->status = 1;
    temp = Inicio;
    while(temp != NULL && temp->status != 0)
      temp = temp->sig;
    men2 = temp;
    temp = Inicio;
    while(temp != NULL){
      if((temp->probabilidad < men2->probabilidad) && temp->status == 0){
        men2 = temp;
      }
      temp = temp ->sig;
    }
    men2->status = 1;
    temp2 = (TipoLista*)malloc(sizeof(TipoLista));
    temp2->probabilidad = (men->probabilidad) + (men2->probabilidad);
    temp2->izq = men;
    temp2->der = men2;
    temp2->sig = NULL;
    temp2->status = 0;
    temp2->tipo = 1;
    *Raiz = temp2;
    temp = Inicio;
    while(temp->sig != NULL)
      temp = temp->sig;
    temp->sig = temp2;
    suma = temp2->probabilidad;
  }
}
void generarCodigos(TipoLista* Raiz, char codigo[], int pos){
    if(Raiz != NULL){
      if(Raiz->izq != NULL){
        codigo[pos] = '0';
        codigo[pos+1] = '\0';
        generarCodigos(Raiz->izq, codigo, pos+1);
      }
      if(Raiz->der != NULL){
        codigo[pos] = '1';
        codigo[pos+1] = '\0';
        generarCodigos(Raiz->der, codigo, pos+1);
      }
      if(Raiz->tipo == 0){
        strcpy(Raiz->codigo, codigo);
      }
    }
}
void imprime(TipoLista* p){
  if(p != NULL){
    imprime(p->izq);
    if(p->tipo == 0)
      printf("\t%c-> %s\n", p->simbolo, p->codigo);
    imprime(p->der);
  }
}
void codificar(TipoLista* Inicio){
  system("clear");
  TipoLista* temp = Inicio;
  char nombre[200], linea[200], nombre2[200];
  int i = 0, flag = 0;
  FILE* Archivo, *Archivo2;
  printf("Ingresar el nombre del archivo donde se encuentra el texto a codificar: ");
  __fpurge(stdin);
  gets(nombre);
  Archivo = fopen(nombre, "rb");
  if (Archivo == NULL) {
    printf("No se ha encontrado el archivo.\n");
  }else{
    if(validarCodificacion(Inicio, nombre) == 0){
      printf("Ingresar archivo donde se guardara el texto codificado: ");
      gets(nombre2);
      Archivo2 = fopen(nombre2, "wt");
      while (fgets(linea, 200, Archivo) != NULL && flag == 0) {
        linea[strlen(linea)-1] = '\0';
        while(linea[i] != '\0'){
          temp = Inicio;
          flag = 0;
          while (temp != NULL && flag == 0) {
            if(linea[i] == temp->simbolo){
              fprintf(Archivo2, "%s", temp->codigo);
              flag = 1;
            }
            temp = temp->sig;
          }
          if(flag == 0){
            printf("No se ha completado la codificacion, ya que hacen falta simbolos\n");
            linea[i] = '\0';
            flag = 1;
          }else{
            i++;
          }
        }
      }
      fclose(Archivo2);
      fclose(Archivo);
      printf("Se ha codificado con exito\n");
    }else
      printf("Hay uno o mas caracteres del archivo que no se encuentran en la lista\n");
  }
}
void decodificar(TipoLista* Raiz, char linea[], char decodificado[], TipoLista* Raiz2){
    if (*linea != '\0') {
      if(Raiz->izq != NULL && (*linea) == '0'){
        decodificar(Raiz->izq, linea+1, decodificado, Raiz2);
      }

      if(Raiz->der != NULL && (*linea) == '1'){
        decodificar(Raiz->der, linea+1, decodificado, Raiz2);
      }
      if(Raiz->tipo == 0){
        *decodificado = Raiz->simbolo;
        *(decodificado + 1) = '\0';
        Raiz = Raiz2;
        decodificar(Raiz, linea, decodificado+1, Raiz2);
      }
    }
    if(*linea == '\0'){
      if(Raiz->tipo == 0){
        *decodificado = Raiz->simbolo;
        *(decodificado + 1) = '\0';
        Raiz = Raiz2;
        decodificar(Raiz, linea, decodificado+1, Raiz2);
      }
    }
}
int validarCodificacion(TipoLista* Inicio, char nombre[]){
  FILE* Archivo = fopen(nombre, "rb");
  TipoLista* temp = Inicio;
  char linea[200];
  int i = 0, flag = 0, error = 0;
  fgets(linea, 200, Archivo);
  linea[strlen(linea)-1] = '\0';
  while(linea[i] != '\0' && error == 0){
    temp = Inicio;
    flag = 0;
    while(temp != NULL && flag == 0){
      if(temp->tipo == 0 && temp->simbolo == linea[i]){
        flag = 1;
      }
      temp = temp->sig;
    }
    if(flag == 0)
      error = 1;
    i++;
  }
  fclose(Archivo);
  return error;
}
void liberarMemoria(TipoLista* Inicio){
  TipoLista* temp;
  while (Inicio != NULL) {
    temp = Inicio;
    Inicio = Inicio->sig;
    free(temp);
  }
}
