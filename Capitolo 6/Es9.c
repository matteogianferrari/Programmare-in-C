/* Author: Matteo Gianferrari
 * Data: 30/01/2022
 * Scrivere una funzione che calcoli il valore di un polinomio di grado n per un determinato valori di x.
 * I coefficienti del polinomio devono essere contenuti in un vettore di n + 1 elementi passato alla funzione come argomento,
 * unitamente ad n ed x. Il programma che implementa e utilizza la funzione ricevera' i valori da linea di comando.
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAXLEN 10

double calc_polin(int *arr, int n, double x);

int main(int argc, char *argv[]){
	int i = 0, coef, arr[MAXLEN];
	double x, ris = 0.0;
	
	if(argc < 3){									/*nome, n, x almeno inseriti*/
		printf("Utilizzo: 6.9 [n] ... [x]\n");
		return -1;
	}
	else{
		while(--argc > 1)
			arr[i++] = atoi(*++argv);
		x = atof(*++argv);

		coef = i;

		printf("Risultato del polinomio: %f\n", calc_polin(arr, coef, x));	
		
		return 0;
	}
}

double calc_polin(int *arr, int n, double x){
	double ris = 0.0;
	int i, n_gradi = n;
	
	for(i = 0; i < n_gradi; i++)
		ris += arr[i] * pow(x, --n);
		
	return ris;
}
