#include "portas.h"

/* Classe principal */

// Construtor
Componente::Componente(int ins, int outs){
	_entradas.assign(ins, 0);
	_saidas.assign(outs, 0);
}
// Definir Entrada
void Componente::set_input(bool* dados){
	unsigned i, size=_entradas.size();

	for(i=0; i<size; i++)
		_entradas[i]=dados[i];
}
void Componente::set_input(vector<bool> dados){ _entradas=dados; }
/* Receber */
vector<bool> Componente::get_output(){ return _saidas; }
vector<bool> Componente::get_input(){ return _entradas; }
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
/*
// 'Bloco' de Componentes
Bloco::Bloco(Componente* porta){ Integrados.push_back(porta); }
// Adicionar Mais Portas
void Bloco::operator()(Componente* porta) { Integrados.push_back(porta); } // Todo: Verificar se a porta a ser ligada é compatível com a anterior
// Processar
void Bloco::processar(){
	vector<Componente*>::iterator it, fim=Integrados.end();
	vector<bool> saida;

	for(it=Integrados.begin(); it!=fim; ++it){ // Processa as portas individualmente
		(**it).processar();
		if (it!=fim){ // Porta atual deve se conectar com outra porta
			saida=(**it).get_output();
			(**(it+1)).set_input(saida); // Entrada da próxima é a saída da anterior
		}
	}
}
*/
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


	#ifdef DEBUG
	cout << "== DEBUG START ==" << endl;
	cout << "Operação AND nas entradas "; (*this).print_input();
	cout << "Retorna "; (*this).print_output();
	cout << "== DEBUG END ==" << endl;
	#endif
}

NOT::NOT(int linhas) : Componente (linhas, linhas){}
// Inverter Todas as Entradas
void NOT::processar(){
	unsigned i, size= _entradas.size();

	for(i=0; i<size; i++){
		_saidas[i]=not _entradas[i];
	}
	#ifdef DEBUG
	cout << "== DEBUG START ==" << endl;
	cout << "Operação NOT nas entradas "; (*this).print_input();
	cout << "Retorna "; (*this).print_output();
	cout << "== DEBUG END ==" << endl;
	#endif
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

	#ifdef DEBUG
	cout << "== DEBUG START ==" << endl;
	cout << "Operação OR nas entradas "; (*this).print_input();
	cout << "Retorna "; (*this).print_output();
	cout << "== DEBUG END ==" << endl;
	#endif
}

/* Memórias */

// Latch SR
Latch_SR::Latch_SR() : Componente (2,2){}
// i=0 é normal, i=1 adiciona enable como terceira entrada
Latch_SR::Latch_SR(bool i=0) : Componente (2+i, 2){}
void Latch_SR::processar(){
	#ifdef DEBUG // Como retorna imediatamente, não é possível colocar no final
	cout << "== DEBUG START ==" << endl;
	cout << "Memória 'LATCH SR' nas entradas "; (*this).print_input();
	cout << "== DEBUG END ==" << endl;
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
	cout << "== DEBUG START ==" << endl;
	cout << "Memória 'LATCH D' nas entradas "; (*this).print_input();
	cout << "== DEBUG END ==" << endl;
	#endif

	if(!_entradas[1]) // Só modifica se Enable estiver ativado
		return;

	_saidas[0]=_entradas[0];
	_saidas[1]=!_entradas[0];
}

/* Testes */
// Individual - porta
void testar(Componente* porta, vector<bool> esp, vector<bool> ent){
	(*porta).set_input(ent);
	(*porta).processar();

	cout << "Resultado: {"; // print_output não funcionou

	vector<bool> saida=(*porta).get_output();
	unsigned i, size=saida.size();


	for(i=0; i<size; i++)
		cout << saida[i];

	cout << "}" << endl;

	if((*porta).get_output()==esp)
		cout << "Resultado foi conforme esperado" << endl;
	else
		cerr << "Resultado diverge do esperado" << endl;
}
// Individual - 'bloco'
/* # TODO */
void teste(){
	vector<bool> esp, ent;
	AND and_port(2);

	ent.assign(2, 0); esp.assign(1, 0);
	testar(&and_port, esp, ent);

	ent[0]=1; esp[0]=0;
	testar(&and_port, esp, ent);

	OR or_port(2);

	ent[1]=1; esp[0]=1;
	testar(&or_port, esp, ent);

	OR or_port1(2);

	ent[0]=or_port.get_output()[0];  // Deve retornar 1
	ent[1]=and_port.get_output()[0]; // Deve retornar 0

	esp[0]=1;

	testar(&or_port1, esp, ent);

	NOT invert(1);

	ent.pop_back(); ent[0]=or_port1.get_output()[0]; // Deve retornar 1

	esp[0]=0;

	testar(&invert, esp, ent);
/*
	Bloco linha(&or_port1);
	linha(&invert);

	ent[0]=1; ent.push_back(0);
	esp[0]=0;

	testar(&linha, esp, ent);
*/
}

