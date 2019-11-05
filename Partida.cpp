#include "Partida.h"

Partida::Partida(){	
	cantPiezas = 0;
	primero = actual = casilla = NULL;
	
	for(int a = 0; a <= 9; a++){
		for(int b = 0; b <= 11; b++){
			Tablero[a][b] = NULL;
		}
	}
	
	//Lo inicio acá porque en el método me genera que los dos jugadores tengan el mismo deck.
	srand(time(NULL));
}

void Partida::PintarTablero(){
	int left = 50; 
	int top = 100;
	int right = 100;
	int bottom = 150;	
	setfillstyle(9, 15);
	for(int i = 0; i <= 9; i++){
		for(int j = 0; j <= 11; j++){
			bar3d(left, top, right, bottom, 0, 0);
			Tablero[i][j] = new Boton(NULL, left, top, right, bottom);
			left += 50;
			right += 50;
		}
		left = 50;
		top += 50; 
		right = 100;
		bottom += 50;		
	}
}

void Partida::PiezasTablero(){
//	Pieza * asd = ficha;
//	Tablero[0][0] = new Boton(ficha, 0, 0, 0, 0);
//	Tablero[0][0]->setCoord(100, 100, 150, 150);
//	Tablero[0][0]->setFicha(ficha);
//	Tablero[0][0]->imprimirFicha();

//	Pieza * as = ficha;
//	as = new Pieza(2, 4);
//	Tablero[0][0]->setFicha(as);
//	Tablero[8][7]->setFicha(as);


//for(int i = 0; i <= 9; i++){
//		for(int j = 0; j <= 11; j++){
//			if(Tablero[i][j]->getFicha() != NULL){
//				Tablero[i][j]->DibujarFicha();
//			}
//		}
//	}

}

void Partida::AgregarPieza(Pieza * ficha, int i, int j){
	if(Tablero[i][j]->getFicha() == NULL){
		Tablero[i][j]->setFicha(ficha);
	} else {
//		return;
	}
}

void Partida::LlenarBolsa(){
	Pieza *ficha;
	for(int a = 0; a < 3; a++){
		for(int i = 0; i < 6; i++){
			for(int j = 0; j < 6; j++){
				ficha = new Pieza(i + 1, j + 1); 
				Bolsa(ficha);
				cantPiezas++;
			}
		}
	}
}

void Partida::iniciarPartida(){
//	Repartir(Comp);
//	Repartir(Player1);
//Tablero[0][0]->DibujarFicha();

//	for(int i = 0; i <= 9; i++){
//		for(int j = 0; j <= 11; j++){
//			if(Tablero[8][7]->getFicha() != NULL){
//				Tablero[8][7]->DibujarFicha();
//			}
//		}
//	}
}

void Partida::Bolsa(Pieza * ficha){
	if(primero == NULL){
		primero = new Nodo(ficha, NULL);
	} else {
		actual = primero;
		while(actual->getSigNodo() != NULL){
			actual = actual->getSigNodo();
		}
		actual->setSigNodo(new Nodo(ficha, NULL));
	}
}

void Partida::Repartir(Jugador player){
	for(int i = 0; i < 6; i++){
		int aux = 0;
		aux = rand()%50 + 1;	
		actual = primero;
		for(int i = 0; i < aux; i++){ 
			if(actual->getSigNodo() != NULL){
	    	actual = actual->getSigNodo();
			}
	    }
	    Pieza * ficha = actual->getDato();
	    player.Deck(ficha);
	    SacarPieza(ficha);
	}
//	cout<<"\n------------Jugador: "<<endl;
//	player.toString();
}

void Partida::SacarPieza(Pieza * borrar){
	if(primero != NULL){
		actual = primero;
		Nodo * anterior = NULL; //Auxiliar 
		while((actual != NULL) && (actual->getDato() != borrar)){
			anterior = actual;
			actual = actual->getSigNodo();
		} 
		anterior->setSigNodo(actual->getSigNodo());
		cout<<"Borra: "<<actual->toString();
		delete actual;
		cantPiezas--;
	}
}

void Partida::impPiezas(){
	actual = primero;
	while(actual != NULL){
		cout<<actual->toString()<<endl;
		actual = actual->getSigNodo();
	}
}
