#ifndef __FUNC_FILE_H__
#define __FUNC_FILE_H__

int *vet_alloc(size_t dim);
size_t print_vet(FILE *stream, int *arr, size_t dim, int n);
int *somma_vet(int *arr1, int *arr2, size_t dim);
double media_vet(int *arr, size_t dim);
int min_vet(int *arr, size_t dim);
int max_vet(int *arr, size_t dim);

int **mat_alloc(size_t rig, size_t col);
size_t print_mat(FILE *stream, int **mat, size_t rig, size_t col, int n);
int **somma_mat(int **mat1, int **mat2, size_t rig, size_t col);
double media_mat(int **mat, size_t rig, size_t col);
int min_mat(int **mat, size_t rig, size_t col);
int max_mat(int **mat, size_t rig, size_t col);
#endif
