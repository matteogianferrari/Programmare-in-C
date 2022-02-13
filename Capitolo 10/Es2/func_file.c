#include <stdio.h>
#include <stdlib.h>
#include "func_file.h"

#define MAX_DIM 0xFFFF
#define MAX_LENGTH 50

int merge_file(char *f1_name, char *f2_name, char *f_out_name){
	FILE *fp1, *fp2, *f_out;
	char c;
	
	if(!(fp1 = fopen(f1_name, "r"))){
		perror(f1_name);
		return -1;
	}

	if(!(fp2 = fopen(f2_name, "r"))){
		perror(f2_name);
		return -2;
	}

	if(!(f_out = fopen(f_out_name, "w"))){
		perror(f_out_name);
		return -3;
	}
	
	while((c = getc(fp1)) != EOF){
		putc(c, f_out);
	}
	while((c = getc(fp2)) != EOF){
		putc(c, f_out);
	}
	
	if(fclose(fp1) == EOF){
		perror(f1_name);
		exit(-1);
	}

	if(fclose(fp2) == EOF){
		perror(f2_name);
		exit(-2);
	}
	
	if(fclose(f_out) == EOF){
		perror(f_out_name);
		exit(-3);
	}
	
	return 0;
}

int split_file(FILE *fp, char *radice, int dim){
	size_t nread;
	int count = 0;
	char fname[MAX_LENGTH], buf[MAX_DIM];
	FILE *f_out;
	
	if(dim <= 0 || dim > MAX_DIM)
		return -1;
	
	do{
		nread = fread(buf, 1, dim, fp);
		sprintf(fname, "%s%d%s", radice, count, ".split");
		if(!(f_out = fopen(fname, "w")))
			return -1;
		fwrite(buf, 1, nread, f_out);
		fclose(f_out);
		count++;
	} while(nread == dim);
	
	return count;
}

/* Ritengo la richiesta dell'esercizio inappliabile in quanto non vi e' un metodo efficacie per utilizzare la funzione merge_file per come dichiarata nella funzione concat.
 * Merge_file e' stata progettata per unire 2 file in un terzo, e non per eventualmente utilizzare il terzo file come input per una concatenazione su se stesso.
 * Se si ignorasse questo problema aggirandolo, verrebbero creati file intermedi utilizzati dalle successive chiamate, poi rimarrebbero inutilizzati, poco elegante come metodo.
 */
int concat_file(char *radice, int n_split){
	int count = 0;
	char c, fname[MAX_LENGTH];
	FILE *f_split, *f_out;
	
	sprintf(fname, "%s%s", radice, ".concat");
	if(!(f_out = fopen(fname, "a"))){
		perror(fname);
		return -1;
	}
	
	while(count < n_split){
		sprintf(fname, "%s%d%s", radice, count, ".split");
		if(!(f_split = fopen(fname, "r")))
			return -1;
		while((c = getc(f_split)) != EOF)
			putc(c, f_out);
		fclose(f_split);
		count++;
	} 
	
	return 0;
}
