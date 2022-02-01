/* Author: Matteo Gianferrari
 * Data: 01/02/2022
 * Si scriva una funzione ricorsiva per il calcolo del prodotto di due numeri interi non negativi come segue:
 * prodotto(x, y) = 0 se y = 0
 * prodotto(x, y) = x + prodotto(x, y - 1) se y > 0
 */
#include <stdio.h>

int prodotto(int x, int y);

int main(void){
	int num1, num2;
	
	scanf("%d %d", &num1, &num2);
	
	printf("prodotto: %d\n", prodotto(num1, num2));
		
	return 0;
}

int prodotto(int x, int y){
	return (y == 0) ? 0 : x + prodotto(x, y - 1);
}
