#include <stdio.h>

#define SIZE 10

void makeheap(int x [], int n);
void heapsort (int x[], int n);

int main(void)
{
  int Arreglo[SIZE], i;
  for(i=0; i<SIZE;i++)
  {
    printf("Ingrese el elemento %d:\n",i+1);
    scanf(" %d", &Arreglo[i]);
  }
  makeheap(Arreglo,10);
  heapsort(Arreglo,10);
  printf("Despues del Heapsort de elementos\n");
  for(i=0; i<SIZE;i++)
    printf("%d\t",Arreglo[i]);
  printf("\n");
  getchar();
}

void makeheap(int x [], int n)
{
  int i, val, s, f;
  for(i=1; i<n; i++)
  {
    val = x[i];
    s=i;
    f = (s-1)/2;
    while (s>0 && x[f]<val)
    {
      x[s] = x[f];
      s= f;
      f= (s-1)/2;
    }
    x[s]= val;
  }
}
void heapsort (int x[], int n)
{
   int i, s, f, ivalue;
   for(i=n-1; i>0; i--)
   {
     ivalue= x[i];
     x[i]= x[0];
     f= 0;
     if(i==1)
        s= -1;
        else
        s=1;
        if(i>2 && x[2] > x[1])
        s=2;
     while (s>=0 && ivalue < x[s])
     {
       x[f] = x[s];
       f = s;
       s = 2 * f + 1;
       if(s+1<=i && x[s] < x[s+1])
        s++;
       if(s>i-1)
        s=-1;
     }
     x[f] = ivalue;
   }
}
