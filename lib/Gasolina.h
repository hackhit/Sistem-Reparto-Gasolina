#ifndef Gasolina_h
#define Gasolina_h

#include <iostream>
using namespace std;

class Gasolina
{
private:
    float litros;
public:
    Gasolina(float);
    ~Gasolina();

    void establecerLitros(float);

    void aumentarLitros(float);
    void reducirLitros(float);
    
    float cantidadLitrosDisponible();
};

Gasolina::Gasolina(float _litros = 0)
{
    establecerLitros(_litros);
}

Gasolina::~Gasolina()
{
}

void Gasolina::establecerLitros(float _litros)
{
    litros = _litros;
}

void Gasolina::aumentarLitros(float valor)
{
    litros += valor; 
}

void Gasolina::reducirLitros(float valor)
{
    litros -= valor;
}

float Gasolina::cantidadLitrosDisponible()
{
    return litros;
}
#endif
