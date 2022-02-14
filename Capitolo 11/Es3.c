/* Author: Matteo Gianferrari
 * Data: 14/02/2022
 * Considerando la variabile num di tipo int, scrivere l'espressione che ritorna 1 se i bit di posizione 4 e 9
 * sono entrambi posti a 1, e ritorna 0 altrimenti. Si consideri avente posizione 0 il bit meno significcativo.
 */
#include <stdio.h>

int bit_mask(int n);

int main(void){
	int n = 528;
	
	printf("%d\n", bit_mask(n));
	
	return 0;
}

int bit_mask(int n){
	return (n & (1 << 4)) && (n & (1 << 9));
}
