/*
 * prat-comp.cpp
 *
 *  Created on: 13 Dec 2021
 *      Author: desker
 */

// Complex Number Calculator using C++
#include "complex.h"

int main(){
	cout << "**********************Calculadora Simples "
			"de Números Complexos***************************" << endl;

	Complexos o1, o2, o3;

	char op;
	do {
		cout << "Entre P para terminar o programa"
				" e S para iniciá-lo" << endl;
		cin >> op;

		switch (op) {
		case 'S':
			// Iniciar o Programa
			cout << "Entre com o Primeiro Número: \n";

			// Ler os números
			o1.com_read();
			cout << "Entre com o Segundo Número: \n";
			o2.com_read();
			cout << "Entre com as Operações ou entre 'D' Para Mostrar os Números"
					" Entrados, 'R' Para Imprimir as Partes Reais dos Números"
					" ou 'I' Para Imprimir as Partes Imaginárias" << endl;
			break;
		case 'D':
			cout << "Valores:\n";

			// Chamar Função Display para Imprimir os Números
			cout << "Número 1:\n";
			o1.display();
			cout << "Número 2:\n";
			o2.display();
			break;
		case '+':
			o3 = o1 + o2;
			cout << "Valor da Soma: \n";
			o3.display();
			break;
		case '-':
			o3 = o1 - o2;
			cout << "Valor da Subtração: \n";
			o3.display();
			break;
		case '*':
			o3 = o1 * o2;
			cout << "Valor da Multiplicação: \n";
			o3.display();
			break;
		case '/':
			o3 = o1 / o2;
			cout << "Valor da Divisão: \n";
			o3.display();
			break;
		case 'R':
			cout << "Valor Real do Primeiro Número: "
				<< o1.get_real() << endl;
			cout << "Valor Real do Segundo Número: "
				<< o2.get_real() << endl;
			break;
		case 'I':
			cout << "Valor Imaginário do Primeiro Número: "
				<< o1.get_img() << endl;
			cout << "Valor Imaginário do Segundo Número: "
				<< o2.get_img() << endl;
			break;
		case 'P':
			return 1;
			break;
		default:
			cout << "Enter valid option!!";
			break;
		}
	} while (1);
	return 0;
}



