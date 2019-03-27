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
 extern int SumarDinero(void);
 extern int MsgProducto(void);
 extern int DineroSuficiente(void);
 extern int ProductoExiste(void);
 extern int NoAlcanza(void);
 extern int NoHayProducto(void);
 extern int DarProducto(void);
extern int nul(void);

/******************** TABLAS ********************
 * En esta seccion se declaran las tablas	*
 * que se van a usar en el programa		*
 ************************************************/

/*************** TABLA DE ACCION ***************/
ACTION_TAB action_table[]={
        /*etype     accion     bandera   sigEdo. */
    { ENTRADA_0,  SumarDinero,     -1,	DESPACHAR},
    { ENTRADA_1,  MsgProducto,	   -1,  CONSULTA},
    { ASTERISCO,  nul,	           -1,	CONSULTA},
    { ENTRADA_2,  SumarDinero,	   -1,	DESPACHAR},
    { ENTRADA_3,  DineroSuficiente,	0,  -1},


};

/*************** TABLA AUXILIAR ***************/  //No borrar aunque no se utilice.
    AUX_TAB aux_table[]={
/*    accion       bandera           sigEdo */
    { NoAlcanza,        -1,          DESPACHAR},
    { ProductoExiste,	   0,          -1},
    { NoHayProducto,	  -1,          DESPACHAR},
    { DarProducto,	    -1,          CONSULTA},
};

/*************** TABLA DE ESTADOS ***************/
STATE_TAB state_table[]={
   /*estado      inicio   fin */
    {CONSULTA,     0,      2},
    {DESPACHAR,    3,      4},
};
