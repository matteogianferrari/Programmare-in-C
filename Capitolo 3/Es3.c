/* Author: Matteo Gianferrari
 * Data: 20/01/2022
 * Definire una macro CUBE(num) che calcola il cubo di un numero e per
 * verificarne il funzionamento, la sistesti con un programma che effettua le chiamate
 */
#include <stdio.h>

#define CUBE(num) num * num * num

int main(){
	printf("%d\n", CUBE(6));
	printf("%d\n", CUBE((3 + 4)));
	printf("%d\n", CUBE(7));
	printf("%d\n", CUBE((9 - 3)));
	return 0;
}
