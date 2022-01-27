/*
 * Declaração de classes e métodos
 */

#ifndef POLI_P2_H_
#define POLI_P2_H_
// Includes
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Funcao{
public:
	// Construtores
	Funcao();
	Funcao(Funcao *f);
	// Métodos
	virtual double operator()(double x)=0;
	double integrar(Funcao *f, double x0, double x1, double step);
};

class Constante: public Funcao{
public:
	Constante(double val);
	double operator()(double x);
private:
	double _value;
};

class Escalar : public Funcao{
public:
	// Construtores
	Escalar(double val, Funcao *f);
	Escalar(double val);
	Escalar(Funcao *f);
	Escalar();
	// Operador
	double operator()(double x);
private:
	Funcao *comp;
	double _value;
};

class Potencial: public Funcao{
public:
	// Construtores
	Potencial(double val, Funcao *f);
	Potencial(double val);
	Potencial(Funcao* f);
	Potencial();
	// Operador
	double operator()(double x);
private:
	Funcao *comp;
	double _value;
};

class Exponencial: public Funcao{
public:
	// Construtores
	Exponencial(double val, Funcao *f);
	Exponencial(double val);
	Exponencial(Funcao *f);
	Exponencial();
	// Operador
	double operator()(double x);
private:
	Funcao *comp;
	double _value;
};

class Seno: public Funcao{
public:
	// Construtores
	Seno(double val, Funcao *f);
	Seno(double val);
	Seno(Funcao *f);
	Seno();
	// Operador
	double operator()(double x);
private:
	Funcao *comp;
	double _value;
};

class Coseno: public Funcao{
public:
	// Construtores
	Coseno(double val, Funcao *f);
	Coseno(double val);
	Coseno(Funcao *f);
	Coseno();
	// Operador
	double operator()(double x);
private:
	Funcao *comp;
	double _value;
};
class FuncaoAgregada: public Funcao{
public:
	void agrega(Funcao *f);
	double operator()(double x);
private:
	vector<Funcao*> funcoes;
};

// Testar Funções
void testar(Funcao *f, double a, double b, double step, double erro); // Função para testar uma função f
void teste();
#endif /* POLI_P2_H_ */
