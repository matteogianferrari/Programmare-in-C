/* Author: Matteo Gianferrari
 * Data: 01/02/2022
 * Si scriva una funzione ricorsiva per il calcolo della somma di due numeri interi non negativi come segue:
 * somma(x, y) = x se y = 0
 * somma(x, y) = 1 + somma(x, y - 1) se y > 0
 */
#include <stdio.h>

int somma(int x, int y);

int main(void){
	int num1, num2;
	
	scanf("%d %d", &num1, &num2);
	
	printf("Somma: %d\n", somma(num1, num2));
		
	return 0;
}

int somma(int x, int y){
	return (y == 0) ? x : 1 + somma(x, y - 1);
}
