
#ifndef COMPLEX_H_
#define COMPLEX_H_

#include <cmath>
#include <complex>
#include <iostream>

using namespace std;

class Complexos {
	// Partes real e imaginária
	double _real, _img;

public:
	// Ler
	void com_read();
	// Imprimir
	void display();

	double get_real();
	double get_img();

	// Declaração do operador +
	Complexos operator+(Complexos);

	// Declaração do operador -
	Complexos operator-(Complexos);

	// Declaração do operador *
	Complexos operator*(Complexos);

	// Declaração do operador /
	Complexos operator/(Complexos);

	// Declaração do operador ~
	Complexos operator~(void);
};

#endif /* COMPLEX_H_ */
