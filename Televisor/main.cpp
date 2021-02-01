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
	cin>>estado;
	t1.setEstado(estado);

	//Si el televisor está apagado
	if (!t1.getEstado()) {
		cout << t1.getMarca() << " " << t1.getModelo() << " " << "-" << " "
				<< "-" << " " << "-" << endl;
		cout <<"El televisor está apagado y se va a encender ..."<<endl;
		t1.encenderTelevisor();
		//Si está encendido el televisor
		if(t1.getEstado()){
			cout << "El televisor se ha encendido correctamente"<<endl;
		}else{
			cout << "El televisor no se puede encender porque el alumno ha hecho algo mal ..."<<endl;
		}

	} else {
		//Si el televisor está encendido
		t1.subirVolumen();
		t1.subirVolumen();
		t1.subirVolumen();
		t1.subirCanal();
		// prueba supervisada
		cout << t1.getMarca() << " " << t1.getModelo() << " " << t1.getCanal()
				<< " " << t1.getVolumen() << " " << t1.getEstado() << endl;
		cout <<"El televisor está encendido y se va a apagar ..."<<endl;
		t1.apagarTelevisor();
		//Si está apagado
		if(!t1.getEstado()){
			cout << "El televisor se ha apagado correctamente"<<endl;
		}else{
			cout << "El televisor no se puede apagar porque el alumno ha hecho algo mal ..."<<endl;
		}


	}



	//Prueba del constructor parametrizado
	string marca1 = "Sony";
	string modelo1 = "Bravia";
	int canal1 = 1;
	int volumen1 = 20;
	bool estado1 = true; //encendida

	Televisor t2(marca1, modelo1, canal1, volumen1, estado1);
	//Si está encendida
	if(t2.getEstado()){
		if(t2.getMarca() == "Sony"){
			if(t2.getModelo() == "Bravia"){
				if(t2.getCanal() == 1){
					if(t2.getVolumen()==20){
						cout << "El constructor parametrizado funciona correctamente."<<endl;
						cout << t2.getMarca() << " " << t2.getModelo() << " " << t2.getCanal()
										<< " " << t2.getVolumen() << " " << t2.getEstado() << endl;

					}else{
						cout << "El volumen del televisor no es el esperado porque el alumno ha hecho algo mal ..."<<endl;
					}
				}else{
					cout << "El canal del televisor no es el esperado porque el alumno ha hecho algo mal ..."<<endl;
				}
			}else{
				cout << "El modelo del televisor no es el esperado porque el alumno ha hecho algo mal ..."<<endl;
			}
		}else{
			cout << "La marca del televisor no es la esperada porque el alumno ha hecho algo mal ..."<<endl;
		}
	}else{
		cout << "El televisor está apagado porque el alumno ha hecho algo mal ..."<<endl;
	}

	return 0;
}



