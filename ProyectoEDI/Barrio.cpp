/*
 * Barrio.cpp
 *
 *  TFG Example
 *      Author: GMCarlos_8
 */

#include "Barrio.h"

using namespace std;

Barrio::Barrio() {
	nombre = " ";
	perteneceDistrito = NULL;
	//cout << "Se esta ejecutando el constructor default de barrio" << endl;
}

Barrio::Barrio(string nombre, Distrito *distrito){
	this->nombre = nombre;
	this->perteneceDistrito = distrito;
}

Barrio::Barrio (const Barrio &B){
	cout << "Ejecutandose constructor por copia" << endl;
	this->nombre = B.nombre;
	this->perteneceDistrito = B.perteneceDistrito;
}

string Barrio::getBarrio(){
	return this->nombre;
}

void Barrio::getDistrito(Distrito *&d){
	d = this->perteneceDistrito;

}

void Barrio::getBarrio(string &nombreB){
	nombreB = nombre;
}


void Barrio::setBarrio(string barrio){
	nombre = barrio;
}

void Barrio::setDistrito(Distrito *d){
	this->perteneceDistrito = d;
}

void Barrio::mostrar(){
	if (perteneceDistrito != NULL){
		cout << "Nombre barrio: " << this->getBarrio() << endl;
		cout << "Distrito: " << perteneceDistrito->getDistrito() << endl;
	}
	else{
		cout << "Nombre barrio: " << this->getBarrio() << endl;
	}
}

void Barrio::operator =(const Barrio &B){
	this->nombre = B.nombre;
	*this->perteneceDistrito = *B.perteneceDistrito;
}

bool Barrio::operator == (const Barrio &B){
	// return (this->nombre == B.nombre); // otra posible implementacion
	bool iguales = false;
	if ( nombre == B.nombre)
		iguales = true;
	return iguales;
}

//void pruebasBarrioE(){
//
//	Barrio b1;
//	string nombreB;
//
//	Barrio b("San Blas","Sur");
//	b1.setBarrio("Moctezuma");
//	b1.setDistrito("Oeste");
//	cout << "BARRIO: " << b1.getBarrio() << endl;
//	cout << "DISTRITO: " << b1.getDistrito() << endl;
//
//	b1.getBarrio(nombreB);
//	cout << "Otra forma: "<< nombreB << endl;
//}

//void pruebasBarrioD(){
//
//	Barrio *b2;
//	b2 = new Barrio();
//	Barrio *b3;
//	b3 = new Barrio("Aldea Moret", "Norte");
//	b2->setBarrio("Mejostilla");
//	b2->setDistrito("Norte");
//
//	cout << "BARRIO: " << b2->getBarrio() << endl;
//	cout << "DISTRITO: " << b2->getDistrito() << endl;
//	delete b2;
//	delete b3;
//}

Barrio::~Barrio() {
	//cout << "Se va a ejecutar el destructor de la clase..." << endl;
}

