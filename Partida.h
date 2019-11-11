#ifndef PARTIDA_H
#define PARTIDA_H
#include <graphics.h>
#include <iostream>
#include <string>
#include <sstream>
#include <ctime> 	//Libreria para el numero aleatorio.
#include <stdlib.h>
#include "Pieza.h"
#include "Nodo.h"
#include "Jugador.h"
#include "Mesa.h"
#define FIL 9
#define COL 10

//Para eliminar nodos usé de referencia este video: https://youtu.be/ljYbVM6j11s
//La parte grafica ha sido la más caotica para mi, era algo nuevo y que he tenido que investigar personalmente al igual los demás.
//Me llevo mucho tiempo ya que usualmente el programa se caía y no tenía idea porqué, aunque si tenía la certeza de que era por la parte gráfica.

using namespace std;

class Partida
{
	private:
		int cantPiezas, puntaje; //Variables locales para determinar el puntaje min para ganar y la cantidad de piezas en la bolsa.
		Jugador Comp, Player1; //Los dos objetos tipo Jugador.
		Mesa * Tablero[FIL][COL]; //Crea una matriz de objetos para dibujar el tablero.
		Nodo *primero, *actual; //Punteros tipo nodo para el manejo de la lista.
	public:
		Partida();
		void NombreJugador(); //Define del nombre del jugador Player1.
		void setPuntaje(); //Define el puntaje minino para ganar la partida.
		void cambiarDeck(); //Cambia el deck completo del jugador si asi lo desea.
		void unaFicha(); //Permite tomar solo una ficha.
		void deckJugador(); 
		char* impPuntaje(); //Hace la conversion de int a char para imprimir en pantalla.
		char* impCantPiezas(); //Hace la conversion de int a char para imprimir en pantalla.
		
		void llenarTablero(); //Llena la matriz de objetos Tablero con coordenadas las coordenadas.
		void pintarTablero(); //Recorre la matriz y dibuja lo que esta contenida en ella.
		
		bool VerificarAdyacencia(int, int, Pieza*); //Hace la verificacion de adyacencia en el tablero que retorna true si es posible la insercion.
		bool VerificarPuntaje(int, int, Pieza*); //Verifica las lineas en busca de una ficha igual, también suma el puntaje.
		//Recibe una posicion "i" y "j" que verifica si el espacio de la matriz esta disponible y retorna true si es insertada.
		bool AgregarPiezaTablero(Pieza*,Pieza*, int, int); 
		
		void LlenarBolsa(); //Crea 108 piezas, con diseño de "(i, j)", donde i y j tienen valores de 1 a 6, cuando se crea la pieza se envia al metodo Bolsa.
		void Bolsa(Pieza*); //Metodo de la lista que recibe una Pieza y la administras en los nodos.
		void RepartirJugador(); //Metodo que reparte las piezas de manera aleatoria.
		void RepartirComp();
		void SacarPieza(Pieza*); //Metodo que elimina el nodo de la bolsa después de ponerlo en el deck del jugador.
		
		void iniciarPartida(); //Llama los metodos anteriores para poder iniciar la partida de manera efectiva.
		
		void ganador();
		void impPiezas();
		
};

#endif
