#ifndef PIEZA_H
#define PIEZA_H
#include <string>
#include <sstream>
#include <graphics.h>

//Para determinar una pieza se necesitan solo dos numero enteros que sean de 1 a 6, y van a ser guardados en idColor y en idFigura.
//La variable auxColor es la que le da el color a la figura y se define automaticamente segun el valor de idColor.

using namespace std;

class Pieza
{	
	private:
		int idColor, idFigura, auxColor;
		string color;
	public:
		Pieza();
		Pieza(int, int); //Recibe los parametros idColor y idFigura, tambien llama el metodo setColor.
		int getFigura();
		void setColor(); //Define auxColor.
		string getColor();
		int getIdColor();	
		int getAux();
		void DibujarPieza(int, int); //Recibe dos coordenadas, X y Y, y llama un metodo de figura segun sea su idFigura.

		//Los siguientes metodos dibujan la figura que esta escrita en su titulo del metodo, y reciben dos enteros que definen la posicion de la figura.
		void Cuadrado(int, int);
		void Circulo(int, int);
		void Equis(int, int);
		void Trebol(int, int);
		void Estrella(int, int);
		void Rombo(int, int);
		string toString();
};

#endif
