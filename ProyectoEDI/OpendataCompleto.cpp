/*
 * Opendata.cpp
 *
 *  Created on: 3 abr. 2017
 *      Author: Jose
 */

#include "Opendata.h"

using namespace std;

Opendata::Opendata() {

	calles = new Calles();
	distritos = new Distritos();
	barrios = new Barrios();
}

void Opendata::cargarVias() {
	int i;
	Via *V;
	Barrio *B;
	float laI, lonI, laM, lonM, laF, lonF;
	ifstream fent;
	string linea;
	fent.open("Via.csv");
	string campo[11];
	if (fent.is_open()) {
		getline(fent, linea);	//leo la cabecera
		while (!fent.eof()) {
			for (i = 0; i < 10; i++) {
				getline(fent, campo[i], ';');
			}
			//if (!fent.eof()) {
				getline(fent, campo[10]);

				laI = atof(campo[6].c_str());
				lonI = atof(campo[7].c_str());
				laF = atof(campo[5].c_str());
				lonF = atof(campo[4].c_str());
				laM = atof(campo[8].c_str());
				lonM = atof(campo[9].c_str());

				V = new Via(campo[0], atof(campo[1].c_str()), campo[2],
					atoi(campo[3].c_str()), laI, lonI, laM, lonM, laF,
					lonF, NULL);
				if(barrios->buscar(campo[10], B)){
					V->setBarrio(B);
				}
				calles->insertarViaOrden(V);    // Inserta en orden
				calles->insertarViaArbol(V);	// Inserta en arbol
			//}
		}
		fent.close();
	} else {
		cout << "ERROR EN LA APERTURA DEL FICHERO" << endl;
	}
}


void Opendata::cargarFarolas(){
	int i;

	Farola *F;

	float lat, lon;
	ifstream fent;
	string linea;
	fent.open("Farola.csv");
	string campo[12];
		if(fent.is_open()) {
			getline(fent, linea);	//leo la cabecera
			while(!fent.eof()) {

				for(i=0; i<11; i++) {
					getline(fent, campo[i], ';');
				}
				//if(!fent.eof()) {
					getline(fent, campo[11]);

					lon = atof(campo[4].c_str());
					lat = atof(campo[7].c_str());
					//Farola(string fun, string protec, string tipoL, string _materialS, float longitud, int pot, float latitud, string tLampara,
					//int _altura, string tSoporte, int _circuitos, string _materialL);
					F = new Farola(campo[0], campo[1], campo[2], campo[3],  lat, atoi(campo[5].c_str()), lon, campo[6], atoi(campo[8].c_str()), campo[9], atoi(campo[10].c_str()), campo[11], NULL);

					calles->insertarFarolaFinal(F);

				//}
			}
			fent.close();
		}
		else {
			cout<<"ERROR EN LA APERTURA DEL FICHERO"<<endl;
		}
	}

void Opendata::cargarBarrios(){
	Barrio *B;
	Distrito *D;
	ifstream fent;
	string barrio, distrito;

	fent.open("Barrio.csv");

	if (fent.is_open()) {
		//getline(fent, barrio); // leo la cabecera
		while (!fent.eof()) {

			getline(fent, barrio, ';');

			//if (!fent.eof()) {
				getline(fent, distrito);

				B = new Barrio(barrio, NULL);
				if(distritos->buscar(distrito,D)){

					B->setDistrito(D);
				}
				barrios->insertarBarrioOrden(B);
			//}
		}
		fent.close();
		}
		else {
			cout << "ERROR EN LA APERTURA DEL FICHERO" << endl;
	}
}

void Opendata::cargarDistritos() {

	Distrito *D;
	ifstream fent;
	string linea;
	fent.open("Distrito.csv");

	if (fent.is_open()) {
		getline(fent, linea); // leo la cabecera
		while (!fent.eof()) {
			getline(fent, linea);
			//if (!fent.eof()) {
				D = new Distrito(linea);
				distritos->insertarDistritoOrden(D);
			//}
		}
		fent.close();
	} else {
		cout << "ERROR EN LA APERTURA DEL FICHERO" << endl;
	}
}


void Opendata::cargarDatos(){

	cout << "Cargando distritos..." << endl;
	this->cargarDistritos();
	cout << "Cargando barrios..." << endl;
	this->cargarBarrios();
	cout << "Cargando vías..." << endl;
	this->cargarVias();
	cout << "Cargando farolas..." << endl;
	this->cargarFarolas();
	calles->insertarFarolaEnVia();
}
void Opendata::mostrarVias(){
	calles->mostrarVias();
	//calles->mostrarViasArbol();
}

void Opendata::mostrarFarolas(){
	calles->mostrarFarolas();
}

void Opendata::mostrarDistritos(){
	distritos->mostrar();
}

void Opendata::mostrarBarrios(){
	barrios->mostrarBarrios();
}

void Opendata::mostrarViaEnBarrio(string B){
	calles->mostrarViasBarrio(B);
}

void Opendata::crearFicheroViaDistrito(string D){
	calles->crearFicheroDistritos(D);
}

void Opendata::mayorConcetracionFarolas(){
	calles->viaMasFarolas();
}

bool Opendata::buscarVia(string V){
	return calles->buscarNombreVia(V);
}

void Opendata::ficheroLampara(string tipo){
	calles->ficheroTipoLampara(tipo);
}

void Opendata::cambiarNombreVia(string V, string Vn){
	calles->cambiarVia(V, Vn);
}

void Opendata::mostrarViasPorSubcadena(string R){
	calles->mostrarViasSubcadena(R);
}

void Opendata::mostrarViasSubcadenaArbol(string R){
	calles->mostrarViasSubArbol(R);
}

void Opendata::consumoDistrito(){
	ListaPI<Distrito *> *listaDistritos = new ListaPI<Distrito *>();
	ListaPI<Barrio *> *listaBarrios = new ListaPI<Barrio *>();
	ListaPI<Via *> *listaVias = new ListaPI<Via *>();
	Distrito *d;
	Barrio *b;
	Via *v;
	string nDistrito;
	string nBarrio;
	string nVia;
	float potencia = 0;

	distritos->devolverListaDistritos(listaDistritos);

	listaDistritos->moverInicio();
	while (!listaDistritos->estaVacia()) {
		listaDistritos->consultar(d);
		nDistrito = d->getDistrito();
		barrios->devolverListaBarriosDistrito(listaBarrios, nDistrito);
		listaBarrios->moverInicio();
		while (!listaBarrios->estaVacia()) {
			listaBarrios->consultar(b);
			nBarrio = b->getBarrio();
			calles->cargarViasDeBarrio(nBarrio, listaVias);
			listaVias->moverInicio();
			while (!listaVias->estaVacia()) {
				listaVias->consultar(v);
				nVia = v->getNombre();
				potencia = potencia + calles->potenciaVia(nVia);
				listaVias->borrar();
				listaVias->moverInicio();
			}

			listaBarrios->borrar();
			listaBarrios->moverInicio();
		}
		cout<<"-Distrito: "<< nDistrito <<" -Consumo: " << (potencia * 8 * 0.12149) / 1000 << endl;
		potencia=0; // actualizamos valor a 0

		listaDistritos->borrar();
		listaDistritos->moverInicio();
	}
	if(listaDistritos != NULL)
		delete listaDistritos;
	if(listaBarrios != NULL)
		delete listaBarrios;
	if(listaVias != NULL)
		delete listaVias;
}

void Opendata::informeAhorro(string tipo1, int potencia1, string tipo2, int potencia2){
	calles->calcularInformeConsumo(tipo1,potencia1,tipo2,potencia2);
}

void Opendata::barriosAdyacentes(string B){
	ListaPI <Via *> *lBAdy = new ListaPI <Via *>();
	ListaPI <Barrio *> *lB= new ListaPI <Barrio *>();
	Barrio *baux;
	string barrio;
	barrios->devolverListaBarrio(lB);  // cargo los barrios en una lista
	if(barrios->buscarBarrio(B)){      // busco que el barrio que me dan existe
		calles->cargarViasDeBarrio(B,lBAdy); //si existe, cargo las vias de ese barrio en una lista
		lB->moverInicio();
		while(!lB->finLista()){
			lB->consultar(baux);
			barrio = baux->getBarrio();
			if(calles->calcularBarriosAdyacentes(lBAdy, barrio))
				if(baux->getBarrio() != B)
					baux->mostrar();
			lB->avanzar();
		}
	}
	delete lBAdy;
	delete lB;
}

//void pruebaCargar(){
//	Calles *calle = new Calles();
//	Barrios *barrio = new Barrios();
//  Distrito *Distrito = new Distritos();
//
//	calle->cargarVias("Aguas Vivas");
//	calle->cargarVias("Agrgentina");
//	calle->cargarVias("Margallo");
//  barrio->cargarBarrio("Argentina");
//	barrio->cargarBarrio("Aldea Moret");
//	distrito->cargarDistrito(Norte);
// distrito->cargaristrito(Sur);
//	calle->mostrarVias();
//  barrio->mostraBarrios();
//  distrito->mostraDistritos();
//
//	delete calle;
//	delete barrio;
//	delete distrito;
//}
//
//void

Opendata::~Opendata() {
	if(calles != NULL)
		delete calles;
	if(distritos != NULL)
		delete distritos;
	if(barrios != NULL)
		delete barrios;
}

