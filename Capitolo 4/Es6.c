/* Author: Matteo Gianferrari
 * Data: 21/01/2022
 * Scrivere un programma che calcoli prodotti, divisioni e resto della divisione tra interi facendo solo uso delle operazioni di  
 * somma e sottrazione. L'input al programma deve essere fornito da tastiera, specificando tre parametri operando1 op opeando2.
 */
#include <stdio.h>

#define MAX_LEN 20

int main(){
	char buf[MAX_LEN];
	int op1, op2, op, i;
	double ris;
	
	fgets(buf, sizeof(buf), stdin);
	op1 = atoi(buf);
	
	do{
		fgets(buf, sizeof(buf), stdin);
		op = buf[0];
	}
	while(op != '*' && op != '/' && op != '%');
	
	fgets(buf, sizeof(buf), stdin);
	op2 = atoi(buf);
	
	switch(op){
		case '*':
			for(i = 0; i < op2; i++)
				ris += op1;
			break;
		case '/':
			ris = op1;
			for(i = 0; (ris -= op2) > 0; i++);
			ris = i;
			break;
		case '%':
			ris = op1;
			while(ris >= op2)
				ris -= op2;
			break;
	}
	
	printf("%d %c %d = %g\n", op1, op, op2, ris);
	return 0;
}
