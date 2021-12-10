#ifndef CLASSES_H_
#define CLASSES_H_

#include <stdlib.h> // Função exit() para falhas críticas

#include <iostream>
#include <vector>

using namespace std;
/* Principal */
class Componente{
public:
	Componente(int ins, int out);
	// Definir Entradas
	void set_input(bool* inputs);
	// Receber Saídas
	vector<bool> get_output();
	// Imprimir Saídas	=> Mais para Debug
	void print_output();
	// Imprimir Entradas=> Mais para Debug
	void print_input();
protected:
	vector<bool> _entradas;
	vector<bool> _saidas;
};

/* Portas Lógicas */
class AND : public Componente{
public:
	AND(int ins);
	// Realizar Operação Lógica
	void processar();
private:
};

class NOT : public Componente{
public:
	NOT(int linhas);
	// Realizar Operação Lógica
	void inverter();
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
	Latch_SR(bool e);
	void processar();
};

#endif /* CLASSES_H_ */
