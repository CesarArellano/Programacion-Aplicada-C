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

/*************** PROTOTIPOS DE FUNCION ***************/ 
void initialise(void);
void getevent(void);

int funcion1(void);
int funcion2(void);
int funcion3(void);
int funcion4(void);
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
}


void getevent(void)
{
    char *ptmp;     
    ptmp = &buf[2];
    
#ifdef DEBUG
    printf("wait event \n");
#endif
    gets(buf); 
         switch (buf[0])
             {
                 case 'A' :
                     event.etype=ENTRADA_1;
                     break;
                 case 'B' :
                     event.etype=ENTRADA_2;
                     break;
                 case 'C' :
                     event.etype=ENTRADA_3;
                     strcpy(event.args,ptmp);	// Esta instruccion se debera hacer en caso de que ademas de la letra
                     				// para indicar la entrada, se pase informacion adicional, por ejemplo
                     				// C:info_adicional
		#ifdef DEBUG
    			printf("---> %s \n",event.args);
		#endif
                     				
                     break;
		default:
		     event.etype=-1;
		     break;
                     
             }//switch
}// getevent
 

/* FUNCIONES DE IMPLEMENTACION */

int funcion1(void)
{
	
}//funcion1

int funcion2(void)
{
	
}//funcion2

int funcion3(void)
{
	
}//funcion3

int funcion4(void)
{
	
}//funcion4

int nul(void)
{
	
}//nul
