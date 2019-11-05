#ifndef PIEZA_H
#define PIEZA_H
#include <string>
#include <sstream>
#include <graphics.h>
using namespace std;

class Pieza
{	
	private:
		int idColor, idFigura, auxColor;
		string color;
	public:
		Pieza();
		Pieza(int, int);
		void setPieza(int, int);
		int getFigura();
		void setColor();
		string getColor();	
		int getAux();
		void DibujarPieza(int, int); //Dibuja la pieza.
		void Cuadrado(int, int); 
		void Circulo(int, int);
		void Equis(int, int);
		void Trebol(int, int);
		void Estrella(int, int);
		void Rombo(int, int);
		string toString();
};

#endif
