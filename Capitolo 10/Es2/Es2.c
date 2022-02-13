/* Author: Matteo Gianferrari
 * Data: 13/02/2022
 * Si definisca in un modulo denominato func_file.c e .h una serie di funzioni che svolgano le seguenti operazioni su file:
 * 1.merge_file: concatena il contenuto di due file e lo salva in un terzo file. I parametri della
 * funzione devono essere: i nomi dei file da concatenare e il nome del file risultante.
 * 2.split_file: partendo da un file di input, lo suddivide in un adeguato numero di file aventi dimensione specificata. Il nome dei 
 * file creati sia costituito da una radice fissa e da un numero progressivo che rappresenta il numero del blocco ottenuto nella suddivisione.
 * 3.concat_file: data la radice del nome di file precedentemente suddiviso in blocchi,
 * lo ricostruisca utilizzando la funzione merge_file richiesta al punto 1. (FUNZIONE MODIFICATA)
 * Si scriva in un file un programma che riceve da linea di comando una opzione che rappresenta il tipo di operazione richiesta (-m -s -c) e una
 * serie di argomenti che specifichino, per ciascuna opzione, i parametri dell'operazione e la esegua invocando le funzioni del modulo fun_file.c.
 */
#include <stdio.h>
#include <stdlib.h>
#include "func_file.h"

int main(int argc, char *argv[]){
	FILE *fp;
	int n_split, ret;

	/* non e' previsto il controllo di errori per i parametri del comando*/
	if(argc == 1 || argv[1][0] != '-'){
		printf("Utilizzo: 10.2 [-m] [-s] [-c] parametri\n");
		return -1;
	}
	
	/* soluzione poco elegante, non ritengo necessario perdere tempo a migliorarla,
	 * in quanto e' un esercizio focalizzato sulla divisione in moduli
	 */
	switch(argv[1][1]){
		case 'm':		/* -m infile.txt infile.txt outfile.txt*/
			ret = merge_file(argv[2], argv[3], argv[4]);
			break;
		case 's':		/* -s infile.txt radice dimensione*/
			if(!(fp = fopen(argv[2], "r"))){
					perror(argv[2]);
					return -1;
				}
			ret = split_file(fp, argv[3], atoi(argv[4]));
			break;
		case 'c':		/* -c radice n_split*/
			ret = concat_file(argv[2], atoi(argv[3]));
			break;
	}
	   
	return ret;
}
