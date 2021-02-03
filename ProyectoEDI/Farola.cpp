/*
 * Farola.cpp
 *
 *  TFG Example
 *  Author: GMCarlos_8
 */

#include "Farola.h"

using namespace std;

Farola::Farola() {
	funcionamiento = " ";
	proteccion = " ";
	tipoLuz = " ";
	materialS = " ";
	localizacion = NULL;
	potencia = 0;
	tipoLampara = " ";
	altura = 0;
	tipoSoporte = " ";
	circuitos = 0;
	materialL = " ";
	perteneceVia = NULL;

}

Farola::Farola(string fun, string protec, string tipoL, string _materialS, float latitud, int pot, float longitud, string tLampara,
			int _altura, string tSoporte, int _circuitos, string _materialL, Via *via){

	this->funcionamiento = fun;
	this->proteccion = protec;
	this->tipoLuz = tipoL;
	this->materialS = _materialS;
	this->localizacion= new Coords(latitud,longitud);
	this->potencia = pot;
	this->tipoLampara = tLampara;
	this->altura = _altura;
	this->tipoSoporte = tSoporte;
	this->circuitos = _circuitos;
	this->materialL = _materialL;
	this->perteneceVia = via;

}

int Farola::getAltura(){
	return this->altura;
}

int Farola::getCircuitos(){
	return this->circuitos;
}

int Farola::getPotencia(){
	return this->potencia;
}

string Farola::getFuncionamiento(){
	return this->funcionamiento;
}

string Farola::getMaterialL(){
	return this->materialL;
}

string Farola::getMaterialS(){
	return this->materialS;
}

string Farola::getProteccion(){
	return this->proteccion;
}

string Farola::getTipoLampara(){
	return this->tipoLampara;
}

string Farola::getTipoLuz(){
	return this->tipoLuz;
}

string Farola::getTipoSoporte(){
	return this->tipoSoporte;
}

void Farola::getVia(Via *&v){
	v = this->perteneceVia;
}

void Farola::getLocalizacion(Coords *&c){
	c = this->localizacion;
}

void Farola::setVia(Via *v){
	this->perteneceVia = v;
}

bool Farola::estaEnVia(string nVia){ // TODO
	bool enc = false;

	return enc;
}

void Farola::mostrar(){
	if (perteneceVia != NULL){
//		cout << "Funcionamiento: " << this->funcionamiento << endl;
//		cout << "Protección: " << this->proteccion << endl;
//		cout << "Tipo de luz: " << this->tipoLuz << endl;
//		cout << "Material S: " << this->materialS << endl;
//		cout << "Potencia: " << this->potencia << endl;
//		cout << "Tipo de lámpara: " << this->tipoLampara << endl;
//		cout << "Altura: " << this->altura << endl;
//		cout << "Soporte: " << this->tipoSoporte << endl;
//		cout << "Circuitos: " << this->circuitos << endl;
//		cout << "Material L: " << this->materialL << endl;
		cout << "Via: " << this->perteneceVia->getNombre() << endl;
	}
	else{
		cout << "Funcionamiento: " << this->funcionamiento << endl;
		cout << "Protección: " << this->proteccion << endl;
		cout << "Tipo de luz: " << this->tipoLuz << endl;
		cout << "Material S: " << this->materialS << endl;
		cout << "Potencia: " << this->potencia << endl;
		cout << "Tipo de lámpara: " << this->tipoLampara << endl;
		cout << "Altura: " << this->altura << endl;
		cout << "Soporte: " << this->tipoSoporte << endl;
		cout << "Circuitos: " << this->circuitos << endl;
		cout << "Material L: " << this->materialL << endl;
	}
}


Farola::~Farola() {

}


