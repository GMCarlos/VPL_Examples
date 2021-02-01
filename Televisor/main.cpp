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
	int opcion;

	//Introduzco la marca
	getline(cin, marca);
	t1.setMarca(marca);

	//Introduzco el modelo
	getline(cin, modelo);
	t1.setModelo(modelo);

	//Introduzco el canal
	cin >> canal;
	t1.setCanal(canal);

	//Introduzco el volumen
	cin >> volumen;
	t1.setVolumen(volumen);

	//Introduzco el estado
	cin >> estado;
	t1.setEstado(estado);

	cin >> opcion;

	switch (opcion) {

//Opcion 1: la television está apagada
	case 1: // tv apagada
		if (!t1.getEstado()) {
			cout << t1.getMarca() << " " << t1.getModelo() << " " << "-" << " "
					<< "-" << " " << "-" << endl;
		}
		//Se enciende el televisor
		t1.encenderTelevisor();
		//Si está encendido el televisor
		if (t1.getEstado()) {
			cout << "El televisor se ha encendido correctamente" << endl;
		} else {
			cout
					<< "El televisor no se puede encender porque el alumno ha hecho algo mal ..."
					<< endl;
		}
		break;

	case 2:  //pruebas con la marca
		//Se enciende el televisor
		t1.encenderTelevisor();
		if(t1.getMarca()=="Sony"){
			cout<<"La marca es correcta."<<endl;
		}else{
			cout<<"La marca es incorrecta."<<endl;
		}
		break;

	case 3:	//pruebas con el modelo
		//Se enciende el televisor
		t1.encenderTelevisor();
		if (t1.getModelo() == "Bravia") {
			cout << "El modelo es correcto." << endl;
		} else {
			cout << "El modelo es incorrecto." << endl;
		}
		break;

	case 4: // tv encendida prueba subir volumen
		t1.encenderTelevisor();
		cout << t1.getMarca() << " " << t1.getModelo() << " " << t1.getCanal()
				<< " " << t1.getVolumen() << " " << t1.getEstado() << endl;
		t1.subirVolumen();
		t1.subirVolumen();
		t1.subirVolumen();
		cout << "Después de subir el volumen 3 veces ..." << endl;
		cout << t1.getMarca() << " " << t1.getModelo() << " " << t1.getCanal()
				<< " " << t1.getVolumen() << " " << t1.getEstado() << endl;

		break;
	case 5: // subir canal
		t1.encenderTelevisor();
		cout << t1.getMarca() << " " << t1.getModelo() << " " << t1.getCanal()
				<< " " << t1.getVolumen() << " " << t1.getEstado() << endl;
		t1.subirCanal();
		t1.subirCanal();
		cout << "Después de subir dos veces el canal ..." << endl;
		cout << t1.getMarca() << " " << t1.getModelo() << " " << t1.getCanal()
				<< " " << t1.getVolumen() << " " << t1.getEstado() << endl;
		break;
	case 6: // cambio de canal
		t1.encenderTelevisor();
		cout << t1.getMarca() << " " << t1.getModelo() << " " << t1.getCanal()
				<< " " << t1.getVolumen() << " " << t1.getEstado() << endl;
		t1.cambioCanal(5);
		cout << "Se ha cambiado al canal 5..." << endl;
		cout << t1.getMarca() << " " << t1.getModelo() << " " << t1.getCanal()
				<< " " << t1.getVolumen() << " " << t1.getEstado() << endl;
		break;

	case 7:	//constructor parametrizado
		//Prueba del constructor parametrizado
		string marca1 = "LG";
		string modelo1 = "OLED65BX6LA";
		int canal1 = 1;
		int volumen1 = 15;
		bool estado1 = true; //encendida

		Televisor t2(marca1, modelo1, canal1, volumen1, estado1);
		//Si está encendida
		if (t2.getEstado()) {
			//Comprobamos la marca
			if (t2.getMarca() == "LG") {
				//Comprobamos el modelo
				if (t2.getModelo() == "OLED65BX6LA") {
					//Comprobamos el canal
					if (t2.getCanal() == 1) {
						//Comprobamos el volumen
						if (t2.getVolumen() == 15) {
							cout
									<< "El constructor parametrizado funciona correctamente."
									<< endl;
							cout << t2.getMarca() << " " << t2.getModelo()
									<< " " << t2.getCanal() << " "
									<< t2.getVolumen() << " " << t2.getEstado()
									<< endl;

						} else {
							cout
									<< "El volumen del televisor no es el esperado porque el alumno ha hecho algo mal ..."
									<< endl;
						}
					} else {
						cout
								<< "El canal del televisor no es el esperado porque el alumno ha hecho algo mal ..."
								<< endl;
					}
				} else {
					cout
							<< "El modelo del televisor no es el esperado porque el alumno ha hecho algo mal ..."
							<< endl;
				}
			} else {
				cout
						<< "La marca del televisor no es la esperada porque el alumno ha hecho algo mal ..."
						<< endl;
			}
		} else {
			cout
					<< "El televisor está apagado porque el alumno ha hecho algo mal ..."
					<< endl;
		}
		break;

	}
	t1.apagarTelevisor();
	if (t1.getEstado() == false) {
		cout << "Se ha apagado el televisor correctamente." << endl;
	}else{
		cout << "El televisor no se ha apagado de forma correcta ..." << endl;
	}

	return 0;
}




