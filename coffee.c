#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "coffee.h"

struct init_coffee{
	
	int coffee;
	int milk;
	int shugar;
	int water;
};

static struct init_coffee coffee;

struct cart_list{
	
	coffee_type type;
	int portion; 
	int count_shugar;
	int price;
	
	struct cart_list* next;
};

// Pointer to first element
struct cart_list *cart_list_start = NULL;

void add_to_cart(coffee_type type, int count_shugar, int portion, int price){
	struct cart_list *element = cart_list_start;


	if (element == NULL){
		element = malloc(sizeof(struct cart_list));
		
		element -> type = type;
		element -> portion = portion;
		element -> count_shugar = count_shugar;
		element -> price = price;
		element -> next = NULL;
		cart_list_start = element;
		return;
	}
		/*Пока существует текущий элемент и элемент 
		по адрессу next (следующий элемент)*/
	while(element != NULL && element -> next != NULL){
		// получаем адрес следующего элемента списка заказа клиента 
		element = element -> next;
	}
	
	element -> next = malloc(sizeof(struct cart_list));
		
	element = element -> next;
	
	element -> type = type;
	element -> portion = portion;
	element -> count_shugar = count_shugar;
	element -> price = price;
	element -> next = NULL;

void print_list (void) {
	struct cart_list *element = cart_list_start;

		/*Пока существует текущий элемент */
	while(element != NULL){
		switch (element -> type){
			case CAPPUCHINO:
				printf ("Cappuchino :");
				break;
			case AMERICANO:
				printf ("Americano :");
				break;
			case ESPRESSO:
				printf ("Espresso :");
				break;	
			default: 
				break;
		}
		printf ("%d rub.\n", element -> price);
		
		// получаем адрес следующего элемента списка заказа клиента 
		element = element -> next;
	}	
}


int make_coffee (coffee_type type, int count_shugar, int portion, int* price){
	
	if (type == NONE) {
		return 0;
	}
	else if(type == CAPPUCHINO) {
		coffee.coffee 	= 2 * portion;
		coffee.milk 	= 2 * portion;
		coffee.shugar 	= count_shugar;
		coffee.water 	= 10 * portion;
	}
	else if(type == AMERICANO) {
		coffee.coffee 	= 2 * portion;
		coffee.milk 	= 0;
		coffee.shugar 	= count_shugar;
		coffee.water 	= 10 * portion;
	}
	else if(type == ESPRESSO) {
		coffee.coffee 	= 5 * portion;
		coffee.milk 	= 0;
		coffee.shugar 	= count_shugar;
		coffee.water 	= 5 * portion;
	}
	
	*price = coffee.coffee * PRICE_OF_COFFEE + 
			coffee.milk * PRICE_OF_MILK + 
			coffee.shugar * PRICE_OF_SHUGAR +
			coffee.water * PRICE_OF_WATER;
	add_to_cart(type, count_shugar, portion, *price);
	return 0;	
}





