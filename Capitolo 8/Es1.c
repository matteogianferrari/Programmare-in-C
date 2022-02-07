/* Author: Matteo Gianferrari
 * Data: 07/02/2022
 * Scrivere un programa che legga da standard input una sequenza di stringhe. Il programma deve determinare e stampare quante 
 * vocali sono state inserite, sia maiuscole che minuscole. Il programma deve terminare quando viene inserita una stringa vuota.
 */
#include <stdio.h>

#define MAX_LEN 1024

int is_vowel(char c);

int main(void){
	char buf[MAX_LEN], *pbuf, *ret;
	int count = 0;
	
	while((ret = fgets(buf, sizeof(buf), stdin)) != NULL && *ret != '\n'){
		pbuf = buf;
		while(*pbuf){
		    if(is_vowel(*pbuf))
		       count++;
			pbuf++;
		}
	}
	
	fprintf(stdout, "Vocali inserite: %d", count);
	
	return 0;
}

int is_vowel(char c){
	return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}
