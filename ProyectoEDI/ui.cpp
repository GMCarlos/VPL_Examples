/*
 * ui.cpp
 *
 *  TFG Example
 *  Author: GMCarlos_8
 */

#include <iostream>
#include <fstream>
#include <cstdlib>
#include "ui.h"




using namespace std;


UI::UI() {
	ejecutar();
}

void UI::ejecutar() {

	O = new Opendata();

	double t_start;
	double t_end;
	string barrio;
	string distrito;
	string raiz;
	string calle, calleNueva;
	string lampara, lampara2;
	string potencia1, potencia2;
	int opcion;

	bool salir=false;
	do {
		opcion = menu();
		switch(opcion){
			case 1:
				cout <<"--------------------------------"<<endl;
				cout <<"Cargando datos ... "<<endl;
				cout <<"--------------------------------"<<endl;
				cout << endl;
				O->cargarDatos();
				//O->mostrarVias();
				cout << endl;
				cout <<"--------------------------------"<<endl;
				cout <<"Carga finalizada ... "<<endl;
				cout <<"--------------------------------"<<endl;
				break;
			case 2:
				cout <<"Introduce un barrio: "<<endl;
				getline(cin, barrio);
				O->mostrarViaEnBarrio(barrio);
				break;
			case 3:
				cout <<"Introduce un distrito: "<<endl;
				getline(cin, distrito);
				O->crearFicheroViaDistrito(distrito);
				break;
			case 4:
				cout <<"Introduce un barrio: "<<endl;
				getline(cin, barrio);
				O->barriosAdyacentes(barrio);
				break;
			case 5:
				O->mayorConcetracionFarolas();
				break;
			case 6:
				cout <<"Lámparas disponibles: "<<endl;
				cout <<"VSAP | VMCC | HM | FCBC | F | MC | H | VSPB: "<<endl;
				cout <<"Solicite un tipo de lámpara: "<<endl;
				getline(cin, lampara);
				O->ficheroLampara(lampara);
				break;
			case 7:
				cout <<"Introduce las letras de comienzo: "<<endl;
				getline(cin, raiz);
				t_start = Timer::getTime();
				O->mostrarViasPorSubcadena(raiz);
				t_end = Timer::getTime();
				cout << "Encontrado en t = " << std::fixed << t_end - t_start << " secs." << endl;
				cout << "Ahora por árboles..." << endl;
				O->mostrarViasSubcadenaArbol(raiz);
				break;
			case 8:
				O->consumoDistrito();
				break;
			case 9:
				cout <<"Lámparas disponibles: "<<endl;
				cout <<"VSAP | VMCC | HM | FCBC | F | MC | H | VSPB: "<<endl;
				cout <<"Solicite un tipo de lámpara: "<<endl;
				getline(cin, lampara);
				cout <<"Introduzca la potencia: "<<endl;
				getline(cin,potencia1);
				cout <<"¿Por qué tipo desea sustituirla? "<<endl;
				getline(cin, lampara2);
				cout <<"Introduzca la nueva potencia: "<<endl;
				getline(cin, potencia2);

				O->informeAhorro(lampara, atoi(potencia1.c_str()),lampara2, atoi(potencia2.c_str()));
				break;
			case 10:
				cout <<"Introduce el nombre de la vía a cambiar: "<<endl;
				getline(cin, calle);
				if(O->buscarVia(calle) == true){
					cout <<"Introduce el nuevo nombre de la vía: "<<endl;
					getline(cin, calleNueva);
					O->cambiarNombreVia(calle,calleNueva);
				}
				else{
					cout <<"No se ha encontrado la vía que buscas"<<endl;
				}
				break;
			case 0:
				// Finalizar

				salir=true;
				break;
			default:
				cout << "ERROR en la opcion de menu" << endl;
				break;
		}

	} while (!salir);


}


int UI::menu(){

	int opcion;

	do {
		cout << endl;
		cout << "__________________ MENU PRINCIPAL ________________" << endl << endl;

		cout << "   1. Carga de datos                          " << endl;
    	cout << "   2. Mostrar vías de un barrio               " << endl;
    	cout << "   3. Generar fichero vías de un distrito     " << endl;
    	cout << "   4. Barrios adyacentes                      " << endl;
    	cout << "   5. Vía con mayor concentración de farolas  " << endl;
    	cout << "   6. Generar fichero de farolas según lámpara" << endl;
    	cout << "   7. Buscar vías, empieza por...             " << endl;
		cout << "   8. Consumo eléctrico por distrito          " << endl;
		cout << "   9. Informe de ahorro                       " << endl;
		cout << "  10. Cambiar nombre a una vía                " << endl;
		cout <<endl;
		cout << "   0. Finalizar.                              " << endl;
		cout << "Opcion:  ";
		cin>> opcion;
		cin.ignore();

	} while ((opcion < 0) || (opcion > 11));

	return opcion;
}




UI::~UI() {

}


int main () {
	UI ui;

}




