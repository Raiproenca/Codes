#ifndef ARQUIVO_H
#define ARQUIVO_H

#include "maquinaturing.h"
#include <string.h>

#define MAX 256

class Arquivo{

private:

    /**
     * @brief arquivo, de onde vai ler os dados
     * @brief maqT, maquina de Turing
     */
    FILE *arquivo;
    maquinaTuring *maqT;

public:

    /**
     * @brief Arquivo, abre o arquivo passado como argumento e inicializa a Maquina
     * @param str, nome do arquivo
     * Pre-condicao: passar nome do arquivo como argumento
     * Pos-condicao: arquivo aberto e maquina inicializada
     */
    Arquivo(char const *str);

    /**
     * @brief inicializarMaquina, inicializa Maquina de Turing
     * @return a Maquina de Turing inicializada
     * Pre-condicao: funcoes auxiliares dependentes
     * Pos-condicao: maquina inicializada
     */
    maquinaTuring *inicializarMaquina();

    /**
     * @brief leQuantidadeEstados, le a quantidade de Estados do arquivo
     * @param arq, arquivo de onde vai ler os estados
     * Pre-condicao: existir funcao adicionarEstado
     * Pos-condicao: quantidade de estados lida e guardada
     */
    void leQuantidadeEstados(FILE *arq);

    /**
     * @brief lerEstadosFinais, Le os Estados Finais do arquivo
     * @param arq, arquivo quer sera lido
     * Pre-condicao: nenhuma
     * Pos-condicao: nenhuma
     */
    void lerEstadosFinais(FILE *arq);

    /**
     * @brief lerAlfabeto, Le o alfabeto do arquivo
     * @param arq, arquivo quer sera lido
     * Pre-condicao: nenhuma
     * Pos-condicao: nenhuma
     */
    void lerAlfabeto(FILE *arq);

    /**
     * @brief lerTransicao, le a Transicao do arquivo
     * @param arq, arquivo quer sera lido
     * Pre-condicao: nenhuma
     * Pos-condicao: nenhuma
     */
    void lerTransicao(FILE *arq);

};

#endif // ARQUIVO_H
