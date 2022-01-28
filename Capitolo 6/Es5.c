/* Author: Matteo Gianferrari
 * Data: 28/01/2022
 * Si scriva una funzione per il calcolo del discriminante di una equazione di secondo grado. Dati i
 * coefficienti a, b e c dell'equazione ax^2 + bx + c = 0, il discriminante si calcola come b^2 - 4ac.
 */
#include <stdio.h>

int discriminante(int a, int b, int c);

int main(int argc, char *argv[]){
	int a, b, c;
	
	if(argc != 4){
		printf("Utilizzo: 6.5 [a] [b] [c]\n");
		return -1;
	}
	else{
		a = atoi(argv[1]);
		b = atoi(argv[2]);
		c = atoi(argv[3]);
		
		printf("b^2 - 4ac = %d\n",discriminante(a, b, c));
		
		return 0;
	}
}

int discriminante(int a, int b, int c){
	return (b * b) - (4 * a * c);
}
