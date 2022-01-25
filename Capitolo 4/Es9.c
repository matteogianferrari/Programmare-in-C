/* Author: Matteo Gianferrari
 * Data: 25/01/2022
 * Scrivere un programma che, dato un numero intero espresso in base decimale, lo converta in una base 
 * b < 10 fornita dall'utente. Come parametro accetti il valore da convertire e la nuova base.
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 20

int main(){
	char s[MAX_LEN];
	int i, n, b, num;
	
	fgets(s, sizeof(s), stdin);
	n = atoi(s);
	fgets(s, sizeof(s), stdin);
	b = atoi(s);
	
	for(i = 1; n != 0; i *= 10){
		num += (n % b) * i;
		n /= b; 
	}
	
	printf("%d\n", num);
	return 0;
}
