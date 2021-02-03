/*
 * Barrios.cpp
 *
 *  TFG Example
 *  Author: GMCarlos_8
 */

#include "Barrios.h"

using namespace std;

Barrios::Barrios() {
	lBarrios = new ListaPI<Barrio *>();

}

void Barrios::insertarBarrioFinal(Barrio *B){
	lBarrios->moverFinal();
	lBarrios->avanzar();
	lBarrios->insertar(B);
}

void Barrios::insertarBarrioOrden(Barrio *B){
	bool enc=false;
	Barrio *baux;
	if(!this->lBarrios->estaVacia()){
		this->lBarrios->moverInicio();
		while(!this->lBarrios->finLista()&&!enc){
			this->lBarrios->consultar(baux);
			if(baux->getBarrio() > B->getBarrio())
				enc=true;
			else
				lBarrios->avanzar();
		}
	}
	lBarrios->insertar(B);
}

void Barrios::mostrarBarrios(){
	Barrio *B;
	lBarrios->moverInicio();
	while(!lBarrios->finLista()){
		lBarrios->consultar(B);
		cout << "Información barrio: " << endl;
		B->mostrar();
		lBarrios->avanzar();
	}
}

bool Barrios::buscar(string nBarrio, Barrio *&B){
	Barrio *bAux;
	bool enc = false;
	lBarrios->moverInicio();
	while(!lBarrios->finLista() && !enc){
		lBarrios->consultar(bAux);
		if(bAux->getBarrio() == nBarrio){
			enc = true;
			B = bAux;
		}
		lBarrios->avanzar();
	}
	return enc;
}

bool Barrios::buscarBarrio(string nBarrio){
	Barrio *bAux;
	bool enc = false;
	lBarrios->moverInicio();
	while(!lBarrios->finLista() && !enc){
		lBarrios->consultar(bAux);
		if(bAux->getBarrio() == nBarrio)
			enc = true;
		else
			lBarrios->avanzar();
		}
	return enc;

}

void Barrios::devolverListaBarrio(ListaPI<Barrio *> *&lBarrio) {

	Barrio *b;

	lBarrios->moverInicio();
	lBarrio->moverInicio();
	while (!lBarrios->finLista()) {
		lBarrios->consultar(b);
		lBarrio->insertar(b);
		lBarrio->avanzar();

		lBarrios->avanzar();
	}

}

void Barrios::devolverListaBarriosDistrito(ListaPI<Barrio *> *&lBarrio, string distrito) {
	Barrio *b;
	Distrito *d;

	lBarrios->moverInicio();
	while (!lBarrios->finLista()) {
		lBarrios->consultar(b);
		b->getDistrito(d);
		if (d->getDistrito() == distrito) {
			lBarrio->insertar(b);
		}
		lBarrios->avanzar();
	}

}



Barrios::~Barrios() {
	Barrio *B;
	lBarrios->moverInicio();
	while(!lBarrios->finLista()){
		lBarrios->consultar(B);
		delete B;
		lBarrios->borrar();
	}
	lBarrios = NULL;
}

