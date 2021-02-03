/*
 * Opendata.cpp
 *
 *  TFG Example
 *  Author: GMCarlos_8
 */

#include "Opendata.h"

using namespace std;

Opendata::Opendata() {

	calles = new Calles();
	distritos = new Distritos();
	barrios = new Barrios();
}

void Opendata::cargarVias() {
	int i;
	Via *V;
	Barrio *B;
	float laI, lonI, laM, lonM, laF, lonF;
	ifstream fent;	//flujo de lectura
	string linea;
	string campo[11];	//vector auxiliar para almacenar los 11 campos de cada via
	//Abrir fichero de lectura Via.csv
	//ToDo

	//Comprobar de que el flujo está abierto
	//if () {	//ToDo

		// leo la cabecera (primera linea del fichero) almacenamos el contenido en la variable linea
		//ToDo
		//Mientras el fichero no esté vacio
		//ToDo
		//while () {

			//Carga la información de las vias
			for (i = 0; i < 10; i++) {
				//Usamos el ; para las 10 primeras columnas
				getline(fent, campo[i], ';');
			}
				//Última columna y acaba en salto de línea, por eso no se usa el ;
				getline(fent, campo[10]);

				laI = atof(campo[6].c_str());
				lonI = atof(campo[7].c_str());
				laF = atof(campo[5].c_str());
				lonF = atof(campo[4].c_str());
				laM = atof(campo[8].c_str());
				lonM = atof(campo[9].c_str());

				//Creamos la via con los valores almacenados
				V = new Via(campo[0], atof(campo[1].c_str()), campo[2],
					atoi(campo[3].c_str()), laI, lonI, laM, lonM, laF,
					lonF, NULL);
				//Buscamos el barrio en la lista
				if(barrios->buscar(campo[10], B)){
					//Almacenamos el barrio a la vía
					V->setBarrio(B);
				}
				//Inserta en la lista de la clase calles
				calles->insertarViaOrden(V);    // Inserta en orden
				//Inserta en el arbol de la clase calles
				calles->insertarViaArbol(V);	// Inserta en arbol

		//}
		//Cerramos el flujo de lectura
		//ToDo

	//} else {
		//Mostramos mensaje de error si no se abre el fichero
		//Todo

	//}
}


void Opendata::cargarFarolas(){
	int i;

	Farola *F;

	float lat, lon;
	ifstream fent;
	string linea;
	string campo[12];

	//Abrir fichero de lectura Farola.csv
	//ToDo

	//Comprobar de que el flujo está abierto
	//Todo
		//if() {

			// leo la cabecera (primera linea del fichero) almacenamos el contenido en la variable linea
			//ToDo


			//Mientras haya información por leer del fichero
			//ToDo
			//while() {
				for(i=0; i<11; i++) {
					//Obtenemos del csv cada columna de una fila y las
					//almacenamos en el vector auxiliar llamado campo
					//Cada columna se almacena en una posicion del vector, por ejemplo, om_funcionamiento se almacenaria en campo[0],
					//om_proteccion se almacenaria en campo[1]
					//ToDo

				}
					//Obtenemos la ultima columna de una fila
					//ToDo

					lon = atof(campo[4].c_str());
					lat = atof(campo[7].c_str());
					//Creamos la farola con los datos obtenidos
					F = new Farola(campo[0], campo[1], campo[2], campo[3],  lat, atoi(campo[5].c_str()),
							lon, campo[6], atoi(campo[8].c_str()), campo[9], atoi(campo[10].c_str()), campo[11], NULL);
					//insertamos la farola en la calle
					calles->insertarFarolaFinal(F);
			//}
			//Cerramos el flujo de lectura
			//ToDo

		//}
		//else {
			//Mostramos mensaje de error si no se abre el fichero
			//ToDo

		//}
	}

void Opendata::cargarBarrios(){
	Barrio *B;
	Distrito *D;
	ifstream fent;	//flujo de lectura
	string barrio, distrito;

	//Abrir fichero de lectura Barrio.csv
	//ToDo

	//Comprobar de que el flujo está abierto
	//if () { 	//ToDo

		//Mientras haya información por leer del fichero
		//ToDo
		//while () {
			//Obtengo el barrio en la variable barrio. Tendríamos que leer solo la primera columna de la fila del csv, por eso se usa el ;
			//Con el ; leemos solo la primera columna en este caso. La siguiente linea que se pida será la segunda columna
			getline(fent, barrio, ';');

				//Obtengo del flujo de entrada el distrito y lo almaceno en la variable distrito
				//ToDo

				//Se crea el barrio
				B = new Barrio(barrio, NULL);
				//Si el distrito existe dentro de nuestra lista de distritos
				if(distritos->buscar(distrito,D)){
					//Asignamos el distrito a nuestro barrio
					B->setDistrito(D);
				}
				//Se inserta el barrio en la lista de barrios
				barrios->insertarBarrioOrden(B);

		//}
		//Cerramos el flujo de lectura
		//ToDo

		//}
		//else {
			//Mostramos mensaje de error si no se abre el fichero
			//ToDo

	//}
}

void Opendata::cargarDistritos() {

	Distrito *D;	//variable auxiliar para almacenar los Distritos
	ifstream fent;	//flujo de entrada
	string linea;	//variable auxiliar para almacenar lo que leemos del fichero
	//Creamos el flujo de entrada para leer el archivo Distrito.csv
	//ToDo

	//Comprobar de que el flujo está abierto
	//if () { //ToDo
		 // leo la cabecera (primera linea del fichero)
		//ToDo

		//Mientras el fichero no esté vacio
		//while () { //ToDo
			//obtenemos linea del flujo
			//ToDo

			//Creamos un distrito con la linea obtenida del fichero
			D = new Distrito(linea);
			//Insertamos el distrito en la lista
			distritos->insertarDistritoOrden(D);

		//}
		//Cerramos el flujo de lectura
		//ToDo

	//} else {
			//Mostramos mensaje de error si el flujo no está abierto
			//ToDo
	//}
}


void Opendata::cargarDatos(){

	cout << "Cargando distritos..." << endl;
	this->cargarDistritos();
	cout << "Cargando barrios..." << endl;
	this->cargarBarrios();
	cout << "Cargando vÃ­as..." << endl;
	this->cargarVias();
	cout << "Cargando farolas..." << endl;
	this->cargarFarolas();
	calles->insertarFarolaEnVia();
}
void Opendata::mostrarVias(){
	calles->mostrarVias();
	//calles->mostrarViasArbol();
}

void Opendata::mostrarFarolas(){
	calles->mostrarFarolas();
}

void Opendata::mostrarDistritos(){
	distritos->mostrar();
}

void Opendata::mostrarBarrios(){
	barrios->mostrarBarrios();
}

void Opendata::mostrarViaEnBarrio(string B){
	calles->mostrarViasBarrio(B);
}

void Opendata::crearFicheroViaDistrito(string D){
	calles->crearFicheroDistritos(D);
}

void Opendata::mayorConcetracionFarolas(){
	calles->viaMasFarolas();
}

bool Opendata::buscarVia(string V){
	return calles->buscarNombreVia(V);
}

void Opendata::ficheroLampara(string tipo){
	calles->ficheroTipoLampara(tipo);
}

void Opendata::cambiarNombreVia(string V, string Vn){
	calles->cambiarVia(V, Vn);
}

void Opendata::mostrarViasPorSubcadena(string R){
	calles->mostrarViasSubcadena(R);
}

void Opendata::mostrarViasSubcadenaArbol(string R){
	calles->mostrarViasSubArbol(R);
}

void Opendata::consumoDistrito(){
	ListaPI<Distrito *> *listaDistritos = new ListaPI<Distrito *>();
	ListaPI<Barrio *> *listaBarrios = new ListaPI<Barrio *>();
	ListaPI<Via *> *listaVias = new ListaPI<Via *>();
	Distrito *d;
	Barrio *b;
	Via *v;
	string nDistrito;
	string nBarrio;
	string nVia;
	float potencia = 0;

	distritos->devolverListaDistritos(listaDistritos);

	listaDistritos->moverInicio();
	while (!listaDistritos->estaVacia()) {
		listaDistritos->consultar(d);
		nDistrito = d->getDistrito();
		barrios->devolverListaBarriosDistrito(listaBarrios, nDistrito);
		listaBarrios->moverInicio();
		while (!listaBarrios->estaVacia()) {
			listaBarrios->consultar(b);
			nBarrio = b->getBarrio();
			calles->cargarViasDeBarrio(nBarrio, listaVias);
			listaVias->moverInicio();
			while (!listaVias->estaVacia()) {
				listaVias->consultar(v);
				nVia = v->getNombre();
				potencia = potencia + calles->potenciaVia(nVia);
				listaVias->borrar();
				listaVias->moverInicio();
			}

			listaBarrios->borrar();
			listaBarrios->moverInicio();
		}
		cout<<"-Distrito: "<< nDistrito <<" -Consumo: " << (potencia * 8 * 0.12149) / 1000 << endl;
		potencia=0; // actualizamos valor a 0

		listaDistritos->borrar();
		listaDistritos->moverInicio();
	}
	if(listaDistritos != NULL)
		delete listaDistritos;
	if(listaBarrios != NULL)
		delete listaBarrios;
	if(listaVias != NULL)
		delete listaVias;
}

void Opendata::informeAhorro(string tipo1, int potencia1, string tipo2, int potencia2){
	calles->calcularInformeConsumo(tipo1,potencia1,tipo2,potencia2);
}

void Opendata::barriosAdyacentes(string B){
	ListaPI <Via *> *lBAdy = new ListaPI <Via *>();
	ListaPI <Barrio *> *lB= new ListaPI <Barrio *>();
	Barrio *baux;
	string barrio;
	barrios->devolverListaBarrio(lB);  // cargo los barrios en una lista
	if(barrios->buscarBarrio(B)){      // busco que el barrio que me dan existe
		calles->cargarViasDeBarrio(B,lBAdy); //si existe, cargo las vias de ese barrio en una lista
		lB->moverInicio();
		while(!lB->finLista()){
			lB->consultar(baux);
			barrio = baux->getBarrio();
			if(calles->calcularBarriosAdyacentes(lBAdy, barrio))
				if(baux->getBarrio() != B)
					baux->mostrar();
			lB->avanzar();
		}
	}
	delete lBAdy;
	delete lB;
}

//void pruebaCargar(){
//	Calles *calle = new Calles();
//	Barrios *barrio = new Barrios();
//  Distrito *Distrito = new Distritos();
//
//	calle->cargarVias("Aguas Vivas");
//	calle->cargarVias("Agrgentina");
//	calle->cargarVias("Margallo");
//  barrio->cargarBarrio("Argentina");
//	barrio->cargarBarrio("Aldea Moret");
//	distrito->cargarDistrito(Norte);
// distrito->cargaristrito(Sur);
//	calle->mostrarVias();
//  barrio->mostraBarrios();
//  distrito->mostraDistritos();
//
//	delete calle;
//	delete barrio;
//	delete distrito;
//}
//
//void

Opendata::~Opendata() {
	if(calles != NULL)
		delete calles;
	if(distritos != NULL)
		delete distritos;
	if(barrios != NULL)
		delete barrios;
}

