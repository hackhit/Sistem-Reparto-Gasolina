#ifndef Refineria_h
#define Refineria_h

#include <iostream>
using namespace std;
#include "Gasolina.h"
#include "Persona.h"
#include "Cisterna.h"

class Refineria
{
private:
    string nombre;
    Gasolina litros;
    Persona encargado;

public:
    Refineria(string, float, string, int, int);
    ~Refineria();

    void producirGasolina(float);
    float llenarCisterna(Cisterna&, float);
};

Refineria::Refineria(string _nombreRefineria, float _litros, string _nombreEncargado, int _cedulaEncargado, int _telefonoEncargado)
{
    nombre = _nombreRefineria;
    litros.aumentar(_litros);
    encargado.establecerDatos(_nombreEncargado, _cedulaEncargado, _telefonoEncargado);
}

Refineria::~Refineria()
{
}

void Refineria::producirGasolina(float _litros)
{
    litros.aumentar(_litros);
}

float Refineria::llenarCisterna(Cisterna &cisterna, float _cantidad)
{
    cisterna.recibir(_cantidad);
    litros.reducir(_cantidad);
}

#endif