/*
 * Televisor.cpp
 *
 *  Created on: 26 ene. 2021
 *      Author: mariscal
 */

#include "Televisor.h"

Televisor::Televisor() {
    //ToDo constructor por defecto
	
}

Televisor::Televisor(string marca, string modelo, int canal, int volumen, bool estado){
	//ToDo constructor parametrizado
}


int Televisor::getCanal()  {
    //ToDo devuelve el atributo canal
	
}

void Televisor::setCanal(int canal) {
	//ToDo guarda el valor del parametro de entrada en el atributo canal
}

int Televisor::getEstado()  {
    //ToDo devuelve el atributo estado
	
}

void Televisor::setEstado(int estado) {
	//ToDo guarda el valor del parametro de entrada en el atributo estado
}

const string Televisor::getMarca()  {
	//ToDo devuelve el atributo marca
}

void Televisor::setMarca( string marca) {
	//ToDo guarda el valor del parametro de entrada en el atributo marca
}

const string Televisor::getModelo()  {
	//ToDo devuelve el atributo modelo
}

void Televisor::setModelo(string modelo) {
	//ToDo guarda el valor del parametro de entrada en el atributo modelo
}

int Televisor::getVolumen()  {
	//ToDo devuelve el atributo volumen
}

void Televisor::setVolumen(int volumen) {
	//ToDo guarda el valor del parametro de entrada en el atributo volumen
}


bool Televisor::subirVolumne() {
    //ToDo aumentar el volumen en 1 si no está al máximo
    //Devuelve true si se puede subir el volumen, si no se puede devuelve false
	
}

bool Televisor::bajarVolumen() {
	//ToDo disminuir el volumen en 1 si no está al mínimo
    //Devuelve true si se puede bajar el volumen, si no se puede devuelve false
}



void Televisor::cambioCanal(int canal) {
	//ToDo guarda el valor del parametro de entrada en el atributo canal
}

bool Televisor::subirCanal() {
    //ToDo aumentar el canal en 1 si no está al máximo
    //Devuelve true si se puede subir el canal, si no se puede devuelve false

}

bool Televisor::bajarCanal() {
	//ToDo disminuir el canal en 1 si no está al mínimo
    //Devuelve true si se puede bajar el canal, si no se puede devuelve false
}

void Televisor::apagarTelevisor(){
	// TODO false-->estado para apagar
	
}
void Televisor::encenderTelevisor() {
	// TODO true-->estado para encender
	
}

Televisor::~Televisor() {
	// TODO Auto-generated destructor stub
}