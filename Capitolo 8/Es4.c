/* Author: Matteo Gianferrari
 * Data: 13/02/2022
 * Scrivere un programma che ricostruisce il file di partenza che e' stato suddiviso mediante 
 * la funzine split_file (programma esempio 29), a partire dai file generati dalla suddivisione.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define F_NAME "outfile"
#define MAX_LENGTH 30
#define MAX_DIM 0xFFFF
#define MERGE_NAME "merge.binary"

int split_file(FILE *fp, int dim);
int merge_split(FILE *fp, int dim, int n_split);

int main(int argc, char *argv[]){
	FILE *f_in, *f_merge; 
	int dim, n_split;
	
	/* inizio programma 29*/
	if(argc != 3){
		printf("Utilizzo: 8.4 [file] [dimensione]\n");
		return -1;
	}
	
	if(!(f_in = fopen(argv[1], "r"))){
		perror(argv[1]);
		return -2;
	}
	
	dim = atoi(argv[2]);
	
	n_split = split_file(f_in, dim);
	
	if(fclose(f_in) == EOF){
		perror(argv[1]);
		exit(-2);
	}
	/* fine programma 29*/
	
	/* inizio esercizio*/
	if(!(f_merge = fopen(MERGE_NAME, "w"))){
		perror(MERGE_NAME);
		return -2;
	}
	
	merge_split(f_merge, dim, n_split);
	
	if(fclose(f_merge) == EOF){
		perror(MERGE_NAME);
		exit(-2);
	}
	/* fine esercizio*/
	
	return 0;
}

int split_file(FILE *fp, int dim){
	size_t nread;
	int count = 0;
	char fname[MAX_LENGTH], buf[MAX_DIM];
	FILE *f_out;
	
	if(dim <= 0 || dim > MAX_DIM)
		return -1;
	
	do{
		nread = fread(buf, 1, dim, fp);
		sprintf(fname, "%s%d%s", F_NAME, count, ".split");
		if(!(f_out = fopen(fname, "w")))
			return -1;
		fwrite(buf, 1, nread, f_out);
		fclose(f_out);
		count++;
	} while(nread == dim);
	
	return count;
}

int merge_split(FILE *fp, int dim, int n_split){
	size_t nread;
	int count = 0;
	char fname[MAX_LENGTH], buf[MAX_DIM];
	FILE *f_split;
	
	if(dim <= 0 || dim > MAX_DIM)
		return -1;
	
	while(count < n_split){
		sprintf(fname, "%s%d%s", F_NAME, count, ".split");
		if(!(f_split = fopen(fname, "r")))
			return -1;
		nread = fread(buf, 1, dim, f_split);
		fwrite(buf, 1, nread, fp);
		fclose(f_split);
		count++;
	} 
	
	return count;
}
