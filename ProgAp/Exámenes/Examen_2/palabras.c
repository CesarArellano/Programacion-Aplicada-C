typedef struct def_Arbol
{
  char palabra[50];
  int frecuencia;
  struct def_Arbol *izq, *der;
}TipoArbol;

void Crear_Arbol (TipoArbol **Raiz, char palabra [50]);
void Imprimir_Orden(TipoArbol *Raiz);
void Imprimir_Pre(TipoArbol *Raiz);
void Imprimir_Post(TipoArbol *Raiz);
void Buscar (TipoArbol *Raiz, char palabra[50]);
void Borrar_Arbol(TipoArbol *Raiz);

int main (void)
{
  int Opcion,i=0,j=0;
  char nombre[50], Renglon[200],palabra[50];
  FILE *Archivo;
  TipoArbol *Raiz=NULL;
  system("clear");
  printf("Ingrese el nombre del archivo\n");
  gets(nombre);
  Archivo = fopen(nombre,"rt");
  if(Archivo== NULL)
    {
      printf("El archivo no se encontró, intente de nuevo\n");
      printf("Saliendo del programa...\n");
      exit(0);
    }
  else
    {
      while(fgets(Renglon,100,Archivo)!=NULL)
	{
	  Renglon[strlen(Renglon)-1]='\0';
	  for(i=0; Renglon[i]!='\0'; i++)
	    {
	      if((Renglon[i]>= 'A' && Renglon[i]<= 'Z') || (Renglon[i]>= 'a' && Renglon[i]<= 'z'))
		{
		  palabra[j]=Renglon[i];
		  j++;
		  if(Renglon[i+1]==' ' || Renglon[i+1]=='\0')
		    {
		      palabra[j]='\0';
		      Crear_Arbol(&Raiz, palabra);
		      j=0;
		    }
		 		     
		}
	    }
	} 
      fclose(Archivo);
    }
  do
    {
      system("clear");
      printf("Menú:\n");
      printf("1.- Imprimir Orden\n");
      printf("2.- Imprimir Pre orden\n");
      printf("3.- Imprimir Post orden\n");
      printf("4.- Salir del programa\n");
      scanf(" %d", &Opcion);
      system("clear");
      switch(Opcion)
	{
	case 1:
	  printf("Impresion en orden:\n\n");
	  Imprimir_Orden(Raiz);
	  break;
	case 2:
	  printf("Impresion en Pre orden:\n\n");
	  Imprimir_Pre(Raiz);
	  break;
	case 3:
	  printf("Impresion en Post orden:\n\n");
	  Imprimir_Post(Raiz);
	  break;
	case 4:
	  printf("Saliendo del programa...\n");
	  Borrar_Arbol(Raiz);
	  exit(0);
	  break;
	default:
	  printf("Opción inválida, intente de nuevo\n");	  
	  break;
	}
      printf("\nPresione Enter para continuar...\n");
      __fpurge(stdin);
      getchar();
    } while(Opcion!=4);
}

void Crear_Arbol (TipoArbol **Raiz, char palabra [50])
{
  TipoArbol *Avanza, *Nuevo;
  Avanza = *Raiz;
  Nuevo = (TipoArbol *) malloc(sizeof(TipoArbol));
  strcpy(Nuevo->palabra, palabra);
  Nuevo->frecuencia=1;
  Nuevo->izq= NULL;
  Nuevo->der= NULL;
  while(Avanza !=NULL)
    {
      if((strcmp(palabra,Avanza->palabra))>0)
	{
	  if(Avanza->der != NULL)
	    Avanza = Avanza->der;
	  else
	    {
	      Avanza->der=Nuevo;
	      return;
	    }
	}
      if((strcmp(palabra,Avanza->palabra))==0)
	{
	  (Avanza->frecuencia)++;
	  return;
	}
      if((strcmp(palabra,Avanza->palabra))<=0) //muevete a la izquierda
	{
	  if(Avanza->izq != NULL)
	    Avanza = Avanza->izq;
	  else
	    {
	      Avanza->izq = Nuevo;
	      return;
	    }
	}
      
    }
  Avanza = Nuevo;
  *Raiz = Avanza;    
}

void Imprimir_Orden(TipoArbol *Raiz)
{
  if(Raiz != NULL)
    {
      Imprimir_Orden(Raiz->izq);
      printf("Palabra: %s, Frecuencia: %d\n",Raiz->palabra, Raiz->frecuencia);
      Imprimir_Orden(Raiz->der);
    }
}
void Imprimir_Pre(TipoArbol *Raiz)
{
  if(Raiz != NULL)
    {
      printf("Palabra: %s, Frecuencia: %d\n",Raiz->palabra, Raiz->frecuencia);
      Imprimir_Pre(Raiz->izq);
      Imprimir_Pre(Raiz->der);
    }
}

void Imprimir_Post(TipoArbol *Raiz)
{
  if(Raiz != NULL)
    {
      Imprimir_Post(Raiz->izq);
      Imprimir_Post(Raiz->der);
      printf("Palabra: %s, Frecuencia: %d\n",Raiz->palabra, Raiz->frecuencia);
    }
}
void Buscar (TipoArbol *Raiz, char palabra[50])
{
  if(Raiz != NULL)
    {
      Buscar(Raiz->izq, palabra);
      if((strcmp(Raiz->palabra,palabra))==0)
	printf("La palabra %s, si se encuentra dentro del árbol y su frecuencia es: %d\n", Raiz->palabra,Raiz->frecuencia);
      Buscar(Raiz->der, palabra);
    }
  else
    printf("La palabra introducida no se encuentra en el árbol\n");
}

void Borrar_Arbol(TipoArbol *Raiz)
{
  if(Raiz != NULL)
    {
      Borrar_Arbol(Raiz->izq);
      Borrar_Arbol(Raiz->der);
      free(Raiz);
    }
}
