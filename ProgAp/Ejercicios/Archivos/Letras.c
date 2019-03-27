#include <stdio.h>

void LeerFrase(char Frase[200]);
void ContarLetras(char Frase [200], char Abecedario[52]);

int main (void)
{
  char Abecedario[52]="abcdefghijklmnopkrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
  char Frase[200];
  LeerFrase(Frase);
  ContarLetras(Frase,Abecedario);
  return 0;
}

void LeerFrase(char Frase[200])
{
  printf("Escriba la frase\n");
  gets(Frase);
}
void ContarLetras(char Frase [200], char Abecedario[52])
{
  int Contador;
  char Letra;
  for(int i=0; i<52; i++)
    {
      Contador=0;
      for(int j=0; Frase[j]!='\0';j++)
	{
	  if(Frase[j]==Abecedario[i])
	    {
	      Contador+=1;
	      Letra=Abecedario[i];
	    }
	}
      if(Contador!=0)
	printf("La letra %c se repite: %d\n",Letra,Contador);
    }
}
