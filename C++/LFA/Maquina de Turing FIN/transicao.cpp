#include "transicao.h"

/**
 * @brief Transicao, inicializa os campos
 * @param simboloL, simbolo lido
 * @param simboloE, simbolo escrito
 * @param estado, estado de chegada
 * @param direcao, direcao do movimento
 * Pre-condicao: nenhuma
 * Pos-condicao: nenhuma
 */
Transicao::Transicao(char simboloL, char simboloE, Estado *estado, int direcao )
{
    //inicializa os campos de transicao
    this->simboloLido = simboloL;
    this->simboloEsc = simboloE;
    this->estado = estado;
    this->direcao = direcao;
}

