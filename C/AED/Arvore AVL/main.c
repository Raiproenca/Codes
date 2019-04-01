#include <stdio.h>
#include"arvoreavl.h"

int main(void)
{
    ArvoreAvl raiz = inicializarArvore();
    int x;

    printf("Informe o 1 valor: ");
    scanf("%d", &x);
    insercao(&(*raiz), x);

    printf("oi");
    imprimirArvore(&((*raiz)));

    return 0;
}


