#include "Pieza.h"

Pieza::Pieza(){
	idColor = idFigura = auxColor = 0;
	color = "";
}

Pieza::Pieza(int idFigura, int idColor){
	this->idFigura = idFigura;
	this->idColor = idColor;
	setColor();		//Se inicia el metodo de convertir el idColor a string para el dibujo de la figura.
}

int Pieza::getFigura(){
	return idFigura;
}

void Pieza::setColor(){ //Metodo cambia los idColor a colores "más bonitos".
	if (idColor == 1){
		color = "RED";
		auxColor = 4;
	} else {
		if(idColor == 2){
			color = "YELLOW";
			auxColor = 14;
		} else {
			if(idColor == 3){
				color = "MAGENTA";
				auxColor = 5;
			} else {
				if(idColor == 4){
					color = "LIGHTBLUE";
					auxColor = 9;
				} else {
					if(idColor == 5){
						color = "LIGHTGREEN";
						auxColor = 10;
					} else {
						if(idColor == 6){
							color = "BROWN";
							auxColor = 6;
					} else {
							color = "WHITE";
							auxColor = 15;
						}
					}
				}
			}
		}
	}
}

string Pieza::getColor(){
	return color;
}

int Pieza::getIdColor(){
	return idColor;
}

int Pieza::getAux(){
	return auxColor;
}

void Pieza::DibujarPieza(int x, int y){ //Dibuja la pieza segun su idFigura.
	if(idFigura == 1){
		Cuadrado(x, y);
	} else {
		if(idFigura == 2){
			Circulo(x, y);
		} else {
			if(idFigura == 3){
				Equis(x, y);
			} else {
				if(idFigura == 4){
					Trebol(x, y);
				} else {
					if(idFigura == 5) {
						Estrella(x, y);
					} else {
						if (idFigura == 6){
							Rombo(x, y);
						} 
					}
				} 
			}
		}
	}
}

//Los siguientes metodos reciben una posicion en x, y que se usa como el centro de la figura.
//No son a escala como las piezas originales pero se distinguen bastante bien.
//Aparte que a la libreria Graphics le queda corta la definicion "caotica".

void Pieza::Cuadrado(int x, int y){
	bar(x-20, y-20, x+20, y+20); 
}

void Pieza::Circulo(int x, int y){
	fillellipse(x, y, 20, 20);
}

void Pieza::Trebol(int x, int y){
	fillellipse(x, y, 10, 10);
	fillellipse(x+13, y, 10, 10);
	fillellipse(x-13, y, 10, 10);
	fillellipse(x, y+13, 10, 10);
	fillellipse(x, y-13, 10, 10);
}

void Pieza::Equis(int x, int y){
	line(x-20, y-20, x+20, y+20);
	line(x+20, y-20, x-20, y+20);
}

void Pieza::Estrella(int x, int y){
	line(x-15, y-15, x+15, y+15);
	line(x+15, y-15, x-15, y+15);
	line(x, y-20, x, y+20);
	line(x-20, y, x+20, y);
}

void Pieza::Rombo(int x, int y){
	int xrad = 275, yrad = 25;
	sector(x, y-25, 225, 315, xrad, yrad);
	sector(x, y+25, 45, 135, xrad, yrad);
}

string Pieza::toString(){
	stringstream s;
	s<<"Id: "<<idFigura
	<<", Id color: "<<idColor
	<<", color: "<<color
	<<", aux color: "<<auxColor<<endl;
	return s.str();
}
