#include "triangulo.h"

/**
 * @brief Triangulo::Triangulo, construtor da Classe Triangulo
 * @param base, valor da base será informado pelo usuário
 * @param altura, valor da altura será informado pelo usuário
 */
Triangulo::Triangulo(double base, double altura) : AreaPoligono()
{
    this->altura = altura;
    this->base = base;
}

/**
 * @brief Triangulo::getArea
 * @return a área do Triangulo
 */
double Triangulo::getArea()
{
    return ((base * altura) / 2);
}

Triangulo::~Triangulo()
{

}


