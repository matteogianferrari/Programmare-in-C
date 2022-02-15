#include <stdlib.h>
#include <stdio.h>
#include "func_file.h"

int *vet_alloc(size_t dim){
	int *p;
	
	p = (int *)malloc(sizeof(*p) * dim);
	
	return (p == NULL) ? NULL : p;
}

size_t print_vet(FILE *stream, int *arr, size_t dim, int n){
	size_t i;
	
	for(i = 0; i < dim; i++)
		fprintf(stream, (i == dim - 1) ? "%*i" : "%*i ", n, arr[i]);
	
	return i;
}

int *somma_vet(int *arr1, int *arr2, size_t dim){
	size_t i;
	int *arr3 = vet_alloc(dim);
	
	for(i = 0; i < dim; i++)
		arr3[i] = arr1[i] + arr2[i];
	
	return arr3;
}

double media_vet(int *arr, size_t dim){
	size_t i;
	double media = 0.0;
	
	for(i = 0; i < dim; i++)
		media += arr[i];
	
	return media / dim;
}

int min_vet(int *arr, size_t dim){
	size_t i;
	int min = arr[0];
	
	for(i = 0; i < dim; i++)
		if(arr[i] < min)
			min = arr[i];
	
	return min;
}

int max_vet(int *arr, size_t dim){
	size_t i;
	int max = arr[0];
	
	for(i = 0; i < dim; i++)
		if(arr[i] > max)
			max = arr[i];
	
	return max;
}


int **mat_alloc(size_t rig, size_t col){
	size_t i;
	int **mat;
	
	mat = malloc(sizeof(*mat) * rig);
	if(mat == NULL)
		return NULL;
		
	for(i = 0; i < rig; i++)
		if((mat[i] = malloc(sizeof(**mat) * col)) == NULL)
			return NULL;
	
	return mat;
}

size_t print_mat(FILE *stream, int **mat, size_t rig, size_t col, int n){
	size_t i, n_el = 0;
	
	for(i = 0; i < rig; i++){
		n_el += print_vet(stream, mat[i], col, n);
		putchar('\n');
	}
	
	return n_el;
}

int **somma_mat(int **mat1, int **mat2, size_t rig, size_t col){
	size_t i, j;
	int **mat3 = mat_alloc(rig, col);
	
	for(i = 0; i < rig; i++)
		for(j = 0; j < col; j++)
			mat3[i][j] = mat1[i][j] + mat2[i][j];
	
	return mat3;
}

double media_mat(int **mat, size_t rig, size_t col){
	size_t i;
	double media = 0.0;
	
	for(i = 0; i < rig; i++)
		media += media_vet(mat[i], col);
	
	return media / rig;
}

int min_mat(int **mat, size_t rig, size_t col){
	size_t i, j;
	int min = mat[0][0];
	
	for(i = 0; i < rig; i++)
		for(j = 0; j < col; j++)
			if(mat[i][j] < min)
				min = mat[i][j];
	
	return min;
}

int max_mat(int **mat, size_t rig, size_t col){
	size_t i, j;
	int max = mat[0][0];
	
	for(i = 0; i < rig; i++)
		for(j = 0; j < col; j++)
			if(mat[i][j] > max)
				max = mat[i][j];
	
	return max;
}
