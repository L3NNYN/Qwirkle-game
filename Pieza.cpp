#include "Pieza.h"

Pieza::Pieza(){
	idColor = idFigura = auxColor = 0;
	color = "";
}

Pieza::Pieza(int idFigura, int idColor){
	this->idFigura = idFigura;
	this->idColor = idColor;
	setColor();
	//Se inicia el metodo de convertir el idColor a string para el dibujo de la figura.
}

void Pieza::setPieza(int idFigura, int idColor){
	this->idColor = idColor;
	this->idFigura = idFigura;
	setColor(); 				
}

int Pieza::getFigura(){
	return idFigura;
}

void Pieza::setColor(){
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

void Pieza::DibujarPieza(int x, int y){
	setcolor(auxColor);
	setfillstyle(1, auxColor);
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
	setfillstyle(9, 15);
}

void Pieza::Cuadrado(int x, int y){
//	x = 50;
//	y = 2 * x;
//	setfillstyle(1, 4);
	bar(x, y, x+50, y+50); 
}

void Pieza::Circulo(int x, int y){
//	setcolor(4);
//	setfillstyle(1, 4);
	fillellipse(x, y, 20, 20);
}

void Pieza::Trebol(int x, int y){
//	setcolor(4);
//	setfillstyle(1, 4);
//	fillellipse(100, 100, 10, 10);
//	fillellipse(115, 100, 10, 10);
//	fillellipse(85, 100, 10, 10);
//	fillellipse(100, 115, 10, 10);
//	fillellipse(100, 85, 10, 10);
	
	fillellipse(x, y, 10, 10);
	fillellipse(x+15, y, 10, 10);
	fillellipse(x-15, y, 10, 10);
	fillellipse(x, y+15, 10, 10);
	fillellipse(x, y-15, 10, 10);
}

void Pieza::Equis(int x, int y){
//	line(50, 50, 100, 100);
//	line(100, 50, 50, 100);
//	setcolor(4);
	line(x-25, y-25, x+25, y+25);
	line(x+25, y-25, x-25, y+25);
}

void Pieza::Estrella(int x, int y){
//	line(50, 50, 100, 100);
//	line(100, 50, 50, 100);
//	line(75, 50, 75, 100);
//	line(50, 75, 100, 75);
	line(x-25, y-25, x+25, y+25);
	line(x+25, y-25, x-25, y+25);
	line(x, y-25, x, y+25);
	line(x-25, y, x+25, y);
}

void Pieza::Rombo(int x, int y){
//	x = 75;
//	y = x + 75;
//	setcolor(4);
//	setfillstyle(1, 4);
	int xrad = 275, yrad = 25;
	sector(x, y-50, 225, 315, xrad, yrad);
	sector(x, y, 45, 135, xrad, yrad);
}

string Pieza::toString(){
	stringstream s;
	s<<"Id: "<<idFigura
	<<", Id color: "<<idColor
	<<", color: "<<color
	<<", aux color: "<<auxColor<<endl;
	return s.str();
}
