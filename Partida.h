#ifndef PARTIDA_H
#define PARTIDA_H
#include <iostream>
#include <string>
#include <sstream>
#include <time.h> 	//Libreria para el numero aleatorio.
#include <stdlib.h>
#include "Pieza.h"
#include "Nodo.h"
#include "Jugador.h"
#include "Boton.h"

//Para eliminar nodos use de referencia este video: https://youtu.be/ljYbVM6j11s

using namespace std;

class Partida
{
	private:
		int cantPiezas;
		Jugador Comp, Player1;
		Boton * Tablero[9][11];
		Nodo * primero;
		Nodo * actual;
		Nodo * casilla;
	public:
		Partida();
		void PintarTablero();
		void PiezasTablero();
		void AgregarPieza(Pieza *, int, int);
		
		void LlenarBolsa();
		void Bolsa(Pieza*);
		void iniciarPartida();
		void Repartir(Jugador); //Metodo que reparte las piezas de manera aleatoria.
		void impPiezas();
		void SacarPieza(Pieza*); //Metodo que elimina el nodo de la bolsa después de ponerlo en el deck del jugador.
		
};

#endif
