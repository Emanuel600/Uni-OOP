/*
 * Definição de Métodos
 */
#include "poli_p2.h"

using namespace std;
Funcao::Funcao(){}

Funcao::Funcao(Funcao* f){
}

double Funcao::operator()(double x){
	return x;
}

double Funcao::integrar(Funcao* f, double x0, double x1, double step){
	double i=0, area=0;
	Funcao dummy = f;

	for (i=x0; i<=x1; i+=step){
		area += dummy(i)*step;
	}

	return area;
}
