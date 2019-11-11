#include <sstream>
#include <iostream>
#include <string>
#include <graphics.h>
#include "Partida.h"

//En las clases omiti comentar los set y gets más básicos, como los de las varibales primitivas, ya que es algo que creo se puede obviar.
//Desde ya informo lo que el proyecto no hace: manejo de archivos, y que la computadora juegue.
//Hay un pequeño bug en el cambiar deck, porque lo hace, cambia todas la fichas del jugador y luego las grafica pero se cae después de hacerlo.
//Al inicio de los botones explico cono funcionan rapidamente, para no ir explicando uno por uno cada vez.

using namespace std;

void Menu();
void Info();

int main(){
	
	//Menu de inicio
	
	initwindow(900, 700); //se inicia la ventana.
	Menu(); //Se iniciar la funcion menu que es la ventana de incicio del menu.

   getch();
   closegraph();

	return 0;
}

void Menu(){
	Partida juego; //Se crea el objeto tipo partida.
	settextstyle(10, 0, 4);
	outtextxy(370, 50, "Qwirkle 4K");
	
	//Ok, basicamente son seis botones, cada boton tiene una condicion y que pasa si no se cumple esa condicion.
	//La condicion es que el mouse debe estar sobre las coordenadas que determinan el boton.
	//Si esa condicion no se cumple simplemente pintara un cuadro, esto me permite que cuando me sobre él, pueda cambiar de color.
	//Entonces pinta lo mismo que en "else" pero con diferente color, para que se vea más porte.
	do{
		//PRIMER BOTON: DEFINIR JUGADOR
		if((mousex()>400)&&(mousex()<550)&&(mousey()>150)&&(mousey()<190)){	
			setcolor(WHITE);
			settextstyle(3, 0, 2);
			outtextxy(410, 155,"Definir Jugador");
			rectangle(400, 150, 550, 190);
			if(ismouseclick(WM_LBUTTONDOWN)){
				clearmouseclick(WM_LBUTTONDOWN);
				cleardevice();
				outtextxy(300, 300, "Inserte su nombre en la consola");
				juego.NombreJugador(); //Si se hace click llama este metodo.
				cleardevice(); //Luego limpia la pantalla.
				Menu(); //Y llama el menu nuevamente.
			}
		}
		else {
			setcolor(LIGHTCYAN);
			settextstyle(3, 0, 2);													
			outtextxy(410, 155, "Definir Jugador");
			rectangle(400, 150, 550, 190);
		}
		
		//SEGUNDO BOTON: PUNTAJE
		
		if((mousex()>400)&&(mousex()<550)&&(mousey()>200)&&(mousey()<240)){	
			setcolor(WHITE);
			settextstyle(3, 0, 2);
			outtextxy(445, 205,"Puntaje");
			rectangle(400, 200, 550, 240);
			if(ismouseclick(WM_LBUTTONDOWN)){ //Si se clickea llama al metodo de setPuntaje
				clearmouseclick(WM_LBUTTONDOWN);
				cleardevice();
				outtextxy(300, 300, "Defina el puntaje en la consola");
				juego.setPuntaje();
				cleardevice();
				Menu();
			}
		}
		else {
			setcolor(LIGHTCYAN);
			settextstyle(3, 0, 2);													
			outtextxy(445, 205, "Puntaje");
			rectangle(400, 200, 550, 240);
		}
		
		//TERCER BOTON: INICIAR PARTIDA
		
		if((mousex()>400)&&(mousex()<550)&&(mousey()>250)&&(mousey()<290)){	
			setcolor(WHITE);
			settextstyle(3, 0, 2);
			outtextxy(420, 255,"Iniciar Partida");
			rectangle(400, 250, 550, 290);
		if(ismouseclick(WM_LBUTTONDOWN)){ //si el mouse es clickeado mientras esta sobre el boton, se inicia la partida.
				clearmouseclick(WM_LBUTTONDOWN);
				cleardevice();
				juego.iniciarPartida(); 
			}
		}
		else {
			setcolor(LIGHTGREEN);
			settextstyle(3, 0, 2);													
			outtextxy(420, 255, "Iniciar Partida");
			rectangle(400, 250, 550, 290);
		}
		
		//CUARTO BOTON: CARGAR PARTIDA
		//En teoría debería cargar una partida pero la verdad es que no funciona.
		
		if((mousex()>400)&&(mousex()<550)&&(mousey()>300)&&(mousey()<340)){		
			setcolor(WHITE);
			settextstyle(3, 0, 2);
			outtextxy(415, 305,"Cargar Partida");
			rectangle(400, 300, 550, 340);
			if(ismouseclick(WM_LBUTTONDOWN)){ //Este no hace nada, pero se ve bonito, dejemoslo ahi por si acaso.
			}
		}
		else {
			setcolor(LIGHTCYAN);
			settextstyle(3, 0, 2);													
			outtextxy(415, 305, "Cargar Partida");
			rectangle(400, 300, 550, 340);
		}
		
		//QUINTO BOTON: INFO
		//Muestra un poco de informacion sobre el estudiante.
		
		if((mousex()>400)&&(mousex()<550)&&(mousey()>350)&&(mousey()<390)){		
			setcolor(WHITE);
			settextstyle(3, 0, 2);
			outtextxy(460, 355,"Info");
			rectangle(400, 350, 550, 390);
			if(ismouseclick(WM_LBUTTONDOWN)){
				Info();
				cleardevice();
				Menu();
			}
		}
		else {
			setcolor(LIGHTCYAN);
			settextstyle(3, 0, 2);														
			outtextxy(460, 355, "Info");
			rectangle(400, 350, 550, 390);
		}
		
		//SEXTO BOTON: SALIR
		//Cierra la ventana gráfica.
		
		if((mousex()>400)&&(mousex()<550)&&(mousey()>450)&&(mousey()<490)){		
			setcolor(RED);
			settextstyle(3, 0, 2);
			outtextxy(455, 455,"Salir");
			rectangle(400, 450, 550, 490);
			if(ismouseclick(WM_LBUTTONDOWN)){
				closegraph();
			}
		}
		else {
			setcolor(LIGHTRED);
			settextstyle(3, 0, 2);														
			outtextxy(455, 455, "Salir");
			rectangle(400, 450, 550, 490);
		}
		
		clearmouseclick(WM_LBUTTONDOWN);

	}	while (not(kbhit()));
}

void Info(){
	cleardevice();
	setcolor(CYAN);
	settextstyle(3, 0, 2);
	for(int i = 0; i <= 15; i++){
		setcolor(i);
		outtextxy(390, 100,"Hecho por:");
		outtextxy(360, 200,"Lennyn el mapachin.");
		outtextxy(390, 300,"(11/11/2019)");
		outtextxy(380, 400,"Programacion I");
		outtextxy(400, 500,"II CICLO");
		delay(500);
	}
}

