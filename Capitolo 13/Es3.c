/* Author: Matteo Gianferrari
 * Data: 15/02/2022
 * Creare un programma che generi un vettore di numeri interi. Il programma deve inserirre nel vettore un insieme di valori interi generati in modo pseudocasuale (funzione rand).
 * Anche il numero totale di valori che componga l'insieme sia scelto in modo pseudocasuale nell'intervallo [10, 1000]. Implementare la funzione che ordina i valori memorizzati nel vettore.
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN 10
#define MAX 1000

int *vet_alloc(size_t dim);
void rand_fill_vet(int *arr, size_t dim);
size_t print_vet(FILE *stream, int *arr, size_t dim, int n);
void bubble_sort(int *arr, size_t dim);
void swap(int *a, int *b);

int main(void){
	int i, dim, *arr;
	
	srand(time(NULL));
	dim = rand() % (MAX + 1) + MIN;

	arr = vet_alloc(dim);
	if(arr == NULL){
		printf("Errore allocazione vettore\n");
		return -1;
	}
	rand_fill_vet(arr, dim);
	
	bubble_sort(arr, dim);
	print_vet(stdout, arr, dim, 1);
	
	return 0;
}

int *vet_alloc(size_t dim){
	int *p;
	
	p = (int *)malloc(sizeof(*p) * dim);
	
	return (p == NULL) ? NULL : p;
}

void rand_fill_vet(int *arr, size_t dim){
	size_t i;
	
	for(i = 0; i < dim; i++)
		arr[i] = rand();
}

size_t print_vet(FILE *stream, int *arr, size_t dim, int n){
	size_t i;
	
	for(i = 0; i < dim; i++)
		fprintf(stream, (i == dim - 1) ? "%*i" : "%*i ", n, arr[i]);
	
	return i;
}

void bubble_sort(int *arr, size_t dim){
	size_t i, j;
	
	for(i = 0; i < dim; i++)
		for(j = i + 1; j < dim; j++)
			if(arr[i] > arr[j])
				swap(&arr[i], &arr[j]);
}

void swap(int *a, int *b){
	int temp;
	
	temp = *a;
	*a = *b;
	*b = temp;
}
