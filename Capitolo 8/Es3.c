/* Author: Matteo Gianferrari
 * Data: 08/02/2022
 * Scrivere un programma che unisce il contenuto di due file di testo, scrivendo su stdout il contenuto dei due file alternando le righe di uno 
 * e dell'altro file. Se un file ha un numero di linee minore dell'altro, le linee eccedenti del file più grosso devono essere semplicemente
 * copiate su stdout dopo aver elaborato le precedenti linee. Si assuma che il massimo numero di caratteri per linea si apari a 1024 byte.
 */
#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 1024

int main(int argc, char *argv[]){
	FILE *fp1, *fp2;
	char f1_buf[MAX_LEN], *f1_ret;
	char f2_buf[MAX_LEN], *f2_ret;
	
	if(argc <= 2){
		printf("Utilizzo: 8.3 [file 1] [file 2]\n");
		return -1;
	}

	if(!(fp1 = fopen(*(argv + 1), "r"))){
		perror(*(argv + 1));
		exit(-1);
	}
	if(!(fp2 = fopen(*(argv + 2), "r"))){
		perror(*(argv + 2));
		exit(-1);
	}
	
	while((f1_ret = fgets(f1_buf, sizeof(f1_buf), fp1)) != NULL && (f2_ret = fgets(f2_buf, sizeof(f2_buf), fp2)) != NULL){
		fprintf(stdout, "%s", f1_buf);
		fprintf(stdout, "%s", f2_buf);
	}
	
	if(f1_ret == NULL){
		while(fgets(f2_buf, sizeof(f2_buf), fp2))
			fprintf(stdout, "%s", f2_buf);
	}
	else if(f2_ret == NULL){
		while(fgets(f1_buf, sizeof(f1_buf), fp1))
			fprintf(stdout, "%s", f1_buf);		
	}
	
	if(fclose(fp1) == EOF){
		perror(*(argv + 1));
		exit(-2);
	}
	if(fclose(fp2) == EOF){
		perror(*(argv + 2));
		exit(-2);
	}
	
	return 0;
}
