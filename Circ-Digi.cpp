#include "portas.h"

int main(){
	unsigned ins=3, i;
	char escolha; // Se o usuário escolhe sair ou não

	bool input[ins];

	Latch_SR porta_1;

	do{
		cout << "Entradas: [A] [B] [E]" << endl;
		for (i=0; i<ins ; i++)
			cin >> input[i];
		cout << endl;

		porta_1.set_input(input);
		porta_1.processar();
		cout << "Saídas";
		porta_1.print_output();

		cout << "Entre 'q' para sair, qualquer outra letra para continuar" << endl;
		cin  >> escolha;
		cout << endl;
	} while(escolha != 'q');
}
