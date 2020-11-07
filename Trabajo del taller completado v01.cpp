#include <stdio.h>
#include <stdlib.h>

//Matias Ignacio Rivera Correa, Mauricio ignacio soto montiel, Raquel Morales Aliaga, Ignacio Gustavo León Gutierrez, Ricardo Rodriguez Soto 

int i,j,k,clientes,filas,columnas,tip_operacion,reservas_activas;				//La idea de posicionar las variables primero que las funciones es que el
char asientos[32][7];															//algoritmo las lea primero que las funciones, para que así estas puedan usar 
float asientos_dinero[32][7],dinero_total,asientos_dinero_orig[32][7];			//dichas variables


void Matriz_dinero();
void Cargar_matriz();
void Menu();
void Reserva ();
void Cancelar ();
void Asientos_disponibles ();
void Ingresos_totales ();
void Mapa_asientos ();
void Revision_puesto ();

int main (){
	
	Cargar_matriz();//Llena la matriz "asientos" con la letra "D"
	Menu();//Abre el menu, asi se evita que la funcion "main" recargue toda la matriz con "D"
	return 0;
}

void Menu (){//Algoritmo que contiene el menu y las interacciones con las demas funciones 
	
	printf("\n");
	printf("     *******************************************************************\n");
	printf("     *                    Menu de operaciones                          *\n");
	printf("     *                                                                 *\n");
	printf("     *               Ingrese una operacion (de 1 a 6)                  *\n");
	printf("     *                                                                 *\n");
	printf("     *  Operacion 1: Reservar un asiento.                              *\n");
	printf("     *  Opreacion 2: Cancelar reserva (anular asiento).                *\n");
	printf("     *  Operacion 3: Muestra de los ingresos disponibles.              *\n");
	printf("     *  Operacion 4: Mostrar los ingresos totales (en pesos chilenos). *\n");
	printf("     *  Operacion 5: Muestra el total de reservas activas en un mapa.  *\n");
	printf("     *  Operacion 6: Salir del Sistema.                                *\n");
	printf("     *                                                                 *\n");
	printf("     *******************************************************************\n");
		
	printf("Ingrese el numero de la operación que desea realizar: ");
	scanf("%i",&tip_operacion);
	
	while(tip_operacion > 6 || tip_operacion < 1){
		printf("Ingrese un valor que este entre las opciones (entre 1 y 6) ");
		scanf("%i",&tip_operacion);
	}
	
	//Todas las operaciones que se pueden hacer en el menu
	if (tip_operacion == 1){
		
		Reserva();
	}
	if(tip_operacion == 2){
		
		Cancelar();
	}
	if (tip_operacion == 3){
		
		Asientos_disponibles ();
	}
	if (tip_operacion == 4){
		
		Ingresos_totales ();
	}
	if (tip_operacion == 5){
		
		Mapa_asientos ();
	}
	if (tip_operacion == 6){
		
		exit(1);		
	}
		
}

void Cancelar(){//Algoritmo que cancela una reserva, tambien revisa si esta reservada o no
	printf("\n");
	
	printf("Escoja la cantidad de clientes que desean cancelar su puesto: ");
	scanf("%i",&clientes);
	
	for(k=1;k<=clientes;k++){
		printf("¿Qué puesto desea cancelar? \n");
		printf("Por favor indique la fila y el asiento el cual desea cancelar\n");
		printf("Se encuentra en la fila: ");
		scanf("%i",&i);
		printf("Y se encuentra en el asiento: ");
		scanf("%i",&j);
		
		while(asientos[i][j]=='D'){//Este while asegura si el puesto esta desocupado
		
			printf("Ese asiento se encuentra desocupado, por favor elija otra fila y otro asiento. \n");
			printf("Escoja una fila\n");
			scanf("%i",&i);
			printf("Escoja un asiento\n");
			scanf("%i",&j);	
		}
		if(asientos[i][j]=='O'){
		
			printf("Ese asiento se encuentra ocupado. Ahora se procederá a cambiar el estado del asiento. \n");
			asientos[i][j]='D';			
		}
}
	printf("\n");
	printf("\n");
	Menu();
}

void Mapa_asientos (){//Esto muestra el estado actual de los asientos reservados y sus reservas activas
	printf("\n");
		
	printf("Los asientos disponibles se ven actualmente de la forma: \n");
	
	for(i=1;i<=32;i++){
        for(j=1;j<=7;j++){
            if (asientos[i][j]=='D'){
            	asientos[i][j]='-';
			}
        }
    }
    printf("\n");
	for(i=1;i<=32;i++){
        for(j=1;j<=7;j++){
        	printf(" [%c] ",asientos[i][j]);
		}
		printf("\n");
	}
	
	for(i=1;i<=32;i++){
		for(j=1;j<=7;j++){
			if(asientos[i][j]=='O'){
				reservas_activas++;
			}
		}
	}
		
	printf("\n");
	printf("Y hay un total de %i reservas activas",reservas_activas);
	printf("\n");
	
	printf("\n");
	printf("\n");
	Menu();
}

void Asientos_disponibles(){//Esto muestra los asientos disponibles en el avion
	printf("\n");
	printf("Los asientos que estan disponibles son: \n");
	
	
	
	for(i=1;i<=32;i++){
        for(j=1;j<=7;j++){ 
			if(asientos[i][j]=='O'){
				asientos[i][j]='-';
			}
        }
    }
    
	for(i=1;i<=32;i++){
        for(j=1;j<=7;j++){
        	printf(" [%c] ",asientos[i][j]);
        }
        printf("\n");
    }
    
	printf("\n");
	printf("\n");
	Menu();
}

void Ingresos_totales(){
	printf("\n");
	
	printf("Los asientos que estan disponibles son: \n");
	printf("\n");
    for(i=1;i<=filas;i++){					
        for(j=1;j<=columnas;j++){			
            asientos_dinero_orig[i][j]=128.25;	
        }
    }
	
		
	for(i=1;i<=32;i++){							//Todo esto muestra los asientos disponibles dentro del avion y su valor
        for(j=1;j<=7;j++){
            if (asientos[i][j]=='D'){
            	printf ("Hay un asiento disponible en la fila %i y asiento %i con un valor de %f\n", i, j,asientos_dinero_orig[i][j]);
			}
        }
    }	
	
    for(i=1;i<=32;i++){
        for(j=1;j<=7;j++){
            dinero_total=(asientos_dinero[i][j]*988.79)+dinero_total;
        }
    }	
	
	printf("\n");
	printf("\n");
	
	printf("El ingreso total es: %i pesos chilenos",dinero_total);
	printf("\n");
	printf("\n");
	
	Menu();
}

void Cargar_matriz(){//Esto carga toda la matriz (al principio) con "D", para asi llenarlo de con los puestos ocupados

    for(i=1;i<=32;i++){
        for(j=1;j<=7;j++){
            asientos[i][j]='D';
        }
    }

}

void Revision_puesto(){//Algoritmo para revisar si el puesto esta ocupado o no
	
	printf("Fila: ");
	scanf("%i",&filas);
	while(filas>32||filas<1){
		printf("Porfavor ingrese una fila existente (max 32) ");
		scanf("%i",&filas);
	}
	printf("Columna: ");
	scanf("%i",&columnas);
	while(columnas>7||columnas<1){
		printf("Porfavor ingrese una columna existente (max 7) ");
		scanf("%i",&columnas);
	}	
	
}

void Matriz_dinero(){//Algoritmo que llena la matriz "asientos_dinero" con el valor 128,25
	printf("\n");

    for(i=1;i<=filas;i++){					//Esto llena la matriz donde se marcará el puesto ocupado con "128,25"
        for(j=1;j<=columnas;j++){			//de esta manera cuando se marque un puesto como libre u ocupado
            asientos_dinero[i][j]=128.25;	//se pueda diferenciar uno con el otro
        }
    }	
	
}

void Reserva (){//Todo este algoritmo realiza la reserva del puesto
	printf("\n");
	printf("\n");
	printf("Por favor ingrese la cantidad de clientes que van a ingresar al avion: ");
	scanf("%i",&clientes);
	while (clientes > 32*7){
		printf("Por favor ingrese una cantidad que pueda ingresarse al avión (una cantidad menor a 224) ");
		scanf("%i",&clientes);
	}
	printf("Ingrese las coordenadas del asiento (max 31 filas, max 7 columnas)\n");
	for(k=1;k<=clientes;k++){
		
    		printf("Fila: ");
    		scanf("%i",&filas);
    		while(filas>32||filas<1){
    			printf("Porfavor ingrese una fila existente (max 32) ");
    			scanf("%i",&filas);
			}
    		printf("Columna: ");
    		scanf("%i",&columnas);
    		while(columnas>7||columnas<1){
    			printf("Porfavor ingrese una columna existente (max 7) ");
    			scanf("%i",&columnas);
			}
			
		while(asientos[filas][columnas]=='O'){		//Este "while" revisa si el puesto ya está ocupado
			printf("El puesto ya esta ocupado, por favor escoja otro\n");
			Revision_puesto();						//Este es el algoritmo encargado de la revision
		}	
		asientos[filas][columnas]='O';
		asientos_dinero[filas][columnas]=128.25+asientos_dinero[filas][columnas];	//De esta forma se acumula el dinero del puesto que se había
	}																				//reservado antes		

    
    
    printf("\n");
    printf("\n");
    Menu ();
}


