#include <stdio.h>
#include "coffee.h"


int main (int argc, char **argv){
	int price;
	printf ("Start\n");
	
	make_coffee(ESPRESSO, 2, PORTION_STANDARD, &price);
	make_coffee(AMERICANO, 2, PORTION_STANDARD, &price);
	make_coffee(CAPPUCHINO, 2, PORTION_DOUBLE, &price);
	make_coffee(ESPRESSO, 2, PORTION_DOUBLE, &price);
	print_list ();
	
	printf("Price = %d\n", price);
	
	return 0;
}
