/*
 * main.c
 *
 *  Created on: 26/02/2015
 *      Author: Marcelo Odir
 */
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

unsigned long fatorialRec(unsigned long number) {
	if(number==0 || number==1) return 1;

	return number * fatorialRec(number-1);
}

unsigned long fatorialDyn(unsigned long number) {
	int i;
	unsigned long fatorial, fator=1;
	if(number==0 || number==1) return 1;

	for(i=2;i<=number;i++) {
		fatorial = i * fator;
		fator = fatorial;
	}
	return fatorial;
}

int fibonacciRec(int number) {
	if(number==1 || number==2) return 1;
	return fibonacciRec(number-1) + fibonacciRec(number-2);
}

int fibonacciDyn(int number) {
	int fib01=1, fib02=1, fib, i;

	if(number==1 || number==2) return 1;

	for(i=3;i<=number;i++) {
		fib = fib01 + fib02;
		fib02 = fib01;
		fib01 = fib;
	}
	return fib;
}


int main(int argc, char **argv) {
	int valor = 20;
	unsigned long resultado;
	double tempo01, tempo02, tempo03,tempo04,ini;

	/**ini = clock();
	resultado = fibonacciRec(valor);
	tempo01 = (clock() - ini) * 1000.0 / CLOCKS_PER_SEC;
	printf("fibonacci recursivo: %d, tempo de exec em ms: %lf\n",resultado,tempo01);

	ini = clock();
	resultado = fibonacciDyn(valor);
	tempo02 = (clock() - ini) * 1000.0 / CLOCKS_PER_SEC;
	printf("fibonacci Dinâmico: %d, tempo de exec em ms: %lf\n",resultado,tempo02);
	**/
	ini = clock();
	resultado = fatorialRec(valor);
	tempo03 = (clock() - ini) * 1000.0 / CLOCKS_PER_SEC;
	printf("fatorial recursivo: %lu, tempo de exec em ms: %lf\n",resultado,tempo03);

	ini = clock();
	resultado = fatorialDyn(valor);
	tempo04 = (clock() - ini) * 1000.0 / CLOCKS_PER_SEC;
	printf("fatorial Dinâmico: %lu, tempo de exec em ms: %lf\n",resultado,tempo04);


	return EXIT_SUCCESS;
}

