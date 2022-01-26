/* Author: Matteo Gianferrari
 * Data: 25/01/2022
 * Dati i 3 valori in semplice precisione x = 10^30, y = -10^30, z = 1,
 * verificare se vale la proprietà asociativa (x + y) + z = x + (y + z).
 */
#include <stdio.h>

int main(){
	float x = 10e30, y = -10e30;
	int z = 1;
	
	printf("%d", ((x + y) + z == x + (y + z)));
	
	return 0;
}
