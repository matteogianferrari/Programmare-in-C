/* Author: Matteo Gianferrari
 * Data: 01/02/2022
 * Si definisca la seguente struttura dati e si scrivano opportune istruzioni per:
 * -stampare la sua occupazione di memoria in byte
 * -verificare se la sua dimensione è pari alla somma della dichiarazione dei campi
 * -verificare se la sua dimensione cambia alternando l'ordine della dichiarazione dei campi
 */
#include <stdio.h>

struct dati{
	char s[5];
	char c;
	int a;
};

int main(void){
	struct dati d1;
	char s[5], c;
	int a;
	
	printf("Dimensione in memoria in byte: %d\n", sizeof(d1));
	printf("Dimensione della struct: %d\t Dimensione dei dati sommati: %d\n", sizeof(d1), sizeof(s) + sizeof(c) + sizeof(a));
	/*La struttura occupi piu' byte rispetto ai singoli campi per questione di padding della memoria, in quanto i campi di
	 *una struct sono allocati in successione nella memoria, mentre i singoli campi sono in diverse posizioni di memoria.
	 *La dimensione della struttura varia in base all'ordine dei dati per lo stesso motivo.*/
	 
	return 0;
}
