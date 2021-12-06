#include "classes.h"


int main(){
	int ins=3;

	NOT porta_1(ins);

	bool input[ins]= {1, 1, 0};

	porta_1.set_input(input);

	porta_1.print_input();

	porta_1.inverter();

	porta_1.print_output();
}
