/* Author: Matteo Gianferrari
 * Data: 14/02/2022
 * Si definisca in un modulo denominato func_file.c e .h una serie di funzioni che svolgano le seguenti operazioni:
 * 1. vet_alloc: alloca un vettore di interi, di dimensione passata come parametro alla funzione.
 * 2. mat_alloc: alloca una matrice di interi, di dimensioni passate come parametri alla funzione.
 * 3. print_vet: stampa su uno stream passato come parametro gli elementi di un vettore di interi, separati da uno spazio su una riga
 *		 (usare il formato %ni per incolonnarli, n sia il numero di posizioni occupate da ciascun valore).
 * 4. print_mat: stampa su uno stream passato come parametro gli elementi di una matrice di interi, riga per riga. La funzione dovrà
 * 	  	 richiamare a sua volta la funzione stampa_vet, per stampare le righe della matrice.
 * 5. somma_vet: calcola la somma degli elementi di due vettori ritornando il risultato in un terzo vettore di interi (tutti della medesima dimensione).
 * 6. somma_mat: calcola la somma degli elementi di due matrici ritornando il risultato in una terza mattrice di interi (tutti della medesima dimensione).
 * 7. media_vet: calcola e restituisce la media degli elementi di un vettore.
 * 8. media_mat: calcola e restituisce la media degli elementi di una matrice, facendo uso anche della funzione media_vet.
 * 9. min_vet: calcola e restituisce il minimo degli elementi di un vettore.
 * 10. max_vet: calcola e restituisce il massimo degli elementi di un vettore.
 * 11. min_mat: calcola e restituisce il minimo degli elementi di una matrice.
 * 12. max_mat: calcola e restituisce il massimo degli elementi di una matrice.
 * Si scriva un programma che riceve da linea di comando una opzione che rappresenta il tipo di elemento su cui svolgere le funzioni
 * (-m matrice, -v vettore) e mostri l'utilizzo delle varie funzioni sopra elencate.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func_file.h"

#define DIM 10
#define RIG 10
#define COL 10

int main(int argc, char *argv[]){
	int i, j, min, max;
	int *arr1, *arr2, *arr3;
	int **mat1, **mat2, **mat3;	
	double media;

	if(argc != 2){
		printf("Utilizzo: 12. [-v o -m] \n");
		return -1;
	}

	if(!strcmp(argv[1], "-v") || !strcmp(argv[1], "-V")){
		arr1 = vet_alloc(DIM);
		arr2 = vet_alloc(DIM);
		
		for(i = 0; i < DIM; i++){
			arr1[i] = 1 + i;	
			arr2[i] = 2 + i;	
		}
	
		arr3 = somma_vet(arr1, arr2, DIM);
		media = media_vet(arr3, DIM);
		min = min_vet(arr3, DIM);
		max = max_vet(arr3, DIM);
		
		print_vet(stdout, arr3, DIM, 1);
		putchar('\n');
		printf("Media vettore: %g\n", media);
		printf("Elemento minimo vettore: %d\n", min);
		printf("Elemento massimo vettore: %d\n", max);
		
		free(arr1);
		free(arr2);
		free(arr3);
	}
	else if(!strcmp(argv[1], "-m") || !strcmp(argv[1], "-M")){
		mat1 = mat_alloc(RIG, COL);
		mat2 = mat_alloc(RIG, COL);
		
		for(i = 0; i < RIG; i++){
			for(j = 0; j < COL; j++){
				mat1[i][j] = 1 + i + j;
	 			mat2[i][j] = 2 + i + j;
			}
		}
		
		mat3 = somma_mat(mat1, mat2, RIG, COL);
		media = media_mat(mat3, RIG, COL);
		min = min_mat(mat3, RIG, COL);
		max = max_mat(mat3, RIG, COL);
	
		print_mat(stdout, mat3, RIG, COL, 2);
		putchar('\n');
		printf("\nMedia matrice: %g\n", media);
		printf("Elemento minimo matrice: %d\n", min);
		printf("Elemento massimo matrice: %d\n", max);
		
		free(mat1);
		free(mat2);
		free(mat3);	
	}
	else{
		printf("Opzione non supportata\n");
		return -2;
	}

	return 0;
}
