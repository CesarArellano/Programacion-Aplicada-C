#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void PedirNombreArchivo(char *NombreArchivo);
void PedirEcuaciones(int MatrizCoef[3][5]);


int main()
{
  FILE *Archivo;
  char NombreArchivo[200],Modo[3],Opcion;
  int MatrizCoef[3][5],i;
  PedirNombreArchivo(NombreArchivo);
  strcpy(Modo,"wt");
  Archivo = fopen(NombreArchivo,"rt");
  if(Archivo != NULL)
    {
      fclose(Archivo);
  do
    {
      printf("El archivo ya existe. Puedes (s)obreescribir (a)nadir (t)erminar: ");
      scanf("%c",&Opcion);
      switch(Opcion)
	{
	case 'S': case 's':
	strcpy(Modo,"wt");
	break;
	case 'A': case'a':
	strcpy(Modo,"at");
	break;
	case 'T': case't':
	printf("Saliendo del programa...\n");
	exit(0);
	break;
	default:
	  printf("Opcion incorrecta. Intenta otra vez.\n");
	  Opcion = 'X';
	  break;
	}
    }while(Opcion=='X');
    Archivo = fopen(NombreArchivo, Modo);
  }

if(Archivo == NULL)
  {
    printf("Error: No fue posible generar el archivo. Revise sus unidades de almacenamiento.\n");
    printf("El programa terminó de manera anormal.\n");
    exit(0);
  }
PedirEcuaciones(MatrizCoef);
for(i=0; i<5;i++)
  fprintf(Archivo, "%d, %d, %d\n",MatrizCoef[0][i],MatrizCoef[1][i],MatrizCoef[2][i]);
fclose(Archivo);
}
void PedirNombreArchivo(char *NombreArchivo)
{
  char Nombre[100];
  printf("Dame el nombre del archivo (sin extensión): ");
  gets(Nombre);
  strcpy(NombreArchivo,Nombre);
  strcat(NombreArchivo,".ecu");
}
void PedirEcuaciones(int MatrizCoef[3][5])
{
  int i;
  printf("Dame cinco ecuaciones de segundo grado.\n");
  printf("En cada renglón escribe los valores de los coeficientes de acuerdo al siguiente formato a,b,c\n");
  for(i=0;i<5;i++)
    scanf("%d, %d, %d",&MatrizCoef[0][i],&MatrizCoef[1][i],&MatrizCoef[2][i]);
}
