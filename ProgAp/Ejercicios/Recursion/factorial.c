#include <stdio.h>

void factorial(int Numero, int *Resultado);

int main (void)
{
 int Numero, Resultado;
 printf("Ingrese el numero\n");
 scanf(" %d",&Numero);
 factorial(Numero,&Resultado);
 printf("El factorial de %d es: %d\n",Numero,Resultado);
}
void factorial(int Numero, int *Resultado)
{
  if(Numero==1)
   *Resultado=1;
   else
   factorial(Numero-1,Resultado);
   *Resultado*=Numero;
}
