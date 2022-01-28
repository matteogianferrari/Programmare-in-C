/* Author: Matteo Gianferrari
 * Data: 28/01/2022
 * Si scriva una funzione che verifica se tre valori possono essere la misura dei lati di un triangolo.
 * Si ricorda ce in un triangolo la somma dei due lati piu' corti e' sempre maggiore del lato piu' lungo.
 */
#include <stdio.h>

int max_num(int a, int b, int c);
int min_num(int a, int b, int c);
int check_lati(int cateto1, int cateto2, int ipotenusa);

int main(int argc, char *argv[]){
	int a, b, c, cateto1, cateto2, ipotenusa;
	
	if(argc != 4){
		printf("Utilizzo: 6.4 [a] [b] [c]\n");
		return -1;
	}
	else{
		a = atoi(argv[1]);
		b = atoi(argv[2]);
		c = atoi(argv[3]);

		cateto1 = min_num(a, b, c);
		ipotenusa = max_num(a, b, c);
		cateto2 = (a + b + c) - (cateto1 + ipotenusa);
		
		printf((check_lati(cateto1, cateto2, ipotenusa)) ? "I lati possono formare un triangolo\n" : "I lati non possono formare un triangolo\n");
		
		return 0;
	}
}

int max_num(int a, int b, int c){
	return (a > b) ? (a > c) ? a : c : (b > c) ? b : c;
}

int min_num(int a, int b, int c){
	return (a < b) ? (a < c) ? a : c : (b < c) ? b : c;
}

int check_lati(int cateto1, int cateto2, int ipotenusa){
	return ((cateto1 + cateto2) > ipotenusa);
}
