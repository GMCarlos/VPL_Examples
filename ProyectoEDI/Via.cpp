/*
 * Via.cpp
 *
 *  TFG Example
 *  Author: GMCarlos_8
 */

#include "Via.h"
#include "coords.h"


using namespace std;

Via::Via() {

	nombre = " ";
	longitud = 0;
	via = " ";
	codigo = 0;
	contadorFarolas = 0;
	contFarolasTipo = 0;
	perteneceBarrio = NULL;
	puntoFinalVia = NULL;
	puntoInicioVia = NULL;
	puntoMedioVia = NULL;


}

Via::Via(string nombre, float longitud, string via, int codigo, float laI, float lonI, float laM, float lonM, float laF,
					float lonF, Barrio *barrio){

	this->nombre = nombre;
	this->longitud = longitud;
	this->via = via;
	this->codigo = codigo;
	this->contadorFarolas = 0;
	contFarolasTipo = 0;
	this->perteneceBarrio = barrio;
	this->puntoFinalVia = new Coords(laF,lonF);
	this->puntoInicioVia = new Coords(laI,lonI);
	this->puntoMedioVia = new Coords(laM,lonM);


}

Via::Via(const Via &V){
	cout << "Ejecutandose constructor por copia" << endl;
	this->nombre = V.nombre;
	this->longitud = V.longitud;
	this->via = V.via;
	this->codigo = V.codigo;
	this->contadorFarolas = V.contadorFarolas;
	this->contFarolasTipo = V.contFarolasTipo;
	this->perteneceBarrio = V.perteneceBarrio;
	this->puntoFinalVia = new Coords (*V.puntoFinalVia);
	this->puntoInicioVia = new Coords (*V.puntoInicioVia);
	this->puntoMedioVia =new Coords (*V.puntoMedioVia);

}

string Via::getNombre(){
	return nombre;
}

int Via::getCodigo(){
	return codigo;
}

int Via::getContador(){
	return contadorFarolas;
}

int Via::getContadorTipo(){
	return 	contFarolasTipo;;
}

void Via::getPuntoInicio(Coords *&c){
	c = this->puntoInicioVia;
}

void Via::getPuntoMedio(Coords *&c){
	c = this->puntoMedioVia;
}

void Via::getPuntoFinal(Coords *&c){
	c = this->puntoFinalVia;
}

void Via::setCodigo(int codigo) {
	this->codigo = codigo;
}

void Via::setContador(int cont){
	this->contadorFarolas = cont;
 }

void Via::setContadorTipo(int cont){
	this->contFarolasTipo = cont;
 }

float Via::getLongitud(){
	return longitud;
}

void Via::setInicioVia (float latitud,float longitud){
	if (puntoInicioVia == NULL )
		puntoInicioVia = new Coords (latitud, longitud);
	else{
        puntoInicioVia->setLatitude(latitud);
        puntoInicioVia->setLongitude(longitud);
	}
}

void Via::setFinalVia (float latitud,float longitud){
	if (puntoFinalVia == NULL )
		puntoFinalVia = new Coords (latitud, longitud);
	else{
        puntoFinalVia->setLatitude(latitud);
        puntoFinalVia->setLongitude(longitud);
	}
}

void Via::setMedioVia (float latitud,float longitud){
	if (puntoMedioVia == NULL )
		puntoMedioVia = new Coords (latitud, longitud);
	else{
        puntoMedioVia->setLatitude(latitud);
        puntoMedioVia->setLongitude(longitud);
	}
}

void Via::setLongitud(float longitud) {
	this->longitud = longitud;
}

void Via::setNombre(string nombre) {
	this->nombre = nombre;
}

string Via::getVia(){
	return via;
}

void Via::getBarrio(Barrio *&b){
	b = this->perteneceBarrio;
}

void Via::setVia(string via) {
	this->via = via;
}

void Via::setBarrio(Barrio *b){
	this->perteneceBarrio = b;
}

float Via::calcularDistancia(Via *via1){

	return puntoInicioVia->distanceTo(via1->puntoInicioVia);

}


// Se queda con la menor distancia
float Via::distanciaMenorVia(Via *v){

	float d = puntoInicioVia->distanceTo(v->puntoInicioVia);

	if(puntoInicioVia->distanceTo(v->puntoFinalVia) < d)
	d = puntoInicioVia->distanceTo(v->puntoFinalVia);

	if(puntoInicioVia->distanceTo(v->puntoMedioVia) < d)
	d = puntoInicioVia->distanceTo(v->puntoMedioVia);

	if(puntoMedioVia->distanceTo(v->puntoInicioVia) < d)
	d = puntoMedioVia->distanceTo(v->puntoInicioVia);

	if(puntoMedioVia->distanceTo(v->puntoFinalVia) < d)
	d = puntoMedioVia->distanceTo(v->puntoFinalVia);

	if(puntoMedioVia->distanceTo(v->puntoMedioVia) < d)
	d = puntoMedioVia->distanceTo(v->puntoMedioVia);

	if(puntoFinalVia->distanceTo(v->puntoFinalVia) < d)
	d = puntoFinalVia->distanceTo(v->puntoFinalVia);

	if(puntoFinalVia->distanceTo(v->puntoMedioVia) < d)
	d = puntoFinalVia->distanceTo(v->puntoMedioVia);

	if(puntoFinalVia->distanceTo(v->puntoInicioVia) < d)
	d = puntoFinalVia->distanceTo(v->puntoInicioVia);

	return d;
}


void Via::mostrar(){
	if (perteneceBarrio != NULL){
		cout << "Código: " << this->getCodigo() << endl;
		cout << "Nombre vía: " << this->getNombre() << endl;
		cout << "Longitud vía: " << this->getLongitud() << endl;
		cout << "Barrio: " << perteneceBarrio->getBarrio() <<endl;
		cout << "Tipo vía: " << this->getVia() << endl;
		cout << "Número de farolas: " << this->getContador() <<endl;
	}
	else{
		cout << "Código: " << this->getCodigo() << endl;
		cout << "Nombre vía: " << this->getNombre() << endl;
		cout << "Longitud vía: " << this->getLongitud() << endl;
		cout << "Tipo vía: " << this->getVia() << endl;
		cout << "Número de farolas: " << this->getContador() <<endl;
	}
	cout << "Coordenadas: " << endl;
	puntoInicioVia->show();
	puntoMedioVia->show();
	puntoFinalVia->show();
}

bool Via::estaEnBarrio(string barrio){
	bool enc = false;
	if(perteneceBarrio!=NULL)
		if(this->perteneceBarrio->getBarrio() == barrio){
			enc = true;
		}
	return enc;
}

bool Via::operator == (const Via &V){
	return (this->nombre == V.nombre);
}

void Via::operator =(const Via &V){
	this->codigo = V.codigo;
	this->longitud = V.longitud;
	this->nombre = V.nombre;
	*this->perteneceBarrio = *V.perteneceBarrio;
	*this->puntoFinalVia = *V.puntoFinalVia;
	*this->puntoInicioVia = *V.puntoInicioVia;
	*this->puntoMedioVia = *V.puntoMedioVia;
	this->via = V.via;

}

bool Via::operator >(const Via &V){
	bool menor;
	if (this->nombre > V.nombre){
			menor = true;
	}
	else{
		menor = false;
	}
	return menor;
}
//void pruebaVia(){
//	Via *v1, *v2;
//	v1 = new Via("Atahualpa", 348.33, "Calle", 68, 39.463483, -6.37534, 39.463083, -6.379342, 39.4632029, -6.37728, b1);
//	v2 = new Via ("Cayo Norbano Flaco", 298.2, "Calle", 1040, 39.473783, -6.378742, 39.475157, -6.377796,  39.476283, -6.376942, b2 );
//	cout << "Mostrando información de las vías..." << endl;
//	cout << "--------Vía1--------" << endl;
//	v1->mostrar();
//	cout << "--------Vía2--------" << endl;
//	v2->mostrar();
//}

Via::~Via() {
	if (puntoFinalVia!= NULL)
		delete puntoFinalVia;
	if (puntoInicioVia!=NULL)
		delete puntoInicioVia;
	if (puntoMedioVia!=NULL)
		delete puntoMedioVia;
	if (perteneceBarrio!=NULL)
		delete perteneceBarrio;


}


