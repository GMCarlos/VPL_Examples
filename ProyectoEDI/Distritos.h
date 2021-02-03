/*
 * Distritos.h
 *
 *  TFG Example
 *  Author: GMCarlos_8
 */

#ifndef DISTRITOS_H_
#define DISTRITOS_H_

#include "Distrito.h"
#include "listapi.h"
#include <fstream>

class Distritos {

private:
	ListaPI <Distrito*> *lDistritos;

public:

	Distritos();

	/* mostrar
	 * PRE {La instancia debe estar creada.}
	 * POST {Muestra los distritos de la lista}
	 * Complejidad: O(1)
	 */
	void mostrar();

	/* insertarDistritoFinal
	 * PRE {La instancia debe estar creada.}
	 * POST {Inserta un distrito por el final en la lista}
	 * Complejidad: O(1)
	 */
	void insertarDistritoFinal(Distrito *D);

	/* insertarDistritoOrden
	 * PRE {La instancia debe estar creada.}
	 * POST {Inserta un distrito en orden en la lista}
	 * Complejidad: O(n)
	 */
	void insertarDistritoOrden(Distrito *D);

	/* buscar
	 * PRE {La instancia debe estar creada.}
	 * POST {Busca un distrito en la lista}
	 * Complejidad: O(n)
	 */
	bool buscar(string nDistrito, Distrito *&D);

	void devolverListaDistritos(ListaPI <Distrito *> *&lD);



	~Distritos();

};

#endif
