#include <sstream>
#include <iostream>
#include <string>
#include <graphics.h>
#include "Boton.h"
#include "Partida.h"

using namespace std;

int main(){
	
	//Menu de inicio
	
//	prueba.LlenarBolsa();
//	prueba.impPiezas();
//	prueba.iniciarPartida();
//	prueba.Repartir();

	initwindow(900, 700);
////	setcolor(0);
	Partida prueba;
	prueba.llenarTablero();
	Pieza * ficha;
	ficha = new Pieza(2, 4);	
	prueba.AgregarPieza(ficha, 8, 7);
	
//	prueba.PiezasTablero();
	
	prueba.pintarTablero();
//	prueba.iniciarPartida();
	
//	prueba.PintarTablero();
//	setfillstyle(2, 0);
	
//	settextstyle(10, 0, 4);
//	outtextxy(370, 50, "Qwirkle 4K");

	//--------------circulo
//	fillellipse(50, 50, 25, 25);

	//-------------cuadrado
//	bar(200, 200, 250, 250);

	//------------equis	
//	line(50, 50, 100, 100);
//	line(100, 50, 50, 100);
	
	//-----------rombo
//	int maxx = 900;
//	int maxy = 700;
//	int midx = 450;
//	int midy = 350;
//	int stangle = 45, endangle = 135;
//  int xrad = 200, yrad = 20;
//  sector(midx, midy-40, 225, 315, xrad, yrad);
//	sector(midx, midy, stangle, endangle, xrad, yrad);


	//-----------trebol
//	fillellipse(100, 100, 10, 10);
//	fillellipse(115, 100, 10, 10);
//	fillellipse(85, 100, 10, 10);
//	fillellipse(100, 115, 10, 10);
//	fillellipse(100, 85, 10, 10);

	//-----------estrella
//	line(50, 50, 100, 100);
//	line(100, 50, 50, 100);
//	line(75, 50, 75, 100);
//	line(50, 75, 100, 75);

	
//	if((mousex()>left)&&(mousex()<right)&&(mousey()>top)&&(mousey()<bottom)){
//		setcolor(WHITE);
//		bar3d(left, top, right, bottom, 0, 0);
//	}
//	else {
//		setcolor(LIGHTCYAN);
//		bar3d(left, top, right, bottom, 0, 0);
//	}
	

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
	
   getch();
   closegraph();

	return 0;
}

//   line(0, 0, getmaxx(), getmaxy());
	
//	cin>>opc;
//	if(opc == 1){
//		cleardevice();
//		bar (0, 0, getmaxx(), getmaxy());
//	} else {
//		outtextxy(450, 150, "Bueeenas");
//		settextstyle(2,0,5);
//	} 

