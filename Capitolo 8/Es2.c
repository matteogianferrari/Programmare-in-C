/* Author: Matteo Gianferrari
 * Data: 07/02/2022
 * Scrivere il programma merge_file che legge una serie di file i cui nomi sono specificati sulla linea di comando.
 * Il contenuto dei file viene concatenato e scritto in un file di output il cui nome corrisponde all'ultimo tra
 * quelli specificati nella linea di comando. Si devono gestire sia file di testo che binari.
 */
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
	FILE *fp_in, *fp_out;
	char c;
	
	if(argc == 1){
		printf("Utilizzo: 8.2 [file_name] ...\n");
		return -1;
	}
	
	if(!(fp_out = fopen(argv[argc - 1], "wb"))){
			perror(argv[argc - 1]);
			exit(-1);
	}
	
	while(--argc > 0 && (*++argv) != NULL){
		if(!(fp_in = fopen(*argv, "rb"))){
			perror(*argv);
			exit(-1);
		}
		
		while((c = getc(fp_in)) != EOF)
			putc(c, fp_out);
		putc('\n', fp_out);
		
		if(fclose(fp_in) == EOF){
			perror(*argv);
			exit(-2);
		}
	}
	
	return 0;
}
