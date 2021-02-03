/*
 * Calles.cpp
 *
 *  TFG Example
 *  Author: GMCarlos_8
 */

#include "Calles.h"

using namespace std;

Calles::Calles() {
	lVias = new ListaPI<Via *>();
	lFarolas = new ListaPI<Farola *>();
	aVias = new Arbol<Via *,ComparaPtrVias>();

}

void Calles::insertarViaFinal(Via *V){
	lVias->moverFinal();
	lVias->avanzar();
	lVias->insertar(V);
}

void Calles::insertarFarolaFinal(Farola *F){
	lFarolas->moverFinal();
	lFarolas->avanzar();
	lFarolas->insertar(F);
}

void Calles::insertarViaOrden(Via *V){
	bool enc=false;
	Via *vaux;
	if(!this->lVias->estaVacia()){
		this->lVias->moverInicio();
		while(!this->lVias->finLista()&&!enc){
			this->lVias->consultar(vaux);
			if(vaux->getNombre() > V->getNombre())
				enc=true;
			else
				lVias->avanzar();
		}
	}
	lVias->insertar(V);
}

void Calles::insertarViaArbol(Via *&V){
	this->aVias->insertar(V);

}

void Calles::mostrarVias(){
	Via *V;
	//int cont=0;
	lVias->moverInicio();
	while(!lVias->finLista()){
		lVias->consultar(V);
		cout << "Información de vía: " << endl;
		V->mostrar();
		lVias->avanzar();
		//cont++;
	}
	//cout<<"Contador: "<<cont<<endl;
}

void Calles::mostrarInOrden(Arbol <Via*, ComparaPtrVias> *arb){
	Arbol <Via*, ComparaPtrVias> *aux;
	Via *v;
	if(!arb->vacio()){
		aux = arb->hijoIzq();
		if (aux != NULL){
			mostrarInOrden(aux);
		}
		v = arb->raiz();
		v->mostrar();

		aux = arb->hijoDer();
		if(aux != NULL){
			mostrarInOrden(aux);
		}
	}
}

void Calles::mostrarViasArbol(){
	mostrarInOrden(this->aVias);
}

void Calles::mostrarFarolas(){
	Farola *F;
	//int cont=0;
	lFarolas->moverInicio();
	while(!lFarolas->finLista()){
		lFarolas->consultar(F);
		cout << "Información de farola: " << endl;
		F->mostrar();
		lFarolas->avanzar();
		//cont++;
	}
	//cout<<"Contador: "<<cont<<endl;
}

void Calles::mostrarViasBarrio(string nBarrio){
	Via *V;
	lVias->moverInicio();
	while(!lVias->finLista()){
		lVias->consultar(V);
		if(V->estaEnBarrio(nBarrio)){
			V->mostrar();
		}
		lVias->avanzar();
	}
}

bool Calles::buscarVia(string nVia, Via *&V){
	Via *Vaux;
	bool enc = false;
	lVias->moverInicio();
	while(!lVias->finLista() && !enc){
		lVias->consultar(Vaux);
		if(Vaux->getNombre() == nVia ){
			enc = true;
			V=Vaux;
		}
		lVias->avanzar();
	}
	return enc;
}

bool Calles::buscarNombreVia(string nVia){
	Via *Vaux;
	bool enc = false;
	lVias->moverInicio();
	while(!lVias->finLista() && !enc){
		lVias->consultar(Vaux);
		if(Vaux->getNombre() == nVia ){
			enc = true;

		}
		lVias->avanzar();
	}
	return enc;
}

bool Calles::buscarNombreLista(string nVia, ListaPI <Via *> *lista){
	Via *Vaux;
	bool enc = false;
	lista->moverInicio();
	while(!lista->finLista() && !enc){
		lista->consultar(Vaux);
		if(Vaux->getNombre() == nVia ){
			enc = true;

		}
		lista->avanzar();
	}
	return enc;
}

void Calles::insertarFarolaEnVia() {
	Farola *f;
	lFarolas->moverInicio();
	while (!lFarolas->finLista()) {
		lFarolas->consultar(f);
		insertarFarola(f);
		lFarolas->avanzar();

	}
}

void Calles::insertarFarola(Farola *&F) {

	float distancia, mejor;
	Coords *c2;
	Coords *c1;
	Via *v, *vmejor;

	if (!lVias->estaVacia()) {

		lVias->moverInicio();
		lVias->consultar(v);
		F->getLocalizacion(c1);
		v->getPuntoInicio(c2);
		distancia = c1->distanceTo(c2);

		// Compruebo el resto
		v->getPuntoMedio(c2);
		if (c1->distanceTo(c2) < distancia) {
			distancia = c1->distanceTo(c2);
		}
		v->getPuntoFinal(c2);
		if (c1->distanceTo(c2) < distancia) {
			distancia = c1->distanceTo(c2);
		}
		mejor = distancia;
		vmejor = v;
		lVias->avanzar();
		while (!lVias->finLista()) {
			this->lVias->consultar(v);

			v->getPuntoInicio(c2);
			if (c1->distanceTo(c2) < distancia) {
				distancia = c1->distanceTo(c2);
			}
			v->getPuntoMedio(c2);
			if (c1->distanceTo(c2) < distancia) {
				distancia = c1->distanceTo(c2);
			}
			v->getPuntoFinal(c2);
			if (c1->distanceTo(c2) < distancia) {
				distancia = c1->distanceTo(c2);
			}
            if(distancia < mejor){
            	mejor = distancia;
            	vmejor = v;
            }
			lVias->avanzar();
		}
		F->setVia(vmejor);
		vmejor->setContador(vmejor->getContador() +1);
	}
}

void Calles::viaMasFarolas() {
	Via *vAux;
	Via *vAux2;
	float cont = 0;
	float mejorCalle = 0;
	lVias->moverInicio();
	while (!lVias->finLista()) {
		lVias->consultar(vAux);
		//cont = vAux->getContador();
		if(vAux->getLongitud() > 0)
			cont = vAux->getContador() / vAux->getLongitud();
			if (cont > mejorCalle) {
				mejorCalle =  cont;
				vAux2 = vAux;
			}
			lVias->avanzar();
		}
		vAux2->mostrar();
}


void Calles::crearFicheroDistritos(string nDistrito){

	Distrito *Dis;
	Barrio *B;
	Via *V;

	ofstream fsal;
	string nombreF = "Vias En "+nDistrito+".csv";

	lVias->moverInicio();
	fsal.open(nombreF.c_str());
	if(fsal.is_open()){
		while(!lVias->finLista()){
			lVias->consultar(V);
			V->getBarrio(B);
			if(B != NULL){
				B->getDistrito(Dis);
				if(Dis->getDistrito() == nDistrito){
					fsal << "-Nombre vía: " << V->getNombre() << ". -Código vía: " << V->getCodigo() << ". -Longitud: " << V->getLongitud()
							<< ". -Barrio: " << B->getBarrio() << ". -Distrito: " << Dis->getDistrito() << endl;
				}
			}
			lVias->avanzar();
		}
		fsal.close();
	}

}

void Calles::ficheroTipoLampara(string tipo){
	ListaPI <Via *> *lviasF = new ListaPI <Via *>();
	ofstream fsal;
	Farola *F;
	Via *V, *V2;
	string nombreF = "Vías con Farola de tipo " + tipo +".csv";

	lFarolas->moverInicio();
	lviasF->moverInicio();
	fsal.open(nombreF.c_str());
	if (fsal.is_open()) {
		while (!lFarolas->finLista()) {
			lFarolas->consultar(F);
			if (F->getTipoLampara() == tipo) {
				F->getVia(V);
				V->setContadorTipo(V->getContadorTipo()+1);
				if(this->buscarNombreLista(V->getNombre(), lviasF) == false)
					lviasF->insertar(V);

			}
			lFarolas->avanzar();
		}
		lviasF->moverInicio();
		while(!lviasF->finLista()){
			lviasF->consultar(V2);
			fsal << "-Nombre vía: " << V2->getNombre() << ". -Código vía: "
				<< V2->getCodigo() << ". -Número farolas: "
				<< V2->getContadorTipo() << endl;
			lviasF->avanzar();
		}

		fsal.close();
	}
	this->resetContFarolas();

}

void Calles::resetContFarolas(){
	Via *vaux;
	if(!this->lVias->estaVacia()){
		this->lVias->moverInicio();
		while(!this->lVias->finLista()){
			this->lVias->consultar(vaux);
			vaux->setContadorTipo(0);
			lVias->avanzar();
		}
	}

}


//cargo en una lista las vias del barrio.
void Calles::cargarViasDeBarrio(string B, ListaPI <Via *> *&lViasBarrio){
	Barrio *b;
	Via *v;

	lVias->moverInicio();
	while(!lVias->finLista()){
		lVias->consultar(v);
		v->getBarrio(b);
		if(b != NULL){
			if(b->getBarrio() == B){
				lViasBarrio->insertar(v);
			}
		}
		lVias->avanzar();
	}
}

float Calles::potenciaVia(string nVia){
	float suma = 0;
	Farola *f;
	Via *v;
	lFarolas->moverInicio();
	while(!lFarolas->finLista()){
		lFarolas->consultar(f);
		f->getVia(v);

		if(v->getNombre() == nVia){
			suma = suma + f->getPotencia();
		}
		lFarolas->avanzar();
	}
	return suma;
}


bool Calles::calcularBarriosAdyacentes(ListaPI <Via *> *lBarrio, string B){
	Via *v1, *v2;
	bool enc = false;
	ListaPI <Via *> *lBarriosAdy = new ListaPI <Via *>();
	this->cargarViasDeBarrio(B, lBarriosAdy);
	lBarrio->moverInicio();
	while(!lBarrio->finLista() && !enc){
		lBarrio->consultar(v1);

		lBarriosAdy->moverInicio();
		while(!lBarriosAdy->finLista() && !enc){
			lBarriosAdy->consultar(v2);
			if(v1->distanciaMenorVia(v2) < 75){
				enc = true;
			}
			else{
				lBarriosAdy->avanzar();
			}
		}
		lBarrio->avanzar();
	}
	return enc;

}

int Calles::consumoTipoFarola(string tipo, int pot){
	Farola *f;
	int total = 0;
	lFarolas->moverInicio();
	while(!lFarolas->finLista()){
		lFarolas->consultar(f);
		if(f->getTipoLampara() == tipo && f->getPotencia() == pot){
			total = total + pot;
		}
		lFarolas->avanzar();
	}
	return total;
}

void Calles::calcularInformeConsumo(string t1, int p1, string t2, int p2){
	int totalAntigua = this->consumoTipoFarola(t1,p1) * 8 * 0.12149;
	int totalNueva = 0;
	Farola *f;
	lFarolas->moverInicio();
		while(!lFarolas->finLista()){
			lFarolas->consultar(f);
			if(f->getTipoLampara() == t1 && f->getPotencia() == p1){
				totalNueva = totalNueva + p2;
			}
			lFarolas->avanzar();
		}
		if(totalAntigua - (totalNueva * 8 * 0.12149) > 0){
			cout << "El ahorro es: " << (totalAntigua - (totalNueva* 8 * 0.12149)) / 1000 << endl;
		}
		else{
			cout << "No se produce ahorro." << endl;
		}

}


void Calles::mostrarViasSubcadena(string raiz) {
	Via *v;

	lVias->moverInicio();
	while (!lVias->finLista()) {
		lVias->consultar(v);
		if (v->getNombre().find(raiz) == 0) { // buscamos por la subcadena
			v->mostrar();
		}
		lVias->avanzar();
	}

}

void Calles::mostrarViasSubArbol(string R){
//	Arbol <Via *, ComparaPtrVias> *aux;
//
//	aux = this->aVias;
//	aux = arbol_similar(aux,R);
//	filtroInOrden(aux,R);
	similar(R);

}

bool Calles::empiezaPor (string str, string substr) {
	bool comienza = false;
	if (str.find(substr) == 0)
		comienza =  true;
	return comienza;
}

void Calles::filtroInOrden(Arbol <Via *, ComparaPtrVias> *bst,const string &nombre) {

	Arbol <Via *, ComparaPtrVias> *aux;
	Via *v;
	string n;
	if (bst != NULL) {

		aux = bst->hijoIzq();
		if (aux != NULL) {
			filtroInOrden(aux, nombre);
		}

		v = bst->raiz();
		n= v->getNombre();
		if (empiezaPor(n, nombre)) {
			v->mostrar();
		}

		aux = bst->hijoDer();
		if (aux != NULL) {
			filtroInOrden(aux, nombre);
		}

	}

}

Arbol<Via *, ComparaPtrVias> * Calles::arbol_similar (Arbol<Via *, ComparaPtrVias> *bst, const string &nombre) {

	Arbol<Via *, ComparaPtrVias> *aux = NULL;
	Arbol<Via *, ComparaPtrVias> *aux2 = NULL;

	string raiz;
	if(!bst->vacio()){
		raiz = bst->raiz()->getNombre();
		if (empiezaPor(raiz, nombre)) {
			aux = bst;
		}
		else
			if (nombre < raiz) {
				aux2 = bst->hijoIzq();
				if (aux2 != NULL) {
					aux = arbol_similar(aux2, nombre);}
				}
				else
					if(nombre > raiz){
					aux2 = bst->hijoDer();
					if (aux2 != NULL) {
						aux = arbol_similar(aux2, nombre);}
					}
	}
		return aux;
}


void Calles::similar (const string &nombre) {

	Arbol<Via *, ComparaPtrVias> *bst;

	if (!this->aVias->vacio()) {

		bst = this->arbol_similar (this->aVias, nombre);
		if (bst != NULL) {
			cout << "Mostrando las coincidencias de: " << nombre << endl;
			filtroInOrden(bst, nombre);
		} else {
			cout << "Ninguna via comienza por: " << nombre << endl;
		}
	}
}


void Calles::cambiarVia(string via, string viaN){
	Via *vaux;
	bool enc = false;
	lVias->moverInicio();
	while(!lVias->finLista()){
		lVias->consultar(vaux);
		if(vaux->getNombre() == via && !enc){
			lVias->borrar();
			aVias->borrar(vaux);
			vaux->setNombre(viaN);
			this->insertarViaOrden(vaux);
			this->insertarViaArbol(vaux);

			enc = true;
		}
		lVias->avanzar();
	}

}

Calles::~Calles() {
	Via *V;
	Farola *F;
	lVias->moverInicio();
	while(!lVias->finLista()){
		lVias->consultar(V);
		delete V;
		lVias->borrar();
	}
	lVias = NULL;

	lFarolas->moverInicio();
	while(!lFarolas->finLista()){
		lFarolas->consultar(F);
		delete F;
		lFarolas->borrar();
	}
	lFarolas = NULL;
}

