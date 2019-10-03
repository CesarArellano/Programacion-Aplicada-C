#include <stdio.h>
#include <stdlib.h>

void Leer_Entrada(char *argv[], int *Num1, int *Num2, char *Signo);

int main (int argc, char *argv[])
{
  char Signo;
  int Num1,Num2,Resultado;
  if(argc!=4)
    {
    printf("Error, excede o falta parametros para operar.\n");
    printf("Ejemplo del uso del programa: ./calculadora.exe 2 + 4.\n");
    exit(0);
    }
  else
    {
      Leer_Entrada(argv,&Num1,&Num2,&Signo);
  switch(Signo)
    {
    case '+':
      Resultado=Num1+Num2;
      printf("EL resultado de la operacion %d %c %d es: %d\n",Num1,Signo,Num2,Resultado);
      break;
    case '-':
    Resultado=Num1-Num2;
    printf("EL resultado de la operacion %d %c %d es: %d\n",Num1,Signo,Num2,Resultado);
      break;
    case 'x':
    Resultado=Num1*Num2;
    printf("EL resultado de la operacion %d %c %d es: %d\n",Num1,Signo,Num2,Resultado);
      break;
      case '/':
      Resultado=Num1/Num2;
      printf("EL resultado de la operacion %d %c %d es: %d\n",Num1,Signo,Num2,Resultado);
      break;
    default:
      printf("Error, la operacion no es posible, intente de nuevo.\n");
      printf("Operaciones posibles: [+,-,x,/].\n]");
      exit(0);
      break;
    }
  }
}

void Leer_Entrada(char *argv[], int *Num1, int *Num2, char *Signo)
{
  sscanf(argv[1],"%d",Num1);
  sscanf(argv[2],"%c",Signo);
  sscanf(argv[3],"%d",Num2);
}
