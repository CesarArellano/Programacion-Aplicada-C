#include <stdio.h>
#include <string.h>

void PedirNombreArchivo(char *NombreArchivo);
void PedirEcuaciones(int MatrizCoef[5][3]);

int main(void)
{
  FILE *Archivo;
  char NombreArchivo[200];
  int MatrizCoef[5][3],i;
  PedirNombreArchivo(NombreArchivo);
  Archivo = fopen(NombreArchivo,"wt");
  PedirEcuaciones(MatrizCoef);
  for(i=0; i<5; i++)
  fprintf(Archivo, "%d, %d, %d\n",MatrizCoef[i][0],MatrizCoef[i][1],MatrizCoef[i][2]);
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
void PedirEcuaciones(int MatrizCoef[5][3])
{
  int i;
  printf("Dame 5 ecuaciones de segundo grado.\n");
  printf("En cada renglon escribe los valores de los coeficientes de acuerdo al siguiente formato: a, b, c\n");
  for(i=0;i<5;i++)
    scanf("%d, %d, %d",&MatrizCoef[i][0],&MatrizCoef[i][1],&MatrizCoef[i][2]);
}
