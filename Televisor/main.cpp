//============================================================================
// Name        : S01.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Televisor.h"

using namespace std;

int main() {
	Televisor t1;
	string marca, modelo;
	int canal, volumen;
	bool estado;

	getline(cin, marca);
	t1.setMarca(marca);

	getline(cin, modelo);
	t1.setModelo(modelo);

	cin >> canal;
	t1.setCanal(canal);
	cin >> volumen;
	t1.setVolumen(volumen);
	cin>>estado;
	t1.setEstado(estado);
	if (!t1.getEstado()) {
		cout << t1.getMarca() << " " << t1.getModelo() << " " << "-" << " "
				<< "-" << " " << "-" << endl;

	} else {
		t1.subirVolumne();
		t1.subirVolumne();
		t1.subirVolumne();
		t1.subirCanal();
		// prueba supervisada
		cout << t1.getMarca() << " " << t1.getModelo() << " " << t1.getCanal()
				<< " " << t1.getVolumen() << " " << t1.getEstado() << endl;


	}
	return 0;
}

