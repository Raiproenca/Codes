#include "circulo.h"

/**
 * @brief Circulo::Circulo, construtor Classe Circulo
 * @param radianos, dado utilizado para calcular a área do Circulo, é informado pelo usuário
 */
Circulo::Circulo(double radianos) : AreaPoligono()
{
    this->radianos = radianos;
}

/**
 * @brief Circulo::getArea, calcula a área. (Pi vezes radianos ao quadrado)
 * @return área do circulo
 */
double Circulo::getArea()
{
   return M_PI * radianos * radianos;
}

Circulo::~Circulo()
{

}
