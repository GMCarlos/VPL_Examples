/*
 * Televisor.h
 *
 *  Created on: 26 ene. 2021
 *      Author: mariscal
 */

#ifndef TELEVISOR_H_
#define TELEVISOR_H_
#include <string>
using namespace std;
const int MAXCANAL = 30;
const int MAXVOLUMEN = 15;


class Televisor  {
	string marca;
	string modelo;
	int canal;
	int volumen;
	bool estado; // false apagado true encendido


public:
	Televisor();
    Televisor(string marca, string modelo, int canal, int volumen, bool estado);
	~Televisor();
	void setMarca( string marca);
	void setModelo( string modelo);
	void setVolumen(int volumen);
	void setCanal(int canal);
	void setEstado(int estado);

	const string getMarca() ;
	const string getModelo() ;
	int getCanal() ;
	int getVolumen() ;
	int getEstado() ;

	bool subirVolumne();
	bool bajarVolumen();

	void cambioCanal(int canal);
	bool subirCanal();
	bool bajarCanal();

	void apagarTelevisor();
	void encenderTelevisor();




};

#endif /* TELEVISOR_H_ */