#include <stdio.h>
#include <stdlib.h>

#include "source.h"


int main(int argc, char* argv[]){
	int argv1, argv2;
	
	if (argc < 3) {
		printf("Vc passou : %d argumento\n", argc);
		printf("Vc precisa passar no minimo 3 argumentos\n");
		return 1;
	}

	if (argc > 3)
	{
		printf("Vc passou muitos parametros!\n");
		printf("Vc precisa passar no maximo 3 argumentos\n");
		return 1;
	}

	printf("primeiro argumento: %s\n", argv[1]);
	printf("segundo argumento: %s\n", argv[2]);

	argv1 = atoi(argv[1]);
	argv2 = atoi(argv[2]);

	printf("A soma de argv[1] e argv[2]: %d\n", soma(argv1, argv2));
	printf("A subtração de argv[1] e argv[2]: %d\n", subtracao(argv1, argv2));
	printf("A multiplicação de argv[1] e argv[2]: %d\n", produto(argv1, argv2));
	printf("A divisão de argv[1] e argv[2]: %d\n", divisao(argv1, argv2));

	return 0;
}
