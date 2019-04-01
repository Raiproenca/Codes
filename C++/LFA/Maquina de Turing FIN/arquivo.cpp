#include "arquivo.h"

/**
 * @brief Arquivo, abre o arquivo passado como argumento e inicializa a Maquina
 * @param str, nome do arquivo
 * Pre-condicao: passar nome do arquivo como argumento
 * Pos-condicao: arquivo aberto e maquina inicializada
 */
Arquivo::Arquivo(char const *str)
{
	this->arquivo = fopen(str, "r+");

	if( this->arquivo == NULL){
		cerr << "Erro na abertura do arquivo!" << endl;
	}

    //retorna a maquina inicializada
	this->maqT = new maquinaTuring();
}

/**
 * @brief inicializarMaquina, inicializa Maquina de Turing
 * @return a Maquina de Turing inicializada
 * Pre-condicao: funcoes auxiliares dependentes
 * Pos-condicao: maquina inicializada
 */
maquinaTuring *Arquivo::inicializarMaquina()
{
    this->maqT = new maquinaTuring();

    // le a quantidade de estado do arquivo
    this->leQuantidadeEstados(this->arquivo);

    // le os estados finais do arquivo
    this->lerEstadosFinais(this->arquivo);

    // le o alfabeto do arquivo
    this->lerAlfabeto(this->arquivo);

    // adiciona '*' e '$' no alfabeto
    this->maqT->novoSimbolo('*');
    this->maqT->novoSimbolo('$');

    while(!feof(arquivo)){
        this->lerTransicao(this->arquivo);
    }

    // inicializa o estado inicial com "q0"
    this->maqT->setEstadoInicial();

    // retorna a MT inicializada
    return this->maqT;
}

/**
 * @brief leQuantidadeEstados, le a quantidade de Estados do arquivo
 * @param arq, arquivo de onde vai ler os estados
 * Pre-condicao: existir funcao adicionarEstado
 * Pos-condicao: quantidade de estados lida e guardada
 */
void Arquivo::leQuantidadeEstados(FILE *arq) {
	int i, quant = 0;
	char str[64];

    // le a quantidade de estado do arquivo
   fscanf(arq, "Q=%d", &quant);

//    printf("Q = %d\n", quant);

   for(i = 0; i < quant; ++i) {
	   sprintf(str, "q%d", i);
	   this->maqT->adicionarEstado(new string(str));
   }
}

/**
 * @brief lerEstadosFinais, Le os Estados Finais do arquivo
 * @param arq, arquivo quer sera lido
 * Pre-condicao: nenhuma
 * Pos-condicao: nenhuma
 */
void Arquivo::lerEstadosFinais(FILE *arq)
{
	char estadoStr[MAX] = {0}, aux[MAX] = {0};
	int i, n;

	fscanf(arq, " F = { %[^}]} ", estadoStr);

	for(i = n = 0; i < (int)strlen(estadoStr); i += n){
        //le os estados finais
        sscanf(estadoStr + i, "%[^,],", aux);
		n = strlen(aux)+1;

        //inicializa o nome do estado
		string *nomeEstado = new string(aux);
		Estado *estadoEncontrado = this->maqT->encontrarEstado(nomeEstado);

        //estado final recebe true
		estadoEncontrado->final = true;

		delete nomeEstado;
	}

}

/**
 * @brief lerAlfabeto, Le o alfabeto do arquivo
 * @param arq, arquivo quer sera lido
 * Pre-condicao: nenhuma
 * Pos-condicao: nenhuma
 */
void Arquivo::lerAlfabeto(FILE *arq)
{
	char strAux[MAX] = {0}, simbolo;
	int i, n;

    //le os alfabetos do arquivo
	fscanf(arq, " alfabeto = {%[^}]} ", strAux);

	for(i = n = 0; i < (int)strlen(strAux); i += n){

        //atribui o alfabeto na memoria
		sscanf(strAux + i, "%c ,%n", &simbolo, &n);
        //adiciona o simbolo lido
		this->maqT->adicionarSimbolo(simbolo);
	}
}

/**
 * @brief lerTransicao, le a Transicao do arquivo
 * @param arq, arquivo quer sera lido
 * Pre-condicao: nenhuma
 * Pos-condicao: nenhuma
 */
void Arquivo::lerTransicao(FILE *arq)
{
	char estadoOrigem[MAX] = {0}, estadoDestino[MAX] = {0};
	char simboloLeitura = 0, simboloEscrita = 0, direcao = 0;

	// enquanto nao chegar no final do arquivo
	while(!feof(arq)){
		fscanf(arq, " ( %[^,], %c ) = ( %[^,], %c , %c ) ", (char*)estadoOrigem, &simboloLeitura, (char*)estadoDestino, &simboloEscrita, &direcao);

        //inicializa os estados de origem e destino
		string *nomeestadoOrigem = new string(estadoOrigem);
		string *nomeEstadoDestino = new string(estadoDestino);

        //testa a direção
		if(direcao == 'D') direcao = 1;
		if(direcao == 'E') direcao = -1;

        //cria a transição
		this->maqT->criarTransicao(nomeestadoOrigem, simboloLeitura, nomeEstadoDestino, simboloEscrita, direcao);
	}
}


