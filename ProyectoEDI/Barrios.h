/*
 * Barrios.h
 *
 *  TFG Example
 *  Author: GMCarlos_8
 */

#ifndef BARRIOS_H_
#define BARRIOS_H_

#include "Barrio.h"
#include "listapi.h"

using namespace std;

class Barrios {

	ListaPI <Barrio*> *lBarrios;

public:

	Barrios();

	/* insertarBarrioFinal
	 * PRE {La instancia debe estar creada.}
	 * POST {Inserta un barrio en la lista por el final}
	 * Complejidad: O(1)
	 */
	void insertarBarrioFinal(Barrio *B);

	/* insertarBarrioOrden
	 * PRE {La instancia debe estar creada.}
	 * POST {Inserta un barrio en orden en la lista}
	 * Complejidad: O(n)
	 */
	void insertarBarrioOrden(Barrio *B);

	/* buscar
	 * PRE {La instancia debe estar creada.}
	 * POST {Busca un barrio en la lista}
	 * Complejidad: O(n)
	 */
	bool buscar(string nBarrio, Barrio *&B);

	bool buscarBarrio(string nBarrio);

	/* mostrarBarrios
	 * PRE {La instancia debe estar creada.}
	 * POST {Muestra los barrios de la lista}
	 * Complejidad: O(1)
	 */
	void mostrarBarrios();

	void devolverListaBarrio(ListaPI <Barrio *> *&lBarrio);

	void devolverListaBarriosDistrito(ListaPI <Barrio *> *&lBarrio, string distrito);

	~Barrios();
};



#endif /* BARRIOS_H_ */
