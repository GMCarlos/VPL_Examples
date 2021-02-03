/*
 * Barrio.h
 *
 *  TFG Example
 *  Author: GMCarlos_8
 */

#ifndef BARRIO_H_
#define BARRIO_H_
#include <iostream>
#include "Distrito.h"

using namespace std;

class Barrio {

private:
	string nombre;
	Distrito *perteneceDistrito;

public:

	/* Constructor por defecto
	 * PRE ={}
	 * POST= {Crea la instancia de la clase}
	 * Complejidad O(1)
	 */
	Barrio();
	/* Constructor parametrizado
	 * PRE ={}
	 * POST= {Crea la instancia de la clase con los parámetros indicados}
	 * Complejidad O(1)
	 */
	Barrio(string nombr, Distrito *distrito);

	/* Constructor por copia
	 *
	 */
	Barrio (const Barrio &B);

	// ------ Metodos Get -----

    /* getBarrio
	 * PRE {La instancia debe estar creada.}
	 * POST {Devuelve el nombre de un barrio}
	 * Complejidad: O(1)
	 */
	string getBarrio();

    /* getBarrio
	 * PRE {La instancia debe estar creada.}
	 * POST {Devuelve el nombre de un barrio}
	 * Complejidad: O(1)
	 */
	void getBarrio(string &nombreB);


	void getDistrito(Distrito *&d);

	// ------ Metodos Set ------

	/* setBarrio
	 * PRE {La instancia debe estar creada.}
	 * POST {Asigna nombre a un barrio}
	 * Complejidad: O(1)
	 */
	void setBarrio(string barrio);

	/* setDistrito
	 * PRE {La instancia debe estar creada.}
	 * POST {Asigna un distrito}
	 * Complejidad: O(1)
	 */
	void setDistrito(Distrito *d);

	/* mostrar
	 * PRE {La instancia debe estar creada.}
	 * POST {Muestra un barrio}
	 * Complejidad: O(1)
	 */
	void mostrar();

	// --------- Operadores -------

	void operator = (const Barrio &B);

	// ejemplo -> if(b==b1) / b llama al operador, b1 es el parámetro que se le pasa.

	bool operator == (const Barrio &B);

	~Barrio();

};

#endif /* BARRIO_H_ */
