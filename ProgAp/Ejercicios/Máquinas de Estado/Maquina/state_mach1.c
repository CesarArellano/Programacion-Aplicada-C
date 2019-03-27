/****************************************************************
 *								*
 * Archivo:	state_mach1.c					*
 * Descripcion: Codigo Fuente para implementar el programa	*
 *		de maquina de estados.			 	*
 *								*
 ****************************************************************/

/*************** ARCHIVOS DE INCLUSION ***************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tables.h"


/*************** VARIABLES GLOBALES ***************/
EVENT event;
int state;
char buf[BUFFER];
int Saldo;
int Stock[10];

/*************** PROTOTIPOS DE FUNCION ***************/
void initialise(void);
void getevent(void);

int SumarDinero(void);
int MsgProducto(void);
int DineroSuficiente(void);
int ProductoExiste(void);
int NoAlcanza(void);
int NoHayProducto(void);
int DarProducto(void);
int nul(void);


/*************** FUNCION PRINCIPAL ***************/
int main(int argc, char **argv)
{
    int actx, auxx, outcome;

    initialise();

    while (1) {    /* loop infinito para la MFE */
        getevent(); // leer el evento

        for ((actx = state_table[state].start);(action_table[actx].event != event.etype) && (actx < state_table[state].end);actx++)
            ;
        outcome = (*(action_table[actx].action))();
            if(action_table[actx].moreacts == -1)
                state = action_table[actx].nextstate;
            else {
                auxx = action_table[actx].moreacts + outcome;
                while (auxx != -1){
                    outcome = (*(aux_table[auxx].action))();
                    if (aux_table[auxx].moreacts == -1 ){
                        state = aux_table[auxx].nextstate;
                        auxx = -1;
                    }
                    else
                        auxx = aux_table[auxx].moreacts + outcome;

                }
        }

    } /* while(1) */
}

void initialise(void)
{
    state = 0;
    Saldo = 0;
    for(int i = 0; i<10; i++)
      Stock[i] = i+1;
    printf("Bienvenido a la máquina dispensadora\n");
}


void getevent(void)
{
    char *ptmp;
    ptmp = &buf[2];

#ifdef DEBUG
    printf("wait event \n");
#endif
    __fpurge(stdin);
    if(state == 0)
      printf("Inserte Dinero ($) o Ingrese codigo de producto (#)\n");
    else
      printf("Inserte Dinero (+) o Ingrese codigo de producto (-)\n");

    gets(buf);
         switch (buf[0])
             {
                 case '$' :
                     event.etype=ENTRADA_0;
                     break;
                 case '#' :
                     event.etype=ENTRADA_1;

                     break;
                 case '+' :
                     event.etype=ENTRADA_2;
                     break;
                 case '-':
                  event.etype=ENTRADA_3;
                     break;
              	 default:
              		     event.etype=-1;
              		     break;

             }//switch
}// getevent


/* FUNCIONES DE IMPLEMENTACION */

int SumarDinero(void)
{
  int auxiliar;
  printf("¿Cuánto dinero vas a ingresar?\n");
  __fpurge(stdin);
  scanf(" %d", &auxiliar);
  Saldo+=auxiliar;
}

int MsgProducto(void)
{
  printf("El precio del producto es: $15 varos\n");
}

int DineroSuficiente(void)
{
  if(Saldo>=15)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int ProductoExiste(void)
{
  int num, flag = 0;
  printf("Ingresa el codigo del producto\n");
  scanf("%d", &num);
  for(int i = 0; i < 10; i++){
    if(Stock[i] == num)
      flag = 1;
  }
  if(flag == 1)
    return 3;
  else
    return 2;
}

int NoAlcanza(void)
{
  printf("No alcanza el dinero para el productos\n");
}

int NoHayProducto(void)
{
  printf("No hay producto\n");
}

int DarProducto(void)
{
  printf("Gracias por su compra\n");
  printf("El cambio es %d \n", Saldo-15);
  Saldo = 0;
}

int nul(void)
{
 printf("Ingrese una opcion valida\n");
}
