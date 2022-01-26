/* Author: Matteo Gianferrari
 * Data: 26/01/2022
 * Scrivere un programma che verifica se in un vettore esiste almeno una coppia di valori uguali.
 */
#include <stdio.h>
#include <stdint.h>

#define MAX_LEN 10

int8_t main(){
	int8_t arr[MAX_LEN] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	int8_t flag = 0, i, j;

	for(i = 0; i < MAX_LEN - 1; i++)
		for(j = i + 1; j < MAX_LEN; j++)
			if(arr[i] == arr[j])
				flag = 1;
		
	printf((flag) ? "Esiste almeno una coppia di valori uguali\n": "Non esiste una coppia di valori uguali\n");
	return 0;
}
