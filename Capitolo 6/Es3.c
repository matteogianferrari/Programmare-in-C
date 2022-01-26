/* Author: Matteo Gianferrari
 * Data: 26/01/2022
 * Date le misure dei lati di un rettangolo a, b, fornite da line di comando, si scriva un programma che calcoli e stampi il perimetro,
 * l'area e la diagonale del rettangolo tramite chiamata a tre distinte funzioni che svolgano ciascuna uno dei calcoli richiesti.
 */
#include <stdio.h>
#include <math.h>

int get_perimetro(int a, int b);
int get_area(int a, int b);
float get_diagonale(int a, int b);

int main(int argc, char *argv[]){
	float diag;
	int a, b, area, perim;
	
	if(argc != 3){
		printf("Utilizzo: 6.3 [a] [b]\n");
		return -1;
	}
	else{
		a = atoi(argv[1]);
		b = atoi(argv[2]);
		
		perim = get_perimetro(a, b);
		area = get_area(a, b);
		diag = get_diagonale(a, b);
		
		printf("Perimetro: %d\nArea: %d\nDiagonale: %f\n", perim, area, diag);
		return 0;
	}
}

int get_perimetro(int a, int b){
	return (2 * a) + (2 * b);
}

int get_area(int a, int b){
	return a * b;
}

float get_diagonale(int a, int b){
	return sqrt((a * a) + (b * b));
}
