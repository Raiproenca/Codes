#ifndef ARVOREAVL_H
#define ARVOREAVL_H
#include<stdio.h>
#include<stdlib.h>

struct NO{
    int info;
    int fb;
    struct NO *esq;
    struct NO *dir;
};

typedef struct NO *ArvoreAvl;

int maior(int x, int y);
int alturadoNo(struct NO *no);
int fatorbalancemento_No(struct NO *no);

ArvoreAvl inicializarArvore();
ArvoreAvl rotacaoEsquerda(ArvoreAvl p);
ArvoreAvl rotacaoDireita(ArvoreAvl p);
ArvoreAvl rotacaoDuplaDireita(ArvoreAvl p);
ArvoreAvl rotacaoDuplaEsquerda(ArvoreAvl p);

int insercao(ArvoreAvl *r, int x);
int remover_ArvAVL(ArvoreAvl *raiz, int valor);
void imprimirArvore(ArvoreAvl raiz);

#endif // ARVOREAVL_H

