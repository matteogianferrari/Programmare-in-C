/* Author: Matteo Gianferrari
 * Data: 21/01/2022
 * Scrivere una funzione che, dati i 3 numeri forniti da tastiera, ne restituisca il massimo
 */
#include <stdio.h>

#define MAX_LEN 20

int max(int a, int b, int c); 

int main(){
	char buf[MAX_LEN];
	int a, b, c;
	
	fgets(buf, sizeof(buf), stdin);
	a = atoi(buf);
	fgets(buf, sizeof(buf), stdin);
	b = atoi(buf);
	fgets(buf, sizeof(buf), stdin);
	c = atoi(buf);
	
	printf("Il numero piu' grande e': %d\n", max(a, b, c));
	return 0;
}

int max(int a, int b, int c){
	return (a > b) ? (a > c) ? a : c : (b > c) ? b : c;
}
