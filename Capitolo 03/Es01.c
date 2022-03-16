/* Author: Matteo Gianferrari
 * Data: 20/01/2022
 * Effettuare il calcolo della valuta da euro a lire e viceversa definendo una macro che definisce
 * la costante 1936,36 e due macro con parametri che effettuano ciascuno una delle due conversioni
 */
#include <stdio.h>

#define CONVERTION 1936.36

#define EUR_TO_ITL(euro) euro * CONVERTION
#define ITL_TO_EUR(lire) lire / CONVERTION

int main(){
	printf("Euro a lira: %.3f\n", EUR_TO_ITL(1000));
	printf("Lira a euro: %.3f\n", ITL_TO_EUR(1936360));
	return 0;
}
