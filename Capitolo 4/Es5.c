/* Author: Matteo Gianferrari
 * Data: 21/01/2022
 * Scrivere un programma che esegua le seguenti operazioni aritmetiche tra interi + - * / %. L'input al programma deve essere fornito da tastiera, specificando 
 * tre parametri operando1 op operando2. Si stampi un messaggio di errore per evidenziare operazioni (es.divisione per zero) o operatori non validi.
 */
#include <stdio.h>

#define MAX_LEN 20

int main(){
	char buf[MAX_LEN];
	int op1, op2, op, flag_err = 0;
	double ris;
	
	fgets(buf, sizeof(buf), stdin);
	op1 = atoi(buf);
	
	do{
		fgets(buf, sizeof(buf), stdin);
		op = buf[0];
	}
	while(op != '+' && op != '-' && op != '*' && op != '/' && op != '%');
	
	fgets(buf, sizeof(buf), stdin);
	op2 = atoi(buf);
	
	switch(op){
		case '+':
			ris = op1 + op2;
			break;
		case '-':
			ris = op1 - op2;
			break;
		case '*':
			ris = op1 * op2;
			break;
		case '/':
			if(op2 == 0)
				flag_err = 1;
			else
				ris = op1 / op2;
			break;
		case '%':
			ris = op1 % op2;
			break;
	}
	
	printf((flag_err) ? "Errore, divisione per 0\n" : "%d %c %d = %g\n", op1, op, op2, ris);
	return 0;
}
