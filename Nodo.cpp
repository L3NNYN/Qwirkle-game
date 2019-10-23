#include "Nodo.h"

Nodo::Nodo(Pieza * qwirkle, Nodo *sig){
	this->qwirkle = qwirkle;
	this->sig  = sig;
}

Nodo::~Nodo(){
	delete qwirkle;
}

void Nodo::setDato(Pieza *){
	this->qwirkle = qwirkle;
}

Pieza * Nodo::getDato(){
	return qwirkle;
}

void Nodo::setSigNodo(Nodo *sig){
	this->sig = sig;
}

Nodo * Nodo::getSigNodo(){
	return sig;
}

string Nodo::toString(){
	stringstream s;
	s<<getDato()->toString()<<endl;
	
	return s.str();
}
