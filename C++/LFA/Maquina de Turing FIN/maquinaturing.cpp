#include "maquinaturing.h"

#include<string.h>

/**
 * @brief maquinaTuring, inicializa os campos da Maquina de Turing
 * Pre-condicao: nenhuma
 * Pos-condicao: campos inicializado
 */
maquinaTuring::maquinaTuring()
{
	this->estados = new vector<Estado*>();
	this->alfabeto = new vector<char>();
	this->estadoInicial = NULL;
}

/**
 * @brief adicionarEstado, adiciona o estado a maquinoa
 * @param nome, nome do Estado
 * @return estado adicionarEstado()
 * Pre-condicao: nenhuma
 * Pos-condicao: Estado e adicionado a lista da maquina
 */
Estado *maquinaTuring::adicionarEstado(string *nome)
{
	// Testa se o estado ja exite no automato
	if(this->encontrarEstado(nome) != NULL){
		cerr << "Erro: Estado " << *nome << " ja existe no automato." << endl;
	}

	// caso nao exista, criar novo estado e inserir no final
	this->estados->push_back(new Estado(nome));

	return this->encontrarEstado(nome);
}

/**
 * @brief encontrarEstado, procura um estado pelo nome
 * @param nome, nome do estado que se quer encontrar
 * @return o estado encontrado
 * Pre-condicao: nenhuma
 * Pos-condicao: nenhuma
 */
Estado *maquinaTuring::encontrarEstado(string *nome)
{
	int tam = (int)this->estados->size();

	// loop para percorrer a lista de estado
	for(int i = 0; i < tam; i++){

		// compara cada posicao do vetor com a variavel nome
		if(!this->estados->at(i)->getNome()->compare(*nome))
			return this->estados->at(i);
	}
	return NULL;
}

/**
 * @brief setEstadoInicial, diz quem eh o estado inicial
 * Pre-condicao: nenhuma
 * Pos-condicao: nenhuma
 */
void maquinaTuring::setEstadoInicial()
{
    //atribui o estado inicial
	string str = string("q0");
	this->estadoInicial = this->encontrarEstado(&str);
}

/**
 * @brief adicionarSimbolo, adiciona novo simbolo na maquinaTuring
 * @param simbolo, simbolo a ser adicionado
 * Pre-condicao: nenhuma
 * Pos-condicao: simbolo adicionado
 */
void maquinaTuring::adicionarSimbolo(char simbolo)
{
	// se o simbolo ja existe
	if(this->contemSimbolo(simbolo)){

		cerr << "Simbolo " << simbolo << " ja existente." << endl;
	}

	// se o simbolo nao existe, adicionar no final do vector
	this->alfabeto->push_back(simbolo);
}

/**
 * @brief novoSimbolo, adiciona novo simbolo no ALFABETO
 * @param simbolo, simbolo a ser adicionado
 * Pre-condicao: nenhuma
 * Pos-condicao: simbolo adicionado
 */
void maquinaTuring::novoSimbolo(char simbolo){

    // se esse simbolo ainda nao existe
	if(!this->contemSimbolo(simbolo)){

        // adiciona ele no alfabeto
		this->alfabeto->push_back(simbolo);

	} else {

        // se nao existe, mostra mensagem de erro
		cerr << "Simbolo " << simbolo << " ja existente." << endl;
	}
}

/**
 * @brief contemSimbolo, verifica se o si­mbolo esta contido no vetor
 * @param simbolo, simbolo a ser comparado
 * @return true se o vetor contem o simbolo e false caso contrario
 * Pre-condicao: nenhuma
 * Pos-condicao: nenhuma
 */
bool maquinaTuring::contemSimbolo(char simbolo)
{
	// recebe o tamanho do vetor alfabeto
	int tam = this->alfabeto->size();

	// loop para percorrer o vetor de alfabeto
	for(int i = 0; i < (int)tam; i++){

        // se elemento no Ãindice i for igual a si­mbolo
		if(this->alfabeto->at(i) == simbolo){

            // se o vetor contem o simbolo
			return true;
		}
	}

    // se nao contem
	return false;
}

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
void maquinaTuring::criarTransicao(string *nomeOrigem, char simboloLido, string *nomeDestino, char simboloEscrito, int direcao)
{
	Estado *origem = this->encontrarEstado(nomeOrigem);
	Estado *destino = this->encontrarEstado(nomeDestino);

    // condicao para adicionar uma nova transicao
	if(origem && destino && this->contemSimbolo(simboloLido) && this->contemSimbolo(simboloEscrito) && movimentoValido(direcao)){
		origem->adicionarTransicao(simboloLido, simboloEscrito, destino, direcao);
	}else{
		cout << "Nao foi possivel adicionar a transicao" << endl;
	}
}

/**
 * @brief movimentoValido, verifica se o movimento e valido
 * @param direcao, direcao que se quer validar
 * @return 1 ou -1
 * Pre-condicao: nenhuma
 * Pos-condicao: nenhuma
 */
bool maquinaTuring::movimentoValido(int direcao)
{
    //retorna a validade do movimento
	return direcao == 1 || direcao == -1;
}

/**
 * @brief testaSequencia, testa a sequencia e diz se esta eh rejeitada ou aceita
 * @param sequencia, sequencia a ser testada
 * Pre-condicao: funcao auxiliar testeSequenciaDoEstado()
 * Pos-condicao: nenhuma
 */
void maquinaTuring::testaSequencia(string *sequencia)
{
    //testa a sequencia e mostra se for aceita ou rejeitada
	if(this->testeSequenciaDoEstado( sequencia, 1, this->estadoInicial)){
        cout << "                       ACEITA" <<endl;
	} else {
        cout << "                      REJEITA" << endl;
	}
}

/**
 * @brief testeSequenciaDoEstado, testa sequencia do estado
 * @param sequencia, sequecia a ser testada
 * @param posicao, posicao
 * @param estadoAtual, estado atual
 * @return NULL se estado atual for final ou return testeSequenciaDoEstado()
 * Pre-condicao: nenhuma
 * Pos-condicao: nenhuma
 */
bool maquinaTuring::testeSequenciaDoEstado(string *sequencia, int posicao, Estado *estadoAtual)
{
	Transicao *transicao;
	char simbolo = 0;

	if(estadoAtual == NULL)
		return false;
	simbolo = (*sequencia)[posicao];

    cout << "                    " << sequencia->substr(0, posicao) << "[" << *estadoAtual->getNome() << "]" << sequencia->substr(posicao) << endl;

    // verifica se o si­mbolo esta contido no vetor
	if(!this->contemSimbolo(simbolo)) return false;

    // pega a transicao da posicao em que esta o simbolo
	transicao = estadoAtual->getTransicao(simbolo);

	if(transicao == NULL){

        // estado atual sera o final
		return estadoAtual->final;
	}

    (*sequencia)[posicao] = transicao->simboloEsc;
	return this->testeSequenciaDoEstado(sequencia, posicao + transicao->direcao, transicao->estado);
}


