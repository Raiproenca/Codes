#ifndef MAQUINATURING_H
#define MAQUINATURING_H

#include<iostream>
#include<string>
#include<vector>

#include "estado.h"

using namespace std;

class maquinaTuring{

private:

    /**
     * @brief estados, vetor para guardar os estados
     * @brief alfabeto, vetor para guardar o alfabeto
     * @brief estadoInicial, estado inicial
     */
    vector<Estado*> *estados;
    vector<char> *alfabeto;
    Estado *estadoInicial;

public:

    /**
     * @brief maquinaTuring, inicializa os campos da Maquina de Turing
     * Pre-condicao: nenhuma
     * Pos-condicao: campos inicializado
     */
    maquinaTuring();

    /**
     * @brief adicionarEstado, adiciona o estado a maquinoa
     * @param nome, nome do Estado
     * @return estado adicionarEstado()
     * Pre-condicao: nenhuma
     * Pos-condicao: Estado e adicionado a lista da maquina
     */
    Estado *adicionarEstado(string *nome);

    /**
     * @brief encontrarEstado, procura um estado pelo nome
     * @param nome, nome do estado que se quer encontrar
     * @return o estado encontrado
     * Pre-condicao: nenhuma
     * Pos-condicao: nenhuma
     */
    Estado *encontrarEstado(string *nome);

    /**
     * @brief setEstadoInicial, diz quem eh o estado inicial
     * Pre-condicao: nenhuma
     * Pos-condicao: nenhuma
     */
    void setEstadoInicial();

    /**
     * @brief adicionarSimbolo, adiciona novo simbolo na maquinaTuring
     * @param simbolo, simbolo a ser adicionado
     * Pre-condicao: nenhuma
     * Pos-condicao: simbolo adicionado
     */
    void adicionarSimbolo(char simbolo);

    /**
     * @brief novoSimbolo, adiciona novo simbolo no ALFABETO
     * @param simbolo, simbolo a ser adicionado
     * Pre-condicao: nenhuma
     * Pos-condicao: simbolo adicionado
     */
    void novoSimbolo(char simbolo);

    /**
     * @brief criarTransicao, cria uma nova transicao
     * @param nomeOrigem, nome do Estado de origem
     * @param simboloLido, simbolo que sera lido
     * @param nomeDestino, nome do Estado de destino
     * @param simboloEscrito, simbolo a ser escrito
     * @param direcao, direcao da transicao
     * Pre-condicao: nenhuma
     * Pos-condicao: nenhuma
     */
    void criarTransicao(string *nomeOrigem, char simboloLido, string *nomeDestino, char simboloEscrito, int direcao);

    /**
     * @brief movimentoValido, verifica se o movimento e valido
     * @param direcao, direcao que se quer validar
     * @return 1 ou -1
     * Pre-condicao: nenhuma
     * Pos-condicao: nenhuma
     */
    bool movimentoValido(int direcao);

    /**
     * @brief contemSimbolo, verifica se o si­mbolo esta contido no vetor
     * @param simbolo, simbolo a ser comparado
     * @return true se o vetor contem o simbolo e false caso contrario
     * Pre-condicao: nenhuma
     * Pos-condicao: nenhuma
     */
    bool contemSimbolo(char simbolo);

    /**
     * @brief testaSequencia, testa a sequencia e diz se esta eh rejeitada ou aceita
     * @param sequencia, sequencia a ser testada
     * Pre-condicao: funcao auxiliar testeSequenciaDoEstado()
     * Pos-condicao: nenhuma
     */
    void testaSequencia(string *sequencia);

    /**
     * @brief testeSequenciaDoEstado, testa sequencia do estado
     * @param sequencia, sequecia a ser testada
     * @param posicao, posicao
     * @param estadoAtual, estado atual
     * @return NULL se estado atual for final ou return testeSequenciaDoEstado()
     * Pre-condicao: nenhuma
     * Pos-condicao: nenhuma
     */
    bool testeSequenciaDoEstado(string *sequencia,int posicao, Estado *estadoAtual);


};

#endif // MAQUINATURING_H
