#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Def_Cola_Impresion
{
  char NombreDoc[200],Estado[200];
  int ID,NumHojas,HojasImpresas;
  struct Def_Cola_Impresion *sig;
}TipoDocumento;

void IntroducirDoc(TipoDocumento **ColaImpresion, TipoDocumento NuevoDocumento, int Numeracion);
void ListarTrabajos(TipoDocumento *ColaImpresion);
void EliminarTrabajos(TipoDocumento **ColaImpresion,int ID);
void ImprimirDoc(TipoDocumento **ColaImpresion);
void GuardarColaArch(TipoDocumento *ColaImpresion);
void LeerColaArch(TipoDocumento **ColaImpresion,int *Numeracion);
void Borrar_Lista(TipoDocumento *ColaImpresion);

int main (void)
{
  TipoDocumento *ColaImpresion=NULL, NuevoDocumento;
  int Opcion,Salir=0,Numeracion=1,ErrorLectura=0,ID;
  do
    {
      system("clear");
      printf("Menú Cola Impresión:\n");
      printf("1.- Introducir documento a la cola de impresión.\n");
      printf("2.- Listar trabajos en la cola de impresión.\n");
      printf("3.- Eliminar trabajo de la cola de impresión.\n");
      printf("4.- Imprimir documento.\n");
      printf("5.- Guardar cola en archivo.\n");
      printf("6.- Leer cola en archivo.\n");
      printf("7.- Salir.\n\n");
      printf("Escoge una opción: \n");
      scanf(" %d",&Opcion);
      switch(Opcion)
	{
	case 1:
	  system("clear");
	  printf("Ingresar a la cola documento:\n");
	  printf("Introduzca el nombre del documento\n");
	  __fpurge(stdin);
	  gets(NuevoDocumento.NombreDoc);
	  printf("Introduzca el número de hojas que contiene el documento\n");
	  __fpurge(stdin);
	  scanf("%d",&NuevoDocumento.NumHojas);
	  if(NuevoDocumento.NumHojas<=0)
	    ErrorLectura=1;
	  if(ErrorLectura==0)
	    {
	      IntroducirDoc(&ColaImpresion,NuevoDocumento,Numeracion);
	      Numeracion++;
	    }
	  else
	    printf("El numero hojas debe ser de al menos 1 hoja, intente de nuevo\n");
	  printf("Presione Enter para continuar...\n");
	  __fpurge(stdin);
	  getchar();
	  break;
	case 2:
	  system("clear");
	  ListarTrabajos(ColaImpresion);
	  break;
	case 3:
	  system("clear");
	  printf("Introduzca el ID del documento a eliminar de la cola\n");
	  scanf(" %d",&ID);
	  EliminarTrabajos(&ColaImpresion,ID);
	  printf("Presione Enter para continuar...\n");
	  __fpurge(stdin);
	  getchar();
	  break;
	case 4:
	  system("clear");
	  ImprimirDoc(&ColaImpresion);
	  break;
	case 5:
	  system("clear");
	  GuardarColaArch(ColaImpresion);
	  break;
	case 6:
	  system("clear");
	  LeerColaArch(&ColaImpresion,&Numeracion);
	  break;
	case 7:
	  Salir=1;
	  break;
	default:
	  system("clear");
	  printf("La opción a seleccionar ha sido incorrecta, intentelo de nuevo :(\n");
	  break;
	}
    } while(Salir==0);
  Borrar_Lista(ColaImpresion);
  printf("Gracias por utilizar el programa, hasta la próxima\n");

}

void ListarTrabajos(TipoDocumento *ColaImpresion)
{
  system("clear");
  TipoDocumento *temp,*temp2;
  temp=ColaImpresion;
  temp2=ColaImpresion;
  printf("Cola de Impresion:\n");
  while(temp!=NULL)
    {
      if(strcmp("Espera",temp->Estado)==0)
	printf("%d: %s, %d hojas, %s\n",temp->ID, temp->NombreDoc, temp->NumHojas, temp->Estado);
      temp=temp->sig;
    }
  while(temp2!=NULL)
    {
      if(strcmp("Imprimiendo",temp2->Estado)==0)
	printf("%d: %s, %d hojas, %s, %d hoja(s) impresa(s)\n",temp2->ID, temp2->NombreDoc, temp2->NumHojas, temp2->Estado, temp2->HojasImpresas);
      temp2=temp2->sig;
    }

  printf("Presione Enter para continuar...\n");
  __fpurge(stdin);
  getchar();
}
void EliminarTrabajos(TipoDocumento **ColaImpresion,int ID)
{
  TipoDocumento *temp,*temp2;
  temp=*ColaImpresion;
  temp2=*ColaImpresion;
  if(*ColaImpresion==NULL) // Si la lista está vacía
    {
      printf("La lista está vacía, no puede eliminar ningún documento\n");
    }
  else
    {
      while(temp!=NULL)
	{
	  if(temp->ID == ID)
	    {
	      if(temp == *ColaImpresion)
		{
		  *ColaImpresion = temp->sig;
		  free(temp);
		}
	      else
		{
		  while(temp2->sig!=temp)
		    temp2=temp2->sig;
		  temp2->sig=temp->sig;
		  free(temp);
		}
	    }
	  temp=temp->sig;
	}
    }

}

void IntroducirDoc(TipoDocumento **ColaImpresion, TipoDocumento NuevoDocumento, int Numeracion)
{
  TipoDocumento *nuevo;
  nuevo=(TipoDocumento *)malloc(sizeof(TipoDocumento));
  strcpy(nuevo->Estado,"Espera");
  strcpy(nuevo->NombreDoc,NuevoDocumento.NombreDoc);
  nuevo->NumHojas=NuevoDocumento.NumHojas;
  nuevo->HojasImpresas=0;
  nuevo->ID=Numeracion;
  nuevo->sig=*ColaImpresion;
  *ColaImpresion=nuevo;
}

void ImprimirDoc(TipoDocumento **ColaImpresion)
{
  TipoDocumento *temp,*temp2;
  int i=1,Verificado=0;
  temp=*ColaImpresion;
  temp2=*ColaImpresion;
  while(temp!=NULL)
    {
      if(strcmp(temp->Estado,"Imprimiendo")==0)
	{
    if(temp->HojasImpresas==temp->NumHojas)
	    EliminarTrabajos(ColaImpresion,temp->ID);
	  else
	    {
        temp->HojasImpresas+=1;
	      printf("Se imprimió con éxito\n");
	      Verificado=1;
	    }
	}
      temp=temp->sig;
    }

  if(Verificado==0)
    {
      while(temp2!=NULL && Verificado==0)
	{
	  if(temp2->sig==NULL && strcmp(temp2->Estado,"Espera")==0)
	    {
	      strcpy(temp2->Estado,"Imprimiendo");
	      temp2->HojasImpresas=1;
	      Verificado=1;
	      printf("Se imprimió con éxito\n");
	      if(temp2->HojasImpresas==temp2->NumHojas)
		EliminarTrabajos(ColaImpresion,temp2->ID);

	    }
	  temp2=temp2->sig;
	}
    }
  printf("Presione Enter para continuar...\n");
  __fpurge(stdin);
  getchar();
}

void GuardarColaArch(TipoDocumento *ColaImpresion)
{
  TipoDocumento *temp;
  char NombreArchivo[200];
  FILE *Archivo;
  temp=ColaImpresion;  printf("Ingresa el nombre del archivo a guardar\n");
  __fpurge(stdin);
  gets(NombreArchivo);
  Archivo = fopen(NombreArchivo,"wt");

  while(temp!=NULL)
    {
      fprintf(Archivo,"%d\n%s\n%d\n%d\n%s\n",temp->ID, temp->NombreDoc, temp->NumHojas,temp->HojasImpresas,temp->Estado);
      temp=temp->sig;
    }
  fclose(Archivo);
}

void LeerColaArch(TipoDocumento **ColaImpresion,int *Numeracion)
{

  TipoDocumento *temp, *nuevo;
  int NuevoID_Documento;
  char NombreArchivo[200];
  FILE *Archivo;
  printf("Ingresa el nombre del archivo a leer\n");
  __fpurge(stdin);
  gets(NombreArchivo);
  Archivo = fopen(NombreArchivo,"rt");
  if(Archivo==NULL)
    printf("No existe el archivo,intentelo de nuevo\n");
  else
    {
      while ((fscanf (Archivo, " %d", &NuevoID_Documento)) == 1)
	{
	  nuevo = (TipoDocumento *)malloc(sizeof(TipoDocumento));
	  nuevo -> ID = NuevoID_Documento;
	  *Numeracion = NuevoID_Documento;
	  fscanf (Archivo, " %[^\n]", nuevo -> NombreDoc);
	  fscanf (Archivo, " %d", &nuevo -> NumHojas);
	  fscanf (Archivo, " %d", &nuevo -> HojasImpresas);
	  fscanf (Archivo, " %[^\n]", nuevo -> Estado);
	  nuevo -> sig = NULL;
	  if (*ColaImpresion != NULL)
	    {
	      temp = *ColaImpresion;
	      while (temp -> sig != NULL)
		temp = temp -> sig;
	      temp -> sig = nuevo;
	    }
	  else
	    *ColaImpresion = nuevo;
	}
      if(*ColaImpresion==NULL)
        *Numeracion=1;
      else
        *Numeracion+=1;

      fclose(Archivo);
    }

  printf("Presione Enter para continuar...\n");
  __fpurge(stdin);
  getchar();
}

void Borrar_Lista(TipoDocumento *ColaImpresion)
{
  TipoDocumento *temp;
  temp=ColaImpresion;
  while(temp!=NULL)
    {
      ColaImpresion=ColaImpresion->sig;
      free(temp);
      temp=ColaImpresion;
    }
}
