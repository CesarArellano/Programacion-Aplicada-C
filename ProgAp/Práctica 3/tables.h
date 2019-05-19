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
extern int SolicitarInfo_BuscarCoincidencia_SesionIniciada (void);
extern int MsgIngresarDinero (void);
extern int MsgRetirarDinero (void);
extern int MostrarSaldo_MsgMenu (void);
extern int MostrarHistorial_MsgMenu (void);
extern int MsgCambiarPassword (void);
extern int MsgSalir_LimpiarLista (void);
extern int MsgMenu (void);
extern int SumarDinero_ActualizarHistorial_MsgMenu (void);
extern int PedirCantidad_SaldoSuficiente (void);
extern int PedirPassword (void);
extern int VolverAPedirPassword_Coinciden (void);
extern int SesionFallida (void);
extern int MsgSaldoInsuficiente_MsgMenu (void);
extern int MsgRetiroExitoso_RestarSaldo_ActualizarHistorial_MsgMenu (void);
extern int MsgErrorCambioPassword_MsgMenu (void);
extern int MsgPasswordCambiada_ActualizarPassword_MsgMenu (void);
extern int nul(void);

/******************** TABLAS ********************
* En esta seccion se declaran las tablas	*
* que se van a usar en el programa		*
************************************************/

/*************** TABLA DE ACCION ***************/
ACTION_TAB action_table[]={
  /*      etype                            accion                      MasAcciones       sigEdo. */
  { ENTRADA_I,          SolicitarInfo_BuscarCoincidencia_SesionIniciada,  0,	                 -1},
  { Asterisco,          nul,	                                           -1,               Espera},
  { ENTRADA_i,          MsgIngresarDinero,	                             -1,     IngresandoDinero},
  { ENTRADA_R,          MsgRetirarDinero,	                               -1,      RetirandoDinero},
  { ENTRADA_C,          MostrarSaldo_MsgMenu,	                           -1,           Atendiendo},
  { ENTRADA_M,          MostrarHistorial_MsgMenu,	                       -1,           Atendiendo},
  { ENTRADA_P,          MsgCambiarPassword,	                             -1,    CambiandoPassword},
  { ENTRADA_Q,          MsgSalir_LimpiarLista,	                         -1,               Espera},
  { Asterisco,          nul,	                                           -1,           Atendiendo},
  { ENTRADA_Admiracion, MsgMenu,	                                       -1,           Atendiendo},
  { ENTRADA_d,          SumarDinero_ActualizarHistorial_MsgMenu,         -1,           Atendiendo},
  { Asterisco,          nul,	                                           -1,     IngresandoDinero},
  { ENTRADA_Gato,       MsgMenu,	                                       -1,           Atendiendo},
  { ENTRADA_D,          PedirCantidad_SaldoSuficiente,	                  0,                   -1},
  { Asterisco,          nul,	                                           -1,      RetirandoDinero},
  { ENTRADA_Dinero,     MsgMenu,	                                       -1,           Atendiendo},
  { ENTRADA_Z,          PedirPassword,	                                 -1,  ComprobandoPassword},
  { Asterisco,          nul,	                                           -1,    CambiandoPassword},
  { ENTRADA_p,          VolverAPedirPassword_Coinciden,	                  0,                   -1},
  { Asterisco,          nul,	                                           -1,  ComprobandoPassword},


};

/*************** TABLA AUXILIAR ***************/  //No borrar aunque no se utilice.
AUX_TAB aux_table[]={
  /*                      accion                           bandera     sigEdo */
  { SesionFallida,                                           -1,          Espera},
  { MsgMenu,	                                               -1,      Atendiendo},
  { MsgSaldoInsuficiente_MsgMenu,                            -1,      Atendiendo},
  { MsgRetiroExitoso_RestarSaldo_ActualizarHistorial_MsgMenu,-1,      Atendiendo},
  { MsgErrorCambioPassword_MsgMenu,                          -1,      Atendiendo},
  { MsgPasswordCambiada_ActualizarPassword_MsgMenu,          -1,      Atendiendo},
};
//Coment

/*************** TABLA DE ESTADOS ***************/
STATE_TAB state_table[]={
  /*estado          inicio   fin */
  {Espera,               0,      1},
  {Atendiendo,           2,      8},
  {IngresandoDinero,     9,     11},
  {RetirandoDinero,      12,    14},
  {CambiandoPassword,    15,    17},
  {ComprobandoPassword,  18,    19},
};
