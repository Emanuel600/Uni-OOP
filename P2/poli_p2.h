/*
 * Declaração de classes e métodos
 */

#ifndef POLI_P2_H_
#define POLI_P2_H_

class Funcao{
public:
	Funcao(Funcao* f);
	Funcao();
	double operator()(double x);
	double integrar(Funcao* f, double x0, double x1, double step);
};




#endif /* POLI_P2_H_ */
