#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
  char NombreArchivo[200];
  int a,b,c,i;
  float x1,x2;
  FILE *Archivo;
  printf("Dame el nombre del archivo con las ecuaciones:\n");
  gets(NombreArchivo);
  Archivo= fopen(NombreArchivo,"rt");
  if(Archivo==NULL)
  {
    printf("No existe el archivo. Fin del Programa.\n");
    exit(0);
  }
  //for(i=1; i<=5; i++)
  //while(!feof(Archivo))
  while(fscanf(Archivo,"%d, %d, %d",&a,&b,&c)==3)
  {
    //fscanf(Archivo, "%d, %d, %d", &a, &b, &c);
    x1 = (-b + sqrt(b*b-4*a*c))/2*a;
    x2 = (-b - sqrt(b*b-4*a*c))/2*a;
    printf("Para %dx2+%dx+%d, X1= %.2f, X2: %.2f\n",a,b,c,x1,x2);
  }
  fclose(Archivo);
  return 0;
}
