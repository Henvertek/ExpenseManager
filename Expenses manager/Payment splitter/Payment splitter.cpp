// Payment splitter.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	float fullPrice, perPerson, left = 0;
	float paid[4] = {0, 0, 0, 0};
	string names[4] = {"Gabriel", "Juan", "Pablo", "Tomas"};
	cout << "Total del ticket:\n>>> $";
	cin >> fullPrice;
	left = fullPrice;
	perPerson = fullPrice / 4;
	cout << "Deberia pagar " << perPerson << " cada uno.\n\n";
	for(int i = 0; i < 4; i++) {
		cout << "Cuanto pago " << names[i] << "?\n>>> $";
		cin >> paid[i];
		left -= paid[i];
	}
	if(left > 0) {
		cout << "\nFaltan $" << left << ". Quien pago eso?\n";
		int input;
		for(int i = 0; i < 4; i++) {
			cout << i + 1 << "......" << names[i] << endl;
		}
		cout << ">>> ";
		cin >> input;
		paid[input - 1] += left;
	}
	cout << endl;
	for(int i = 0; i < 4; i++) {
		if(paid[i] < perPerson) {
			cout << names[i] << " debe poner " << perPerson - paid[i] << ".\n";
		}
	}
	cout << endl;
	for(int i = 0; i < 4; i++) {
		if(paid[i] > perPerson) {
			cout << names[i] << " debe tomar " << paid[i] - perPerson << " del fondo acumulado.\n";
		}
	}
	cout << "\n\n\n";
	system("pause");
  return 0;
}