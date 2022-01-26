/* Author: Matteo Gianferrari
 * Data: 26/01/2022
 * Modificare il programma precedente per gestire il possibile inserimento di valori non validi. Si introduca
 * una funzione che controlla la validita' della funzione da richiamare prima di usare il programma.
 */
#include <stdio.h>

int day_of_year(int day, int month);
int check_validity(int day, int month);

static char days_in_month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};		/*0 iniziale per allineare i mesi all'indice*/

int main(int argc, char *argv[]){
	int day, month;
	
	if(argc != 3){
		printf("Uso: 6.2 [day] [month]");
		return -1;
	}
	else{
		day = atoi(argv[1]);		/*se inserita una stringa di caratteri invece che di numeri atoi ritorna 0*/
		month = atoi(argv[2]);
		
		if(check_validity(day, month)){
			printf("Numero di giorni: %d\n", day_of_year(day, month));
			return 0;
		}
		else{
			printf("Valori inseriti non validi\n");
			return -2;
		}
	}
}

int day_of_year(int day, int month){
	int i;
	
	for(i = 1; i < month; i++)
		day += days_in_month[i];
	
	return day;
}

int check_validity(int day, int month){
	return ((month <= 0 || month > 12) || (day <= 0 || day > days_in_month[month])) ? 0 : 1;	/*uso month come indice perche' se non valido il controllo viene interrotto prima di utilizzare month come indice*/
}
