#include <iostream>
#include<math.h>

#include"areapoligono.h"
#include"circulo.h"
#include"retangulo.h"
#include"triangulo.h"

using namespace std;

int main()
{
    Retangulo *retangulo = new Retangulo(20, 10);

    cout << "Area do Retangulo: " << retangulo->getArea() << endl;

    Circulo *circulo = new Circulo(2);

    cout << "Area do Circulo: " << circulo->getArea() << endl;

    Triangulo *triangulo = new Triangulo(30, 10);

    cout << "Area do Triangulo: " << triangulo->getArea() << endl;


    delete triangulo;
    delete retangulo;
    delete circulo;

    return 0;
}

