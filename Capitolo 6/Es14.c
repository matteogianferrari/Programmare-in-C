/* Author: Matteo Gianferrari
 * Data: 01/02/2022
 * Si scriva una funzione ricorsiva per verificare se due numeri interi sono primi tra loro come segue:
 * vero se x = 1 oppure y = 1
 * falso se x != 1, y != 1 e x = y
 * primi(x, y) = primi(x, y - x) se x != 1, y != 0 e x < y
 * primi(x, y) = primi(x - y, y) se x != 1, y != 0 e x > y
 */
#include <stdio.h>

int primi(int x, int y);

int main(void){
	int num1, num2;
	
	scanf("%d %d", &num1, &num2);
	
	printf(primi(num1, num2) ? "I numeri %d e %d sono primi tra loro\n" : "I numeri %d e %d non sono primi tra loro\n", num1, num2);
		
	return 0;
}

int primi(int x, int y){
	if(x == 1 || y == 1)
		return 1;
	else if(x != 1 && y != 1 && x == y)
		return 0;
	else if(x != 1 && y != 0 && x < y)
		return primi(x, y - x);
	else if(x != 1 && y != 0 && x > y)
		return primi(x - y, y);
}
