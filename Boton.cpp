#include "Boton.h"

Boton::Boton(){
	x1 = 0;
	y1 = 0;
	x2 = 0;
	y2 = 0;
	ficha = NULL;
}

Boton::Boton(Pieza * ficha, int x1, int y1, int x2, int y2){
	this->ficha = ficha;
	this->x1 = x1;
	this->y1 = y1;
	this->x2 = x2;
	this->y2 = y2;
}

void Boton::setCoord(int x1, int y1, int x2, int y2){
	this->x1 = x1;
	this->y1 = y1;
	this->x2 = x2;
	this->y2 = y2;
}

int Boton::getX1(){
	return x1;
}

int Boton::getX2(){
	return x2;
}

int Boton::getY1(){
	return y1;
}

int Boton::getY2(){
	return y2;
}

void Boton::setFicha(Pieza * ficha){
	this->ficha = ficha;
}

void Boton::DibujarTablero(){
	if (ficha == NULL){
		setfillstyle(9, 15);
		setcolor(0);
		bar3d(x1, y1, x2, y2, 0, 0);
	} else {
		int auxColor = 0;
		auxColor = ficha->getAux();
		setcolor(auxColor);
		setfillstyle(1, auxColor);
		DibujarFicha();
	}
}

void Boton::DibujarFicha(){
	int x3 = (x1 + x2)/2;
	int y3 = (y1 + y2)/2;
	ficha->DibujarPieza(x3, y3);
}

Pieza * Boton::getFicha(){
	return ficha;
}

void Boton::imprimirFicha(){
	cout<<ficha->toString();
}

void Boton::Menu(){
//	settextstyle(10, 0, 4);
//	outtextxy(370, 50, "Qwirkle 4K");
//	do {
//		
//		//PRIMER BOTON: DEFINIR JUGADOR
//		
//		if((mousex()>400)&&(mousex()<550)&&(mousey()>150)&&(mousey()<190)){		//si pasa por esas coordenadas el boton cambiará de color
//			setcolor(WHITE);
//			settextstyle(3, 0, 2);
//			outtextxy(410, 155,"Definir Jugador");
//			rectangle(400, 150, 550, 190);
//		}
//		else {
//			settextstyle(3, 0, 2);														//sino se mantendrá igual con el color actual
//			outtextxy(410, 155, "Definir Jugador");
//			setcolor(LIGHTCYAN);
//			rectangle(400, 150, 550, 190);
//		}
//		
//		//SEGUNDO BOTON: PUNTAJE
//		
//		if((mousex()>400)&&(mousex()<550)&&(mousey()>200)&&(mousey()<240)){		//si pasa por esas coordenadas el boton cambiará de color
//			setcolor(WHITE);
//			settextstyle(3, 0, 2);
//			outtextxy(445, 205,"Puntaje");
//			rectangle(400, 200, 550, 240);
//		}
//		else {
//			setcolor(LIGHTCYAN);
//			settextstyle(3, 0, 2);														//sino se mantendrá igual con el color actual
//			outtextxy(445, 205, "Puntaje");
//			rectangle(400, 200, 550, 240);
//		}
//		
//		//TERCER BOTON: INICIAR PARTIDA
//		
//		if((mousex()>400)&&(mousex()<550)&&(mousey()>250)&&(mousey()<290)){		//si pasa por esas coordenadas el boton cambiará de color
//			setcolor(WHITE);
//			settextstyle(3, 0, 2);
//			outtextxy(420, 255,"Iniciar Partida");
//			rectangle(400, 250, 550, 290);
//		}
//		else {
//			setcolor(LIGHTCYAN);
//			settextstyle(3, 0, 2);														//sino se mantendrá igual con el color actual
//			outtextxy(420, 255, "Iniciar Partida");
//			rectangle(400, 250, 550, 290);
//		}
//		
//		//CUARTO BOTON: CARGAR PARTIDA
//		
//		if((mousex()>400)&&(mousex()<550)&&(mousey()>300)&&(mousey()<340)){		//si pasa por esas coordenadas el boton cambiará de color
//			setcolor(WHITE);
//			settextstyle(3, 0, 2);
//			outtextxy(415, 305,"Cargar Partida");
//			rectangle(400, 300, 550, 340);
//		}
//		else {
//			setcolor(LIGHTCYAN);
//			settextstyle(3, 0, 2);														//sino se mantendrá igual con el color actual
//			outtextxy(415, 305, "Cargar Partida");
//			rectangle(400, 300, 550, 340);
//		}
//		
//		//QUINTO BOTON: INFO
//		
//		if((mousex()>400)&&(mousex()<550)&&(mousey()>350)&&(mousey()<390)){		//si pasa por esas coordenadas el boton cambiará de color
//			setcolor(WHITE);
//			settextstyle(3, 0, 2);
//			outtextxy(460, 355,"Info");
//			rectangle(400, 350, 550, 390);
//		}
//		else {
//			setcolor(LIGHTCYAN);
//			settextstyle(3, 0, 2);														//sino se mantendrá igual con el color actual
//			outtextxy(460, 355, "Info");
//			rectangle(400, 350, 550, 390);
//		}
//		
//	} while (not(kbhit()));
}

//int Boton::BotonesColor(){
//	setcolor(WHITE);
//	outtextxy(120,474,"TABLA DE COLORES");
//	rectangle(20,490,350,580);
//	setcolor(colores);
//	setfillstyle(1,colores);
//	bar(X+4,Y+4,Ancho-4,Alto-4);				//crea los botones de colores
//	if((mousex()>X)&&(mousex()<Ancho)&&(mousey()>Y)&&(mousey()<Alto)){
//		setcolor(WHITE);									//si pasa por las coordenadas del boton se crea un rectangulo blanco al rededor de cuadro 
//		rectangle(X,Y,Ancho,Alto);	
//	}
//	else{
//		setcolor(colores);
//		rectangle(X,Y,Ancho,Alto);			//si no pasa por las coordenadas de los botones el rectangulo  permanece de igual color al boton	
//	}
//	if((mousex()>X)&&(mousex()<Ancho)&&(mousey()>Y)&&(mousey()<Alto)&&(ismouseclick(WM_LBUTTONDOWN))){	
//		return 1;
//	}
//}


