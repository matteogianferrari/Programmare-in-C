/* Author: Matteo Gianferrari
 * Data: 26/01/2022
 * Scrivere un programma che copia un vettore di interi in un altro vettore di intere invertendo l'ordine degli elementi.
 */
#include <stdio.h>

#define MAX_LEN 10

int main(){
	char arr1[MAX_LEN] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	char arr2[MAX_LEN];
	int i, j;
	
	for(i = MAX_LEN - 1, j = 0; i >= 0; i--, j++)
		arr2[j] = arr1[i];
	
	printf("Array invertito:\n");
	for(i = 0; i < MAX_LEN; i++)
		printf("%d\n", arr2[i]);
	
	return 0;
}
