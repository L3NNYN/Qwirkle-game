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
		string nombre;
		int puntaje;
		Nodo * primero;
		Nodo * actual;
	public:
		Jugador();
		void setPuntaje(int);
		int getPuntaje();
		void setNombre(string);
		string getNombre();
		void Deck(Pieza *);
		void toString();
};

#endif
