/* Author: Matteo Gianferrari
 * Data: 21/01/2022
 * Scrivere un programma che determini se, in una sequenza di numeri inseriti da tastiera, vis ono due 
 * o piu' valori consecutivi uguali. Il programma deve terminare quando viene inserito il valore 0
 */
#include <stdio.h>

#define MAX_LEN 20

int main(){
	char buf[MAX_LEN];
	int num, prev_num = 0;
	
	
	while((num = atoi(fgets(buf, sizeof(buf), stdin))) != 0){
		if(num == prev_num)
			printf("%d uguale al precedente\n", num);
		prev_num = num;
	}
	
	return 0;
}
