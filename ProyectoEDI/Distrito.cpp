/*
 * Distrito.cpp
 *
 *  TFG Example
 *  Author: GMCarlos_8
 */

#include "Distrito.h"

using namespace std;

Distrito::Distrito() {
	nombreDistrito = " ";

}

Distrito::Distrito(string nombreD){
	this->nombreDistrito = nombreD;
}

Distrito::Distrito(const Distrito &D){
	cout << "Ejecutandose constructor por copia" << endl;
	this->nombreDistrito = D.nombreDistrito;
}

string Distrito::getDistrito(){
	return this->nombreDistrito;
}

void Distrito::setDistrito(string distrito){
	this->nombreDistrito = distrito;
}

void Distrito::mostrar(){
	cout << "Nombre distrito: " << this->getDistrito()<< endl;
}

bool Distrito::empiezaPor (string str, string substr) {
	bool comienza = false;
	if (str.find(substr) == 0)
		comienza =  true;

	return comienza;
}

void Distrito::operator =(const Distrito &D){
	this->nombreDistrito = D.nombreDistrito;

}

bool Distrito::operator == (const Distrito &D){
	return (this->nombreDistrito == D.nombreDistrito);
}

Distrito::~Distrito() {

}
