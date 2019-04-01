#ifndef TRIANGULO_H
#define TRIANGULO_H

#include"areapoligono.h"
#include<iostream>

using namespace std;

class Triangulo : public AreaPoligono
{
private:
    double base;
    double altura;
public:
    Triangulo(double base, double altura);

    double getArea();

    ~Triangulo();
};

#endif // TRIANGULO_H
