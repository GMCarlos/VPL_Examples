/*
 * Calles.h
 *
 *  TFG Example
 *  Author: GMCarlos_8
 */

#ifndef CALLES_H_
#define CALLES_H_

#include "Via.h"
#include "Barrio.h"
#include "Distrito.h"
#include "Farola.h"
#include "listapi.h"
#include "arbol.h"
#include <fstream>

using namespace std;

class Calles {

	ListaPI <Via*> *lVias;
	ListaPI <Farola*> *lFarolas;
	Arbol <Via *, ComparaPtrVias> *aVias;


public:

	Calles();

	/* insertarViaFinal
	 * PRE {La instancia debe estar creada.}
	 * POST {Inserta una via al final de la lista}
	 * Complejidad: O(1)
	 */
	void insertarViaFinal(Via *V);

	/* insertarViaOrden
	 * PRE {La instancia debe estar creada.}
	 * POST {Inserta una via en orden en la lista}
	 * Complejidad: O(n)
	 */
	void insertarViaOrden(Via *V);

	void insertarViaArbol (Via *&V);

	/* mostrarVias
	 * PRE {La instancia debe estar creada.}
	 * POST {Muestra las vias de la lista}
	 * Complejidad: O(1)
	 */
	void mostrarVias();

	/* mostrarFarolas
	 * PRE {La instancia debe estar creada.}
	 * POST {Muestra las farolas de la lista}
	 * Complejidad: O(1)
	 */
	void mostrarFarolas();

	/* mostrarViasBarrio
	 * PRE {La instancia debe estar creada.}
	 * POST {Muestra las vis de un barrio}
	 * Complejidad: O(1)
	 */
	void mostrarViasBarrio(string nBarrio);

	void mostrarFarolasVia(string nVia);

	void mostrarInOrden(Arbol <Via*, ComparaPtrVias> *arb);

	void mostrarViasArbol();

	bool buscarVia(string nVia, Via *&V);

	bool buscarNombreVia(string nVia);

	/* insertarFarolaFinal
	 * PRE {La instancia debe estar creada.}
	 * POST {Inserta una farola al final de la lista }
	 * Complejidad: O(1)
	 */
	void insertarFarolaFinal(Farola *F);

	/* cargarViasDeBarrio
	 * PRE {La instancia debe estar creada.}
	 * POST {Carga en una lista las vias que pertenecen a un barrio}
	 * Complejidad: O(n)
	 */
	void cargarViasDeBarrio(string B, ListaPI <Via *> *&lBarrios);

	bool buscarNombreLista(string nVia, ListaPI <Via *> *lista);

	bool calcularBarriosAdyacentes(ListaPI <Via *> *lBarrio, string B);

	void adyacentes(string barrio);

	void insertarFarolaEnVia();

	void insertarFarola(Farola *&F);

	void viaMasFarolas();

	void insertarEnListaFarolas();

	void resetContFarolas();

	void crearFicheroDistritos(string nDistrito);

	void ficheroTipoLampara(string tipo);

	void mostrarViasSubcadena(string raiz);

	void mostrarViasSubcadenaArbol(string raiz);

	void mostrarViasSubArbol(string R);

	float potenciaVia(string nVia);

	int consumoTipoFarola(string tipo, int pot);

	void calcularInformeConsumo(string t1, int p1, string t2, int p2);

	void cambiarVia(string via, string viaN);

	bool empiezaPor (string str, string substr);

	void informeAhorro();

	void filtroInOrden(Arbol <Via *, ComparaPtrVias> *bst,const string &nombre);

	void similar (const string &nombre);

	Arbol<Via *, ComparaPtrVias> * arbol_similar (Arbol<Via *, ComparaPtrVias> *bst, const string &nombre);


	void cambiarViaArbol(string via, string viaN);

	~Calles();
};



#endif /* CALLES_H_ */
