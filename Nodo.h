#ifndef NODO_H
#define NODO_H
#include "Pieza.h"

class Nodo
{	
	private:
		Pieza * qwirkle;
		Nodo *sig;
	public:
		Nodo(Pieza *, Nodo *);
		~Nodo();
		void setDato(Pieza *);
		Pieza * getDato();
		void setSigNodo(Nodo *sig);
		Nodo * getSigNodo();
		string toString();
};

#endif
