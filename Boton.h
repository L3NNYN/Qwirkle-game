#ifndef BOTON_H
#define BOTON_H
//#include <graphics.h>
#include <sstream>
#include <string>
#include <iostream>
#include <graphics.h>
#include "Pieza.h"

using namespace std;

class Boton
{
	private:
		int x1, x2, y1, y2;
//		 ancho, alto, color;
		Pieza * ficha;
	public:
		Boton();
		Boton(Pieza *, int, int, int, int);
		void setCoord(int, int, int, int);
		int getX1();
		int getX2();
		int getY1();
		int getY2();
		void setFicha(Pieza *);
		void DibujarTablero();
		Pieza * getFicha();
		void DibujarFicha();
		void imprimirFicha();
		void Menu();
};

#endif
