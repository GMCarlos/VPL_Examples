============================================================================
 Name         Bateria.cpp
 Author       Carlos Guillen
 Version     
 Copyright    Your copyright notice
 Description  Hello World in C++, Ansi-style
============================================================================

#include iostream
using namespace std;

void mostrar(int numeroBilletes, float valor, float numero) {
	if (numeroBilletes  0) {
		if (numeroBilletes == 1) {
			if(valor2){
				cout  1 billete de   valor   euros  endl;
			}else{
				if(valor1){
					cout  1 moneda de   numero   céntimos  endl;
				}else{
					cout  1 moneda de   valor   euros  endl;
				}

			}

		} else {
			if(valor2){
				cout  numeroBilletes   billetes de   valor   euros  endl;
			}else{
				if(valor1){
					cout  numeroBilletes   monedas de   numero   céntimos  endl;
				}else{
					cout  numeroBilletes   monedas de   valor   euros  endl;
				}

			}

		}
	}
}


int main() {
	int billetes500 = 0;
	int billetes200 = 0;
	int billetes100 = 0;
	int billetes50 = 0;
	int billetes20 = 0;
	int billetes10 = 0;
	int billetes5 = 0;
	int monedas2euro = 0;
	int monedas1euro = 0;
	int monedas50 = 0;
	int monedas20 = 0;
	int monedas10 = 0;
	int monedas5 = 0;
	int monedas2 = 0;
	int monedas1 = 0;
	cout  Introduzca la cantidad de dinero  endl;
	float dinero=0;
	cin  dinero;
	if (dinero  0) {
		cout   error  endl;
	} else {
		if (dinero == 0) {
			cout  No necesita monedas ni billetes.  endl;
		} else {
			Averiguamos los billetes de 500
			while (dinero = 500) {
				dinero = dinero - 500;
				billetes500++;

			}
			Averiguamos los billetes de 200
			while (dinero = 200) {
				dinero = dinero - 200;
				billetes200++;
			}
			Averiguamos los billetes de 100
			while (dinero = 100) {
				dinero = dinero - 100;
				billetes100++;
			}
			Averiguamos los billetes de 50
			while (dinero = 50) {
				dinero = dinero - 50;
				billetes50++;
			}
			Averiguamos los billetes de 20
			while (dinero = 20) {
				dinero = dinero - 20;
				billetes20++;
			}
			Averiguamos los billetes de 10
			while (dinero = 10) {
				dinero = dinero - 10;
				billetes10++;
			}
			Averiguamos los billetes de 50
			while (dinero = 5) {
				dinero = dinero - 5;
				billetes5++;
			}
			Averiguamos las monedas de 2 euros
			while (dinero = 2) {
				dinero = dinero - 2;
				monedas2euro++;
			}

			Averiguamos las monedas de 2 euros
			while (dinero = 1) {
				dinero = dinero - 1;
				monedas1euro++;
			}

			Averiguamos las monedas de 50 centimos
			while (dinero = 0.5) {
				dinero = dinero - 0.5;
				monedas50++;
			}
			Averiguamos las monedas de 50 centimos
			while (dinero = 0.2) {
				dinero = dinero - 0.2;
				monedas20++;
			}
			Averiguamos las monedas de 50 centimos
			while (dinero = 0.1) {
				dinero = dinero - 0.1;
				monedas10++;
			}
			Averiguamos las monedas de 5 centimos
			while (dinero = 0.05) {
				dinero = dinero - 0.05;
				monedas5++;
			}
			Averiguamos las monedas de 2 centimos
			while (dinero = 0.02) {
				dinero = dinero - 0.02;
				monedas2++;
			}
			Averiguamos las monedas de 2 centimos
			while (dinero = 0.01) {
				dinero = dinero - 0.01;
				monedas1++;
			}

			Mostramos el valor en billetes y monedas
			mostrar(billetes500, 500, 500);
			mostrar(billetes200, 200, 200);
			mostrar(billetes100, 100, 100);
			mostrar(billetes50, 50, 50);
			mostrar(billetes20, 20, 20);
			mostrar(billetes10, 10, 10);
			mostrar(billetes5, 5, 5);
			mostrar(monedas2euro, 2, 2);
			mostrar(monedas1euro, 1, 1);
			mostrar(monedas50, 0.5, 50);
			mostrar(monedas20, 0.2, 20);
			mostrar(monedas10, 0.1, 10);
			mostrar(monedas5, 0.05, 5);
			mostrar(monedas2, 0.02, 2);
			mostrar(monedas1, 0.01, 1);




		}
	}


	return 0;
}