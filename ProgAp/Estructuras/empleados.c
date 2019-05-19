#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct def_Empleado
{

  char Nombre[200];
  int Edad,Antiguedad;
  float Sueldo;

} TipoEmpleado;

void InsertarEmpleados(TipoEmpleado Empleado[10], int *LimiteEmpleados);
void ImprimirEmpleados(TipoEmpleado Empleado[10], int LimiteEmpleados);
void BuscarEmpleados(TipoEmpleado Empleado[10], int LimiteEmpleados);
void ImprimirPorAntiguedad(TipoEmpleado Empleado[10], int LimiteEmpleados);
void Convertir(TipoEmpleado Empleado[10], int LimiteEmpleados);
void Mayusculas(TipoEmpleado *Empleado, int *Flag);
void LeerArchivo(TipoEmpleado Empleado[10],int *LimiteEmpleados);
void GuardarArchivo(TipoEmpleado Empleado[10], int LimiteEmpleados);


int main(void)
{
  TipoEmpleado Empleado[10];
  int LimiteEmpleados=0,Opcion,Salir=0;
  do
    {
      system("clear");
      printf("Menu:\n");
      printf("1.- Ingresar empleados [max:10]\n");
      printf("2.- Imprimir empleados del sistema\n");
      printf("3.- Buscar empleados [por nombre]\n");
      printf("4.- Imprimir por antiguedad\n");
      printf("5.- Convertir a Mayusculas\n");
      printf("6.- Leer el archivo\n");
      printf("7.- Guardar en el Archivo\n");
      printf("8.- Salir\n");
      printf("Escoge una opción: ");
      scanf(" %d",&Opcion);
      switch(Opcion)
    {
    case 1:
      InsertarEmpleados(Empleado,&LimiteEmpleados);
      break;
    case 2:
      ImprimirEmpleados(Empleado,LimiteEmpleados);
      break;
    case 3:
      BuscarEmpleados(Empleado,LimiteEmpleados);
      break;
    case 4:
      ImprimirPorAntiguedad(Empleado,LimiteEmpleados);
      break;
    case 5:
      Convertir(Empleado,LimiteEmpleados);
      break;
  case 6:
    LeerArchivo(Empleado,&LimiteEmpleados);
    break;
  case 7:
    GuardarArchivo(Empleado,LimiteEmpleados);
    break;
    case 8:
      Salir=1;
      printf("Saliendo...¡Hasta Pronto!\n");
      break;
    default:
      printf("Opción incorrecta, intente de nuevo\n");
      system("sleep 1");
      break;
    }
    } while(Salir!=1);
  return 0;
}
void InsertarEmpleados(TipoEmpleado Empleado[10], int *LimiteEmpleados)
{
  char Letra;
  int i;
  if(*LimiteEmpleados<10)
    {
      *LimiteEmpleados+=1;
      i=(*LimiteEmpleados)-1;
      printf("Registro Empleado %d\n",*LimiteEmpleados);
      printf("Ingrese el nombre:\n");
      __fpurge(stdin);
      gets(Empleado[i].Nombre);
      printf("Ingrese edad\n");
      scanf(" %d", &Empleado[i].Edad);
      printf("Ingrese antiguedad\n");
      scanf(" %d", &Empleado[i].Antiguedad);
      printf("Ingrese sueldo\n");
      scanf(" %f", &Empleado[i].Sueldo);
      printf("\nRegistro Éxitoso\n");
    }
  else
    printf("Ya no puede agregar más empleados, recuerde registro máximo de 10\n");
  printf("\nIngrese una letra para regresar al menú\n");
  scanf(" %c", &Letra);
}
void ImprimirEmpleados(TipoEmpleado Empleado[10], int LimiteEmpleados)
{
  char Letra;
  for(int i=0; i<LimiteEmpleados; i++)
    {
      printf("\n####################################\n");
      printf("Empleado %d\n",i+1);
      printf("Nombre: %s\n",Empleado[i].Nombre);
      printf("Edad: %d\n",Empleado[i].Edad);
      printf("Antiguedad: %d\n", Empleado[i].Antiguedad);
      printf("Sueldo: %.2f\n",Empleado[i].Sueldo);
      printf("####################################\n");
    }
  printf("\nIngrese una letra para regresar al menú\n");
  scanf(" %c", &Letra);
}
void BuscarEmpleados(TipoEmpleado Empleado[10], int LimiteEmpleados)
{
  int Encontro=0;
  char Comparar[200],Letra;
  printf("Ingrese el nombre del empleado a buscar.\n");
  __fpurge(stdin);
  gets(Comparar);
  for(int i=0; i<LimiteEmpleados; i++)
    {
      if((strcmp(Comparar,Empleado[i].Nombre))==0)
    {
      Encontro=1;
      printf("¡Empleado Encontrado!\n");
      printf("Nombre: %s\n",Empleado[i].Nombre);
      printf("Edad: %d\n",Empleado[i].Edad);
      printf("Antiguedad: %d\n", Empleado[i].Antiguedad);
      printf("Sueldo: %f\n",Empleado[i].Sueldo);
    }
    }

  if(Encontro==0)
    printf("No existe el empleado, verifique el nombre, intente de nuevo.\n");
  printf("Ingrese una letra para regresar al menú\n");
  scanf(" %c", &Letra);
}
void ImprimirPorAntiguedad(TipoEmpleado Empleado[10], int LimiteEmpleados)
{
  char Letra;
  int Encontro=0,Anios;
  printf("Ingrese los años de antiguedad de los empleados a desplegar.\n");
  scanf(" %d",&Anios);
  for(int i=0; i<LimiteEmpleados; i++)
    {
      if(Empleado[i].Antiguedad==Anios)
    {
      Encontro=1;
      printf("¡Empleado Encontrado!\n");
      printf("Nombre: %s\n",Empleado[i].Nombre);
      printf("Edad: %d\n",Empleado[i].Edad);
      printf("Antiguedad: %d\n", Empleado[i].Antiguedad);
      printf("Sueldo: %f\n",Empleado[i].Sueldo);
    }
    }
  if(Encontro!=1)
    printf("No encontró ningún empleado con esa antiguedad\n");
  printf("Ingrese una letra para regresar al menú\n");
  scanf(" %c", &Letra);
}

void Convertir(TipoEmpleado Empleado[10], int LimiteEmpleados)
{
  int NumEmp,Verificado=0,Flag=0;
  char Nombre[200],Letra;
  printf("Ingresa el nombre del empleado para convertir a mayúsculas.\n");
  __fpurge(stdin);
  gets(Nombre);
  for(int i=0; i<LimiteEmpleados; i++)
    {
      if((strcmp(Nombre,Empleado[i].Nombre))==0)
    {
      Mayusculas(&Empleado[i],&Flag);
      Verificado=1;
      NumEmp=i;
    }
    }
  if(Verificado==1 && Flag==0)
    {
    printf("El nombre se convirtió exitosamente\n");
    puts(Empleado[NumEmp].Nombre);
    }
    if(Verificado==1 && Flag==1)
    printf("El nombre ya está en Mayúsculas\n");
   if(Verificado==0)
    printf("El nombre no encontró intente de nuevo\n");

  printf("Ingrese una letra para regresar al menú\n");
  scanf(" %c", &Letra);
}
void Mayusculas(TipoEmpleado *Empleado, int *Flag)
{
  int Comprobar=0;
  for(int j=0; j<strlen(Empleado->Nombre);j++)
    {
      if(Empleado->Nombre[j]>='a' && Empleado->Nombre[j]<='z')
      {
           Empleado->Nombre[j]= Empleado->Nombre[j]-'a'+'A';
         Comprobar=1;
      }
    }
    if(Comprobar==0)
      *Flag=1;
}
void LeerArchivo(TipoEmpleado Empleado[10], int *LimiteEmpleados)
{
  FILE *Archivo;
  int Elementos=0;
  char NombreArchivo[200];
  printf("Ingresa el nombre del archivo a leer los datos.\n");
  __fpurge(stdin);
  gets(NombreArchivo);
  Archivo = fopen(NombreArchivo,"rb");
  if(Archivo==NULL)
  {
    printf("El archivo no existe, intente de nuevo.\n");
    exit(0);
  }
  else
    {
      fseek(Archivo,0L,SEEK_END);
      Elementos=ftell(Archivo);
      *LimiteEmpleados=Elementos/sizeof(TipoEmpleado);
      fseek(Archivo,0L,SEEK_SET);
      fread(Empleado,sizeof(TipoEmpleado),*LimiteEmpleados,Archivo);

    }
  fclose(Archivo);
}
void GuardarArchivo(TipoEmpleado Empleado[10],int LimiteEmpleados)
{
  FILE *Archivo;
  char NombreArchivo[200];
  printf("Ingresa el nombre del archivo a guardar los datos.\n");
  __fpurge(stdin);
  gets(NombreArchivo);
  Archivo = fopen(NombreArchivo,"wb");
  fwrite(Empleado,sizeof(TipoEmpleado),LimiteEmpleados,Archivo);
  fclose(Archivo);
}
