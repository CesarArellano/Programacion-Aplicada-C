#include <stdio.h>

int main()
{
  FILE *Archivo;
  char Frase[200];
  Archivo=fopen("algo.txt","wt");
  printf("Escribe tu frase favorita\n");
  gets(Frase);
  fprintf(Archivo,"Tu frase favorita es: %s\n",Frase);
  fclose(Archivo);
}
