// Descrição do programa:

/* Recebe do usuário a qunatia de números inteiros que serão entrados,
* os imprime na ordem que foram entrados, organiza as entradas em ordem
* crescente, imprime o menor elemento seguido pelo maior e finalmente
* imprime o conjunto de números (ordenado de forma crescente)
*/
#include "auxiliar.h"

int main(){
	unsigned size;

	cout << "Entre com a quantia de itens a serem processados:" << endl;

	cin >> size;

	auxiliar obj(size);

	obj.get_array();

	cout << "==> Números entrados <==" << endl;

	obj.print_array();

	obj.sort_array();
	cout << "-=======-" << endl;

	cout << "Menor número entrado: " << obj.get_first() << endl;
	cout << "Maior número entrado: " << obj.get_last() << endl;

	cout << "-=======-" << endl;

	cout << "==> Números entrados em ordem crescente <==" << endl;
	obj.print_array();
}
