/* Author: Matteo Gianferrari
 * Data: 10/02/2022
 * Scrivere un programma che implementi una funzione integral per il calcolo dell'integrale di funzioni. La funzione f da integrare deve essere
 * definita nell'intervallo [a, b] di integrazione. I valori a e b siano forniti da line di comando. Per garantire la generalità della funzione
 * di calcolo dell'integrale, la funzione f da integrare deve essere passata alla funzione integral mediante un puntatore a funzione.
 */
#include <stdio.h>
#include <stdlib.h>

#define STEP 0.001

double f(double x);
double integral(double a, double b, double (*f)(double), double step);

int main(int argc, char *argv[]){
	double a, b, f_x;
	
	if(argc != 3){
		printf("Utilizzo: 9.5 [a] [b]\n");
		return -1;
	}
	
	a = atof(*++argv);
	b = atof(*++argv);
	
	f_x = integral(a, b, f, STEP);
	printf("L'integrale della funzione nell' intervallo [%g, %g] vale: %g\n", a, b, f_x);
	
	return 0;
}

double f(double x){
	return (5 * x * x * x) + (4 / 5 * x * x) - (8 / 7 * x) + (14 / 37);
}

double integral(double a, double b, double (*f)(double), double step){
	double i, value = 0;
	
	for(i = a; i < b; i += step)
		value += step * (*f)(i + (step / 2));
	
	return value;
}
