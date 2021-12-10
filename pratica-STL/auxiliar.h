/*
 * auxiliar.h
 *
 *  Declaração de métodos e variáveis. Classe foi criada
 * pois facilita a ordenação do vetor, uma vez que assim
 * não tenho que alocar memória e utilizar ponteiros para
 * passar valores entre funções.
 */

#ifndef AUXILIAR_H_
#define AUXILIAR_H_

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class auxiliar{
public:
	auxiliar(unsigned size);

	int get_last();
	int get_first();

	void get_array();
	void sort_array();
	void print_array();
private:
	unsigned _size;
	vector<int> _num;
	// Toda instância da classe deve ser criada com um determinado tamanho
	auxiliar();
};



#endif /* AUXILIAR_H_ */
