/************************************************************************
 *									*
 * Archivo:	tables.h						*
 * Descripcion: Tablas para la maquina de estados y funciones externas	*
 *		Aqui se definen todos las tablas que se utilizan	*
 *		en el programa						*
 *									*
 ************************************************************************/

/*************** ARCHIVOS DE INCLUSION ***************/ 
#include "local.h"
#include <stdio.h>


/*************** FUNCIONES EXTERNAS *********************
 * En esta seccion se declaran los encabezados de 	*
 * todas las funciones que se utilizan en las     	*
 * tablas del programa. Todas las funciones deben 	*
 * ser de tipo entero y no deben recibir parametros	*
 ********************************************************/ 
extern int funcion1(void);
extern int funcion2(void);
extern int funcion3(void);
extern int funcion4(void);
extern int nul(void);

/******************** TABLAS ********************
 * En esta seccion se declaran las tablas	*
 * que se van a usar en el programa		*
 ************************************************/ 
 
/*************** TABLA DE ACCION ***************/  
ACTION_TAB action_table[]={
        /*etype     accion     bandera   sigEdo. */    
    { ENTRADA_0,  Pide_Passw,  	-1,	Pass_Word_1},
    { ENTRADA_1,  Error_U,	-1,	Inicio_0},
    { ENTRADA_2,  Correcto,	 0,	Inicio_1},
    { ENTRADA_3,  Error_P,	-1,	Pass_Word_1},    
};

/*************** TABLA AUXILIAR ***************/  //No borrar aunque no se utilice.
    AUX_TAB aux_table[]={        
/*    accion       bandera           sigEdo */
    { funcion1,        -1,          ESTADO_0},
    { funcion2,	       -1,          ESTADO_0},
};

/*************** TABLA DE ESTADOS ***************/  
STATE_TAB state_table[]={
   /*estado      inicio   fin */
    {ESTADO_0,     0,      1},
    {ESTADO_1,     2,      3},
};


    
        

        
    
        
    
        
    
        
    
        
    
        
    
        
    
        
    
        
    
        
    
        
    
    
        
