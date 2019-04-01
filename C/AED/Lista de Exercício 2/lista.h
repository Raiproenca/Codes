#ifndef LISTA_H
#define LISTA_H
#include<stdio.h>
#include<stdlib.h>

//LISTA ENCADEADA SIMPLE:
struct No{
    int num;
    struct No* prox;
};

typedef struct No Lista;

Lista* criarLista();

// Testa se uma lista e vazia
// Entrada: lista
// Retorno: 1 se a lista e vazia ou 0 caso contrario
// Pre-condic~ao: nenhuma
// Pos-condic~ao: nenhuma
int vazia(Lista * li);

// Insere um elemento na lista
// Entrada: lista e elemento a ser inserido
// Retorno: lista alterada
// Pre-condic~ao: nenhuma
// Pos-condic~ao: elemento e inserido na lista
Lista* insere(Lista* li, int info);
Lista* insereOrdenado(Lista* li, int info);
Lista* inserirapos(Lista *li, int info_ref, int info);
// Remove um elemento da lista
// Entrada: lista e elemento a ser removido
// Retorno: lista alterada
// Pre-condic~ao: nenhuma
// Pos-condic~ao: elemento e removido da lista
Lista* retirar(Lista* li, int info);

// Imprime os elementos da lista
// Entrada: lista
// Retorno: nenhum
// Pre-condic~ao: nenhuma
// Pos-condic~ao: os elementos s~ao impressos no console
void imprime(Lista* li);
void imprime2(Lista* li);

// Inverte uma lista
// Entrada: lista
// Retorno: lista invertida
// Pre-condic~ao: nenhuma
// Pos-condic~ao: lista original n~ao e modificada
Lista* inverter(Lista* li);

// Concatena duas listas
// Entrada: listas a serem concatenadas
// Retorno: lista resultante da concatenac~ao
// Pre-condic~ao: nenhuma
// Pos-condic~ao: listas originais n~ao s~ao modificadas
Lista* concatena(Lista* li1, Lista* li2);

// Intercala duas listas
// Entrada: listas a serem intercaladas
// Retorno: lista resultante da intercalac~ao
// Pre-condic~ao: nenhuma
// Pos-condic~ao: listas originais permanecem inalteradas
Lista* merge(Lista* li1, Lista* li2);

//Retorna quantas vezes o numero digitado apareceu na lista
int conta_ocorrencia(Lista* li, int num);

void impares(Lista* li);

//Cria uma lista com os números ímpares da lista informada
// Entrada: lista
// Retorno: lista de números ímpares
// Pré-condição: nenhuma
//Pós-condição: retorna uma nova lista com os números ímpares
// mantendo a lista original
Lista* imparesLista(Lista* li);

//Remove os elementos que estejam em um intervalo dado
//Entrada: Lista e intervalo fechado [a,b]
//Retorno: lista
//Pré-condição: a<= b
//Pós-condição lista modificada sem números no intervalo fechado [a,b]
Lista* remove_intervalo(Lista* li, int a, int b);
#endif // LISTA_H
