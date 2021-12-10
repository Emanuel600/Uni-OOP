#include "classes.h"


int main(){
	unsigned ins=3, i;
	bool input[ins];

	Latch_SR porta_1(1);

	while(1){
		cout << "Entradas: ";
		for (i=0; i<ins ; i++)
			cin >> input[i];
		cout << endl;

		porta_1.set_input(input);
		porta_1.processar();
		cout << "Saídas";
		porta_1.print_output();
	}
}
