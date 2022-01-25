/* Author: Matteo Gianferrari
 * Data: 25/01/2022
 * Scrivere un programma che stampi la dimensione in byte dei diversi tipi di dati primitivi previsti nel linguaggio C.
 */
#include <stdio.h>

int main(){
	printf("Dimensione long double: %d byte\n", sizeof(long double));
	printf("Dimensione double: %d byte\n", sizeof(double));
	printf("Dimensione float: %d byte\n", sizeof(float));
	printf("Dimensione long long: %d byte\n", sizeof(long long));
	printf("Dimensione long: %d byte\n", sizeof(long));
	printf("Dimensione int: %d byte\n", sizeof(int));
	printf("Dimensione short: %d byte\n", sizeof(short));
	printf("Dimensione char: %d byte\n", sizeof(char));
	
	return 0;
}
