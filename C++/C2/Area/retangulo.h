#ifndef RETANGULO_H
#define RETANGULO_H

#include"areapoligono.h"
#include<iostream>

using namespace std;

class Retangulo : public AreaPoligono
{
private:
    double base;
    double altura;
public:
    Retangulo(double base, double altura);

    double getArea();

    ~Retangulo();
};

#endif // RETANGULO_H

