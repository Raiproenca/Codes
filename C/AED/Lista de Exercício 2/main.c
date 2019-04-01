#include "lista.h"
#include"lista.c"

int main() {

   int x;
   Lista* li = criarLista();
   Lista* li1 = criarLista();
   Lista* li2 = criarLista();
   Lista* li3 = criarLista();
   Lista* li4 = criarLista();
   Lista* li5 = criarLista();
   printf("Criando Lista... \n\n");

   printf("Lista 1: \n\n");
   li1 = insere(li1, 15);
   li1 = insere(li1, 25);
   li1 = insere(li1, 35);
   li1 = insere(li1, 45);
//   imprime(li1);

   printf("Inserindo apos:\n");
   li = inserirapos(li1, 45, 55);
   imprime(li);

   printf("Lista 1 invertida: \n\n");
//   li1= inverter(li1);
//   imprime(li1);

   printf("Lista 2: \n\n");
   li2 = insere(li2, 10);
   li2 = insere(li2, 20);
   li2 = insere(li2, 30);
   li2 = insere(li2, 40);
//   imprime(li2);

   printf("Lista 2 invertida: \n\n");
//   li2 = inverter(li2);
//   imprime(li2);

   printf("Lista 1 e 2 contatenadas: \n\n");
//   li = concatena(li1,li2);
//   imprime(li);

    printf("Lista 1 e 2 intercaladas: \n\n");
//    li = merge(li1,li2);
//    li=inverter(li);
//    imprime(li);

   li3 = insereOrdenado(li3,1);
   li3 = insereOrdenado(li3,2);
   li3 = insereOrdenado(li3,3);
   li3 = insereOrdenado(li3,4);
   li3 = insereOrdenado(li3,5);
   li3 = insereOrdenado(li3,5);
   li3 = insereOrdenado(li3,7);
   li3 = insereOrdenado(li3,8);
   //   imprime(li3);

   x = conta_ocorrencia1(li3, 5);
   printf("Conta ocorrencias:\n");
   printf("%d\n", x);

   printf("\nLista de impares:\n");
   impares(li3);

   printf("\nLista de impares:\n");
   li4 = imparesLista(li3);
   imprime(li4);

//   printf("\nRemovendo intervalo de 'a' a 'b':\n");
//   li5 = remove_intervalo(li3,2,5);
//   li5 = inverter(li5);
//   imprime(li5);

   li5 = menores(li3,4);
   imprime(li5);
   return 0;
}

