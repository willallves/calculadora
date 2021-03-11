#include <stdio.h>
#include <stdlib.h>

#include "source.h"


void calculadora() {
	printf("\nsoma %d\n", soma(1, 1));
	printf("subtracao %d\n", subtracao(1, 1));
	printf("multiplicacao %d\n", produto(1, 1));
	printf("dividida %d\n", divisao(1, 1));
}

int main(int argc, char* argv[]) {

	calculadora();

	return 0;
}
