/* Author: Matteo Gianferrari
 * Data: 26/01/2022
 * Scrivere un programma che accetti da linea di comando due valori interi, rispettivamente il giorno de4l mese e il mese dell'anno, e 
 * calcoli il giorno dell'anno a partire dal 1 Gennaio (es. 1 Febbraio = 32, 31 Dicembre = 365). Si considerino solo gli anni non bisestili.
 */
#include <stdio.h>

int day_of_year(int day, int month);

int main(int argc, char *argv[]){
	if(argc != 3){
		printf("Uso: 6.1 [day] [month]");
		return -1;
	}
	else{
		printf("Numero di giorni: %d\n", day_of_year(atoi(argv[1]), atoi(argv[2])));
		return 0;
	}
}

int day_of_year(int day, int month){
	int i;
	static char days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};		/*0 iniziale per allineare i mesi all'indice*/
	
	for(i = 1; i < month; i++)
		day += days_in_month[i];
	
	return day;
}
