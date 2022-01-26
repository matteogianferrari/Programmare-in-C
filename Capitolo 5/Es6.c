/* Author: Matteo Gianferrari
 * Data: 25/01/2022
 * Scrivere un programma che, letto da tastiera un singolo carattere, verigichi se e' un carattere alfabetico (si puo' utilizzare la funzione isalpha dichiarata in ctype.h).
 * In caso lo sia, stampi a video se questo e' maiuscolo o minuscolo, altrimenti segnali un errore. Sfruttare le funzioni di libreria definite in ctype.h come isupper e islower.
 */
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_LEN 20
#define CONVERTION 10

int main(){
	char s[MAX_LEN], b[MAX_LEN], *ps = s;
	int base, val = 0, flag = 0;
	
	fgets(s, sizeof(s), stdin);
	do{
		base = atoi(fgets(b, sizeof(b), stdin));	
	}while(base != 2 && base != 8 && base != 10 && base != 16);
	
	for(; *ps != '\0' && *ps != '\n'; ps++){
		if(isdigit(*ps))
			val = *ps - '0';
		else if(isalpha(*ps))
			val = islower(*ps) ? *ps - 'a' + CONVERTION : *ps - 'A' + CONVERTION;
		else
			flag = 1;
		
		if(val >= base)
			flag = 1;
	}
	
	printf((flag == 1) ? "Stringa non valida\n": "Stringa valida\n");
	return 0;
}
