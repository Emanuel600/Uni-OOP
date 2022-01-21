/*
 * main_p2.cpp
 *
 *  Created on: 2 de jan. de 2022
 *      Author: emanuel
 */

#include "poli_p2.h"

int main(){
	Funcao teste;

	double area=teste.integrar(&teste, 0, 1, 1e-10);

	cout << area << endl;
}


