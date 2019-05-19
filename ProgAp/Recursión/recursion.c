#include <stdio.h>
#include <string.h>
void InvierteFrase(char Cadena[200], char Cadena2[200]);
int main (void)
{
int i;
char Frase[200], Frase2[200];
printf("Dame una frase: ");
gets(Frase);
printf("Tu frase invertida es: ");
InvierteFrase(Frase,Frase2);
puts(Frase2);
printf("\n");
}
void InvierteFrase(char Cadena[200], char Cadena2[200])
{
 int i=strlen(Cadena)-1;
 if(Cadena!='\0')
 {
   InvierteFrase(Cadena+1,Cadena2);
   Cadena2[i]=*Cadena;
 }
  Cadena2[strlen(Cadena)]='\0';
}
