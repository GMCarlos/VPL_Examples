/*
 * Televisor.cpp
 *
 *  Created on: 26 ene. 2021
 *      Author: mariscal
 */

#include "Televisor.h"

Televisor::Televisor() {
	marca  = "";
	modelo = "";
	canal = 0;
	volumen = 0;
	estado = false;
}

Televisor::Televisor(string marca, string modelo, int canal, int volumen, bool estado){
	this->marca  = marca;
	this->modelo = modelo;
	this->canal = canal;
	this->volumen = volumen;
	this->estado = estado;
}


int Televisor::getCanal()  {
	return canal;
}

void Televisor::setCanal(int canal) {
	this->canal = canal;
}

int Televisor::getEstado()  {
	return estado;
}

void Televisor::setEstado(int estado) {
	this->estado = estado;
}

const string Televisor::getMarca()  {
	return marca;
}

void Televisor::setMarca( string marca) {
	this->marca = marca;
}

const string Televisor::getModelo()  {
	return modelo;
}

void Televisor::setModelo( string modelo) {
	this->modelo = modelo;
}

int Televisor::getVolumen()  {
	return volumen;
}

void Televisor::setVolumen(int volumen) {
	this->volumen = volumen;
}


bool Televisor::subirVolumne() {
	bool sePuede = false;
	if (volumen < MAXVOLUMEN){
		volumen++;
		sePuede = true;
	}
	return sePuede;
}

bool Televisor::bajarVolumen() {
	bool sePuede = false;
	if (volumen > 0){
		volumen--;
		sePuede = true;
	}
	return sePuede;
}



void Televisor::cambioCanal(int canal) {
	this->canal = canal;
}

bool Televisor::subirCanal() {
	bool sePuede = false;
	if (canal < MAXCANAL){
		canal++;
		sePuede = true;
	}
	return sePuede;
}

bool Televisor::bajarCanal() {
	bool sePuede = false;
	if (canal >  0){
		canal--;
		sePuede = true;
	}
	return sePuede;
}

void Televisor::apagarTelevisor(){
	// TODO false-->estado para apagar
	this->estado=false;
}
void Televisor::encenderTelevisor() {
	// TODO true-->estado para encender
	this->estado=true;
}

Televisor::~Televisor() {
	// TODO Auto-generated destructor stub
}
