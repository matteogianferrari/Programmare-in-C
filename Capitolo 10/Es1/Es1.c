/* Author: Matteo Gianferrari
 * Data: 13/02/2022
 * Implementare il programma descritto nell'esercizio 5 capitolo 9, collocando tutte le funzioni da integrare in un modulo dedicato.
 */
#include <stdio.h>
#include <stdlib.h>
#include "integral.h"

#define STEP 0.001

int main(int argc, char *argv[]){
	double a, b, f_x;
	
	if(argc != 3){
		printf("Utilizzo: 10.1 [a] [b]\n");
		return -1;
	}
	
	a = atof(*++argv);
	b = atof(*++argv);
	
	f_x = integral(a, b, f, STEP);
	printf("L'integrale della funzione nell' intervallo [%g, %g] vale: %g\n", a, b, f_x);
	
	return 0;
}
