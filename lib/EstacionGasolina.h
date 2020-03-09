#ifndef EstacionGasolina_h
#define EStacionGasolina_h

#include <iostream>
using namespace std;
#include <stack>
#include "Gasolina.h"
#include "Persona.h"
#include "Cisterna.h"

class EstacionGasolina
{
private:
    string nombre;
    Gasolina litros;
    float limiteGasolina = 110000;
    Persona encargado;
    stack<string> vehiculos;

public:
    EstacionGasolina(string, float, string, int, int);
    ~EstacionGasolina();

    void surtirGasolina(string, float);
    void llenarGasolinera(Cisterna& ,float);
};

EstacionGasolina::EstacionGasolina(string _nombre, float _litros, string _nombreEncargado , int _cedulaEncargado, int _telefonoEncargado)
{
    nombre = _nombre;
    litros.establecer(_litros, limiteGasolina);
    encargado.establecerDatos(_nombreEncargado, _cedulaEncargado, _telefonoEncargado);
}

EstacionGasolina::~EstacionGasolina()
{
}

void EstacionGasolina::surtirGasolina(string placa, float _litros)
{
    vehiculos.push(placa);
    litros.reducir(_litros);
}

void EstacionGasolina::llenarGasolinera(Cisterna &cisterna, float _litros)
{
    cisterna.extraer(_litros);
    litros.aumentar(_litros);
}

#endif 