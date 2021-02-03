/*
 * Farola.h
 *
 *  TFG Example
 *  Author: GMCarlos_8
 */

#ifndef FAROLA_H_
#define FAROLA_H_
#include "coords.h"
#include "Via.h"
#include <iostream>

using namespace std;

class Farola {
private:
	string funcionamiento;
	string proteccion;
	string tipoLuz;
	string materialS;
	Coords *localizacion;
	int potencia;
	string tipoLampara;
	int altura;
	string tipoSoporte;
	int circuitos;
	string materialL;
	Via *perteneceVia;
public:

	// ----- Constructores -----

	Farola();

	Farola(string fun, string protec, string tipoL, string _materialS, float longitud, int pot, float latitud, string tLampara,
			int _altura, string tSoporte, int _circuitos, string _materialL, Via *via);

	// ------ Metodos Get -----

    /* getFuncionamiento
	 * PRE {La instancia debe estar creada.}
	 * POST {Devuelve el funcionamiento}
	 * Complejidad: O(1)
	 */
	string getFuncionamiento();

    /* getProteccion
	 * PRE {La instancia debe estar creada.}
	 * POST {Devuelve la proteccion}
	 * Complejidad: O(1)
	 */
	string getProteccion();

    /* getTipoLuz
	 * PRE {La instancia debe estar creada.}
	 * POST {Devuelve el tipo de luz}
	 * Complejidad: O(1)
	 */
	string getTipoLuz();

    /* getMaterialS
	 * PRE {La instancia debe estar creada.}
	 * POST {Devuelve el materialS}
	 * Complejidad: O(1)
	 */
	string getMaterialS();

    /* getPotencia
	 * PRE {La instancia debe estar creada.}
	 * POST {Devuelve la potencia}
	 * Complejidad: O(1)
	 */
	int getPotencia();

    /* getTipoLampara
	 * PRE {La instancia debe estar creada.}
	 * POST {Devuelve el tipo de lámpara}
	 * Complejidad: O(1)
	 */
	string getTipoLampara();

    /* getAltura
	 * PRE {La instancia debe estar creada.}
	 * POST {Devuelve la altura}
	 * Complejidad: O(1)
	 */
	int getAltura();

    /* getTipoSoporte
	 * PRE {La instancia debe estar creada.}
	 * POST {Devuelve el soporte}
	 * Complejidad: O(1)
	 */
	string getTipoSoporte();

    /* getCircuitos
	 * PRE {La instancia debe estar creada.}
	 * POST {Devuelve el circuito
	 * Complejidad: O(1)
	 */
	int getCircuitos();

    /* getMaterialL
	 * PRE {La instancia debe estar creada.}
	 * POST {Devuelve el materialL}
	 * Complejidad: O(1)
	 */
	string getMaterialL();

	/* mostrar
	 * PRE {La instancia debe estar creada.}
	 * POST {Muestra una farola}
	 * Complejidad: O(1)
	 */
	void mostrar();

	void getVia(Via *&v);

	void getLocalizacion(Coords *&c);

	void setVia(Via *v);

	/* estaEnVia
	 * PRE {La instancia debe estar creada.}
	 * POST {true si se encuentra en la vía}
	 * Complejidad: O()
	 */
	bool estaEnVia(string nVia);

	~Farola();
};


#endif /* FAROLA_H_ */
