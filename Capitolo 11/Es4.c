/* Author: Matteo Gianferrari
 * Data: 14/02/2022
 * Nelle stesse condizioni dell'esercizio precedente, verificare che i due bit siano posti a 0 invece che a 1.
 */
#include <stdio.h>

int bit_mask(int n);

int main(void){
	int n = 495;
	
	printf("%d", bit_mask(n));
	
	return 0;
}

int bit_mask(int n){
	return !(n & (1 << 4)) && !(n & (1 << 9));
}
