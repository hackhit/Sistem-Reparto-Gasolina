#ifndef EstacionGasolina_h
#define EStacionGasolina_h

#include <iostream>
using namespace std;
#include <queue>
#include "Persona.h"
#include "Tanque.h"

class EstacionGasolina : Tanque
{
private:
    string nombre;
    Persona encargado;
    queue<string> vehiculos;

public:
    EstacionGasolina(string, float, float, string, string, string);
    ~EstacionGasolina();

    void surtirGasolina(string, float);
};

EstacionGasolina::EstacionGasolina(string _nombre, float _litros, float capacidadGasolinera = 150000, string _nombreEncargado = "", string _cedulaEncargado = "", string _telefonoEncargado = "") : Tanque(_litros, capacidadGasolinera)
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