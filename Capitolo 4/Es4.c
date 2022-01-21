/* Author: Matteo Gianferrari
 * Data: 21/01/2022
 * Scrivere un programma che, dato un giorno dell'anno compreso tra 1 e 365 (non considerando gli anni bisestili),
 * calcoli e restituisca il valore del mese a cui appartiene espresso come intero da 1 (Gennaio) a 12 (Dicembre)
 */
#include <stdio.h>

#define MAX_LEN 20

char days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};		/*0 iniziale per allineare i mesi all'indice*/

int month_of_day(int day);

int main(){
	char buf[MAX_LEN];
	int day;
	
	while((day = atoi(fgets(buf, sizeof(buf), stdin))) < 1 || day > 365);
	
	printf("Il mese che contiene il giorno %d e' il %d\n", day, month_of_day(day));
	
	return 0;
}

int month_of_day(int day){
	int i;
	
	for(i = 1; day > days_in_month[i]; i++)
			day -= days_in_month[i];
	
	return i;
}
