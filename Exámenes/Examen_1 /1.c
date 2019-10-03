#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct def_Texto
{
  int CantP, Minus,Mayus,Total,Espacios;
  
}TipoTexto;

void LeerArchivo(TipoTexto *ArchivoTexto);
void ImprimirResultados(TipoTexto ArchivoTexto);
int main (void)
{
  system("clear");
  TipoTexto ArchivoTexto;
  ArchivoTexto.CantP=0;
  ArchivoTexto.Minus=0;
  ArchivoTexto.Mayus=0;
  ArchivoTexto.Total=0;
  ArchivoTexto.Espacios=0;
  LeerArchivo(&ArchivoTexto);
  ImprimirResultados(ArchivoTexto);
}

void LeerArchivo(TipoTexto *ArchivoTexto)
{
  FILE *Archivo;
  char Renglon[100],NombreArchivo[200];
  printf("¿Cual es el nombre del archivo?\n");
  gets(NombreArchivo);
  Archivo = fopen(NombreArchivo,"rt");
  if(Archivo==NULL)
    {
      printf("El archivo no existe, intente de nuevo\n");
      exit(0);
    }
  else
    {
      while(fgets(Renglon,100,Archivo)!=NULL)
	{
	  Renglon[strlen(Renglon)-1]='\0';
	  for(int i=0; Renglon[i]!='\0';i++)
	    {
	      if((Renglon[i]>='a' && Renglon[i]<='z')|| (Renglon[i]>='A' && Renglon[i]<='Z'))
		{
		  if (Renglon[i+1]==' ' || Renglon[i+1]=='\0')
		    {
		      ArchivoTexto->CantP+=1;
		    }		
		}
	      if(Renglon[i]==' ')
		ArchivoTexto->Espacios+=1;
	      if(Renglon[i]>='a' && Renglon[i]<='z')
		ArchivoTexto->Minus+=1;
	      if(Renglon[i]>='A' && Renglon[i]<='Z')
		ArchivoTexto->Mayus+=1;
	    }
	}
      ArchivoTexto->Total=ArchivoTexto->Minus+ArchivoTexto->Mayus;
      fclose(Archivo);
    }
}

void ImprimirResultados(TipoTexto ArchivoTexto)
{
  printf("El archivo contiene:\n");
  printf("Cantidad de Palabras: %d\n",ArchivoTexto.CantP);
  printf("Letras Minusculas: %d\n",ArchivoTexto.Minus);
  printf("Letras Mayusculas: %d\n",ArchivoTexto.Mayus);
  printf("Letras Totales: %d\n",ArchivoTexto.Total);
  printf("Espacios existentes: %d\n",ArchivoTexto.Espacios);
}

