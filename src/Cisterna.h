#ifndef Cisterna_h
#define Cisterna_h

#include <iostream>
using namespace std;
#include <fstream>
#include "Tanque.h"
#include "Persona.h"

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
    return "\nPlaca: " + placa + "\nLitros manejados: " + Manejados + "\nLitros restantes: " + litrosDisponibles + "\nDatos del chofer" + datosChofer;
}

void Cisterna::guardarDatos()
{
    ofstream archivoCisternas;
    //TODO cambie de crear el archivo a solo añadir informacion
    archivoCisternas.open("Cisternas.txt", ios::app); //Abrimos el archivoCisternas
    //
    if (archivoCisternas.fail())
    {
        cout << "No se pudo abrir el archivo" << endl;
        exit(1);
    }
    
    archivoCisternas << obtenerDatos();

    archivoCisternas.close();
}
#endif