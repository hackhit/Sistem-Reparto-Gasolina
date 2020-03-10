#ifndef Refineria_h
#define Refineria_h

#include <iostream>
using namespace std;
#include "Gasolina.h"
#include "Persona.h"
#include "Tanque.h"

class Refineria : public Tanque
{
private:
    string nombre;
    Persona encargado;

public:
    Refineria(string, float, float ,string, string, string);
    ~Refineria();

    void producirGasolina(float);
};
/*
Suponemos que cuando creamos la refineria tiene capacidad infinita pues porque queremos
*/
Refineria::Refineria(string _nombreRefineria, float _litros, float capacidad = 10000000000, string _nombreEncargado = "", string _cedulaEncargado = "", string _telefonoEncargado = "") : Tanque(_litros, capacidad)
{
    nombre = _nombreRefineria;
    encargado.establecerDatos(_nombreEncargado, _cedulaEncargado, _telefonoEncargado);
}

Refineria::~Refineria()
{
}

void Refineria::producirGasolina(float _litros)
{
    aumentarLitros(_litros);
    aumentarLitrosTotales(_litros);
}


#endif