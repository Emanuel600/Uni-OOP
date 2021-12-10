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
// Processar
OR::OR(int ins) : Componente (ins, 1){}
void OR::processar(){
	unsigned i, size= _entradas.size();

	bool ini= _entradas[0];

	for(i=0; i<size; i++){
		ini |= _entradas[i];
	}

	_saidas[0]=ini;
}

/* Memórias */

//Latch SR
// i=0 é normal, i=1 adiciona enable como terceira entrada
Latch_SR::Latch_SR(bool i=0) : Componente (2+i, 2){}
void Latch_SR::processar(){
	// Enable
	if (_entradas.size()==3){ // Se Enable existe,
		if (!_entradas[2]) // Não modifica saídas se Enable=0
			return;
	}
	// Reset
	switch(_entradas[0]){
	case 0: // Latch
		break;
	case 1:
		_saidas[0]=0;
		_saidas[1]=!_entradas[1];
		return;
	default:
		cerr << "Caso inesperado, valor de Reset= " << _entradas[0];
		cerr << "Quando deve ser ou '1' ou '0'" << endl;
		exit(-1); // Erro crítico
	}
	// Set
	switch(_entradas[1]){
	case 0: // Latch
		break;
	case 1:
		_saidas[0]=1;
		_saidas[1]=0;
		break;
	default:
		cerr << "Caso inesperado, valor de Set= " << _entradas[1];
		cerr << "Quando deve ser ou '1' ou '0'" << endl;
		exit(-1); // Erro crítico
	}
}








