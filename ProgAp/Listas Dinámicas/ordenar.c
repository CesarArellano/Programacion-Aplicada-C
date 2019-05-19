#include <stdio.h>

void PedirDatos(int Num[], int *Cant);
void Ordenar(int Num[], int Cant);
void Imprimir(int Num[], int Cant);

int main (void)
{
  int Numeros[100],CantNum;
  PedirDatos(Numeros,&CantNum);
  Ordenar(Numeros,CantNum);
  Imprimir(Numeros,CantNum);
  return 0;
}

void PedirDatos(int Num[], int *Cant)
{
  do
    {
      printf("Introduce la cantidad de numeros [max:100]\n");
      scanf(" %d",Cant);
    } while(*Cant<1 || *Cant>100);

  for(int i=0; i<*Cant;i++)
    {
      printf("Ingresa el valor %d\n",i+1);
      scanf(" %d",&Num[i]);
    }
}
void Ordenar(int Num[], int Cant)
{  
  int temp;
  for(int i=0; i<Cant; i++)
    {
      for(int j=i+1; j<Cant; j++)
	{
	  if(Num[j]<Num[i])
	    {
	      temp=Num[i];
	      Num[i]=Num[j];
	      Num[j]=temp;
	    }
	}
    }
}
void Imprimir(int Num[], int Cant)
{
   for(int i=0; i<Cant;i++)
    {
      printf("Valor %d: %d\n",i+1,Num[i]);
    }
}
