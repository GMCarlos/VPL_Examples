/*
 * coords.h
 *
 *  TFG Example
 *  Author: GMCarlos_8
 */

#ifndef COORDS_H_
#define COORDS_H_

const float PI = 3.14159265;

class Coords {

private:

	float latitude;
	float longitude;

public:

	/*
	 * Constructor por defecto
	 * PRE:
	 * POST:Devuelve un objeto de tipo Coords inicializado
	 * COMPLEJIDAD
	 */
	Coords();
	/*
	 * Constructor  parametrizado
	 * PRE:
	 * POST:Devuelve un objeto de tipo Coords inicializado a partir de los valores pasados en los parámetros
	 * COMPLEJIDAD
	 */
	Coords(float latitude, float longitude);
	/*
	 * Constructor  copia
	 * PRE:
	 * POST:Devuelve un objeto de tipo Coords inicializado a partir de los valores pasados en los parámetros
	 * COMPLEJIDAD
	 */

	Coords (const Coords &c);

	void setLatitude  (float latitude);
	void setLongitude (float longitude);

	/*
	 * PRE: {c <> NULL}
	 * POST:  Distance in meters between two points identified by decimal degrees coords.
	 * COMPLEJIDAD: O(1)
	 */
	float distanceTo(Coords *c);

	/*
	 * PRE:  {latitude<> 0 and longitude<>0}
	 * POST:  Distance in meters between two points identified by decimal degrees coords.
	 * COMPLEJIDAD: O(1)
	 */
	float distanceTo(float latitude, float longitude);
	/*
	 * PRE:  {}
	 * POST: {}
	 * COMPLEJIDAD: O(1)
	 */
	void show();

	~Coords();
};

#endif /* COORDS_H_ */
