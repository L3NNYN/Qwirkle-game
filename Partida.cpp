#include "Partida.h"

Partida::Partida(){
	cantPiezas = 0;
	puntaje = 10;
	primero = actual = NULL;
	
	for(int a = 0; a < FIL; a++){
		for(int b = 0; b < COL; b++){
			Tablero[a][b] = new Mesa(); //Llena la matriz con vacios.
		}
	}
	//Lo inicio acá porque en el método me genera que los dos jugadores tengan el mismo deck.
	srand(time(NULL));
}

void Partida::NombreJugador(){
	string nom;
	cout<<endl;
	cout<<"Inserte su nickname: ";	//Se inserta el nombre deseado en consola.
	cin>>nom;
	Player1.setNombre(nom); //Luego lo configura y limpia la pantalla.
	system("cls");
}

void Partida::setPuntaje(){
	cout<<endl;
	cout<<"Inserte el puntaje minimo para ganar: "; //Toma un entero y lo configura como puntaje minimo para ganar.
	cin>>puntaje;
	system("cls");
}

char* Partida::impPuntaje(){
	stringstream ss;
		ss << puntaje;	//Convierte el int a un char para imprimirlo en pantalla.
		string str = ss.str();
		char* p = strdup(str.c_str());
	return p;
}

char* Partida::impCantPiezas(){
	stringstream ss;
		ss << cantPiezas; //Convierte el int a char para que ver cuantas piezas quedan en la bolsa.
		string str = ss.str();
		char* c = strdup(str.c_str());
	return c;
}

void Partida::llenarTablero(){
	int left = 50; 
	int top = 100;
	int right = 100;
	int bottom = 150;	
	for(int i = 0; i < FIL; i++){
		for(int j = 0; j < COL; j++){
			Tablero[i][j] = new Mesa(NULL, left, top, right, bottom); //Toma las coordenadas y las va sumando necesarias para el constructor.
			left += 50;												//La ficha se deja en NULL.
			right += 50;
		}
		left = 50;
		top += 50; 
		right = 100;
		bottom += 50;		
	}
	pintarTablero();
}

void Partida::pintarTablero(){
	//Se pinta primero el espacio donde va el deck del computador.
	int x1 = 150;
	int	x2 = 200; 
	int y1 = 50;
	int y2 = 100;
	for(int i = 0; i < 6; i++){
			setfillstyle(11, 15);
			setcolor(0);
			bar3d(x1, y1, x2, y2, 0, 0);
			x1 += 50;
			x2 += 50;	
	}
	
	//Luego los cuadros donde deberia ir el deck del jugador.
	x1 = 150;
	x2 = 200; 
	y1 = 550;
	y2 = 600;
	for(int i = 0; i < 6; i++){
			setfillstyle(11, 15);
			setcolor(0);
			bar3d(x1, y1, x2, y2, 0, 0);
			x1 += 50;
			x2 += 50;	
	}
	
	//Luego se recorre la matriz del tablero y va llamando el metodo dibujar.
	for(int i = 0; i < FIL; i++){
		for(int j = 0; j < COL; j++){
			Tablero[i][j]->DibujarTablero();	//Pinta las coordenadas y si hay una ficha tambien.
		}
	}
}

void Partida::deckJugador(){
	Player1.imprimirDeck(); //Imprime el deck en su respectivo espacio.
}

void Partida::cambiarDeck(){
	Pieza * ficha; //se crea un auxiliar
	int cant = Player1.getPiezas(); //se obtiene la cantidad de piezas para el For 
	cout<<"cant: "<<cant<<endl;
	for(int i = 0; i < cant; cant++){
//		ficha = Player1.getFicha(i); //El metodo recibe un auxiliar y recorre la lista cierta cantidad de veces, despues retorna una ficha.
//		Bolsa(ficha); //Se guarda en el auxiliar y se pone de vuelta en la bolsa.
	}
	Player1.~Jugador(); //Asi que se hizo una copia de cada ficha del deck y se inserto en la bolsa se puede borrar todo del deck del jugador.
	RepartirJugador(); //Para despues repartirle piezas nuevas.
}

//En teoria debe repartir una ficha cuando el jugador llama el metodo.
void Partida::unaFicha(){
	int auxP = Player1.getPiezas();
	if(auxP < 6){
		int aux = 0;
		aux = (rand()%50) + 1;	
		actual = primero;
		for(int i = 0; i < aux; i++){ 
			if(actual->getSigNodo() != NULL){
	    	actual = actual->getSigNodo();
			}
	    }
	    Pieza * aux2 = actual->getDato(); 
	    int f = aux2->getFigura();
	    int c = aux2->getIdColor();
		Pieza *ficha = new Pieza(f, c);
		Player1.Deck(ficha);
	    SacarPieza(aux2);
	} else {
		cout<<"Tienes el deck lleno."<<endl;
	}
	deckJugador();
}

//Se sabe que cada ficha posee dos caracteristicas, pero solo puede poser una similar a la adyacente para insertarse.
//Entonces se comprueba similitud con la figura, si no cumple, se comprueba con el color, si ninguno cumple retorna falso.
//Ya que las 4 variables deben estar en verdadero para que retorne true.
//Se comprueba en muchos casos, por ejemplo cuando se quiere poner una ficha en algun borde.

bool Partida::VerificarAdyacencia(int i, int j, Pieza * t){
	//Variables de disponibilidad; l=left, r=right, to=top, b=bottom.
	bool l, r, to, b;
	l = r = to = b = false;
	Pieza * aux, *aux2;
	
	//Se comprueba la fila primero
	if((i > 0) && (i < 8)){
		aux = Tablero[i-1][j]->getFicha();
		aux2 = Tablero[i+1][j]->getFicha();
		
		if((aux == NULL) &&(aux2 == NULL)){
			b = to = true;
		}
		
		//si solo el espacio de arriba es nulo
		if (aux == NULL){
			to = true;
			if(aux2 != NULL){ 
				if((aux2->getIdColor() == t->getIdColor()) && (aux2->getFigura() != t->getFigura())){
					b = true;
				} else {
						if((aux2->getIdColor() != t->getIdColor()) && (aux2->getFigura() == t->getFigura())){
							b = true;
						}
					}
			}
		}
 		
 		//si solo el espacio de abajo es nulo
		if(aux2 == NULL){
			b = true;
			if(aux != NULL){
				if((aux->getIdColor() != t->getIdColor()) && (aux->getFigura() == t->getFigura())){
					to = true;
				} else {
						if((aux->getIdColor() == t->getIdColor()) && (aux->getFigura() != t->getFigura())){
							to = true;
						}
					}
			}
		} 

		//si el espacio de abajo y el de arriba son diferentes de nulos		
		if((aux != NULL) && (aux2 != NULL )){				
			if((aux->getIdColor() == t->getIdColor()) && (aux->getFigura() != t->getFigura())){
				if((aux2->getIdColor() == t->getIdColor()) && (aux2->getFigura() != t->getFigura())){
					b = to = true;
				}
			} else if((aux->getIdColor() != t->getIdColor()) && (aux->getFigura() == t->getFigura())){
					if((aux2->getIdColor() != t->getIdColor()) && (aux2->getFigura() == t->getFigura())){
						b = to = true;
					}
				}
		}	
	//si se encuentra en la primer fila
	} else { 
		if(i == 0){
			to = true;
			aux = Tablero[i+1][j]->getFicha();
			if(aux == NULL){
				b = true;
			} else {
			if((aux->getIdColor() == t->getIdColor())&&(aux->getFigura() != t->getFigura())){
				b = true;
			} else {
					if((aux->getIdColor() != t->getIdColor())&&(aux->getFigura() == t->getFigura())){
						b = true;
					}
				}
			}
		//si se encuentra en la ultima fila	
		} else {
			if(i == 8){
			b = true;
			aux = Tablero[i-1][j]->getFicha();
			if(aux == NULL){
				to = true;
			} else {
			if((aux->getIdColor() == t->getIdColor())&&(aux->getFigura() != t->getFigura())){
				to = true;
			} else {
					if((aux->getIdColor() != t->getIdColor())&&(aux->getFigura() == t->getFigura())){
						to = true;
					}
				}
			}
			}
		}
	}
	
	//Se comprueba la columna
	if((j > 0) && (j < 9)){
		aux = Tablero[i][j+1]->getFicha();
		aux2 = Tablero[i][j-1]->getFicha();
		
		if (aux == NULL){
			r = true;
			if(aux2 != NULL){
				if((aux2->getIdColor() == t->getIdColor())&&(aux2->getFigura() != t->getFigura())){
					l = true;
				} else {
					if((aux2->getIdColor() != t->getIdColor())&&(aux2->getFigura() == t->getFigura())){
						l = true;
					}
				}
			}
		}
		if(aux2 == NULL){
			l = true;
			if(aux != NULL){
				if((aux->getIdColor() == t->getIdColor())&&(aux->getFigura() != t->getFigura())){
					r = true;
				} else {
					if((aux->getIdColor() != t->getIdColor())&&(aux->getFigura() == t->getFigura())){
						r = true;
					}
				}
			}
		}
		
		if((aux != NULL) && (aux2 != NULL )){		
			if((aux->getIdColor() == t->getIdColor()) && (aux->getFigura() != t->getFigura())){
				if((aux2->getIdColor() == t->getIdColor()) && (aux2->getFigura() != t->getFigura())){
					l = r = true;
				}
			} else if((aux->getIdColor() != t->getIdColor()) && (aux->getFigura() == t->getFigura())){
					if((aux2->getIdColor() != t->getIdColor()) && (aux2->getFigura() == t->getFigura())){
						l = r = true;
					}
				}
		}
		
	} else {
		//si se encuentra en la primera columna.
		if(j == 0){
			l = true;
			aux = Tablero[i][j+1]->getFicha();
			if(aux == NULL){
				r = true;
			} else {
				if((aux->getIdColor() == t->getIdColor())&&(aux->getFigura() != t->getFigura())){
					r = true;
				} else {
					if((aux->getIdColor() != t->getIdColor())&&(aux->getFigura() == t->getFigura())){
						r = true;
					}
				}
			}
		} else {
			//si se encuentra en la ultima columna.
			if(j == 9){
			r = true;
			aux = Tablero[i][j-1]->getFicha();
			if(aux == NULL){
				l = true;
			} else {
				if((aux->getIdColor() == t->getIdColor())&&(aux->getFigura() != t->getFigura())){
					l = true;
				} else {
					if((aux->getIdColor() != t->getIdColor())&&(aux->getFigura() == t->getFigura())){
						l = true;
					}
				}
			}
		}
		}
	}
	//Si todas la variables fueron cambiadas a verdadero de retorna verdadero para el respectivo ingreso de la ficha en el tablero
	if((l == true) && (r == true) && (to == true) && (b == true)){
		return true;
	} else {
		system("cls");
		cout<<"Incumple reglas del juego: "<<endl;
			if(l == false){
				cout<<"Izquierda"<<endl;
			}
			if(b == false){
				cout<<"Abajo"<<endl;
			}
			if(to == false){
				cout<<"Arriba"<<endl;
			}
			if(r == false){
				cout<<"Derecha"<<endl;
			}
		return false;
	}
}

//Verifica la filas y columnas en cruz en busqueda de la misma pieza.
bool Partida::VerificarPuntaje(int i, int j, Pieza *p){
	bool auxi, auxj, vacio = true;
	int aux, aux2;
	 aux = aux2 = 0;
	//Se verifica la fila		
	for(int i = 0; i < FIL; i++){
		for (int j = 0; j < COL; j++){
			if(Tablero[i][j]->getFicha() != NULL){ //Primero verifica si el tablero esta vac
				vacio = false;
			}
		}
	}
	
	if( vacio == false){
		for(int a = 0; a < 9; a++){
			cout<<"("<<a<<j<<")";
			if(Tablero[a][j]->getFicha() == p){
				auxi = false; 
			} else if(Tablero [a][j]->getFicha() != NULL){
				aux++;
			}
		}
		//Se verifica la columna en su totalidad
		for(int b = 0; b < 10; b++){
			if(Tablero[i][b]->getFicha() == p){
				auxj = false; 
			} else if(Tablero [i][b]->getFicha() != NULL){
				aux2++;
			}
		}
		
	}
	
	if((auxi == true) && (auxj == true)){
		Player1.setPuntaje(1);
		Player1.setPuntaje(aux + aux2);
		return true;
	} else {
		return false;
	}
}

bool Partida::AgregarPiezaTablero(Pieza *ficha, Pieza* usar, int mx, int my){
	int x1, x2, y1, y2 = 0;
	//Se recorre la matriz hasta que encuentre el elemento con las coordenadas recibidas por parametros.
		for(int i = 0; i < FIL; i++){ 
			for(int j = 0; j < COL; j++){
				if(Tablero[i][j]->getPos(mx, my) == true){ //Metodo que retorna true cuando encuentra el cuadro que se clickeo.
					if(Tablero[i][j]->getFicha() == NULL){ //Comprueba que ninguna pieza este en ese espacio.
						if(VerificarAdyacencia(i, j, usar) == true){ //Si el espacio es vacio se procede a verificar la adyacencia.
							if(VerificarPuntaje(i, i, usar) == true){	//Recorre toda la fila y la columna para sumar puntaje y verificar que no haya ficha igual.
								Tablero[i][j]->setFicha(ficha);	 //Si cumple con todo lo anterior se inserta la ficha en ese espacio.
								system("cls");
								cout<<"Buen movimiento. "<<endl;
								return true;
							} else {
								return false;
							}
						} else { //En caso de que no se pueda.
							setcolor(RED);
							outtextxy(200, 620,"Movimiento invalido."); //Pinta en rojo.
							delay(1000);
							setcolor(0);
							outtextxy(200, 620,"Movimiento invalido."); //Espera un momento y lo sobrepinta en negro para que no se note.
							return false;
						}
					}
					clearmouseclick(WM_LBUTTONDOWN);
				}
			}
		}
		return false;
		clearmouseclick(WM_LBUTTONDOWN);
}

void Partida::LlenarBolsa(){
	Pieza *ficha;
	for(int a = 0; a < 3; a++){
		for(int i = 0; i < 6; i++){
			for(int j = 0; j < 6; j++){
				ficha = new Pieza(i + 1, j + 1); 
				Bolsa(ficha);
				cantPiezas++;
			}
		}
	}
}

//Acontinuacion el metodo que mas caos me ha generado.
void Partida::iniciarPartida(){
	llenarTablero(); //Primero que llena la matriz con las coordenadas para cada cuadro del tablero.
	LlenarBolsa(); //Genera y ingresa en la bolsa las 36 fichas diferentes que deben haber, esto lo hace 3 veces.
	RepartirJugador(); //Reparte las fichas al jugador.
	RepartirComp(); //Reparte las fichas a la computadora.
	pintarTablero(); //Pinta la matriz de objetos.
	deckJugador();	//Pinta el deck del jugador.
	int mx, my; //Esto guarda los clicks del deck y el tablero para compararlos y asi proceder.
	mx = my = 0; 
	int aux = 7;
	do{		
	
			//Basicamente son unos botones, similares a los del menu, cada boton tiene una condicion y que pasa si no se cumple esa condicion.
			//La condicion es que el mouse debe estar sobre las coordenadas que determinan el boton.
			//Si esa condicion no se cumple simplemente pintara un cuadro, esto me permite que cuando me sobre él, pueda cambiar de color.
			//Entonces pinta lo mismo que en "else" pero con diferente color, para que se vea más porte.
			Pieza * ficha, *usarDeck; //Y dos auxliliares tipo pieza.
			int f, c = 0; //Se determinan auxiliares para la creacion de una nueva pieza.
			
			setcolor(LIGHTCYAN);
			settextstyle(3, 0, 2);
			rectangle(590, 100, 770, 170);
			outtextxy(600, 105,"Piezas en bolsa: ");
			outtextxy(742, 105, impCantPiezas());
			outtextxy(600, 140,"Puntos de gane: ");
			outtextxy(742, 140, impPuntaje());
			
			//puntaje
			setcolor(9);
			rectangle(590, 172, 770, 240);
			outtextxy(600, 180,"Computadora");
			outtextxy(740, 180, Comp.impPuntaje());
			Player1.imprimirNombre();
			outtextxy(740, 205, Player1.impPuntaje());
			
		if((mousex()>590)&&(mousex()<770)&&(mousey()>250)&&(mousey()<300)){	
			setcolor(YELLOW);
			settextstyle(3, 0, 2);
			outtextxy(610, 260,"Cambiar fichas");
			rectangle(590, 250, 770, 300);
		}
		else {
			setcolor(LIGHTGREEN);
			rectangle(590, 250, 770, 300);
			settextstyle(3, 0, 2);
			outtextxy(610, 260,"Cambiar fichas");
		}
		
		if((mx>590)&&(mx<770)&&(my>250)&&(my<300)){
				cambiarDeck();
				deckJugador();
		}
		
		if((mousex()>590)&&(mousex()<770)&&(mousey()>310)&&(mousey()<360)){	
			setcolor(YELLOW);
			settextstyle(3, 0, 2);
			outtextxy(610, 320,"Guardar partida");
			rectangle(590, 310, 770, 360);
		}
		else {
			setcolor(CYAN);
			rectangle(590, 310, 770, 360);
			settextstyle(3, 0, 2);
			outtextxy(610, 320,"Guardar partida");
		}
		
		if((mousex()>590)&&(mousex()<770)&&(mousey()>370)&&(mousey()<420)){		
			setcolor(YELLOW);
			settextstyle(3, 0, 2);
			outtextxy(630, 380,"Una ficha");
			rectangle(590, 370, 770, 420);
		}
		else {
			setcolor(LIGHTGREEN);
			rectangle(590, 370, 770, 420);
			settextstyle(3, 0, 2);
			outtextxy(630, 380,"Una ficha");
		}
		
		if((mx>590)&&(mx<770)&&(my>370)&&(my<420)){
			unaFicha();
		}
		
//		ficha = usarDeck = NULL;
		getmouseclick(WM_LBUTTONDOWN, mx, my);
		if((mx>150)&&(mx<450)&&(my>550)&&(my<600)){
			if((mx>150)&&(mx<200)){
				aux = 0;
			} else if((mx>200)&&(mx<250)){
				aux = 1;
			} else if ((mx>250)&&(mx<300)){
				aux = 2;
			} else if ((mx>300)&&(mx<350)){
				aux = 3;
			} else if ((mx>350)&&(mx<400)){
				aux = 4;
			} else if ((mx>400)&&(mx<450)){
				aux = 5;
			} else if ((mx>450)&&(mx<500)){
				aux = 6;
			} else {
					
			}
			int aux2 = Player1.getPiezas();
			if(aux < aux2){	
					if(Player1.getFicha(aux) != NULL){
						ficha = Player1.getFicha(aux);
						usarDeck = ficha;
						f = ficha->getFigura();
						c = ficha->getIdColor();
						ficha = new Pieza(f, c);
						aux = 7;
						f = c = 0;
						cout<<"------ "<<mx<<"/"<<my<<endl;
					} else{
						mx = my = 0;
						}
			}
			clearmouseclick(WM_LBUTTONDOWN);
			
		} else if ((mx>50)&&(mx<550)&&(my>100)&&(my<550)){
			cout<<"------ "<<mx<<"/"<<my<<endl;
			if(aux == 7){
				if(AgregarPiezaTablero(ficha, usarDeck, mx, my) == true){
					pintarTablero();
					Player1.usarPieza(usarDeck, aux);
					deckJugador();
					ficha = new Pieza();
					clearmouseclick(WM_LBUTTONDOWN);
					aux = 0;
				}
				clearmouseclick(WM_LBUTTONDOWN);
				} else {
					mx = my = 0;
				}

			} else {
				if((mx>0)&&(mx<900)&&(my>0)&&(my<700))
				cout<<"------ "<<mx<<"/"<<my<<endl;
			}	
			
			
		ganador(); //Y por ultimo se verifica todo el tiempo si ya hay un ganador.
	} while (not(kbhit()));
}


//verifica si ya alguno alcanzo el puntaje para ganar.
void Partida::ganador(){
	//se guardan los puntajes de ambos jugador en dos enteros
	int p1 = Player1.getPuntaje();
	int p2 = Comp.getPuntaje();
	bool p = true;
	
	//Y si alguno ta lo supero o alcanzo se imprime en pantalla
	if(p1 >= puntaje){
		cout<<"HAS GANADO"<<endl;
		while(p == true){	
			for(int i = 0; i <= 15; i++){
				setcolor(i);
				settextstyle(4, 0, 2);
				outtextxy(600, 525,"¡HAS GANADO!");
				delay(500);
			}		
		}
	} else {
		if(p2 >= puntaje){
			cout<<"La computadora ha ganado."<<endl;
			while(p == true){	
				for(int i = 0; i <= 15; i++){
					setcolor(i);
					settextstyle(4, 0, 2);
					outtextxy(600, 525,"LA COMP HA GANADO");
					delay(500);
				}		
			}
		}
	}
	
}

//Este metodo es el que recibe y acomoda las fichas en los nodos, no tiene mucho de interesante pero si es importante.
void Partida::Bolsa(Pieza * ficha){
	if(primero == NULL){
		primero = new Nodo(ficha, NULL);
	} else {
		actual = primero;
		while(actual->getSigNodo() != NULL){
			actual = actual->getSigNodo();
		}
		actual->setSigNodo(new Nodo(ficha, NULL));
	}
}

//Ya que soy un inutil y no logre hacer un sólo método para ambos, tuve que hacer uno de repartir para cada uno.
//Intente hacer por referencia, de que reciba la direccion del objeto y lo modifique a partir de ahi como me aconsejo.
//Entonces ejemplo llame Repartir(&Comp) y el metodo recibia un puntero en teoría, pero siguio dandome error y no entendia bien porque.
//Obvio hubiese sido mas eficiente hacerlo de esa manera (de hecho lo habia hecho asi) peeero no me servia, asi que tuve que hacerlo de esta otra manera.

//Reparte fichas al jugador principal
void Partida::RepartirJugador(){
	for(int i = 0; i < 6; i++){
		int aux = 0;
		aux = (rand()%50) + 1;	
		actual = primero;
		for(int i = 0; i < aux; i++){ 
			if(actual->getSigNodo() != NULL){
	    	actual = actual->getSigNodo();
			}
	    }
	    Pieza * aux2 = actual->getDato(); 
	    int f = aux2->getFigura();
	    int c = aux2->getIdColor();
		Pieza *ficha = new Pieza(f, c);
		Player1.Deck(ficha);
	    SacarPieza(aux2);
	}
	
}

//Reparte fichas a la computadora.
void Partida::RepartirComp(){
	for(int i = 0; i < 6; i++){
		int aux = 0;
		aux = (rand()%50) + 1;	
		actual = primero;
		for(int i = 0; i < aux; i++){ 
			if(actual->getSigNodo() != NULL){
	    	actual = actual->getSigNodo();
			}
	    }
	    Pieza * aux2 = actual->getDato(); 
	    int f = aux2->getFigura();
	    int c = aux2->getIdColor();
		Pieza *ficha = new Pieza(f, c);
		Comp.Deck(ficha);
	    SacarPieza(aux2);
	}
}

//Recibe una pieza y la borra de la bolsa cuando la encuenta.
void Partida::SacarPieza(Pieza * borrar){
	if(primero != NULL){
		actual = primero;
		Nodo * anterior = NULL; 
		while((actual != NULL) && (actual->getDato() != borrar)){ //Mientras sea diferente de nulo y no sea la pieza que se busca, sigue avanzando.
			anterior = actual;
			actual = actual->getSigNodo();
		} 
		anterior->setSigNodo(actual->getSigNodo());
		delete actual;
		cantPiezas--;
	}
}

//Imprime todas las piezas que tiene en los nodos (en la consola).
void Partida::impPiezas(){
	actual = primero;
	while(actual != NULL){
		cout<<actual->toString()<<endl;
		actual = actual->getSigNodo();
	}
}
