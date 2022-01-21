/* Author: Matteo Gianferrari
 * Data: 21/01/2022
 * Scrivere un programma che stampi a video un triangolo rettangolo di '*' la cui base e altezza siano lette da tastiera
 */
#include <stdio.h>

#define MAX_LEN 20

int main(){
	char buf[MAX_LEN];
	int i, j, b;
	
	fgets(buf, sizeof(buf), stdin);
	b = atoi(buf);

	for(i = 1; i <= b; i++)
		for(j = 1; j <= i; j++)
			printf((j == i) ? "*\n" : "*");
	
	return 0;
}
