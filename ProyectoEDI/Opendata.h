/*
 * Opendata.h
 *
 *  TFG Example
 *  Author: GMCarlos_8
 */

#ifndef OPENDATA_H_
#define OPENDATA_H_
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Calles.h"
#include "Distritos.h"
#include "Barrios.h"
#include "arbol.h"

using namespace std;

class Opendata {

	Distritos *distritos;
	Barrios *barrios;
	Calles *calles;



public:

	Opendata();

	void cargarVias();

	void cargarFarolas();

	void cargarDistritos();

	void cargarBarrios();

	void cargarDatos();

	void mostrarVias();

	void mostrarFarolas();

	void mostrarDistritos();

	void mostrarBarrios();

	void mostrarViaEnBarrio(string B);

	void crearFicheroViaDistrito(string D);

	void barriosAdyacentes(string B);

	void mayorConcetracionFarolas();

	void ficheroLampara(string tipo);

	bool buscarVia(string V);

	void consumoDistrito();

	void mostrarViasPorSubcadena(string R);

	void mostrarViasSubcadenaArbol(string R);

	void informeAhorro(string tipo1, int potencia1, string tipo2, int potencia2);

	void cambiarNombreVia(string V, string Vn);



	~Opendata();
};



#endif /* OPENDATA_H_ */
