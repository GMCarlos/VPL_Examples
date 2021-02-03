/*
 * Via.h
 *
 *  TFG Example
 *  Author: GMCarlos_8
 */

#ifndef VIA_H_
#define VIA_H_
#include <iostream>
#include "coords.h"
#include "arbol.h"
#include "Barrio.h"

#include "listapi.h"

using namespace std;

class Via {

private:

	string nombre;
	float longitud;
	string via;
	int codigo;
	int contadorFarolas;
	int contFarolasTipo;
	Barrio *perteneceBarrio;
	Coords *puntoFinalVia;
	Coords *puntoInicioVia;
	Coords *puntoMedioVia;


public:
	// ----- Constructores -----

	/* Constructor por defecto
	 * PRE ={}
	 * POST= {Crea la instancia de la clase}
	 * Complejidad O(1)
	 */
	Via();

	/* Constructor parametrizado
	 * PRE ={}
	 * POST= {Crea la instancia de la clase con los parámetros indicados}
	 * Complejidad O(1)
	 */
	Via(string nombre, float longitud, string via, int codigo, float laI, float lonI, float laM, float lonM, float laF,
			float lonF, Barrio *barrio);

	/* Constructor por copia
	 *
	 */
	Via(const Via &V);

	// ------ Metodos Get -----

    /* getNombre
	 * PRE {La instancia debe estar creada.}
	 * POST {Devuelve el nombre de una via}
	 * Complejidad: O(1)
	 */
	string getNombre();

    /* getBarrio
	 * PRE {La instancia debe estar creada.}
	 * POST {Devuelve el nombre de un barrio}
	 * Complejidad: O(1)
	 */
	int getCodigo();

	int getContador();

	int getContadorTipo();

    /* getNombre
	 * PRE {La instancia debe estar creada.}
	 * POST {Devuelve el nombre de una via}
	 * Complejidad: O(1)
	 */
	string getVia();

    /* getLongitud
	 * PRE {La instancia debe estar creada.}
	 * POST {Devuelve la longitud}
	 * Complejidad: O(1)
	 */
	float getLongitud();

	void getPuntoInicio(Coords *&c);

	void getPuntoMedio(Coords *&c);

	void getPuntoFinal(Coords *&c);

	void getBarrio(Barrio *&b);

	// ------ Metodos Set -----

	/* setInicioVia
	 * PRE {La instancia debe estar creada.}
	 * POST {Asigna el inicio de un vía}
	 * Complejidad: O(1)
	 */
	void setInicioVia(float latitud,float longitud);

	/* setFinalVia
	 * PRE {La instancia debe estar creada.}
	 * POST {Asigna el final de una vía
	 * Complejidad: O(1)
	 */
	void setFinalVia (float latitud,float longitud);

	/* setMedioVia
	 * PRE {La instancia debe estar creada.}
	 * POST {Asigna el punto medio de una vía}
	 * Complejidad: O(1)
	 */
	void setMedioVia (float latitud,float longitud);

	/* setNombre
	 * PRE {La instancia debe estar creada.}
	 * POST {Asigna nombre a un barrio}
	 * Complejidad: O(1)
	 */
	void setCodigo(int codigo);

	/* setLongitud
	 * PRE {La instancia debe estar creada.}
	 * POST {Asigna una longitud}
	 * Complejidad: O(1)
	 */
	void setLongitud(float longitud);

	/* setNombre
	 * PRE {La instancia debe estar creada.}
	 * POST {Asigna nombre a una via}
	 * Complejidad: O(1)
	 */
	void setNombre(string nombre);

	/* setVia
	 * PRE {La instancia debe estar creada.}
	 * POST {Asigna nombre a una via}
	 * Complejidad: O(1)
	 */

	void setContador(int cont);

	void setContadorTipo(int cont);

	void setVia(string via);

	/* setBarrio
	 * PRE {La instancia debe estar creada.}
	 * POST {Asigna un barrio}
	 * Complejidad: O(1)
	 */
	void setBarrio(Barrio *b);

	/* mostrar
	 * PRE {La instancia debe estar creada.}
	 * POST {Muestra una vía}
	 * Complejidad: O(1)
	 */
	void mostrar();

	/* calcularDistancia
	 * PRE {La instancia debe estar creada.}
	 * POST {Devuelve la distancia de una vía}
	 * Complejidad: O(1)
	 */
	float calcularDistancia(Via *via1);

	/* etaEnBarrio
	 * PRE {La instancia debe estar creada.}
	 * POST {True si se encuentra el barrio}
	 * Complejidad: O(1)
	 */
	bool estaEnBarrio(string barrio);

	/* distanciaMenorVia
	 * PRE {La instancia debe estar creada.}
	 * POST {Devuelve la menor distancia de una vía}
	 * Complejidad: O(1)
	 */
	float distanciaMenorVia(Via *v);



	// ------ Operadores -----

	bool operator == (const Via &V);

	void operator = (const Via &V);

	bool operator > (const Via &V);

	~Via();
};

class ComparaPtrVias {

public:

	int operator()(Via *v1, Via *v2) {
		int n;
		if(v1->getVia() == v2->getVia()){
			n = 0;
		}
		else{
			if(v1->getVia() > v2->getVia()){
				n = 1;
			}
			else{
				if(v1->getVia()< v2->getVia()){
					n = -1;
				}
			}
		}
	return n;
	}

};



#endif /* VIA_H_ */
