#include <stdio.h>
#include <stdlib.h>

int main (void)
{
  int Numtemps,*Listatemps,i;
  printf("Cuantas temperaturas quieres?\n");
  scanf("%d",&Numtemps);
  Listatemps=(int *)malloc(sizeof(int)*Numtemps);
  for(i=0; i<Numtemps; i++)
  {
    printf("Ingrese la temperatura [%d]: \n",i+1);
    scanf("%d", &Listatemps[i]);
  }
  for(i=0; i<Numtemps; i++)
    printf("Temperatura [%d]: %d \n",i+1, Listatemps[i]);
  free(Listatemps);
}
