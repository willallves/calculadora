/*
* For compile use
* gcc loadingLibrary.c -o bin -ldl
*/


#include <dlfcn.h>
#include <stdio.h>
 
int (*somaA)(int a, int b);
int (*produtoA)(int a, int b);

int main(int argc, char **argv) {
 
    void *handle = dlopen ("./libcalculadora.so", RTLD_LAZY);
    if (!handle) {
        printf("error\n");
        return -1;
    }
    //printf("%p", handle);

    somaA = dlsym(handle, "soma");
    produtoA = dlsym(handle, "produto");


    int soma = somaA(1, 1);
    int produto = produtoA(1, 1);

    printf("soma = %d\n", soma);
    printf("produto = %d\n", produto);

   
    dlclose(handle);
    return 0;
}
