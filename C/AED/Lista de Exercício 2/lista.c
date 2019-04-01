#include"lista.h"

Lista* criarLista()
{
    return NULL;
}

int vazia (Lista* li){
    return ( li == NULL);
}

Lista* insere(Lista* li, int info)
{
   Lista* novo = (Lista*)malloc(sizeof(Lista));
   novo->num = info;
   novo->prox = li;
   return novo;
}

void imprime(Lista* li)
{
    Lista* p;
    for( p = li; p != NULL; p = p->prox)
        printf("%d.\n", p->num);
    printf("\n");
//    printf("->");
}

//recursivo
void imprime2(Lista* li)
{
    if(vazia(li))
        printf("NULL");
    else{
        printf("%d\n",li->num);
        imprime2(li->prox);
    }
}

Lista* buscarElemento ( Lista* li, int x)
{
    Lista* p;
    for( p = li; p != NULL; p=p->prox)
        if(p->num == x)
            return p;
        return NULL;
}

Lista* retirar(Lista* li, int info)
{
    Lista* ant = NULL;                                  // ponteiro para o elemento anterior
    Lista* p = li;                                      // ponteiro para percorrer a lista

    if ( p == NULL ){
        return li;
    }

    while ( p != NULL && p->num != info ){
        ant = p;
        p = p->prox;
    }

    if( ant == NULL){
        li = p->prox;
    }else{
        ant->prox = p->prox;
    }
    free(p);
    return li;
}

void liberaLista (Lista* li)
{
    Lista* p = li;
    while( p != NULL){
        Lista* t = p->prox;
        free(p);
        p = t;
    }
}

Lista* insereOrdenado(Lista *li, int info){
    Lista* novo = NULL;
    Lista* ptr = NULL;
    if(!li || li->num > info){
        novo = (Lista*) malloc(sizeof(Lista));
        novo->num = info;
        novo->prox = li;
        return novo;
    }
    if(!li->prox || li->prox->num > info){
       novo = (Lista*) malloc(sizeof(Lista));
       novo->num = info;
       ptr = li->prox;
       li->prox = novo;
       novo->prox = ptr;
    }else{
       li->prox = insereOrdenado(li->prox,info);
    }
    return li;
}

Lista* inverter(Lista* li) {

   Lista* p;
   Lista* q = NULL;

   for ( p = li; p; p = p->prox)
       q = insere(q, p->num);
   return q;
}

Lista* concatena(Lista* li1, Lista* li2)
{
    Lista* p = NULL;

    if( li1 == NULL ) return li2;
    if( li2 == NULL ) return li1;

    p = li1;
    while( p->prox != NULL )
        p = p->prox;

    p->prox = li2;

    return li1;
}

Lista* merge(Lista* li1, Lista* li2)
{
    Lista* novaLista = NULL;
    Lista* auxli1 = li1;
    Lista* auxli2 = li2;

    while (auxli1 != NULL && auxli2 != NULL){
        novaLista = insere(novaLista, auxli1->num);
        novaLista = insere(novaLista, auxli2->num);
        auxli1 = auxli1->prox;
        auxli2 = auxli2->prox;
    }
    while(auxli1 != NULL){
        novaLista = insere(novaLista, auxli1->num);
        auxli1 = auxli1->prox;
    }
    while(auxli2 != NULL){
        novaLista = insere(novaLista, auxli2->num);
        auxli2 = auxli2->prox;
    }
    return novaLista;
}

Lista* merge_ord( Lista* li1, Lista* li2, Lista* ordem)
{
    Lista* novalista = NULL;

    if ( li1 == NULL ) return li2;
    if ( li2 == NULL ) return li1;

    if ( li1 && li2 )
    {
        if(li1->num <= li2->num)
        {
            ordem = li1;
            li1 = ordem->prox;
        }else{
            ordem = li2;
            li2 = ordem->prox;
        }
    }

    novalista = ordem;

    while( li1 && li2 )
    {
        if(li1->num <= li2->num)
        {
            ordem->prox = li1;
            ordem = li1;
            li1 = ordem->prox;
        }else{
            ordem->prox = li2;
            ordem = li2;
            li2 = ordem->prox;
        }
    }

    if ( li1 == NULL) ordem->prox = li2;
    if ( li2 == NULL) ordem->prox = li1;

    return novalista;
}

int conta_ocorrencia1(Lista* li, int num)
{
    Lista* p = li;
    int c = 0;
    if (vazia(li)){
        printf("Lista vazia");
    }else{
        while(p != NULL){
            if(p->num == num){
                c++;
            }
            p = p->prox;
        }
    }
    return c;
}

int conta_ocorrencia( Lista* li, int num)
{
    if(li == NULL) return 0;

    if(li->num == num){
        return 1 + conta_ocorrencia(li->prox,num);
    }

    return conta_ocorrencia(li->prox,num);
}

void impares(Lista* li)
{
    Lista* p = li;
    if(vazia(li)) printf("NULL\n");
    while( p != NULL){
        if(p->num%2 != 0 ){
            printf("%d\n", p->num);
        }
    p = p->prox;
    }
}

Lista* imparesLista(Lista* li)
{
    Lista* novo = NULL; //lista p guardar os impares
    Lista* p = li; // percorre li

    if(vazia(li)) printf("NULL\n");

    while( p != NULL){
        if(p->num%2 != 0){ // se p->num é impar
          novo = insere(novo, p->num);
        }
        p = p->prox;
    }

    return novo;
}

Lista* remove_intervalo(Lista* li, int a, int b)
{
    Lista* p = li;
    Lista* novo = NULL;

    if(vazia(li)) printf("NULL\n");

    if(a > b) printf("ERRO!\n 'a' tem que ser menor ou igual a 'b'\n");

    while( p != NULL){
         if( p->num < a || p->num > b)
            novo = insere(novo,p->num);

        p = p->prox;
    }
    return novo; // faz com que a lista volta normal;
}

Lista* inserirapos(Lista *li, int info_ref, int info) {
    Lista* aux;
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    novo->num = info;
    novo->prox = NULL;

    if(vazia(li)) {
        return novo;
    }

    if(li->num != info && li->prox) {
        inserirapos(li->prox, info_ref, info);
        return li;
    }

    aux = li->prox;
    li->prox = novo;
    li->prox->prox = aux;

    return li;
}

Lista* menores ( Lista* li, int info)
{
    Lista* p = NULL;
    Lista* novo = NULL;

    if(li == NULL) return NULL;

    for( p = li; p; p = p->prox){
        if(p->num < info){
            novo = insere(novo,p->num);
         }
    }
    return novo;
}

//questão 1 da prova
Lista* removerEnesimo ( Lista* li, int n){
    if(vazia(li)) return NULL;
    if (n == 1){
        Lista* aux = li;
        li = li->prox;
        free(aux);
    }else{
        li->prox = removerEnesimo(li->prox, n-1);
        return li;
    }
}

Lista* remover_enesimo (Lista* li, int n){
    Lista* anterior = li;
    Lista* p = li;
    while (!vazia(p) && n != 1){
        anterior = p;
        p = p->prox;
        n--;
    }
    if(!vazia(p)){ // achou
        if( p == li){
            li = li->prox;
        }else{
            anterior->prox = p->prox;
        }
        free(p);
    }
    return li;
}

//questão 3 da prova
Lista* intercala_prova ( Lista* li1, Lista* li2){
    if(vazia(li1) && vazia(li2)) return NULL;

    if(vazia(li1))
        return insere(intercala_prova(NULL, li2->prox), li2->num);

    if(vazia(li2))
        return insere(intercala_prova(li1->prox, NULL), li1->num);

    return insere(insere(intercala_prova(li1->prox,li2->prox),li2->num),li1->num);
}

// questao 5 da prova
/* typedef struct no{
        int info;
        struct no* prox;
   }

   typedef struct no_ext{
      struct no* cabeça;
      struct no_ext * prox;
  }
