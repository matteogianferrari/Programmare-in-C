/* Author: Matteo Gianferrari
 * Data: 26/01/2022
 * Si scriva un programma che data una stringa binaria derivi il numero intero decimale che essa rappresenta in notazione binaria pura.
 */
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <math.h>

#define MAX_LEN 32

int main(){
	int8_t i, j, bin_str[MAX_LEN] = "010110100001010";
	uint32_t num;
	
	for(i = strlen(bin_str) - 1, j = 0; i >= 0; i--, j++)
		num += (bin_str[i] - '0') * (int)pow(2, j);
	
	printf("Binario: %s\tDecimale: %d\n", bin_str, num);
	return 0;
}
