#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
  FILE *Archivo;
  char Renglon[200];

  if(argc!=2)
    {
      printf("Uso:\n text6.exe <archivo-de-texto>\n");
      exit(1);
    }
  Archivo= fopen(argv[1], "rt");
  if(Archivo==NULL)
    {
      printf("No existe el archivo. Fin del programa \n");
      exit(0);
    }
  while(fgets(Renglon,100,Archivo)!=NULL)
    {
      Renglon[strlen(Renglon)-1]='\0';
      puts(Renglon);
    }
  fclose(Archivo);
}
