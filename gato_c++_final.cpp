#include <iostream>
#include <stdlib.h>
#include <time.h>


using namespace std;

void mostrar_logo(){
    cout<<"####################################"<<endl;
	cout<<"##             GATO#              ##"<<endl;
	cout<<"##________________________________##"<<endl;

}

void logo_P1vsP2(){
    cout<< "####################################"<<endl;
	cout<< "##        JUEGO P1 VS P2          ##"<<endl;
	cout<< "##________________________________##"<<endl;
}

void logo_P1vsPc(){
    cout<< "####################################"<<endl;
	cout<< "##        JUEGO P1 VS PC          ##"<<endl;
	cout<< "##________________________________##"<<endl;
}



int menu_principal(){
    mostrar_logo();
    int tipo_juego=0;
	cout<< "####################################"<<endl;
	cout<<  "##         Menu princial          ##"<<endl;
	cout<<  "##________________________________##"<<endl;
	cout<<  "##  Seleccione un modo            ##"<<endl;
	cout<<  "##    1- Player1 vs Player2       ##"<<endl;
	cout<<  "##    2- Player1 vs PC            ##"<<endl;
	cout<<  "##________________________________##"<<endl;
	cout<<  "ingrese...."	<<endl;
	cin>> tipo_juego;
	return tipo_juego;
}


void secuencia_jugadas(int var_comienza){
    string jugadas_par;
    string jugadas_impar;
    string jugador_actual;
    char simbolo_actual;
    bool cuadrante_logico;
    char cuadrante_num;
    bool ganar=false;
    int i=0, j=0,turno=0;

    //definir matriz
    char matriz[3][9];
    for(i=0;i<3;i++){
        for(j=0;j<=9;j++){
            matriz[i][j]=']';
            if((i==0 || i==1 || i==2) && (j==0 || j==3 || j==6) ){
                matriz[i][j]='[';
            }
        }
    }
    matriz[0][1]='1';
    matriz[0][4]='2';
    matriz[0][7]='3';
    matriz[1][1]='4';
    matriz[1][4]='5';
    matriz[1][7]='6';
    matriz[2][1]='7';
    matriz[2][4]='8';
    matriz[2][7]='9';

  if(var_comienza==0){
    jugadas_par="player2";
    jugadas_impar="player1";
  }
  if(var_comienza==1){
    jugadas_par="player1";
    jugadas_impar="player2";
  }
  turno=1;
  while( turno<=9 && ganar==false){
    cout<<"turno numero: "<<turno<<endl;

    if(turno % 2 !=0){
        cout<<jugadas_impar<<" es su turno"<<endl;
        simbolo_actual='x';
        jugador_actual=string(jugadas_impar);
    }
    if(turno % 2 ==0){
        cout<<jugadas_par<<" es su turno"<<endl;
        simbolo_actual='o';
        jugador_actual=string(jugadas_par);
    }
    //cout<<jugador_actual<<endl;
    turno=turno+1;

   //mostrar
    for(i=0;i<3;i++){
        for(j=0;j<9;j++){
            cout<<matriz[i][j];
        }
        cout<<endl;
    }

    //ingresasr el cuadrante donde se insertara
    cuadrante_logico=false;
    while(cuadrante_logico==false){
        cout<<"SELECCIONE UN CUADRANTE"<<endl;
        cin >>cuadrante_num;

        for(i=0;i<3;i++){
            for(j=0;j<9;j++){
                if(matriz[i][j]==cuadrante_num){
                    matriz[i][j]= simbolo_actual;
                    cout<<"se agrego simbolo"<<endl;
                    cuadrante_logico=true;
                }
            }
            cout<<endl;
        }
    }
    //revisar si alguien ha ganado
    //caso 1
    if(matriz[0][1]==simbolo_actual && matriz[0][4]==simbolo_actual && matriz[0][7]==simbolo_actual){
        ganar=true;
    }
    //caso 2
    if(matriz[1][1]==simbolo_actual && matriz[1][4]==simbolo_actual && matriz[1][7]==simbolo_actual){
        ganar=true;
    }
    //caso 3
    if(matriz[2][1]==simbolo_actual && matriz[2][4]==simbolo_actual && matriz[2][7]==simbolo_actual){
        ganar=true;
    }
    //caso 4
    if(matriz[0][1]==simbolo_actual && matriz[1][1]==simbolo_actual && matriz[2][1]==simbolo_actual){
        ganar=true;
    }
    //caso 5
    if(matriz[0][4]==simbolo_actual && matriz[1][4]==simbolo_actual && matriz[2][4]==simbolo_actual){
        ganar=true;
    }
     //caso 6
    if(matriz[0][7]==simbolo_actual && matriz[1][7]==simbolo_actual && matriz[2][7]==simbolo_actual){
        ganar=true;
    }
     //caso 7
    if(matriz[0][1]==simbolo_actual && matriz[1][4]==simbolo_actual && matriz[2][7]==simbolo_actual){
        ganar=true;
    }
     //caso 8
    if(matriz[0][7]==simbolo_actual && matriz[1][4]==simbolo_actual && matriz[2][1]==simbolo_actual){
        ganar=true;
    }
    system("cls");
  }
  if(ganar==true){
        cout<<"#############################"<<endl;
        cout<<"#        Game Over          #"<<endl;
        cout<<"#      hay un ganador       #"<<endl;
        cout<<"#############################"<<endl;
        //mostrar
    for(i=0;i<3;i++){
        for(j=0;j<9;j++){
            cout<<matriz[i][j];
        }
        cout<<endl;
    }
  }
  cout <<"FELICIDADES "<<jugador_actual<<endl;
  if(ganar==false){
        cout<<"#############################"<<endl;
        cout<<"#        Game Over          #"<<endl;
        cout<<"#          EMPATE           #"<<endl;
        cout<<"#############################"<<endl;
  }
}


//modo juego P1 VS P2
void contra_jugador(){
    char aux[2] ;
	int num=0;
	int var_quien_comienza=0;

	system("cls");
	mostrar_logo();
	logo_P1vsP2();

	cout<< "Elija un player cada jugador"<<endl;
	cout<< "ingrese cualquier tecla para continuar..."<<endl;
	cin>> aux;

    //azar
	srand(time(NULL));
	num = rand()%2;

	if(num==0){
        cout<<"comienza el Player1"<<endl;
        var_quien_comienza=0;
	}
	if(num==1){
        cout<<"comienza el Player2"<<endl;
        var_quien_comienza=1;
	}
	cout<<"presione una tecla para continuar";
	cin >>aux;
	system("cls");
	secuencia_jugadas(var_quien_comienza);
}


int elegir_cuadrante_pc( ){
    int cuadrante=0;
    srand(time(NULL));
	cuadrante = (rand()%9) +1;
	return cuadrante;
}


void secuencia_jugadas2(int var_comienza){
    string jugadas_par;
    string jugadas_impar;
    string jugador_actual;
    char simbolo_actual;
    bool cuadrante_logico;
    char cuadrante_num;
    bool ganar=false;
    int i=0, j=0,turno=0;
    int indice =0;
    string aux;

    //definir matriz
    char matriz[3][9];
    for(i=0;i<3;i++){
        for(j=0;j<=9;j++){
            matriz[i][j]=']';
            if((i==0 || i==1 || i==2) && (j==0 || j==3 || j==6) ){
                matriz[i][j]='[';
            }
        }
    }     
    
    matriz[0][1]='1';
    matriz[0][4]='2';
    matriz[0][7]='3';
    matriz[1][1]='4';
    matriz[1][4]='5';
    matriz[1][7]='6';
    matriz[2][1]='7';
    matriz[2][4]='8';
    matriz[2][7]='9';
    
    
       //declarar un vector
       char vector[9];
       vector[0]='1';
       vector[1]='2';
       vector[2]='3';
       vector[3]='4';
       vector[4]='5';
       vector[5]='6';
       vector[6]='7';
       vector[7]='8';
       vector[8]='9';
       

  if(var_comienza==0){
    jugadas_par="computadora";
    jugadas_impar="player1";
  }
  if(var_comienza==1){
    jugadas_par="player1";
    jugadas_impar="computadora";
  }
  turno=1;
  while( turno<=9 && ganar==false){
    cout<<"turno numero: "<<turno<<endl;

    if(turno % 2 !=0){
        cout<<jugadas_impar<<" es su turno"<<endl;
        simbolo_actual='x';
        jugador_actual=string(jugadas_impar);
    }
    if(turno % 2 ==0){
        cout<<jugadas_par<<" es su turno"<<endl;
        simbolo_actual='o';
        jugador_actual=string(jugadas_par);
    }
    //cout<<jugador_actual<<endl;
    cuadrante_logico=false;
    while(cuadrante_logico==false){
    	cout<<"SELECCIONE UN CUADRANTE: "<<endl;    	    	
    	if(jugador_actual=="computadora"){
    		cout<<"me va a ingresar un cuadrante la compu"<<endl;
    		indice = rand()%9;
    		cuadrante_num = vector[indice];
    		cout<<"computadora selecciono cuadrante: "<<cuadrante_num<<endl;
    		
		}
		if(jugador_actual=="player1"){
			cout<<"me va a ingresar un cuadrante el jugador 1"<<endl;
			cin>>cuadrante_num;
		}
		//verifico que este disponible el cuadrante
		for(i=0;i<3;i++){
            for(j=0;j<9;j++){
                //cout<<"comparando "<<matriz[i][j]<<" con "<<cuadrante_num<<endl;
                if(matriz[i][j]== cuadrante_num){
                    matriz[i][j]= simbolo_actual;
                    cout<<"se agrego simbolo"<<endl;
                    cuadrante_logico=true;
                    
                }
            }

	}
    
    turno=turno+1;
	
   //mostrar
    for(i=0;i<3;i++){
        for(j=0;j<9;j++){
            cout<<matriz[i][j];
        }
        cout<<endl;
    }
    if(jugador_actual=="computadora"){
    	cout<<"ingrese cualquier tecla para continuar..."<<endl;
    	cin>>aux;
	}

    //ingresasr el cuadrante donde se insertara
    
   
  }
  if(ganar==true){
        cout<<"#############################"<<endl;
        cout<<"#        Game Over          #"<<endl;
        cout<<"#      hay un ganador       #"<<endl;
        cout<<"#############################"<<endl;
        //mostrar
    for(i=0;i<3;i++){
        for(j=0;j<9;j++){
            cout<<matriz[i][j];
        }
        cout<<endl;
    }
  }
  cout <<"FELICIDADES "<<jugador_actual<<endl;
  if(ganar==false){
        cout<<"#############################"<<endl;
        cout<<"#        Game Over          #"<<endl;
        cout<<"#          EMPATE           #"<<endl;
        cout<<"#############################"<<endl;
  }
  system("cls");
	}
}


void secuencia_jugadas3(int var_comienza){
	 //definir variables
	string jugadas_par;
    string jugadas_impar;
    string jugador_actual;
    char simbolo_actual;
    bool cuadrante_logico;
    char cuadrante_num;
    bool ganar=false;
    int i=0, j=0,turno=1;
    int indice =0;
    string aux;
	 
	 
	 //crear matriz base
	char matriz[3][9];
    for(i=0;i<3;i++){
        for(j=0;j<=9;j++){
            matriz[i][j]=']';
            if((i==0 || i==1 || i==2) && (j==0 || j==3 || j==6) ){
                matriz[i][j]='[';
            }
        }
    }  
    matriz[0][1]='1';
    matriz[0][4]='2';
    matriz[0][7]='3';
    matriz[1][1]='4';
    matriz[1][4]='5';
    matriz[1][7]='6';
    matriz[2][1]='7';
    matriz[2][4]='8';
    matriz[2][7]='9';
        
    //crear arreglo declarar un vector
    char vector[9];
    vector[0]='1';
    vector[1]='2';
    vector[2]='3';
    vector[3]='4';
    vector[4]='5';
    vector[5]='6';
    vector[6]='7';
    vector[7]='8';
    vector[8]='9';
	
	//asignar el orden de inicio
	 if(var_comienza==0){
    	jugadas_par="computadora";
    	jugadas_impar="player1";
  	}
  	if(var_comienza==1){
    	jugadas_par="player1";
    	jugadas_impar="computadora";
  	}

	//el ciclo while de los 9 turnos
	while(turno<=9 && ganar==false){
		cout<<"turno numero: "<<turno<<endl;
		//en un turno impar
		if(turno % 2 != 0 ){
			cout<<jugadas_impar <<" es su turno"<<endl;
			jugador_actual = jugadas_impar;
			simbolo_actual = 'x';
		}
			//un turno par
		if(turno % 2 == 0){
			cout<<jugadas_par <<" es su turno"<<endl;
			jugador_actual = jugadas_par;
			simbolo_actual = 'o';
		}
		
		//mostrar matriz	
    	for(i=0;i<3;i++){
        	for(j=0;j<9;j++){
            	cout<<matriz[i][j];
        	}
        	cout<<endl;
    	}
    	//ingresar el cuadrante donde se inserta simbolo 
    	cuadrante_logico=false;
    	while(cuadrante_logico==false){
    		cout<<"SELECCIONE UN CUADRANTE"<<endl;
    		if(jugador_actual=="computadora"){
    			indice = rand()%9;
    			cuadrante_num = vector[indice];
			}
			if(jugador_actual=="player1"){
    			cin>>cuadrante_num;
			}
			//verificar que ingreso un cuadrante disponible 
			for(i=0;i<3;i++){
        		for(j=0;j<9;j++){
            		if(matriz[i][j]==cuadrante_num){
            			matriz[i][j]=simbolo_actual;
            			cout<<"se agrego simbolo"<<endl;
            			cuadrante_logico=true;
					}
        		}        	
    		}			
		} 
		//para que me muestre lo que hace la compu , una pausa
		 if(jugador_actual=="computadora"){
		 	cout<<"computadora seleccion el cuadrante: "<<cuadrante_num<<endl;
    		cout<<"ingrese cualquier tecla para continuar..."<<endl;
    		cin>>aux;
		}


		//revisar si al agregar el simbolo hay algun ganador		 
    //caso 1
    if(matriz[0][1]==simbolo_actual && matriz[0][4]==simbolo_actual && matriz[0][7]==simbolo_actual){
        ganar=true;
    }
    //caso 2
    if(matriz[1][1]==simbolo_actual && matriz[1][4]==simbolo_actual && matriz[1][7]==simbolo_actual){
        ganar=true;
    }
    //caso 3
    if(matriz[2][1]==simbolo_actual && matriz[2][4]==simbolo_actual && matriz[2][7]==simbolo_actual){
        ganar=true;
    }
    //caso 4
    if(matriz[0][1]==simbolo_actual && matriz[1][1]==simbolo_actual && matriz[2][1]==simbolo_actual){
        ganar=true;
    }
    //caso 5
    if(matriz[0][4]==simbolo_actual && matriz[1][4]==simbolo_actual && matriz[2][4]==simbolo_actual){
        ganar=true;
    }
     //caso 6
    if(matriz[0][7]==simbolo_actual && matriz[1][7]==simbolo_actual && matriz[2][7]==simbolo_actual){
        ganar=true;
    }
     //caso 7
    if(matriz[0][1]==simbolo_actual && matriz[1][4]==simbolo_actual && matriz[2][7]==simbolo_actual){
        ganar=true;
    }
     //caso 8
    if(matriz[0][7]==simbolo_actual && matriz[1][4]==simbolo_actual && matriz[2][1]==simbolo_actual){
        ganar=true;
    }
	system("cls");
	
		
		turno=turno+1;
	}
		
	if(ganar==true){
		cout<< "#############################"<<endl;
		cout<< "#        Game Over          #"<<endl;
		cout<< "# el ganador es :"<<jugador_actual<<"    #"<<endl;
	}		        
	if(ganar==false){
		cout<< "#############################"<<endl;
		cout<< "#        Game Over          #"<<endl;
		cout<< "#          EMPATE           #"<<endl;
	}
}


//modo juego P1 VS PC
void contra_maquina(){
    string aux;
	int num;
	int var_quien_comienza;

	system("cls");
	mostrar_logo();
	logo_P1vsPc();

	cout<< "usted es el Player1"<<endl;
	cout<< "presione para continuar..."<<endl;
	cin>> aux;
	//numero al azar del 0 al 1
	//azar
	srand(time(NULL));
	num = rand()%2;

	if(num==0){
        cout<<"comienza el Player1"<<endl;
        var_quien_comienza=0;
	}
	if(num==1){
        cout<<"comienza la computadora"<<endl;
        var_quien_comienza=1;
	}

	cout<<"presione una tecla para continuar";
	cin >>aux;

	system("cls");
	secuencia_jugadas3(var_quien_comienza);
}




int main()
{
	int tipo_juego;
	tipo_juego=menu_principal();
	if(tipo_juego==1){
		cout<<"Juego Jugador vs Jugador"<<endl;
		contra_jugador();
	}
	if(tipo_juego==2){
		cout<<"Juego Jugador vs Pc"<<endl;
		contra_maquina();
	}
	
	
	/*
    contra_maquina();
    return 0;
    */
}

