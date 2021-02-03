/* Distrito.h
 *
 *  TFG Example
 *  Author: GMCarlos_8
 */

#ifndef DISTRITO_H_
#define DISTRITO_H_
#include <iostream>

using namespace std;

class Distrito {

private:
	string nombreDistrito;

public:

	// ----- Constructores -----

	/* Constructor por defecto
	 * PRE ={}
	 * POST= {Crea la instancia de la clase}
	 * Complejidad O(1)
	 */
	Distrito();

	/* Constructor parametrizado
	 * PRE ={}
	 * POST= {Crea la instancia de la clase con los parámetros indicados}
	 * Complejidad O(1)
	 */
	Distrito(string nombreD);

	/* Constructor por copia
	 *
	 */
	Distrito(const Distrito &D);

	// ------ Metodos Get -----

    /* getDistrito
	 * PRE {La instancia debe estar creada.}
	 * POST {Devuelve el nombre de un distrito}
	 * Complejidad: O(1)
	 */
	string getDistrito();

	// ------ Metodos Set -----

	/* setDistrito
	 * PRE {La instancia debe estar creada.}
	 * POST {Asigna nombre a un distrito}
	 * Complejidad: O(1)
	 */
	void setDistrito(string distrito);

	/* mostrar
	 * PRE {La instancia debe estar creada.}
	 * POST {Muestra un distrito}
	 * Complejidad: O(1)
	 */
	void mostrar();

	/* empiezaPor
	 * PRE {La instancia debe estar creada.}
	 * POST {True si la se encuentra la subcadena}
	 * Complejidad: O(1)
	 */
	bool empiezaPor (string str, string substr);

	// ------ Operadores -----

	bool operator == (const Distrito &D);

	void operator = (const Distrito &D);

	~Distrito();
};



#endif /* DISTRITO_H_ */
