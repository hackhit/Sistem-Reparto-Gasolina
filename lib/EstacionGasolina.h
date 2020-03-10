#ifndef EstacionGasolina_h
#define EStacionGasolina_h

#include <iostream>
using namespace std;
#include <stack>
#include "Persona.h"
#include "Tanque.h"

class EstacionGasolina : Tanque
{
private:
    string nombre;
    Persona encargado;
    stack<string> vehiculos;

public:
    EstacionGasolina(string, float, float, string, int, int);
    ~EstacionGasolina();

    void surtirGasolina(string, float);
};

EstacionGasolina::EstacionGasolina(string _nombre, float _litros, float capacidadGasolinera = 150000, string _nombreEncargado , int _cedulaEncargado, int _telefonoEncargado) : Tanque(_litros, capacidadGasolinera)
{
    nombre = _nombre;
    encargado.establecerDatos(_nombreEncargado, _cedulaEncargado, _telefonoEncargado);
}

EstacionGasolina::~EstacionGasolina()
{
}

void EstacionGasolina::surtirGasolina(string placa, float _litros)
{
    vehiculos.push(placa);
    descargar(_litros);
}

#endif 