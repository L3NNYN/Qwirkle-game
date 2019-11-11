#ifndef NODO_H
#define NODO_H
#include <sstream>
#include "Pieza.h"

//Lista simplemente enlazada.
//Creo que esto se puede obviar ya que es igual a su ejemplo subido al aula virtual.

class Nodo
{	
	private:
		Pieza * qwirkle;
		Nodo *sig;
	public:
		Nodo(Pieza *, Nodo *);
//		Nodo ()
		~Nodo();
		void setDato(Pieza *);
		Pieza * getDato();
		void setSigNodo(Nodo *sig);
		Nodo * getSigNodo();
		string toString();
};

#endif
