#include "Mesa.h"

Mesa::Mesa(){
	x1 = 0;
	y1 = 0;
	x2 = 0;
	y2 = 0;
	ficha = NULL;
}

Mesa::Mesa(Pieza * ficha, int x1, int y1, int x2, int y2){
	this->ficha = ficha;
	this->x1 = x1;
	this->y1 = y1;
	this->x2 = x2;
	this->y2 = y2;
}

//Este metodo es importante ya que se recorre en la clase partida.
//Aqui recibe dos posiciones y las compara hasta que se retorne true.
//En ese momento se sabe con certeza que se tiene el cuadro que se clickeo en la matriz.
bool Mesa::getPos(int mx, int my){
	if((mx>x1)&&(mx<x2)&&(my>y1)&&(my<y2)){
		return true;
	} else {
		return false;
	}
	
}

int Mesa::getX1(){
	return x1;
}

int Mesa::getX2(){
	return x2;
}

int Mesa::getY1(){
	return y1;
}

int Mesa::getY2(){
	return y2;
}

//Este metodo sirve para una vez verificada la posicion de la matriz, se pueda insertar una ficha rapidamente en el.
void Mesa::setFicha(Pieza * ficha){
	this->ficha = ficha;
}

void Mesa::DibujarTablero(){
	if (ficha == NULL){ //Si no hay una ficha dibuja un solo cuadro.
		setfillstyle(9, 15);
		setcolor(0);
		bar3d(x1, y1, x2, y2, 0, 0);
	} else {
		//Si la ficha se encuentra primero dibuja un cuadro negro que sirve como nuevo fondo.
		setfillstyle(1, 0);
		setcolor(0);
		bar3d(x1, y1, x2, y2, 0, 0);
		int auxColor = 0;
		auxColor = ficha->getAux();
		setcolor(auxColor);
		setfillstyle(1, auxColor);
		DibujarFicha(); //Y dibuja la ficha encima de dicho cuadro en las posiciones definidas.
	}
}

void Mesa::DibujarFicha(){
	//Me di cuenta que sumando los dos valores que determinan los extremos (en x, y) y luego dividiendolos entre dos
	//me iba a dar como resultado el centro de ese cuadro que es justo lo que necesito para graficar la pieza.
	int x3 = (x1 + x2)/2;
	int y3 = (y1 + y2)/2;
	ficha->DibujarPieza(x3, y3);
}

Pieza * Mesa::getFicha(){
	return ficha;
}

void Mesa::imprimirFicha(){
	if(ficha != NULL){	
	cout<<ficha->toString();
	}
}
