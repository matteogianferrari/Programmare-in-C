/* Author: Matteo Gianferrari
 * Data: 20/01/2022
 * Si scriva una sola istruzione per eseguire ognuna delle seguenti operazioni:
 * -dichiarare due variabili intere a e b e inizializzarle rispettivamente ai valori 0 e 3;
 * -assegnare alla variabile y il valore dell'espressione m * x + q
 * -date 2 variaibli intere a e b (inizializzate rispettivamente ai valori 3 e 2) si stampi il messaggio "3 + 2 = 5", ottenuto stampando il valore delle variabili a e b eil risultato della loro somma
 */
#include <stdio.h>

int main(){
	int a = 0, b = 3;	/*1 istruzione*/
	
	int m, x, q;		/*Per non generare errori*/
	int y = m * x + q;	/*1 istruzione*/
	
	a = 3;	/*Inizializzazione*/
	b = 2;	/*Inizializzazione*/
	printf("%d + %d = %d\n", a, b, a + b);	/*1 istruzione*/
	
	return 0;
}
