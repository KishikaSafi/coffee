#ifndef __COFFEE_H
#define __COFFEE_H

#define PORTION_STANDARD	1
#define PORTION_DOUBLE		2

#define PRICE_OF_MILK	10
#define PRICE_OF_COFFEE	15
#define PRICE_OF_SHUGAR	2
#define PRICE_OF_WATER	1	

typedef enum {
	NONE		= 0,
	CAPPUCHINO  = 1,
	AMERICANO,
	ESPRESSO
} coffee_type;

int make_coffee (coffee_type type, int count_shugar, int portion, int* price);
void print_list (void);
void add_to_cart(coffee_type type, int count_shugar, int portion, int price);
#endif