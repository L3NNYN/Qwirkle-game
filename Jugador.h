#ifndef JUGADOR_H
#define JUGADOR_H
#include <sstream>
#include <string>
#include <iostream>
#include "Nodo.h"
#include "Pieza.h"

using namespace std;

class Jugador
{	
	private:
		string nombre; //Guarda el nombre del jugador.
		int puntaje, piezas; //Variables que guardan la cantidad de piezas del deck y el puntaje de cada jugador.
		Nodo *primero, *actual; 
	public:
		Jugador();
		~Jugador(); //Sirve para limpiar la lista del jugador.
		void setPuntaje(int); //Determina el puntaje personal.
		int getPuntaje(); //Retorna el puntaje del jugador.
		char* impPuntaje(); //Hace la conversion de int a char para imprimir en la pantalla.
		void setNombre(string); //Define el nombre que desea.
		string getNombre(); //Retorna el nombre.
		Pieza* getFicha(int aux); //Recorre la lista n veces y retorna una ficha segun el auxiliar que reciba.
		void borrarPrimeraPieza(); //Borra la primera pieza de la lista.
		void borrarUltimaPieza(); //Borra la ultima pieza de la lista.
		void Deck(Pieza*); //Ingresa las fichas en la lista del jugador.
		void imprimirDeck(); //Imprime el deck (piezas) en coordenadas especificas.
		void imprimirNombre(); //Imprime el nombre el punto en coordenada especifica.
		int getPiezas(); //Retorna la cantidad de piezas que posee en el deck.
		void usarPieza(Pieza*, int); //Borra una pieza del deck si se inserta en el tablero.
		void toString();
};

#endif
