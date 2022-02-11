/* Author: Matteo Gianferrari
 * Data: 01/02/2022
 * Si scriva un programma che memorizzi in una struttura dati opportuna i voti conseguiti durante il primo anno delle matricole di ingegneria.
 * Si supponga che gli studenti siano al massimo 100 e che gli esami da sostenere durante il primo anno siano 8. I dati vanno forniti nel seguente modo:
 * numero studente, numero esame, voto esame.
 * Si calcoli infine per ciascun studente il numero di esami superati e la media dei voti e per ciascun esame il numero di voti registrati e la media dei voti.
 * Per provare il programma si scrivano i dati in un file e si utilizzi  la redirezione dell'input.
 */
#include <stdio.h>

#define MAX_LEN 10
#define N_ESAMI 8
#define N_STUDENTI 100

void init_libretti(int arr[][N_ESAMI]);
void statistiche_stud(int arr[][N_ESAMI]);
void statistiche_esami(int arr[][N_ESAMI]);

int main(void){
	int libretti[N_STUDENTI][N_ESAMI];
	char buf[MAX_LEN];
	int temp_stud, temp_es, temp_vot;
	
	init_libretti(libretti);
	
	while(fgets(buf, sizeof(buf), stdin) != NULL){
		sscanf(buf, "%d %d %d", &temp_stud, &temp_es, &temp_vot);
		libretti[temp_stud - 1][temp_es - 1] = temp_vot;
	}
	
	statistiche_stud(libretti);
	putchar('\n');
	statistiche_esami(libretti);
		
	return 0;
}

void init_libretti(int arr[][N_ESAMI]){
	int i, j;
	
	for(i = 0; i < N_STUDENTI; i++)
		for(j = 0; j < N_ESAMI; j++)
			arr[i][j] = 0;
}

void statistiche_stud(int arr[][N_ESAMI]){
	double media = 0.0;
	int i, j, count = 0;
	
	for(i = 0; i < N_STUDENTI; i++){
		for(j = 0; j < N_ESAMI; j++){
			if(arr[i][j] != 0){
				count++;
				media += arr[i][j];
			}
		}
		media = (count) ? media / count : 0.0;
		printf("Studente %d:\nEsami superati: %d\tMedia esami: %g\n", i + 1, count, media);
		count = 0;
		media = 0;
	}	
}

void statistiche_esami(int arr[][N_ESAMI]){
	double media[N_ESAMI] = {0.0};
	int i, j, count[N_ESAMI] = {0};
	
	for(i = 0; i < N_STUDENTI; i++)
		for(j = 0; j < N_ESAMI; j++)
			if(arr[i][j] != 0){
				count[j]++;
				media[j] += arr[i][j];
			}
	
	for(i = 0; i < N_ESAMI; i++){
		printf("Esame %d:\nNumero voti: %d\tMedia voti: %g\n", i + 1, count[i], media[i] / count[i]);
	}
}
