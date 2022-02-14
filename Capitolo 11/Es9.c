/* Author: Matteo Gianferrari
 * Data: 14/02/2022
 * Prendere spunto dall'esempio mostrato in sezione 11.2.2 per la realizzazione della stampa ciclica del 
 * contenuto di un vettore. Si provi ad ottenere il medesimo risultato senza l'uso dell'operatore modulo.
 */
#include <stdio.h>

#define NOTE 12

int main(){
	int i, j, k, n;
	char *note[] = {"C", "Db", "D", "Eb", "E", "F", "Gb", "G", "Ab", "A", "Bb", "B"};
	
	for(i = 0; i < NOTE - 1; i++){
		for(j = 0; j < NOTE; j++){
			if(i != 10 || j < 7)
				n = printf("%s%d", note[j], i - 1);
			for(k = n; k < 5; k++)
				putchar(' ');
		}
		putchar('\n');
	}
	return 0;
}
