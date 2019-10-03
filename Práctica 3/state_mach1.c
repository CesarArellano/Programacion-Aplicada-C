/****************************************************************
*						       	       	*
* Archivo:	state_mach1.c                           	*
* Descripcion: Codigo Fuente para implementar el programa       *
*		de maquina de estados.                         	*
*                                        			*
****************************************************************/
//Coment

/*************** ARCHIVOS DE INCLUSION ***************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tables.h"
#include <time.h>


/*************** VARIABLES GLOBALES ***************/
EVENT event;
int state;
char buf[BUFFER];
char Parametro[10], NumCuenta[20],Bitacora[100];
// Parametro -> Copia argumento de terminal "-c" para verificar si es admin o no para CargarBase.
char Usuario[100], Password[100], NewPassword[100]; //NewPassword -> Utilizada para cambiar la PIN.
int Opcion=0,Login=0,Leido=0,Dinero;
// Opcion -> Switch Menú Admin. // Login -> Permite Entrar al usuario e identificar si es la primera ejecución.
// Leido-> Verifica si la carga de archivo se hizo, para no cargar más elementos en las lista dinámica.
long long int Saldo, Cuenta;
TipoLista *Inicio=NULL;
int Validacion1 = 0;
int Validacion2 = 0;
//Las demás variables globales son utilizadas a lo largo del programa.

/*************** PROTOTIPOS DE FUNCION ***************/
void initialise(void);
void getevent(void);

int Creditos (void);
int CargarBase (void);
int Login_Cajero (void);
int Registro (void);
int Imprimir (void);
int GuardarUsuarios (void);
int SolicitarInfo_BuscarCoincidencia_SesionIniciada (void);
int MsgIngresarDinero (void);
int MsgRetirarDinero (void);
int MostrarSaldo_MsgMenu (void);
int MostrarHistorial_MsgMenu (void);
int MsgCambiarPassword (void);
int MsgSalir_LimpiarLista (void);
int Msg_Espera (void);
int MsgMenu (void);
int SumarDinero_ActualizarHistorial_MsgMenu (void);
int PedirCantidad_SaldoSuficiente (void);
int PedirPassword (void);
int VolverAPedirPassword_Coinciden (void);
int SesionFallida (void);
int MsgSaldoInsuficiente_MsgMenu (void);
int MsgRetiroExitoso_RestarSaldo_ActualizarHistorial_MsgMenu (void);
int MsgErrorCambioPassword_MsgMenu (void);
int MsgPasswordCambiada_ActualizarPassword_MsgMenu (void);
int Borrar_Lista(void);
int ActualizarRegistro (void);
int ActualizarCuentaHabiente(void);
int menu();
void validacion(char Password[]);
int nul(void);


/*************** FUNCION PRINCIPAL ***************/
int main(int argc, char **argv){
  system("clear");
  if(argc!=1 && argc!=2){
    printf("Insertó parámetros de más, intente de nuevo.\n");
    exit(0);
  }else{
    if(argc==1){
      Creditos();
      system("clear");
      CargarBase();
      initialise();
      machine();
    }
    if(argc==2 && (strcmp(argv[1],"-c"))==0){
      strcpy(Parametro,argv[1]);
      CargarBase();
      do
      {
        menu();
        switch(Opcion){
          case 1:
            Registro();
            break;
          case 2:
            GuardarUsuarios();
            printf("Se han guardado los datos correctamente\n");
            printf("Saliendo del programa...\n");
            Borrar_Lista();
            exit(0);
            break;
          default:
            printf("Opción Inválida\n");
            break;
        }
        printf("Presione Enter para continuar...\n");
        __fpurge(stdin);
        getchar();
      }while(Opcion!=2);
    }else{
      printf("Opción inválida, intente de nuevo.\n");
      printf("Modo Admin: $./practica3.c -c.\n");
      exit(0);
    }
  }
}

void initialise(void){
  state = 0;
  Msg_Espera();
}

void getevent(void){
  char *ptmp;
  ptmp = &buf[2];

  #ifdef DEBUG
  printf("wait event \n");
  #endif
  __fpurge(stdin);
  gets(buf);
  switch (buf[0]){
    case 'I' :
    event.etype=ENTRADA_I;
    break;
    case 'i' :
    event.etype=ENTRADA_i;
    break;
    case 'R' :
    event.etype=ENTRADA_R;
    break;
    case 'C':
    event.etype=ENTRADA_C;
    break;
    case 'M':
    event.etype=ENTRADA_M;
    break;
    case 'P':
    event.etype=ENTRADA_P;
    break;
    case 'Q':
    event.etype=ENTRADA_Q;
    break;
    case '!':
    event.etype=ENTRADA_Admiracion;
    break;
    case 'd':
    event.etype=ENTRADA_d;
    break;
    case '#':
    event.etype=ENTRADA_Gato;
    break;
    case 'D':
    event.etype=ENTRADA_D;
    break;
    case '$':
    event.etype=ENTRADA_Dinero;
    break;
    case 'Z':
    event.etype=ENTRADA_Z;
    break;
    case 'p':
    event.etype=ENTRADA_p;
    break;
    default:
    event.etype=-1;
    break;

  }//switch
}// getevent


/* FUNCIONES DE IMPLEMENTACION */

int Creditos(void){
  system("clear");
  printf("Desarrollado por:\n\n");
  printf("\t• César Mauricio Arellano Velásquez\n");
  printf("\t• Raúl González Portillo\n");
  printf("\t• Allan Jair Escamilla Hernández\n\n");
  printf("Presione Enter para continuar...\n");
  __fpurge(stdin);
  getchar();
  system("clear");
  printf("Objetivo principal del programa:\n\n");
  printf("Con este programa practicamos la realización de máquinas de estado al simular un cajero automático funcional.\n\n");
  printf("Presione Enter para continuar...\n");
  __fpurge(stdin);
  getchar();
}

int CargarBase(void){
  FILE *Archivo;
  TipoLista *Nuevo,*temp;
  char User[100];
  Archivo = fopen("CuentaHabientes.txt","rt");
  if(Archivo==NULL && (strcmp(Parametro,"-c"))==0){
    printf("Se ha detectado que es la primera ejecución del programa\n");
    printf("Presione Enter para empezar la configuración inicial...\n");
    __fpurge(stdin);
    getchar();
    strcpy(NumCuenta,"1234567890");
    Login=1; //Indicamos que es la primera ejecución del programa
    Registro();
    printf("Presione Enter para continuar...\n");
    __fpurge(stdin);
    getchar();
  }else{
    if(Archivo==NULL){
      printf("Se ha detectado que es la primera ejecución del programa,\ndebido a que no existen los archivos necesarios para funcionar.\n");
      printf("Para continuar es necesario acceder al módulo de administrador.\n");
      printf("Saliendo del programa...\n");
      exit(0);
    }else{
      if(Leido==0){
        while(fscanf(Archivo," %[^\n]", User)==1){
          Nuevo = (TipoLista *)malloc(sizeof(TipoLista));
          strcpy(Nuevo -> NumCuenta, User);
          fscanf(Archivo, " %[^\n]", Nuevo -> Password);
          fscanf(Archivo, " %[^\n]", Nuevo -> Usuario);
          fscanf(Archivo, " %lld", &Nuevo -> Saldo);
          Nuevo -> sig = NULL;
          if (Inicio != NULL){
            temp = Inicio;
            while (temp -> sig != NULL)
            temp = temp -> sig;
            temp -> sig = Nuevo;
          }else
            Inicio = Nuevo;
          Cuenta = atoi(Nuevo->NumCuenta);
          Cuenta += 1;
          Leido=1;
        }
        fclose(Archivo);
      }
    }
  }
}

int Login_Cajero(void){
  TipoLista *temp;
  temp=Inicio;
  while(temp != NULL){
    if(strcmp(NumCuenta,temp->NumCuenta)==0 && strcmp(Password,temp->Password)==0){
      strcpy(Usuario,temp->Usuario);
      Saldo=temp->Saldo;
      Login=1;
      Cuenta-=1;
    }
    temp = temp-> sig;
  }
}

int Registro (void){
  system("clear");
  TipoLista *Nuevo, *temp;
  temp=Inicio;
  Nuevo = (TipoLista *)malloc(sizeof(TipoLista));
  printf("Ingrese nombre del cuentahabiente-> ");
  scanf(" %[^\n]",Nuevo->Usuario);
  printf("Ingrese PIN del cuentahabiente-> ");
  __fpurge(stdin);
  gets(Nuevo->Password);
  validacion(Nuevo->Password);
  if(Validacion1 == 1 || Validacion2 == 1){
    printf("El PIN debe incluir solo numeros y únicamente incluir 4 números.\n");
    Validacion1 = 0;
    Validacion2 = 0;
    return 0;
  }
  Nuevo->Saldo=0;
  if(Login==1){ //Si es la primera ejecución...
    strcpy(Nuevo->NumCuenta,NumCuenta); //Asignamos el numero que generamos
    Cuenta = atoi(Nuevo->NumCuenta); //Mandamos el mismo numero a la variable que lleva la contabilidad de los Nos. de cuenta
    Login=0;
  }else
    sprintf(Nuevo->NumCuenta, "%lld", Cuenta);
  printf("\nEl número de cuenta generado es: %s\n\n",Nuevo->NumCuenta);
  Cuenta+=1;
  Nuevo->sig=NULL;
  if (Inicio != NULL){ //Si la lista tiene algo, metemos a Nuevo al final
    temp = Inicio;
    while (temp -> sig != NULL)
      temp = temp -> sig;
    temp -> sig = Nuevo;
  }else//Si la lista esta vacía, el Nuevo elemento será nuestro primer elemento
    Inicio = Nuevo;
}

int GuardarUsuarios (void)
{
  TipoLista *temp;
  FILE *Archivo;
  temp=Inicio;
  Archivo = fopen("CuentaHabientes.txt","wt");
  while(temp!=NULL){
    fprintf(Archivo,"%s\n",temp->NumCuenta);
    fprintf(Archivo,"%s\n",temp->Password);
    fprintf(Archivo,"%s\n",temp->Usuario);
    fprintf(Archivo,"%lld\n",temp->Saldo);
    temp=temp->sig;
  }
  fclose(Archivo);
}

int SolicitarInfo_BuscarCoincidencia_SesionIniciada (void){
  system("clear");
  printf("Por favor ingrese sus datos para entrar a su cuenta:\n\n");
  printf("Número de cuenta-> ");
  scanf (" %[^\n]", NumCuenta);
  printf("PIN-> ");
  scanf (" %[^\n]", Password);
  printf("Verificando...\n");
  system("sleep 0.5");
  Login_Cajero();
  system("clear");
  if(Login==1){
    printf("Ha iniciado sesión con éxito\n");
    printf("Presione Enter para continuar...");
    __fpurge(stdin);
    getchar();
    return 1;
  }else
    return 0;
}

int MsgIngresarDinero (void){
  system("clear");
  printf("Accion: Ingresar Dinero\n\n");
  printf("\t1.-Ingresa Dinero con (d)\n");
  printf("\t2.-Cancelar acción con (!)\n\n");
  printf("Seleccionar opcion: ");
}

int MsgRetirarDinero (void){
  system("clear");
  printf("Accion: Retirar Dinero\n\n");
  printf("\t1.-Retirar Dinero con D\n");
  printf("\t2.-Cancelar acción con #\n\n");
  printf("Seleccionar opcion: ");
}

int MostrarSaldo_MsgMenu (void){
  system("clear");
  printf("Accion: Mostrar Saldo\n\n");
  printf("Su saldo actual es de: $%lld\n",Saldo);
  printf("Presione Enter para continuar...\n");
  __fpurge(stdin);
  getchar();
  MsgMenu();
}

int MostrarHistorial_MsgMenu (void){
  FILE *Archivo;
  char Temp[100];
  system("clear");
  strcpy(Temp,"Cliente_");
  strcat(Temp,NumCuenta);
  strcat(Temp,".txt");
  printf("Accion: Mostrar Movimientos.\n\n");
  printf("Historial de Movimientos:\n");
  Archivo = fopen(Temp,"rd");
  if(Archivo!=NULL){
    while(fgets(Temp,99,Archivo)!=NULL){
      Temp[strlen(Temp)-1]='\0';
      puts(Temp);
    }
    fclose(Archivo);
  }
  else
    printf("No hay movimientos en su cuenta.\n\n");
  printf("Presione Enter para continuar...\n");
  __fpurge(stdin);
  getchar();
  MsgMenu();
}

int MsgCambiarPassword (void){
  system("clear");
  printf("Accion: Cambiar PIN\n\n");
  printf("\t1.- Cambiar PIN con (Z)\n");
  printf("\t2.- Cancelar Acción con ($)\n");
  printf("Seleccionar opción: ");
}

int MsgSalir_LimpiarLista (void){
  printf("\nSaliendo del Menú...\n");
  system("sleep 1");
  GuardarUsuarios();
  Borrar_Lista();
  Leido=0;
  Login=0;
  Msg_Espera();
}

int Msg_Espera (void){
  system("clear");
  printf("Bienvenido a:\n\n");
  printf ("  ____                                          _ _        _ _     _         \n");
  printf (" | __ )  __ _ _ __   ___ ___     ___ __ _ _ __ (_) |_ __ _| (_)___| |_ __ _  \n");
  printf (" |  _ | / _` | '_ | / __/ _ |   / __/ _` | '_ || | __/ _` | | / __| __/ _` | \n");
  printf (" | |_) | (_| | | | | (_| (_) | | (_| (_| | |_) | | || (_| | | |__ | || (_| \n");
  printf (" |____/ |__,_|_| |_||___|___/_  |___|__,_| .__/|_||__|__,_|_|_|___/|__|__,_| \n");
  printf ("   __ _  ___ _ __   ___ _ __(_) ___ ___  |_|                                 \n");
  printf ("  / _` |/ _ | '_ | / _ | '__| |/ __/ _ |                                     \n");
  printf (" | (_| |  __/ | | |  __/ |  | | (_| (_) |                                    \n");
  printf ("  |__, ||___|_| |_||___|_|  |_||___|___/                                     \n");
  printf ("  |___/                                                                      \n\n\n");
  printf("Por favor ingrese I para continuar:\n");
}

int MsgMenu (void){
  system("clear");
  printf("Bienvenido %s al menú de acciones:\n\n", Usuario);
  printf("\t1.- Ingresar dinero, ingrese (i)\n");
  printf("\t2.- Retirar dinero, ingrese (R)\n");
  printf("\t3.- Mostrar Saldo, ingrese (C)\n");
  printf("\t4.- Mostrar historial, ingrese (M)\n");
  printf("\t5.- Cambiar PIN, ingrese (P)\n");
  printf("\t6.- Salir del menú, ingrese (Q)\n\n");
  printf("Seleccione una opcion-> ");
}

int SumarDinero_ActualizarHistorial_MsgMenu (void){
  TipoLista *temp;
  time_t rawtime;
  char SaldoActual[100];
  struct tm *timeinfo;
  time(&rawtime);
  timeinfo = localtime(&rawtime);
  system("clear");
  temp=Inicio;
  printf("Ingresa el monto a ingresar: ");
  scanf(" %d",&Dinero);
  while(temp!=NULL){
    if((strcmp(Usuario,temp->Usuario))==0){
      temp->Saldo+=Dinero;
      Saldo=temp->Saldo;
      strftime(Bitacora,200,"%d/%m/%Y - %H:%M:%S",timeinfo);
      strcat(Bitacora,", Mov: Ingresar Dinero, Monto Ingresado: ");
      sprintf(SaldoActual,"%d",Dinero);
      strcat(Bitacora,SaldoActual);
      strcat(Bitacora,", Saldo Actual: ");
      sprintf(SaldoActual,"%lld",temp->Saldo);
      strcat(Bitacora,SaldoActual);
    }
    temp=temp->sig;
  }
  ActualizarRegistro();
  MsgMenu();
}

int PedirCantidad_SaldoSuficiente (void){
  TipoLista *temp;
  time_t rawtime;
  char SaldoActual[100];
  struct tm *timeinfo;
  time(&rawtime);
  timeinfo = localtime(&rawtime);
  temp=Inicio;
  system("clear");
  printf("Ingresa el monto a retirar: ");
  scanf(" %d",&Dinero);
  while(temp!=NULL){
    if((strcmp(Usuario,temp->Usuario))==0){
      if(temp->Saldo >=Dinero){
        temp->Saldo-=Dinero;
        Saldo=temp->Saldo;
        strftime(Bitacora,200,"%d/%m/%Y - %H:%M:%S",timeinfo);
        strcat(Bitacora,", Mov: Retirar Dinero, Monto retirado: ");
        sprintf(SaldoActual,"%d",Dinero);
        strcat(Bitacora,SaldoActual);
        strcat(Bitacora,", Saldo Actual: ");
        sprintf(SaldoActual,"%lld",temp->Saldo);
        strcat(Bitacora,SaldoActual);
        return 3;
      }
      else
        return 2;
    }
    temp=temp->sig;
  }
}

int PedirPassword (void){
  system("clear");
  printf("Ingrese nuevo PIN (Recuerde ingresar 4 dígitos) -> ");
  scanf(" %[^\n]",NewPassword);
  system("clear");
  printf("Accion: Comprobando PIN\n\n");
  printf("Comprobar PIN con (p)\n");
  printf("Seleccionar opción: ");
}

int VolverAPedirPassword_Coinciden (void){
  system("clear");
  char Comprobar[100];
  printf("Ingrese de nuevo la PIN\n");
  scanf(" %[^\n]",Comprobar);
  validacion(Comprobar);
  if(Validacion1 == 1 || Validacion2 == 1){
    printf("El PIN debe incluir solo numeros y únicamente incluir 4 números.\n\n");
    Validacion1 = 0;
    Validacion2 = 0;
    printf("Presione Enter para continuar...\n");
    __fpurge(stdin);
    getchar();
    return 1;
  }
  if((strcmp(NewPassword,Comprobar))==0){
    return 5;
  }
  else
    return 4;
}

int SesionFallida (void){
  printf("Usuario y/o PIN son incorrectos\n");
  printf("Intente de nuevo\n");
  printf("Presione Enter para continuar...\n");
  __fpurge(stdin);
  getchar();
  Msg_Espera();
}

int MsgSaldoInsuficiente_MsgMenu (void){
  system("clear");
  printf("La operación falló, no hay saldo suficiente\n");
  printf("Intente de nuevo\n");
  printf("Presione Enter para continuar...\n");
  __fpurge(stdin);
  getchar();
  MsgMenu();
}

int MsgRetiroExitoso_RestarSaldo_ActualizarHistorial_MsgMenu (void){
  system("clear");
  printf("Retiro Éxitoso\n");
  printf("Presione Enter para continuar...\n");
  __fpurge(stdin);
  getchar();
  ActualizarRegistro();
  MsgMenu();
}

int MsgErrorCambioPassword_MsgMenu (void){
  system("clear");
  printf("Error, PINs no coinciden\n");
  printf("Intente nuevamente\n");
  printf("Presione Enter para continuar...\n");
  __fpurge(stdin);
  getchar();
  MsgMenu();
}

int MsgPasswordCambiada_ActualizarPassword_MsgMenu (void){
  system("clear");
  TipoLista *temp;
  temp = Inicio;
  while(temp!=NULL){
    if((strcmp(Usuario,temp->Usuario))==0)
    strcpy(temp->Password,NewPassword);
    temp=temp->sig;
  }
  GuardarUsuarios();
  printf("La PIN se modificó éxitosamente.\n");
  printf("Presione Enter para continuar...\n");
  __fpurge(stdin);
  getchar();
  MsgMenu();
}
int ActualizarRegistro (void){
  FILE *Archivo;
  char Temp[100];
  strcpy(Temp,"Cliente_");
  strcat(Temp,NumCuenta);
  strcat(Temp,".txt");
  Archivo = fopen(Temp,"at");
  fprintf(Archivo, "%s\n", Bitacora);
  fclose(Archivo);
}

int Borrar_Lista(void){
  TipoLista *temp;
  temp=Inicio;
  while(temp!=NULL){
    Inicio=Inicio->sig;
    free(temp);
    temp=Inicio;
  }
}

int nul(void){
  printf("Opcion Inválida\n");
}
int menu(){
  system("clear");
  printf("Bienvenido al modo administrador\n\n");
  printf("\t\tMenú:\n\n");
  printf("\t1.- Dar de alta cuentahabientes\n");
  printf("\t2.- Salir y Guardar Cambios\n\n");
  printf("Ingrese la opción que desea realizar-> ");
  scanf(" %d", &Opcion);
  system("clear");
}
int machine(){
  int actx, auxx, outcome;
  while (1) {    /* loop infinito para la MFE */
    CargarBase();
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
  }
}

void validacion(char Password[]){
  system("clear");
  if ((strlen (Password)) != 4) //Verificamos que el PIN introducido sea exactamente de 4 digitos
    Validacion1 = 1;
  for (int i = 0; i < 4; i ++){//Verificamos que el PIN solo contenga númeross
    if (Password [i] < '0' || Password [i] > '9'){
        Validacion2 = 1;
      }
    }
}
