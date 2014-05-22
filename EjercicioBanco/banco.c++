#include <stdio.h>
#define limpia_pantalla(X) for(i = 0; i < 40; i++) printf("\n");
#define NUM_CUENTAS 10

//clase Cuenta
class Cuenta
{
	public: 

	int numCuenta;
	float saldo;
	char titular[20];

	Cuenta(){}
	
	Cuenta(int num, float cantidad, char *tit) 
	{
		numCuenta = num;
		saldo = cantidad;
		sprintf(titular,tit);
	}

	void ingresar(float cantidad)
	{
		saldo += cantidad;
	}

	bool extraer(float cantidad)
	{
		if(saldo >= cantidad)
		{	
			saldo -= cantidad;
			return true;
		}
		return false;
	}

	float verSaldo()
	{
		return saldo;
	}

	void inicializar(int num, float cantidad, char *tit)
	{
		numCuenta = num;
		saldo = cantidad;
		sprintf(titular,tit);
	}
};

Cuenta *punteroCuentaSel; //creamos un puntero de tipo cuenta

Cuenta * vectorCuenta[NUM_CUENTAS];//vectorCuenta es un puntero que apunta a la primera posición del puntero

void muestraMenu()
{
	int i;
	limpia_pantalla();
	for(i = 0; i < 40; i++) printf("_ ");

	printf("\n");
	printf("\n");
	printf("1- Elegir cuenta \n");
	printf("2- Ingresar \n");
	printf("3- Retirar \n");
	printf("4- Ver saldo \n");
	printf("5- Ver todas las cuentas \n");
	printf("6- Crear una cuenta \n");
	printf("7- Borrar cuenta seleccionada \n");
	printf("q- Salir del programa\n");
	for(i = 0; i++ < 10; printf("\n"));
}

void crearCuenta()
{
	int i;
	int num;
	float dinero;
	char nombre[20];

	printf("Número de cuenta: ");
		scanf("%i",&num);
	printf("Titular: ");
		scanf("%s",&nombre);
	printf("Saldo: ");
		scanf("%f",&dinero);

	for(i=0;i<NUM_CUENTAS;i++)
	{
		if(vectorCuenta[i] == NULL)
		{
			vectorCuenta[i] = new Cuenta(num,dinero,nombre);
			break;
		}
	}	
}

void inicializarVector()
{	
	int i;
	for(i=0;i<NUM_CUENTAS;i++) 
	{
		vectorCuenta[i] = NULL;
	}
}

void llenarVector()
{
	vectorCuenta[0] = new Cuenta(10,1000,"Juan");
	vectorCuenta[1] = new Cuenta(20,2000,"Pepe");
	vectorCuenta[2] = new Cuenta(30,3000,"Miguel");
	vectorCuenta[3] = new Cuenta(40,4000,"Ramon");
}

void borrarSeleccionada(Cuenta * punt)
{
	int i,j;
	for(i = 0;i < NUM_CUENTAS; i++)
	{
		if(vectorCuenta[i]->numCuenta == punt->numCuenta)
		{
			delete vectorCuenta[i];
			
			for(j=i; j < NUM_CUENTAS - 1; j++)
			{
				vectorCuenta[j] = vectorCuenta[j + 1];
			}

			if(j == NUM_CUENTAS - 1)
			{
				vectorCuenta[NUM_CUENTAS - 1] = NULL;
			}
			break;		
		}
	}
}

void mostrarVector()//para ver todas las cuentas que tenemos creadas
{
	int i;
	for(i = 0;i < NUM_CUENTAS; i++)
	{
		if(vectorCuenta[i] != NULL)
		{
			printf("Titular: %s \n",vectorCuenta[i]->titular);
			printf("Número de cuenta: %i \n",vectorCuenta[i]->numCuenta);
			printf("Saldo: %f \n",vectorCuenta[i]->saldo);
			printf("----------------------------------------- \n");	
		}
		else
		{
			break;
		}	
	}
}

void limpiar()
{
	int i;
	for(i=0;i<10;i++) printf("\n");
}

Cuenta * encontrarCuenta(int numeroCuenta)
{	
	int i;
	for(i = 0;i < NUM_CUENTAS; i++)
	{
		if(vectorCuenta[i]->numCuenta == numeroCuenta)
		{
			return vectorCuenta[i];
		}
	}
	return NULL;
}

void mostrarCuentas()
{
	int i;

	for(i = 0; i < NUM_CUENTAS; i++)
	{
		if(vectorCuenta[i] != NULL)
		{
			printf("Números de cuentas disponibles: %i \n", vectorCuenta[i]->numCuenta);
			printf("Nombre del titular de la cuenta: %s \n",vectorCuenta[i]->titular);
			printf("---------------------------------------------------- \n");
		}
		else
		{
			break;
		}	
	}
}


//MAIN
int main(int argc, char *argv[])
{
	char c;
	int cuentaSeleccionada = 0;
	int *puntero;

	inicializarVector();
	llenarVector();
	punteroCuentaSel = NULL;

	while (c!='q')
	{
		muestraMenu();
		printf("Elige un opción: ");
		c=getchar();
		getchar();

		switch(c)
		{
			case '1': 
				printf("Has seleccionado la opción de Seleccionar cuenta \n");
				limpiar();
				mostrarCuentas();
				
				while(punteroCuentaSel == NULL) 
				{
					printf("¿Qué cuenta desea? ");
					scanf("%i",&cuentaSeleccionada);

					punteroCuentaSel = encontrarCuenta(cuentaSeleccionada);

					if(punteroCuentaSel == NULL)
					{
						printf("No se ha encontrado la cuenta \n");
					}
				}
			break;

			case '2': 
				float cantidadIngresar;
				
				if(punteroCuentaSel == NULL)
				{
					printf("Debes seleccionar una cuenta \n");
					break;
				}

				printf("Has seleccionado la opción de Ingresar cuenta y estas ingresando saldo en la cuenta %i \n" ,punteroCuentaSel->numCuenta);
				printf("¿Qué cantidad quiere ingresar? ");
				scanf("%f",&cantidadIngresar);
				punteroCuentaSel->ingresar(cantidadIngresar);
			break;

			case '3':
				float cantidadExtraer;
				printf("Has seleccionado la opción de Extraer de la cuenta %i \n" ,punteroCuentaSel->numCuenta);
				printf("¿Qué cantidad quiere extraer? ");
				scanf("%f",&cantidadExtraer);

				if(!punteroCuentaSel->extraer(cantidadExtraer))
				{
					printf("Saldo en la cuenta insuficiente \n");	
					getchar();			
				}
			break;
			
			case '4': 
				printf("Has seleccionado la opción de Ver saldo cuenta %i \n" ,punteroCuentaSel->numCuenta);
				limpiar();
				printf("El titular de la cuenta %s cuyo numero de cuenta es %i tiene %f de saldo\n"
				,punteroCuentaSel->titular
				,punteroCuentaSel->numCuenta
				,punteroCuentaSel->verSaldo());
			break;

			case '5':
				limpiar();
				mostrarVector();
			break;

			case '6':
				printf("Has elegido la opción de crear una cuenta \n");
				limpiar();
				crearCuenta();
			break;

			case '7':
				printf("Has elegido borrar la cuenta seleccionada \n");
				limpiar();
				borrarSeleccionada(punteroCuentaSel);
			break;

			case 'q':
				printf("Gracias por utilizar el programa de gestión de cuentas bancarias"); 
			break;
			default	: printf("Opción incorrecta \n");
		}	
		printf("Pulse cualquier tecla para seguir con el programa");
		getchar();
	}
}

