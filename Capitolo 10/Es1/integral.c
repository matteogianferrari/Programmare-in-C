#include "integral.h"

double f(double x){
	return (5 * x * x * x) + (4 / 5 * x * x) - (8 / 7 * x) + (14 / 37);
}

double integral(double a, double b, double (*f)(double), double step){
	double i, value = 0;
	
	for(i = a; i < b; i += step)
		value += step * (*f)(i + (step / 2));
	
	return value;
}
