#ifndef CIRCULO_H
#define CIRCULO_H

#include<iostream>
#include<math.h>
#include"areapoligono.h"

using namespace std;

class Circulo : public AreaPoligono
{
private:
    double radianos;
public:
    Circulo(double radianos);

    double getArea();

    ~Circulo();
};

#endif // CIRCULO_H
