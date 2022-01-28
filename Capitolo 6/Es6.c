/* Author: Matteo Gianferrari
 * Data: 28/01/2022
 * Dato un numero N > 0 fornito da linea di comand, si calcoli il piu' piccolo numero M tale che M! > N. Si definisca nel programma una
 * funzione che calcoli il fattoriale di un numero e la funzione che svolge la verifica richiesta utilizzando la funzione fattoriale.
 */
#include <stdio.h>

unsigned long long fattoriale(int n);
int find_m(int n);

int main(int argc, char *argv[]){
	unsigned long long fact;
	int n;
	
	if(argc != 2){
		printf("Utilizzo: 6.6 [n]\n");
		return -1;
	}
	else{
		n = atoi(argv[1]);
		
		printf("%d\n", find_m(n));
		
		return 0;
	}
}

int find_m(int n){
	int m = 0;
	
	while(fattoriale(m) <= n)
		m++;

	return m;
}

unsigned long long fattoriale(int n){
	unsigned long long fact = 1;
	int i;
	
	for(i = 1; i <= n; i++)
	    fact *= i;
	
	return fact;
}
