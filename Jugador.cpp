#include "Jugador.h"

Jugador::Jugador(){
	nombre = "";
	puntaje = 0;
	primero = actual = NULL;
}

void Jugador::setPuntaje(int puntaje){
	this->puntaje = puntaje;
}

int Jugador::getPuntaje(){
	return puntaje;
}

void Jugador::setNombre(string nombre){
	this->nombre = nombre;
}

string Jugador::getNombre(){
	return nombre;
}

void Jugador::Deck(Pieza * ficha){
	if(primero == NULL){
		primero = new Nodo(ficha, NULL);
	} else {
		actual = primero;
		while(actual->getSigNodo() != NULL){
			actual = actual->getSigNodo();
		}
		actual->setSigNodo(new Nodo (ficha, NULL));
	}
}

void Jugador::toString(){
	actual = primero;
	while(actual != NULL){
		cout<<actual->toString()<<endl;
		actual = actual->getSigNodo();
	}
}
