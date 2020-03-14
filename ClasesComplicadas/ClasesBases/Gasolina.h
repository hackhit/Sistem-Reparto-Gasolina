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

/*
    Establece la variable litros por la cantidad ingresada
*/
void Gasolina::establecerLitros(float _litros)
{
    litros = _litros;
}

/*
    Aumenta la variable litros por la cantidad ingresada
*/
void Gasolina::aumentarLitros(float valor)
{
    litros += valor; 
}

/*
    Reduce la variable litros por la cantidad ingresada
*/
void Gasolina::reducirLitros(float valor)
{
    litros -= valor;
}

/*
    Devuelve la cantidad de gasolina disponible
*/
float Gasolina::cantidadLitrosDisponible()
{
    return litros;
}
#endif
