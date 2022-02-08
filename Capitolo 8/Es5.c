/* Author: Matteo Gianferrari
 * Data: 08/02/2022
 * Si consideri un file contenente informazioni relative ai risultati delle partite di calcio di un girone (max 18 squadre). Il file contiene in ciascuna riga, separati da spazio:
 * nome della squadra (max 10 caratteri), numero di partite vinte, numero di partite perse, numero di partite pareggiate, goal fatti, goal subiti.
 * Si scriva un programma che definita un'opportuna struttura dati, cairichi in memoria questi dati e generi un secondo file che contiene in ciascuna riga le seguenti informazioni:
 * nome squadra, numero partite giocate, punteggio (3 punti per partita vinta 1 per pareggiata), media dei goal fatti per partita, media dei goal subiti a partita.
 */
#include <stdio.h>
#include <stdlib.h>

#define MAXLEN 10
#define MAX_SQUADRE 18
#define MAX_LEN_LINE 1024
#define NAME_FILE "output.txt"
struct info_squadra{
	char nome[MAXLEN];
	int n_vittorie;
	int n_sconfitte;
	int n_pareggiate;
	int g_fatti;
	int g_subiti;
};

int read_data(FILE *fp, struct info_squadra *arr);		
void print_data(FILE *fp, struct info_squadra *arr, int count);

int main(int argc, char *argv[]){
	FILE *fp_in, *fp_out;
	struct info_squadra arr[MAX_SQUADRE], *p = arr;
	int count;
	
	
	if(argc <= 1){
		printf("Utilizzo: 8.5 [file]\n");
		return -1;
	}
	
	if(!(fp_in = fopen(*++argv, "r"))){
		perror(*argv);
		exit(-1);
	}
	if(!(fp_out = fopen(NAME_FILE, "w"))){
		perror(NAME_FILE);
		exit(-1);
	}
	
	count = read_data(fp_in, arr);
	print_data(fp_out, arr, count);
	
	if(fclose(fp_in) == EOF){
		perror(*argv);
		exit(-2);
	}
	if(fclose(fp_out) == EOF){
		perror(NAME_FILE);
		exit(-2);
	}
	return 0;
}

int read_data(FILE *fp, struct info_squadra *arr){
	char buf[MAX_LEN_LINE];
	int c = 0;
	
	while(fgets(buf, sizeof(buf), fp) != NULL){
		sscanf(buf, "%10[^ ] %d %d %d %d %d", arr->nome, &arr->n_vittorie, &arr->n_sconfitte, &arr->n_pareggiate, &arr->g_fatti, &arr->g_subiti);
		arr++;
		c++;
	}
	
	return c;
}

void print_data(FILE *fp, struct info_squadra *arr, int count){
	int i, p_giocate, punteggio;
	float m_goal_fatti, m_goal_subiti;
	
	for(i = 0; i < count; i++, arr++){
		p_giocate = arr->n_vittorie + arr->n_sconfitte + arr->n_pareggiate;
		punteggio = (3 * arr->n_vittorie) + arr->n_pareggiate;
		m_goal_fatti = (float)arr->g_fatti / p_giocate;
		m_goal_subiti = (float)arr->g_subiti / p_giocate;
		
		fprintf(fp, "%s %d %d %f %f\n", arr->nome, p_giocate, punteggio, m_goal_fatti, m_goal_subiti);
	}
}
