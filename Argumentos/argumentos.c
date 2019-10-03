#include <stdio.h>
int main (int argc, char *argv[])
{
  printf("Hay %d argumentos\n",argc);
  for(int i=0; i<argc; i++)
  puts(argv[i]);
}
