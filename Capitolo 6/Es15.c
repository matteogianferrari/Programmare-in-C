/* Author: Matteo Gianferrari
 * Data: 01/02/2022
 * Si scriva una funzione ricorsiva per il calcolo del potenza x^y (numeri interi non negativi) come segue:
 * espon(x, y) = 1 se y = 0
 * espon(x, y) = x * espon(x, y - 1) se y > 0
 */
#include <stdio.h>

int espon(int x, int y);

int main(void){
	int num1, num2;
	
	scanf("%d %d", &num1, &num2);
	
	printf("%d^%d = %d\n", num1, num2, espon(num1, num2));
		
	return 0;
}

int espon(int x, int y){
	return (y == 0) ? 1 : x * espon(x, y - 1);
}
