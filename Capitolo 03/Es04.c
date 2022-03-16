/* Author: Matteo Gianferrari
 * Data: 20/01/2022
 * Scrivere un programma che calcola l'area e il perimetro di un cerchio di raggio r facendo uso della macro PI 
 * (definita in math.h) che definisce la costante 3,14159 e di due macro AREA(r) e PERIMETRO(r) che effettuano i 2 calcoli
 */
#include <stdio.h>
#include <math.h>

#define AREA(r) M_PI * r * r
#define PERIMETRO(r) 2 * M_PI * r

int main(){
	printf("Area del cerchio: %f\n", AREA(6));
	printf("Perimetro del cerchio: %f\n", PERIMETRO(6));
	return 0;
}
