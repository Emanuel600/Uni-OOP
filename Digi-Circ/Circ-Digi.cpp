#include "classes.h"


int main(){
	int ins=3;

	OR porta_1(ins);

	bool input[ins]= {0, 0, 1};

	porta_1.set_input(input);

	porta_1.print_input();

	porta_1.processar();

	porta_1.print_output();
}
