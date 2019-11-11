#include "Jugador.h"

Jugador::Jugador(){
	piezas = 0;
	nombre = "Sin definir";
	puntaje = 0;
	primero = actual = NULL;
}

Jugador::~Jugador(){
	while (primero != NULL ){
		actual = primero;
		primero = primero->getSigNodo();
		delete actual;
	}
	piezas = 0;
}

int Jugador::getPiezas(){
	return piezas; //retorna la cantidad de piezas en el deck.
}

void Jugador::setPuntaje(int npuntaje){
	puntaje += npuntaje; //Recibe puntaje y lo suma al anterior.
}

int Jugador::getPuntaje(){
	return puntaje; //Retorna el puntaje.
}

char* Jugador::impPuntaje(){
	stringstream ss; //Funcion que convierte el puntaje de tipo entero a un char.
		ss << puntaje; //Necesario para imprimirlo en la pantalla.
		string str = ss.str();
		char* p = strdup(str.c_str());
	return p;
}

void Jugador::setNombre(string nombre){
	this->nombre = nombre;
}

string Jugador::getNombre(){
	return nombre;
}


//Recibe una ficha con el axuliar.
//El auxiliar se define segun las coordenadas en las que di click.
//El auxiliar hace que se recorra la lista hasta que se de con la pieza elegida.
Pieza *Jugador::getFicha(int aux){
	Pieza * p;
	int i = 0;
	actual = primero;
	if(aux == 0){ //Si el aux es igual a 0 se retorna el primer elemento.
		p = primero->getDato();
		return primero->getDato();
	}
	while(i < aux){
		actual = actual->getSigNodo(); //Se recorre mientras i sea menor al aux
		i++;
	}
	p = actual->getDato();
	return p;
}

void Jugador::borrarPrimeraPieza(){
	actual = primero;
	if (primero != NULL) {
		primero = actual->getSigNodo();
		delete actual;
	}
}

void Jugador::borrarUltimaPieza(){
	actual = primero;
	Nodo *anterior = actual;
	if (primero != NULL ){
		if (primero->getSigNodo()==NULL ) {
			delete primero;
			primero = NULL; 
		}
		else {
			while (actual->getSigNodo() != NULL ) {
				anterior = actual;
				actual = actual->getSigNodo();
			}
			anterior->setSigNodo(NULL );
			delete actual;
		}
	}
}

void Jugador::Deck(Pieza * ficha){
	if(primero == NULL){
		primero = new Nodo(ficha, NULL);
	} else {
		actual = primero;
		while(actual->getSigNodo() != NULL){
			actual = actual->getSigNodo();
		}
		actual->setSigNodo(new Nodo (ficha, NULL));
	}
		piezas++;
}

void Jugador::imprimirDeck(){
	setcolor(15);
	settextstyle(3, 0, 2);
	outtextxy(50, 550, "Tu deck: ");
	
	//Se establecen las coordenadas que en las que se van a pintar las piezas.
	int x1 = 150;
	int	x2 = 200; 
	int y1 = 550;
	int y2 = 600;
	
	actual = primero;
	
	if(piezas != 0){
		for(int i = 0; i < piezas; i++){
			if(actual == NULL){
				setfillstyle(11, 15);
				setcolor(0);
				bar3d(x1, y1, x2, y2, 0, 0);
				actual = actual->getSigNodo();
			} else {
				Pieza * ficha = actual->getDato();
				setfillstyle(1, 0); //Dibuja el fondo de la figura.
				setcolor(0);
				bar3d(x1, y1, x2, y2, 0, 0);
				int auxColor = ficha->getAux(); //Recibe el color para usarlo en la figura.
				setcolor(auxColor);
				setfillstyle(1, auxColor);
				int x3 = (x1 + x2)/2;
				int y3 = (y1 + y2)/2;
				ficha->DibujarPieza(x3, y3); //Luego dibuja la figura.
			}
			actual = actual->getSigNodo(); //Luego procede a pintar el siguiente.
			x1 += 50;	//Luego procede setear las siguientes coordenadas.
			x2 += 50;
		}
	}
}

void Jugador::imprimirNombre(){
	setcolor(9); 
	settextstyle(3, 0, 2);
	string str = nombre; 
	char* chr = strdup(str.c_str()); //funcion que convierte un string a char.
	outtextxy(600, 205, chr); //Ya que solo puede imprimirse en la pantalla grafica con un char.
}

void Jugador::usarPieza(Pieza *borrar, int aux){
	int aux2 = 0;
	if(primero != NULL){
		actual = primero;
		Nodo * anterior = NULL; //Necesario un auxiliar para guardar el nodo anterior.
		while((actual != NULL) && (actual->getDato() != borrar)){ 	//Recorre hasta que actual sea igual a la pieza recibida por parametros.
			anterior = actual;
			actual = actual->getSigNodo();
			aux2++;
		} 
		
		anterior->setSigNodo(actual->getSigNodo()); //Crea un tipo de puente que conecta el nodo anterior al que apunta el actual.
		delete actual;	//Luego borra el actual.
		piezas--;
	}
}


void Jugador::toString(){
	actual = primero;
	while(actual != NULL){
		cout<<actual->toString()<<endl;
		actual = actual->getSigNodo();
	}
}
