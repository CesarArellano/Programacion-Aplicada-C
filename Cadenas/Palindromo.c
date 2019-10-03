#include <stdio.h>
#include <string.h>

void QuitarEspacios(char Frase[200]);
void Mayusculas(char Frase[200]);
void Invertir(char Frase[200], char Frase2[200]);


int main (void)
{
  char Frase[200], Frase2[200];
  printf("Escribe la frase\n");
  gets(Frase);
  QuitarEspacios(Frase);
  Mayusculas(Frase);
  Invertir(Frase,Frase2);
  if((strcmp(Frase,Frase2))==0)
    printf("Es un palindromo\n");
  else
    printf("No es una palindromo\n");
}
void QuitarEspacios(char Frase[200])
{
  char Letras[200];
  int i,j=0;
  for(int i=0;i<strlen(Frase);i++)
    {
      if((Frase[i]>='a' && Frase[i]<='z') || (Frase[i]>='A' && Frase[i]<='Z'))
	{
	  Letras[j]=Frase[i];
	  j++;
	}
    }
  Letras[j]='\0';
  strcpy(Frase,Letras);
}
void Mayusculas(char Frase[200])
{
  for(int i=0; i<strlen(Frase);i++)
    {
      if((Frase[i]>='a' && Frase[i]<='z'))
	Frase[i]=Frase[i]-'a'+'A';
    }
}
void Invertir(char Frase[200], char Frase2[200])
{
  int i,j=0;
  for(i=strlen(Frase)-1;i>=0;i--)
    {
      Frase2[j]=Frase[i];
      j++;
    }
  Frase2[j]='\0';
}
