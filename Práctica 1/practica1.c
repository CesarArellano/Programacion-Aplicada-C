#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct def_Imagen
{
  char Valor1,Valor2;
  int X, Y, Max;
}TipoImagen;

void Creditos(void);
void Leer_Imagen(TipoImagen *Encabezado,char Lectura_Arch[]);
void Guardar_en_Matriz(int *Dimensiones[],TipoImagen Encabezado, char Lectura_Arch[]);
void Negativo(int *Dimensiones[],TipoImagen Encabezado);
void Ecualizar(int *Dimensiones[],TipoImagen Encabezado);
void Reducir(int *Dimensiones[],int *Dimensiones2[],TipoImagen Encabezado);
void Ampliar(int *Dimensiones[],int *Dimensiones2[],TipoImagen Encabezado);
void Guardar_en_Archivo(int **Dimensiones,TipoImagen Encabezado);
void Liberar_Matriz(int *Dimensiones[],int *Dimensiones2[],TipoImagen Encabezado,int Opcion);

int main(void)
{
  int **Dimensiones,**Dimensiones2, i,j,Opcion,Verificar=0;
  char Lectura_Arch[200];
  TipoImagen Encabezado;
  Creditos();
  Leer_Imagen(&Encabezado,Lectura_Arch);
  Dimensiones = (int **) malloc(sizeof(int *)*Encabezado.Y);
  for (i=0;i<Encabezado.Y;i++)
    Dimensiones[i] = (int *) malloc (Encabezado.X * sizeof(int));
  Guardar_en_Matriz(Dimensiones,Encabezado,Lectura_Arch);
  do
    {
      system("clear");
      printf("PGM Optimizer Menu:\n");
      printf("1.- Negativo de la imagen\n");
      printf("2.- Ecualizar linealmente la imagen\n");
      printf("3.- Reducir la imagen\n");
      printf("4.- Ampliar la imagen\n");
      printf("Escoge una opción: \n");
      scanf("%d",&Opcion);
      switch(Opcion)
	{
	case 1:
	  Negativo(Dimensiones,Encabezado);
	  break;
	case 2:
	  Ecualizar(Dimensiones,Encabezado);
	  break;
	case 3:
	  Encabezado.Y/=2;
	  Encabezado.X/=2;
	  Dimensiones2 = (int **) malloc(sizeof(int *)*Encabezado.Y);
	  for (i=0;i<Encabezado.Y;i++)
	    Dimensiones2[i] = (int *) malloc (Encabezado.X *sizeof(int));
	  Reducir(Dimensiones,Dimensiones2,Encabezado);
	  break;
	case 4:
	  Encabezado.Y*=2;
	  Encabezado.X*=2;
	  Dimensiones2 = (int **) malloc(sizeof(int *)*Encabezado.Y);
	  for (i=0;i<Encabezado.Y;i++)
	    Dimensiones2[i] = (int *) malloc (Encabezado.X *sizeof(int));
	  Ampliar(Dimensiones,Dimensiones2,Encabezado);
	  break;
	default:
	  printf("Opción Incorrecta, intenta ingresar otra opción.\n");
	  printf("Presione Enter para continuar...\n");
	  __fpurge(stdin);
	  getchar();
	  Verificar=1;
	  break;
	}
    } while(Verificar==1);

  printf("Se realizó con éxito la operación.\n");
  printf("Presione Enter para guardar el archivo...\n");
  __fpurge(stdin);
  getchar();
  if(Opcion==1 || Opcion==2)
    Guardar_en_Archivo(Dimensiones,Encabezado);
  else
    Guardar_en_Archivo(Dimensiones2,Encabezado);
  Liberar_Matriz(Dimensiones,Dimensiones2,Encabezado,Opcion);
}

void Creditos(void)
{
  system("clear");
  system("sleep 0.07");
  printf(" ______     ________ __   ___       ______    ______    ___________  __   __   ___   __   ________   _______  _______\n");
  system("sleep 0.07");
  printf("|   _  `   /  _____||  ` /   |     /  __  `  |   _  `  |           ||  | |  ` /   | |  | |       /  |   ____||   _   `\n");
  system("sleep 0.07");
  printf("|  |_)  | |  |  __  |  `  /  |    |  |  |  | |  |_)  | `---|  |----`|  | |  `  /  | |  | `---/  /   |  |__   |  |_)  |\n");
  system("sleep 0.07");
  printf("|   ___/  |  | |_ | |  |`/|  |    |  |  |  | |   ___/      |  |     |  | |  |`/|  | |  |    /  /    |   __|  |      /\n");
  system("sleep 0.07");
  printf("|  |      |  |__| | |  |  |  |    |  `--'  | |  |          |  |     |  | |  |  |  | |  |   /  /----.|  |____ |  |`  `----.\n");
  system("sleep 0.07");
  printf("|__|       `______| |__|  |__|     `______/  |__|          |__|     |__| |__|  |__| |__|  /________||_______||__| `._____|\n\n\n");
  system("sleep 0.07");
  printf("Desarrollado por: César Mauricio Arellano Velásquez\n\n");
  system("sleep 0.08");
  printf("Presione Enter para continuar...\n");
  getchar();

  system("clear");
  system("sleep 0.07");
  printf("Objetivo del Programa: \n");
  system("sleep 0.07");
  printf("A través de este programa se busca que el usuario pueda editar de manera básica imágenes formato PGM.\n");
  system("sleep 0.07");
  printf("1.- Transformar imágenes PGM en su forma negativa.\n");
  system("sleep 0.07");
  printf("2.- Ecualizar de manera lineal la fotografía.\n");
  system("sleep 0.07");
  printf("3.- Reducir la imagen al doble.\n");
  printf("4.- Ampliar la imagen al doble.\n");
  system("sleep 0.07");
  printf("Presione Enter para continuar...\n");
  getchar();
  system("clear");
}

void Leer_Imagen(TipoImagen *Encabezado,char Lectura_Arch[])
{
  int Verificar=0;
  FILE *Archivo;
  printf("Ingrese el nombre del archivo de la imagen\n");
  scanf(" %[^\n]",Lectura_Arch);
  Archivo = fopen(Lectura_Arch,"rb");
  if(Archivo==NULL)
    {
      printf("El archivo introducido no existe, intente de nuevo...\n");
      exit(1);
    }
  else
    {
      fscanf(Archivo,"%c%c %d %d %d",&Encabezado->Valor1,&Encabezado->Valor2,&Encabezado->X,&Encabezado->Y,&Encabezado->Max);
      if(Encabezado->Valor1 =='P' && (Encabezado->Valor2=='2' || Encabezado->Valor2=='5'))
	Verificar=1;
      else
	Verificar=0;
      if(Verificar==0)
	{
	  printf("El archivo no está en formato PGM, intenta con otro archivo.\n");
	  printf("Saliendo del programa...\n");
	  exit(1);
	}
      fclose(Archivo);
    }
}

void Guardar_en_Matriz(int *Dimensiones[],TipoImagen Encabezado, char Lectura_Arch[])
{
  FILE *Archivo;
  int i,j;
  unsigned char temp;
  Archivo = fopen(Lectura_Arch,"rb");
  fseek(Archivo,15L,SEEK_SET);
  for (i = 0; i<Encabezado.Y; i++)
    {
      for (j = 0; j<Encabezado.X; j++)
	{
	  fread(&temp,sizeof(unsigned char),1,Archivo);
	  Dimensiones[i][j] = temp;
	}
    }
  fclose(Archivo);

}

void Negativo(int *Dimensiones[],TipoImagen Encabezado)
{
  for (int i = 0; i<Encabezado.Y; i++)
    {
      for (int j = 0; j<Encabezado.X; j++)
	{
	  Dimensiones[i][j]=(Dimensiones[i][j] * (-1))+255;
	}
    }
}

void Ecualizar(int *Dimensiones[],TipoImagen Encabezado)
{
  int i, Menor,Mayor,m,b;
  Menor = 255;
  Mayor = 0;
  for (int i = 0; i<Encabezado.Y; i++)
    {
      for (int j = 0; j<Encabezado.X; j++)
	{
	  if(Menor > Dimensiones[i][j])
	    Menor=Dimensiones[i][j];
	  if(Mayor < Dimensiones[i][j])
	    Mayor = Dimensiones[i][j];
	}
    }
  printf("Mayor: %d, Menor: %d\n",Mayor,Menor);
  m = 255 / (Mayor-Menor);
  b = ((-1)*(m * Menor));
  for (int i = 0; i<Encabezado.Y; i++)
    {
      for (int j = 0; j<Encabezado.X; j++)
	{
	  Dimensiones[i][j]=(Dimensiones[i][j] * m)+b;
	}
    }

}

void Reducir(int *Dimensiones[],int *Dimensiones2[],TipoImagen Encabezado)
{
  int x,y=0;
  Encabezado.Y*=2;
  Encabezado.X*=2;

  for (int i = 0; i<Encabezado.Y; i+=2)
    {
      x=0;
      for (int j = 0; j<Encabezado.X; j+=2)
	{
	  Dimensiones2[y][x]=Dimensiones[i][j];
	  x++;
	}
      y++;
    }
  }

  void Ampliar(int *Dimensiones[],int *Dimensiones2[],TipoImagen Encabezado)
  {
    int x=0,y=0;
    Encabezado.Y/=2;
    Encabezado.X/=2;
    for (int i = 0; i<Encabezado.Y; i++)
    {
      x=0;
      for (int j = 0; j<Encabezado.X; j++)
      {
        Dimensiones2[y][x]=Dimensiones[i][j];
        x+=2;
      }
      y+=2;
    }
    y=1;
    for (int i = 0; i<Encabezado.Y; i++)
    {
      x=1;
      for (int j = 0; j<Encabezado.X; j++)
      {
        Dimensiones2[y][x]=Dimensiones[i][j];
        x+=2;
      }
      y+=2;
    }
    y=1;
    for (int i = 0; i<Encabezado.Y; i++)
    {
      x=0;
      for (int j = 0; j<Encabezado.X; j++)
      {
        Dimensiones2[y][x]=Dimensiones[i][j];
        x+=2;
      }
      y+=2;
    }
    y=0;
    for (int i = 0; i<Encabezado.Y; i++)
    {
      x=1;
      for (int j = 0; j<Encabezado.X; j++)
      {
        Dimensiones2[y][x]=Dimensiones[i][j];
        x+=2;
      }
      y+=2;
    }
  }

void Guardar_en_Archivo(int **Dimensiones,TipoImagen Encabezado)
{
  FILE *Archivo;
  char NombreArchivo[200];
  system("clear");
  printf("Ingrese el nombre donde se guardará la imagen\n");
  scanf(" %[^\n]",NombreArchivo);
  Archivo = fopen(NombreArchivo,"wb");
  int i,j;
  fprintf(Archivo,"%c",Encabezado.Valor1);
  fprintf(Archivo,"%c",Encabezado.Valor2);
  fprintf(Archivo," %d",Encabezado.X);
  fprintf(Archivo," %d",Encabezado.Y);
  fprintf(Archivo," %d ",Encabezado.Max);
  for (i = 0; i<Encabezado.Y; i++)
    {
      for (j = 0; j<Encabezado.X; j++)
	{
	  fwrite(&(Dimensiones[i][j]),sizeof(unsigned char),1,Archivo);
	}
    }
  fclose(Archivo);
  printf("Se ha guardado con éxito el archivo, gracias por utilizar el programa\n");
}

void Liberar_Matriz(int *Dimensiones[],int *Dimensiones2[],TipoImagen Encabezado,int Opcion)
{
  int i,tempy;
  if(Opcion==1 || Opcion==2)
  {
    for(i=0; i<Encabezado.Y; i++)
    free(Dimensiones[i]);
    free(Dimensiones);
  }
  if(Opcion==3)
    {
      tempy=Encabezado.Y*2;
      for(i=0; i<tempy; i++)
      free(Dimensiones[i]);
      free(Dimensiones);
      for(i=0; i<Encabezado.Y; i++)
      free(Dimensiones2[i]);
      free(Dimensiones2);
    }
  if(Opcion==4)
      {
        tempy=Encabezado.Y/2;
        for(i=0; i<tempy; i++)
        free(Dimensiones[i]);
        free(Dimensiones);
        for(i=0; i<Encabezado.Y; i++)
        free(Dimensiones2[i]);
        free(Dimensiones2);
      }
}

