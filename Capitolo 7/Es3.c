/* Author: Matteo Gianferrari
 * Data: 01/02/2022
 * Si scriva una funzione che riceve una stringa che rappresenta un tempo nel formato hh:mm:ss tt (il termine tt puo' valere "AM" o "PM")
 * e costruisce una struttura che ne rappresenta ora, minuti e secondi (si usi la struttura definita all'esercizio precedente).
 * La funzione dovra' restituire un intero che vale 0 se il tempo rappresentato dalla stringa e' valido, 1 altrimenti.
 */
#include <stdio.h>

struct tempo{
	int ore;
	int minuti;
	int secondi;
};

int check_time_format(char *str);

int main(int argc, char *argv[]){
	if(argc != 2){
		printf("Utilizzo: 7.3 \"hh:mm:ss tt\"\n");
		return -1;
	}
	
	printf(check_time_format(argv[1]) ? "Non valido\n" : "Valido\n");
	return 0;
}

int check_time_format(char *str){
	struct tempo t1;
	char string[3];
	
	if(sscanf(str, "%d:%d:%d %s", &t1.ore, &t1.minuti, &t1.secondi, string) != 4){
		printf("Errore formato immesso\n");
		return -1;
	}
	else if((t1.ore < 0 || t1.ore > 12) || (t1.minuti < 0 || t1.minuti > 59) || (t1.secondi < 0 || t1.secondi > 59))
		return 1;
	else if((strcmp(string, "AM") != 0) && (strcmp(string, "PM") != 0))
		return 1;
		
	return 0;
}
