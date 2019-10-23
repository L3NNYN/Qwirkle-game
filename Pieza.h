#ifndef PIEZA_H
#define PIEZA_H
#include <string>
#include <sstream>
using namespace std;

class Pieza
{	
	private:
		int idColor, idFigura;
		string color;
	public:
		Pieza();
		Pieza(int, int);
		int getFigura();
		void setColor();
		string getColor();	
		string toString();
};

#endif
