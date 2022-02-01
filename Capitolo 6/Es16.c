/* Author: Matteo Gianferrari
 * Data: 01/02/2022
 * Si scriva una funzione ricorsiva per il calcolo del Massimo Comune Divisore (MCD) tra due numeri interi che sfrutti l'algoritmo di Euclide. L'algoritmo prevede di calcolare il MCD(m, n) come segue:
 * MCD(m, n) = MCD(m - n, n) se m > n
 * MCD(m, n) = MCD(m, n - m) se m < n
 * MCD(m, n) = m se m = n
 */
 #include <stdio.h>

int MCD(int m, int n);

int main(void){
	int num1, num2;
	
	scanf("%d %d", &num1, &num2);
	
	printf("Massimo comune divisore tra %d e %d: %d\n", num1, num2, MCD(num1, num2));
		
	return 0;
}

int MCD(int m, int n){
	if(m == n)
		return m;
	else if(m > n)
		return MCD(m - n, n);
	else if(m < n)
		return MCD(m, n - m);
}
