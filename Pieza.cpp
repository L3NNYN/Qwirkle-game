#include "Pieza.h"

Pieza::Pieza(){
	idColor = idFigura = 0;
	color = "";
}

Pieza::Pieza(int idColor, int idFigura){
	this->idColor = idColor;
	this->idFigura = idFigura;
}

int Pieza::getFigura(){
	return idFigura;
}

void Pieza::setColor(){
//	this->color = color;
	if (idColor == 1){
		color = "RED";
		if(idColor == 2){
			color = "YELLOW";
			if(idColor == 3){
				color = "MAGENTA";
				if(idColor == 4){
					color = "LIGHTBLUE";
					if(idColor == 5){
						color = "LIGHTGREEN";
						if(idColor == 6){
							color = "BROWN";
						}
					}
				}
			}
		}
	} else {
		color = "WHITE";
	}
}

string Pieza::getColor(){
	return color;
}

string Pieza::toString(){
	stringstream s;
	s<<getFigura()<<endl;
	
	return s.str();
}
