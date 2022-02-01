/* Author: Matteo Gianferrari
 * Data: 01/02/2022
 * Si scrivano due funzioni che, dato un tempo memorizzato in apposita struttura, generano una stringa
 * che rappresenta rispettivamente il tempo nei formati HH:mm:ss (formato 24 ore) e hh:mm:ss tt (formato 12 ore).
 * Si provino le due funzioni con un programma che riceve in input un tempo nel formato hh:mm:ss tt,
 * lo memorizza nella struttura e lo ristampa in entrambi i formati. Di seguito i prototipi delle funzioni.
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TEMP_LEN 3
#define TIME12_LEN 12
#define TIME24_LEN 8

struct tempo{
	int ore;
	int minuti;
	int secondi;
	char tt[TEMP_LEN];
};

char *strhh24(struct tempo *t);
char *strhh12(struct tempo *t);

int main(void){
	struct tempo t;
	char *time_f24, *time_f12;

	scanf("%d:%d:%d %s", &t.ore, &t.minuti, &t.secondi, &t.tt);
	
	time_f12 = strhh12(&t);
	time_f24 = strhh24(&t);
	
	printf("Formato 12 ore: %s\n", time_f12);
	printf("Formato 24 ore: %s\n", time_f24);
	
	free(time_f12);
	free(time_f24);
	
	return 0;
}

char *strhh12(struct tempo *t){
	char temp[TEMP_LEN], *str_f12;
	
	str_f12 = (char *)malloc(TIME12_LEN * sizeof(char));
	
	itoa(t->ore, temp, 10);
	strcpy(str_f12, temp);
	strcat(str_f12, ":");
	itoa(t->minuti, temp, 10);
	strcat(str_f12, temp);	
	strcat(str_f12, ":");
	itoa(t->secondi, temp, 10);
	strcat(str_f12, temp);
	strcat(str_f12, " ");
	strcat(str_f12, t->tt);
	
	return str_f12;
}

char *strhh24(struct tempo *t){
	char temp[TEMP_LEN], *str_f24;
	int conversion;
	
	str_f24 = (char *)malloc(TIME24_LEN * sizeof(char));
	conversion = (!strcmp(t->tt, "PM") || (t->ore == 12 && !strcmp(t->tt, "AM"))) ? 12 : 0;
	
	itoa(t->ore + conversion, temp, 10);
	strcpy(str_f24, temp);
	strcat(str_f24, ":");
	itoa(t->minuti, temp, 10);
	strcat(str_f24, temp);	
	strcat(str_f24, ":");
	itoa(t->secondi, temp, 10);
	strcat(str_f24, temp);
	
	return str_f24;
}
