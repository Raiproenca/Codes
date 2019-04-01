#include "estado.h"

/**
 * @brief Estado::Estado, inicializa o estado
 * @param nome, nome do estado
 * Pre-condicao: nenhuma
 * Pos-condicao: estado inicializado
 */
Estado::Estado(string *nome)
{
    this->transicao = new vector<Transicao*>();
    this->nome = nome;
    this->final = false;
}

/**
 * @brief Estado::getNome
 * @return nome do estsado
 * Pre-condicao: nenhuma
 * Pos-condicaoo: nenhuma
 */
string *Estado::getNome()
{
    //retorna o nome do estado
    return nome;
}

/**
 * @brief adicionarTransicao, adiciona transicao
 * @param simboloL, simbolo lido
 * @param simboloE, simbolo escrito
 * @param estado, estado de chegada
 * @param direcao, direcao movimento
 * Pre-condicao: nenhuma
 * Pos-condicao: nenhuma
 */
void Estado::adicionarTransicao(char simboloL, char simboloE, Estado *estado, int direcao)
{
    // adiciona uma nova transicao no vetor de transicoes
    this->transicao->push_back(new Transicao(simboloL,simboloE, estado, direcao));
}

/**
 * @brief getTransicao, compara uma transicao com o simbolo lido
 * @param simbolo, simbolo usado para comparar
 * @return transicao, a posicao da transicao com o simbolo lido
 * Pre-condicao: nenhuma
 * Pos-condicao: nenhuma
 */
Transicao *Estado::getTransicao(char simbolo)
{
    int tam = this->transicao->size();
    int i;

    // loop para percorrer a lista de transicoes
    for(i = 0; i < tam; i++){

        // compara posiscao i do vetor transicao com o simbolo
        if(this->transicao->at(i)->simboloLido == simbolo){
            return this->transicao->at(i);
        }
    }
    return NULL;
}
