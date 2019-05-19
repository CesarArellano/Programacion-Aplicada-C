/****************************************************************
*							                                                 	*
* Archivo:	local.h				                                  		*
* Descripcion: Archivo de encabezado para maquina de estados   	*
*		Aqui se definen todos los tipos de datos y 	                *
*		constantes que se utilizan en el programa	                  *
*					                                                			*
****************************************************************/

/******************* CONSTANTES *******************
* En esta seccion se declaran todas las 	        *
* las constantes que se necesiten en el programa  *
**************************************************/
#define BUFFER        128
#define L_EVENT_ARGS  21


/****************** ESTRUCTURAS *****************
* En esta seccion se declaran todas las	        *
* estructuras que se necesiten en el programa	  *
************************************************/

// Este tipo de datos se utiliza para leer la informacion
// que teclea el usuario
struct event_s
{
  int etype;
  char args[L_EVENT_ARGS];
};
typedef struct event_s EVENT;

// Este tipo de datos se utiliza para implementar
// la tabla auxiliar
struct aux_table_s
{
  int (*action)();
  int moreacts;
  int nextstate;
};
typedef struct aux_table_s AUX_TAB;

// Este tipo de datos se utiliza para implementar
// la tabla de accion
struct action_tab_s
{
  int event;
  int (*action)();
  int moreacts;
  int nextstate;
};
typedef struct action_tab_s ACTION_TAB;

// Este tipo de datos se utiliza para implementar
// la tabla de estados
struct state_tab_s
{
  int state;
  int start;
  int end;
};
typedef struct state_tab_s STATE_TAB;

typedef struct def_Lista
{
  char Usuario[100], Password[100], NumCuenta[20];
  long long int Saldo;
  struct def_Lista *sig;
}TipoLista;

/********************* GLOBALES ***********************
* En esta seccion se pueden declarar todas	          *
* variables globales que se necesiten en el programa  *
******************************************************/
FILE *fp;


/********************* EVENTOS *******************
* En esta seccion se declarar como constantes	   *
* los eventos (entradas) que recibe el programa  *
*************************************************/
#define ENTRADA_I           0
#define ENTRADA_i           2
#define ENTRADA_R           3
#define ENTRADA_C           4
#define ENTRADA_M           5
#define ENTRADA_P           6
#define ENTRADA_Q           7
#define ENTRADA_Admiracion  9
#define ENTRADA_d           10
#define ENTRADA_Gato        12
#define ENTRADA_D           13
#define ENTRADA_Dinero      15
#define ENTRADA_Z           16
#define ENTRADA_p           18
#define Asterisco           -1

//Coment

/********************* ESTADOS ******************
* En esta seccion se declarar como constantes	  *
* los estados de que consta el programa 	      *
************************************************/
#define Espera              0
#define Atendiendo          1
#define IngresandoDinero    2
#define RetirandoDinero     3
#define CambiandoPassword   4
#define ComprobandoPassword 5
