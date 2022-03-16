/* Author: Matteo Gianferrari
 * Data: 20/01/2022
 * Scrivere un programma che stampi a video il seguente messagio:
 * Benvenuto
 * alla programmazione
 * in linguaggio C!
 * Facendo uso di : -una sola chiamata a printf -tre chiamate a printf -quattro chiamate a printf
 */
#include <stdio.h>

int main(){
	/*Primo metodo*/
	printf("Benvenuto\nalla programmazione\nin linguaggio C!\n");
	
	/*Secondo metodo*/
	printf("Benvenuto\n");
	printf("alla programmazione\n");
	printf("in linguaggio C!\n");
	
	/*Terzo metodo*/
	printf("Benvenuto\n");
	printf("alla programmazione\n");
	printf("in linguaggio ");
	printf("C!\n");
	
	return 0;
}
