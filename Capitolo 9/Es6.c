/* Author: Matteo Gianferrari
 * Data: 10/02/2022
 * Si consideri la funzione print_matr inclusa nel programma di esempio matrix_alloc.c illustrato nella sezione 9.5.2. Si scriva una funzione che effettua la stampa della matrice senza utilizzare
 * l'accorgimento basato sulla stringa separator. Si noti che la stampa dei valori e' tale per cui davanti al primo numero e dopo l'ultimo numero di ciascuna riga non e' presente alcuno spazio.
 * Ci si renderà conto che non e' possibile ottenere lo stesso risultato a meno di non utilizzare un costrutto if oppure di effettuare la stampa del primo elemento di ciascuna riga al di fuori 
 * del ciclo for. Entrambe le soluzioni alternative sono meno eleganti di quella presentata. PARERE PERSONALE E' MEGLIO IL MIO METODO CHE QUELLO USATO NEL LIBRO.
 */
#include <stdio.h>
#include <stdlib.h>

#define N_RIG 10
#define N_COL 10

int **alloc_matr(int rig, int col);
void fill_matr(int **mat, int rig, int col);
void print_matr(int **mat, int rig, int col);

int main(void){
	int **mat;
	
	mat = alloc_matr(N_RIG, N_COL);
	
	fill_matr(mat, N_RIG, N_COL);
	print_matr(mat, N_RIG, N_COL);
	
	return 0;
}

int **alloc_matr(int rig, int col){
	int i, *data, **mat;
	
	if((data = malloc(rig * col * sizeof(*data))) == NULL)
		return NULL;
	
	if((mat = malloc(rig * sizeof(*mat))) == NULL)
		return NULL;
		
	for(i = 0; i < rig; i++, data += col)
		mat[i] = data;
	
	return mat;
}

void fill_matr(int **mat, int rig, int col){
	int i, j;
	
	for(i = 0; i < rig; i++)
		for(j = 0; j < col; j++) 
			mat[i][j] = 0;	
}

void print_matr(int **mat, int rig, int col){
	int i, j;
	
	for(i = 0; i < rig; i++)
		for(j = 0; j < col; j++) 
			printf((j == col - 1) ? "%d\n" : "%d ", mat[i][j]);
}
