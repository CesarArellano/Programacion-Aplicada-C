#include <stdio.h>
#include <string.h>

void Invertir (char *Frase, char *Frase2);

int main (void)
{
  char Frase[200], Frase2[200];
  printf("Escribe la frase\n");
  scanf(" %[^\n]", Frase);
  Invertir(Frase,Frase2);
  puts(Frase2);
}

void Invertir (char *Frase, char *Frase2)
{
  int j=0;
  for(int i=strlen(Frase)-1;i>=0;i--)
    {
     	*(Frase2+j)=*(Frase+i);
	j+=1;
    }
  *(Frase2+j)='\0';
}
