#ifndef CLASSES_H_
#define CLASSES_H_
//
#include <stdlib.h> // Função exit() para falhas críticas

#include <iostream>
#include <vector>

using namespace std;
/* Principal */
// Geral
class Componente{
public:
	Componente();
	Componente(int ins, int out);
	// Definir Entradas
	void set_input(vector<bool> inputs);
	void set_input(bool* inputs);
	/* Receber */
	vector<bool> get_output(); // Saída
	vector<bool> get_input(); // Entrada
	// Imprimir Saídas  => Mais para Debug
	void print_output();
	// Imprimir Entradas=> Mais para Debug
	void print_input();
	// Processar Entradas
	virtual void processar()=0;
protected:
	vector<bool> _entradas;
	vector<bool> _saidas;
};
// Blocos Lógicos => Se comporta mais como uma linha de componentes
/* Ainda falta muito a ser implementado propriamente
class Bloco{
public:
	Bloco(Componente* porta);

	void processar();
	void operator()(Componente* porta);
private:
	vector<Componente*> Integrados;
};
*/
/* Portas Lógicas */
class AND : public Componente{
public:
	AND(int ins);
	// Realizar Operação Lógica
	void processar();
};

class NOT : public Componente{
public:
	NOT(int linhas);
	// Realizar Operação Lógica
	void processar();
};

class OR : public Componente{
public:
	OR(int ins);
	// Realizar Operação Lógica
	void processar();
};

/* Memórias */
// Latch SR
class Latch_SR : public Componente{
public:
	Latch_SR(bool e); // Enable
	Latch_SR();

	void processar();
};
// Latch D
class Latch_D : public Componente{
public:
	Latch_D();

	void processar();
};

/* Testes */
// Individual
void testar(Componente* porta, vector<bool> esper, vector<bool> ent); // Porta a ser testada e resultado esperado
// Rotina
void teste();
#endif /* CLASSES_H_ */
