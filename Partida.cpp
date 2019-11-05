#include "Partida.h"

Partida::Partida(){
	cantPiezas = 0;
	primero = actual = casilla = NULL;
	
	for(int a = 0; a < FIL; a++){
		for(int b = 0; b < COL; b++){
			Tablero[a][b] = new Boton();
		}
	}
	//Lo inicio acá porque en el método me genera que los dos jugadores tengan el mismo deck.
	srand(time(NULL));
}

void Partida::llenarTablero(){
	int left = 50; 
	int top = 100;
	int right = 100;
	int bottom = 150;	
	for(int i = 0; i < FIL; i++){
		for(int j = 0; j < COL; j++){
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

void Partida::pintarTablero(){
//	Pieza * ficha;
//	ficha = new Pieza(2, 4);
//	AgregarPieza(ficha, 8, 7);

	for(int i = 0; i < FIL; i++){
		for(int j = 0; j < COL; j++){
			Tablero[i][j]->DibujarTablero();
		}
	}
	
}

void Partida::PiezasTablero(){
for(int i = 0; i < FIL; i++){
		for(int j = 0; j < COL; j++){
			if(Tablero[i][j]->getFicha() != NULL){
				Tablero[i][j]->DibujarFicha();
			}
		}
	}

}

void Partida::AgregarPieza(Pieza * ficha, int i, int j){
//	if(Tablero[i][j]->getFicha() == NULL){
		Tablero[i][j]->setFicha(ficha);
//	} else {
//		return;
//	}
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
Tablero[8][7]->DibujarFicha();
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
