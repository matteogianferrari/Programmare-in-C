/* Author: Matteo Gianferrari
 * Data: 01/02/2022
 * Scrivere una funzione di nome multiplo() la quale, fornitale una coppia di interi, determini se il secondo sia multiplo del primo.
 * La funzione dovra' ricevere due argomenti interi e restituire 1 se il secondo valore e' multiplo del primo, 0 in caso contrario.
 * Si utilizzi questa funzione in un programma che acquisisca da tastiera una serie di coppie di interi e che abbia termine quando
 * l'utente intende terminare l'immissione di valori. A tal scopo si effettui un ciclo che ad ogni iterazione legga la coppia di valori da elaborare.
 */
#include <stdio.h>

int multiplo(int n1, int n2);

int main(void){
	int num1, num2;
	
	while(scanf("%d %d", &num1, &num2) != EOF)
		printf((multiplo(num1, num2)) ? "%d e' multiplo di %d\n" : "%d non e' multiplo di %d\n", num2, num1);
		
	return 0;
}

int multiplo(int n1, int n2){
	return n2 == n1 || n2 % n1 == 0;
}
