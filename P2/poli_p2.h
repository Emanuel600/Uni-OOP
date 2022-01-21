/*
 * Declaração de classes e métodos
 */

#ifndef POLI_P2_H_
#define POLI_P2_H_

#include <iostream>

using namespace std;

class Funcao{
public:
	Funcao();
	Funcao(Funcao* f);
	double operator()(double x);
	double integrar(Funcao* f, double x0, double x1, double step);
};




#endif /* POLI_P2_H_ */
