#include "classes.h"

/* Classe principal */

// Construtor
Componente::Componente(int ins, int outs){
	_entradas.assign(ins, 0);
	_saidas.assign(outs, 0);
}
// Definir Entrada
void Componente::set_input(bool* dados){
	unsigned i; unsigned size=_entradas.size();

	for(i=0; i<size; i++){
		_entradas[i]=dados[i];
	}
}
// Receber Saída
vector<bool> Componente::get_output(){
	return _saidas;
}
// Imprimir Entrada
void Componente::print_input(){
	unsigned i, size=_entradas.size();

	cout << "{";

	for (i=0; i<size; i++)
		cout << " " << _entradas[i] << " ";

	cout << "}" << endl;
}
// Imprimir Saída
void Componente::print_output(){
	unsigned i, size=_saidas.size();

	cout << "{";

	for (i=0; i<size; i++)
		cout << " " << _saidas[i] << " ";

	cout << "}" << endl;
}

/* Classes Lógicas */

// Construtora
AND::AND(int ins) : Componente (ins, 1){}
// Processar
void AND::processar(){
	unsigned i, size=_entradas.size();

	bool ini = _entradas[0];

	for(i=1; i<size; i++)
		ini&=_entradas[i];

	_saidas[0]=ini;
}

NOT::NOT(int linhas) : Componente (linhas, linhas){}
// Inverter Todas as Entradas
void NOT::inverter(){
	unsigned i, size= _entradas.size();

	for(i=0; i<size; i++){
		_saidas[i]=not _entradas[i];
	}
}






