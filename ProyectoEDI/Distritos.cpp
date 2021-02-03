/*
 * Distritos.cpp
 *
 *  TFG Example
 *  Author: GMCarlos_8
 */


#include <cstdlib>
#include <fstream>

#include "Distritos.h"
using namespace std;

Distritos::Distritos() {
	lDistritos = new ListaPI<Distrito *>();
}

bool Distritos::buscar (string nombreDistrito, Distrito *&d){

	Distrito *dAux;
	bool enc = false;
	lDistritos->moverInicio();
	while(!lDistritos->finLista() && !enc){
		lDistritos->consultar(dAux);
		if(dAux->getDistrito() == nombreDistrito){
			enc = true;
			d= dAux;
		}
		lDistritos->avanzar();
	}
	return enc;
}



void Distritos::insertarDistritoFinal(Distrito *D){
	lDistritos->moverFinal();
	lDistritos->avanzar();
	lDistritos->insertar(D);
}

void Distritos::insertarDistritoOrden(Distrito *D){
	bool enc=false;
	Distrito *daux;
	if(!this->lDistritos->estaVacia()){
		this->lDistritos->moverInicio();
		while(!this->lDistritos->finLista()&&!enc){
			this->lDistritos->consultar(daux);
			if(daux->getDistrito() > D->getDistrito())
				enc=true;
			else
				lDistritos->avanzar();
		}
	}
	lDistritos->insertar(D);
}

void Distritos::devolverListaDistritos(ListaPI<Distrito *> *&lD){

	Distrito *d;

	lDistritos->moverInicio();
	lD->moverInicio();
	while (!lDistritos->finLista()) {
		lDistritos->consultar(d);
		lD->insertar(d);
		lD->avanzar();

		lDistritos->avanzar();
	}

}

void Distritos::mostrar(){
	Distrito *D;
	lDistritos->moverInicio();
	while(!lDistritos->finLista()){
		lDistritos->consultar(D);
		//cout << "Info Distritos: " << endl;
		D->mostrar();
		lDistritos->avanzar();
	}
}

Distritos::~Distritos() {
	Distrito *D;
	lDistritos->moverInicio();
	while(!lDistritos->finLista()){
		lDistritos->consultar(D);
		delete D;
		lDistritos->borrar();
	}
	lDistritos = NULL;
}





