#include "retangulo.h"

/**
 * @brief Retangulo::Retangulo, construtor Classe Retangulo
 * @param base, valor da base será informado pelo usuário
 * @param altura, valor da altura será informado pelo usuário
 */
Retangulo::Retangulo(double base, double altura) : AreaPoligono()
{
    this->base = base;
    this->altura = altura;
}

/**
 * @brief Retangulo::getArea
 * @return a área do retangulo
 */
double Retangulo::getArea()
{
    return base * altura;
}

Retangulo::~Retangulo()
{

}

