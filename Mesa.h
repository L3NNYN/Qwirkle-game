#ifndef MESA_H
#define MESA_H
#include <graphics.h>
#include <sstream>
#include <string>
#include <iostream>
#include <graphics.h>
#include "Pieza.h"

using namespace std;

class Mesa
{
	private:
		int x1, x2, y1, y2; //Coordenadas necesarias para graficar un bar3d.
		Pieza * ficha; //Si se encuentra la ficha dentro de las coordenadas la graficara.
	public:
		Mesa();
		Mesa(Pieza *, int, int, int, int); //Recibe las coordenadas para dibujar el cuadro y una pieza o NULL.
		bool getPos(int, int); //Metodo de verificacion de coordenadas que recibe un X y Y.
		int getX1();  //Este y el siguiente metodo retorna las coordenadas para la esquina superior izquierda.
		int getY1();
		int getX2(); //Y este retorna las coordenadas para la esquina inferior izquierda.
		int getY2();
		void setFicha(Pieza *);
		void DibujarTablero(); //Dibujar un cuadro segun las coordenadas y dibuja la ficha si es diferente de NULL.
		Pieza * getFicha(); //Retorna la ficha segun las coordenadas.
		void DibujarFicha(); //Toma los dos X y los Y para crear un tercer auxiliar para tener el centro del cuadro necesario para dibujar la pieza.
		void imprimirFicha(); //Configura el centro del cuadro para dibujar la ficha.
};

#endif
