#ifndef Cisterna_h
#define Cisterna_h

#include <iostream>
using namespace std;
#include "Tanque.h"
#include "Persona.h"

class Cisterna : public Tanque
{
private:
    string placa;
    Persona chofer;

public:
    Cisterna(string, float, float, string, int, int);
    ~Cisterna();

};

Cisterna::Cisterna(string _placa, float _litros,float capacidadCisterna = 50000,  string _nombreChofer, int _cedulaChofer, int _telefonoChofer) : Tanque(_litros, capacidadCisterna)
{    
    chofer.establecerDatos(_nombreChofer, _cedulaChofer, _telefonoChofer);
    
}

Cisterna::~Cisterna()
{
}

#endif