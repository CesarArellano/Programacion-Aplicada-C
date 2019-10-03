#include <stdio.h>

int main (void)
{
  int j,i,n;
  printf("Ingrese la altura del triangulo\n");
  scanf(" %d",&n);

  for(i=1; i<=n; i++)
  {
    for(j=1; j<=n-i; j++)
      printf(" ");
    for(j=1; j<=2*i-1; j++)
      printf("*");
      printf("\n");
  }
  for(i=n; i>=1; i--)
  {
    if(i!=n)
    {
      for(j=n-i; j>=1; j--)
        printf(" ");
      for(j=2*i-1; j>=1; j--)
        printf("*");
        printf("\n");
    }
  }
}
