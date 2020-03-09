#ifndef Cisterna_h
#define Cisterna_h

#include <iostream>
using namespace std;
#include "Gasolina.h"
#include "Persona.h"

class Cisterna
{
private:
    string placa;
    Gasolina litros;
    Persona chofer;
    float limiteGasolina = 11000;

public:
    Cisterna(string, float, string, int, int);
    ~Cisterna();

    void extraer(float);
    void recibir(float);

};

Cisterna::Cisterna(string _placa, float _litros, string _nombreChofer, int _cedulaChofer, int _telefonoChofer)
{
    placa = _placa;

    if (_litros <= limiteGasolina)
    {
        litros.aumentar(_litros);
    }
    else
    {
        litros.aumentar(limiteGasolina);
    }
    
    chofer.establecerDatos(_nombreChofer, _cedulaChofer, _telefonoChofer);
    
}

Cisterna::~Cisterna()
{
}

void Cisterna::extraer(float _litros)
{
    litros.reducir(_litros);
}

void Cisterna::recibir(float _litros)
{
    litros.aumentar(_litros);
}

#endif