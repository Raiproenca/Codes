#include"arvoreavl.h"

int vazia(ArvoreAvl arvore){
    return(arvore == NULL);
}

int alturadoNo(struct NO *no)
{
    if(no == NULL)
        return -1;
    else
        return no->fb;
}

int fatorbalancemento_No(struct NO *no)
{
    return labs(alturadoNo(no->esq) - alturadoNo(no->dir));
}

///calcula o maior valor
int maior(int x, int y){
    if(x > y)
        return x;
    else
        return y;
}


struct NO* procuraMenor(struct NO* atual)
{
    struct NO *no1 = atual; // 1
    struct NO *no2 = atual->esq; // 2 (1 e 2) procura pelo noh mais a esquerda
    while(no2 != NULL){
        no1 = no2;
        no2 = no2->esq;
    }
    return no1;
}

ArvoreAvl rotacaoEsquerda(ArvoreAvl p)
{
    ArvoreAvl u = p->dir;
    ArvoreAvl t2 = u->esq;
    u->esq = p;
    p->dir = t2;
    return u;
}


ArvoreAvl rotacaoDireita(ArvoreAvl p)
{
    ArvoreAvl u = p->esq;
    ArvoreAvl t2 = u->dir;
    u->dir = p;
    p->esq = t2;
    return u;
}

ArvoreAvl rotacaoDuplaEsquerda(ArvoreAvl p)
{
    ArvoreAvl u = p->dir;
    ArvoreAvl v = u->esq;
    ArvoreAvl t2 = v->esq;
    ArvoreAvl t3 = v->dir;

    p->dir = t2;
    u->esq = t3;
    v->esq = p;
    v->dir = u;
    return v;
}

ArvoreAvl rotacaoDuplaDireita(ArvoreAvl p){
    ArvoreAvl u = p->esq;
    ArvoreAvl v = u->dir;
    ArvoreAvl t2 = v->esq;
    ArvoreAvl t3 = v->dir;

    p->esq = t3;
    u->dir = t2;
    v->esq = u;
    v->dir = p;
    return v;
}

int insercao(ArvoreAvl *r, int x)
{
    printf("\nAQUI 00001\n");
    // caso arvore vazia
    if(vazia(*r)) {
        *r = (ArvoreAvl)malloc(sizeof(struct NO));
        (*r)->info = x;
        (*r)->esq = (*r)->dir = NULL;
        (*r)->fb = 0;
        return 1;
    }

    printf("\nAQUI 0002\n");
    // caso inserir na arvore esquerda
    if( x < (*r)->info){
        if(insercao(&((*r)->esq), x)){
            switch((*r)->fb){
            case -1: (*r)->fb = 0; return 0;
            case 0: (*r)->fb = 1; return 1;
            case 1: // rebalancear
                if((*r)->esq->fb >= 0){
                    *r = rotacaoDireita(*r);
                    (*r)->dir->fb = 0;
                }else{
                    *r = rotacaoDuplaDireita(*r);
                    switch((*r)->fb){
                    case -1:
                        (*r)->esq->fb = 1;
                        (*r)->dir->fb = 0;
                        break;
                    case 0:
                        (*r)->esq->fb = 0;
                        (*r)->dir->fb = 0;
                        break;
                    case 1:
                        (*r)->esq->fb = 0;
                        (*r)->dir->fb = -1;
                        break;
                    }
                }
                (*r)->fb = 0; // atualiza fb da nova raiz
                return 0;
            }
        }
        printf("\nAQUI 3\n");
    }
    // inserir na arvore da direita
    else if(insercao(&((*r)->dir), x)){
        switch((*r)->fb){
        case 1:
            (*r)->fb = 0;
            return 0;
        case 0:
            (*r)->fb = -1;
            return 1;
        case -1:
            if((*r)->dir->fb <= 0){
                *r = rotacaoEsquerda(*r);
                (*r)->esq->fb = 0;
            }else{
                *r = rotacaoDuplaEsquerda(*r);
                switch((*r)->fb){
                case -1:
                    (*r)->esq->fb = 1;
                    (*r)->dir->fb = 0;
                    break;
                case 0:
                    (*r)->esq->fb  = 0;
                    (*r)->dir->fb = 0;
                    break;
                case 1:
                    (*r)->esq->fb = 0;
                    (*r)->dir->fb = -1;
                    break;
                }
            }
            (*r)->fb = 0;
            return 0;
        }
    }
    printf("\nAQUI 5\n");
}

int remover_ArvAVL(ArvoreAvl *raiz, int valor)
{
    if(*raiz == NULL)
    {
        printf("nao existe");
        return 0;
    }

    int res;

    if(valor < (*raiz)->info){
        if((res = remover_ArvAVL(&(*raiz)->esq, valor)) == 1){
            if(fatorbalancemento_No(*raiz) >= 2){
                if(alturadoNo((*raiz)->dir->esq) <= alturadoNo((*raiz)->dir->dir))
                    rotacaoEsquerda(*raiz);
                else
                    rotacaoDuplaEsquerda(*raiz);
            }
        }
    }

    if((*raiz)->info < valor){
        if((res = remover_ArvAVL(&(*raiz)->dir,valor)) == 1){
            if(fatorbalancemento_No(*raiz) >= 2 ){
                if(alturadoNo((*raiz)->esq->dir) <= alturadoNo((*raiz)->esq->esq))
                    rotacaoDireita(*raiz);
                else
                    rotacaoDuplaDireita(*raiz);
            }
        }
    }

    if((*raiz)->info == valor){ // pai tem 1 ou nenhum filho
        if(((*raiz)->esq == NULL || (*raiz)->dir == NULL)){
//            struct NO* oldNode = (*raiz);
            if((*raiz)->esq != NULL)
                *raiz = (*raiz)->esq;
            else
                *raiz = (*raiz)->dir;
        }else{ // no tem 2 filhos
            remover_ArvAVL(&(*raiz)->dir, (*raiz)->info);
            if(fatorbalancemento_No(*raiz) >= 2){
                if(alturadoNo((*raiz)->esq->dir) <= alturadoNo((*raiz)->esq->esq))
                    rotacaoEsquerda(*raiz);
                else
                    rotacaoDuplaDireita(*raiz);
            }
        }
        return 1;
    }
    return res;
}

void imprimirArvore(ArvoreAvl raiz )
{
    if ( raiz != NULL )
    {
        printf("No = %d, altura = %d, FATBAL = %d\n", raiz->info, alturadoNo(raiz), fatorbalancemento_No(raiz));
        imprimirArvore( raiz->esq );
        imprimirArvore( raiz->dir );
    }
}

ArvoreAvl inicializarArvore(){

    ArvoreAvl arvore = NULL;

    if((arvore = malloc(sizeof(arvore))) == NULL){
        return NULL;
    }

    arvore->dir = NULL;
    arvore->esq = NULL;
    return arvore;
}





