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
extern int msg_aEdoA(void);
extern int msg_aEdoB(void);
extern int msg_SalA(void);
extern int msg_SalB(void);
extern int nul(void);

/******************** TABLAS ********************
 * En esta seccion se declaran las tablas	*
 * que se van a usar en el programa		*
 ************************************************/ 
 
/*************** TABLA DE ACCION ***************/  
ACTION_TAB action_table[]={
        /*etype     accion     bandera   sigEdo. */    
    { ENTRADA_0,  msg_aEdoA,  	-1,    EdoA},
    { ENTRADA_1,  msg_aEdoB,	-1,    EdoB},
    { asterisco,  nul,          -1,    Inicio},
    { ENTRADA_3,  msg_SalA,	-1,    Inicio},
    { asterisco,  nul,          -1,    EdoA},
    { ENTRADA_5,  msg_SalB,	-1,    Inicio},
    { asterisco,  nul,	        -1,    EdoB},
};

/*************** TABLA AUXILIAR ***************/  //No borrar aunque no se utilice.
    AUX_TAB aux_table[]={        
/*    accion       bandera           sigEdo */
    { nul,        0,          0},
};

/*************** TABLA DE ESTADOS ***************/  
STATE_TAB state_table[]={
   /*estado      inicio   fin */
    {Inicio,     0,      2},
    {EdoA,       3,      4},
    {EdoB,       5,      6},
};


    
        

        
    
        
    
        
    
        
    
        
    
        
    
        
    
        
    
        
    
        
    
        
    
    
        
