#ifndef Cisterna_h
#define Cisterna_h

#include <iostream>
using namespace std;
#include <fstream>
#include "ClasesBases/Tanque.h"
#include "ClasesBases/Persona.h"

class Cisterna : public Tanque
{
private:
    string placa;
    Persona chofer;

public:
    Cisterna(string, float, float, string, string, string);
    ~Cisterna();

    void guardarDatos();
    string obtenerPlaca()
    {
        return placa;
    }
    string obtenerDatos();
};

Cisterna::Cisterna(string _placa, float _litros,float capacidadCisterna = 50000,  string _nombreChofer = "", string _cedulaChofer = "", string _telefonoChofer = "") : Tanque(_litros, capacidadCisterna)
{    
    chofer.establecerDatos(_nombreChofer, _cedulaChofer, _telefonoChofer);
    placa = _placa;
}

Cisterna::~Cisterna()
{
}

string Cisterna::obtenerDatos()
{
    string datosChofer = chofer.obtenerDatos();
    string Manejados = to_string(litrosManejados()) ;
    string litrosDisponibles = to_string(cantidadLitrosDisponible());
    string capacidadTanque = to_string(obtenerCapacidad());

    return "\nPlaca: " + placa + "\nCapacidad del tanque: " + capacidadTanque +  "\nLitros manejados: " + Manejados + "\nLitros restantes: " + litrosDisponibles + "\nDatos del chofer" + datosChofer;
}

void Cisterna::guardarDatos()
{
    ofstream archivo;
    //TODO cambie de crear el archivo a solo añadir informacion
    archivo.open("BaseDatos/Cisternas.txt", ios::app); //Abrimos el archivo
    //
    if (archivo.fail())
    {
        cout << "No se pudo abrir el archivo Cisternas" << endl;
        exit(1);
    }
    
    archivo << obtenerDatos();

    archivo.close();
}


#endif