/* Author: Matteo Gianferrari
 * Data: 14/02/2022
 * Scrivere una funzione che, ricevuti due parametri interi, restituisca 1 se uno e' multiplo dell'altro. Altrimenti restituisca 0.
 */
#include <stdio.h>

int multiplo(int a, int b);

int main(void){
	int a, b;
	
	a = 5;
	b = 10;
	
	printf(multiplo(a, b) ? "Un numero e' multiplo dell'altro\n" : "I numeri non sono multipli\n");
	
	return 0;
}

int multiplo(int a, int b){
	return (b == a || b % a == 0) || (a == b || a % b == 0);
}
