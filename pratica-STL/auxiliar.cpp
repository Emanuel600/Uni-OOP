// Definie como os métodos da classe "auxiliar" operam

#include "auxiliar.h"

auxiliar::auxiliar(unsigned size){
	_size= size;
}

// Recebe um conjunto de números inteiros do usuário
void auxiliar::get_array(){
	unsigned i; int num;
	cout << "Entre com todos os " << _size << " itens" << endl;

	for (i=0; i<_size; i++){
		cin >> num;
		_num.push_back(num);
	}
}
// Imprime um conjunto de ítens na forma: "{ num num num ... num }"
void auxiliar::print_array(){
	unsigned i;

	cout << "{ ";
	for (i=0; i<_size; i++)
		cout << _num[i] << " ";
	cout << "}" << endl;
}
// Organizar o vetor em ordem crescente
void auxiliar::sort_array(){
	sort(_num.begin(), _num.end());
}
// Imprime último valor de um vetor
int auxiliar::get_last(){
	return _num.back();
}
// Imprime primeiro valor de um vetor
int auxiliar::get_first(){
	return _num.front();
}

