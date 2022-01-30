#include "portas.h"

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
		if( (dados[i]==1) | (dados[i]==0) )
			_entradas[i]=dados[i];
		}
}
// Inverter Entrada
void Componente::invert_ent(){
	unsigned size=_entradas.size(), i;

	#ifdef DEBUG
	cout << "Invertendo entrada "; (*this).print_input();
	#endif

	for (i=0; i<size; i++)
		_entradas[i]=not _entradas[i];
}
// Inverter Saída
void Componente::invert_out(){
	unsigned size=_saidas.size(), i;

	#ifdef DEBUG
	cout << "Invertendo saída "; (*this).print_output();
	#endif

	for (i=0; i<size; i++)
		_saidas[i]=not _saidas[i];
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

	#ifdef DEBUG
	cout << "Operação AND nas entradas "; (*this).print_input();
	#endif

	for(i=1; i<size; i++)
		ini&=_entradas[i];

	_saidas[0]=ini;
}

NOT::NOT(int linhas) : Componente (linhas, linhas){}
// Inverter Todas as Entradas
void NOT::inverter(){
	unsigned i, size= _entradas.size();

	#ifdef DEBUG
	cout << "Operação NOT nas entradas "; (*this).print_input();
	#endif

	for(i=0; i<size; i++){
		_saidas[i]=not _entradas[i];
	}
}
// Processar
OR::OR(int ins) : Componente (ins, 1){}
void OR::processar(){
	unsigned i, size= _entradas.size();

	bool ini= _entradas[0];

	#ifdef DEBUG
	cout << "operação OR com as entradas "; (*this).print_input();
	#endif

	for(i=0; i<size; i++){
		ini |= _entradas[i];
	}

	_saidas[0]=ini;
}

/* Memórias */

// Latch SR
Latch_SR::Latch_SR() : Componente (2,2){}
// i=0 é normal, i=1 adiciona enable como terceira entrada
Latch_SR::Latch_SR(bool i=0) : Componente (2+i, 2){}
void Latch_SR::processar(){
	#ifdef DEBUG
	cout << "Memória 'LATCH SR' nas entradas "; (*this).print_input();
	#endif

	// Enable
	if (_entradas.size()==3){ // Se Enable existe,
		if (!_entradas[2]) // Não modifica saídas se Enable=0
			return;
	}
	// Set
	if(_entradas[0]){
		_saidas[0]=!_entradas[1];
		_saidas[1]=0;
		return;
	}
	// Reset
	if(_entradas[1]){
		_saidas[0]=0;
		_saidas[1]=1;
		return;
	}
	return; // Se foi passado nulo, não altera
}

// Latch D
Latch_D::Latch_D() : Componente(2, 2){}
void Latch_D::processar(){
	#ifdef DEBUG
	cout << "Memória 'LATCH D' nas entradas "; (*this).print_input();
	#endif

	if(!_entradas[1]) // Só modifica se Enable estiver ativado
		return;

	_saidas[0]=_entradas[0];
	_saidas[1]=!_entradas[0];
}






