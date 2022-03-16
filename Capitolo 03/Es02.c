/* Author: Matteo Gianferrari
 * Data: 20/01/2022
 * Definire una macro ABSOLUTE(num) che calcola il valore assoluto di un numero. 
 * Per verificarne il funzionamento, la sistesti con un programma che effettua le chiamate
 */
#include <stdio.h>

#define ABSOLUTE(num) (num < 0) ? num * -1 : num

int main(){
	printf("%d\n", ABSOLUTE(-1));
	printf("%d\n", ABSOLUTE((3 - 4)));
	printf("%d\n", ABSOLUTE(7));
	printf("%d\n", ABSOLUTE((-8 - 3)));
	return 0;
}
