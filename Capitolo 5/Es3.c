/* Author: Matteo Gianferrari
 * Data: 25/01/2022
 * Scrivere un programma che, letto da tastiera un singolo carattere, verigichi se e' un carattere alfabetico (si puo' utilizzare la funzione isalpha dichiarata in ctype.h).
 * In caso lo sia, stampi a video se questo e' maiuscolo o minuscolo, altrimenti segnali un errore. Sfruttare le funzioni di libreria definite in ctype.h come isupper e islower.
 */
#include <stdio.h>
#include <ctype.h>

#define MAX_LEN 20

int main(){
	char s[MAX_LEN];
	char c;
	
	fgets(s, sizeof(s), stdin);
	c = s[0];
	
	if(isalpha(c))
		printf((islower(c)) ? "Minuscolo\n" : "Maiuscolo\n");
	else
		printf("Non e' un carattere alfabetico\n");

	return 0;
}
