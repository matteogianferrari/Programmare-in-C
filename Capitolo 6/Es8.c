/* Author: Matteo Gianferrari
 * Data: 28/01/2022
 * Dati i coefficienti a, b, c di un plinomio di secondo grado ax^2 + bx + c, si calcolino e stampino a video i valori 
 * assunti dal polinomio per x che varia nell'intervallo [0, 3]. La variabile x partira' da 0 e dovra' raggiungere 3 con
 * incrementi di 0.1. Si crei a tal scopo la funzione che calcoli il valore di un polinomio arbitrario di grado 2.
 */
#include <stdio.h>
#include <stdlib.h>

double calc_polinomio(double a, double b, double c, double x);

int main(int argc, char *argv[]){
	double a, b, c, x = 0.0;
	
	if(argc != 4){
		printf("Utilizzo: 6.8 [a] [b] [c]\n");
		return -1;
	}
	else{
		a = atof(argv[1]);
		b = atof(argv[2]);
		c = atof(argv[3]);
		
		while(x < 3.1){
			printf("x: %.2f --> %.2fx^2 + %.2fx + %.2f = %.2f\n", x, a, b, c, calc_polinomio(a, b, c, x));
			x += 0.1;
		}
		
		return 0;
	}
}

double calc_polinomio(double a, double b, double c, double x){
	return (a * x * x) + (b * x) + c;
}
