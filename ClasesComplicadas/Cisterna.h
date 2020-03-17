#ifndef Cisterna_h
#define Cisterna_h

#include <iostream>
using namespace std;
#include "ClasesBases/Gasolina.h"
#include "ClasesBases/Persona.h"
#include "ClasesBases/Infraestructura.h"

class Cisterna : public Infraestructura
{
private:
    string baseDatos = "BaseDatos/Cisternas.txt";

public:
    Cisterna(string, float, float ,string, string, string);
    ~Cisterna();
    
    void guardarDatos()
    {
        Infraestructura::guardarDatos(baseDatos);
    }
};

Cisterna::Cisterna(string _nombre, float _litros, float capacidadTanque = 150000, string _nombreEncargado = "", string _cedulaEncargado = "", string _telefonoEncargado = "") : Infraestructura(_nombre,  _litros, capacidadTanque = 150000, _nombreEncargado ,  _cedulaEncargado , _telefonoEncargado )
{
}

Cisterna::~Cisterna()
{
}

#endif