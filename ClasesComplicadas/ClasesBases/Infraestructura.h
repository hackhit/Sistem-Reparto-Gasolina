#ifndef Infraestructura_h
#define Infraestructura_h

#include <iostream>
using namespace std;
#include <queue>
#include "Persona.h"
#include "Tanque.h"
#include "fstream"

class Infraestructura : public Tanque
{
private:
    string tipoInfraestructura;
    string nombre;
    Persona encargado;
    queue<string> vehiculos;

public:
    Infraestructura(string, float, float, string, string, string);
    ~Infraestructura();

    void guardarDatos();
    void pedirDatos();
    string obtenerDatos();
};

Infraestructura::Infraestructura(string _nombre, float _litros, float capacidadTanque = 150000, string _nombreEncargado = "", string _cedulaEncargado = "", string _telefonoEncargado = "") : Tanque(_litros, capacidadTanque)
{
    nombre = _nombre;
    encargado.establecerDatos(_nombreEncargado, _cedulaEncargado, _telefonoEncargado);
}

Infraestructura::~Infraestructura()
{
}

string Infraestructura::obtenerDatos()
{
    string datosEncargado = encargado.obtenerDatos();
    string Manejados = to_string(litrosManejados()) ;
    string litrosDisponibles = to_string(cantidadLitrosDisponible());
    string capacidadTanque = to_string(obtenerCapacidad());

    return "\nNombre: " + nombre + "\nCapacidad del tanque: " + capacidadTanque + "\nLitros manejados: " + Manejados + "\nLitros restantes: " + litrosDisponibles + "\nDatos del encargado" + datosEncargado;
}

void Infraestructura::guardarDatos()
{
    ofstream archivo;
    //TODO cambie de crear el archivo a solo añadir informacion
    archivo.open("Estaciones.txt", ios::app); //Abrimos el archivoCisternas
    //
    if (archivo.fail())
    {
        cout << "No se pudo abrir el archivo" << endl;
        exit(1);
    }
    
    archivo << obtenerDatos();

    archivo.close();
}
/*
    Establece las siguientes variables de la Infraestructura actual
    string _nombre;
    float _litros;
    float capacidadTanque = 150000;
    string _nombreEncargado;
    string _cedulaEncargado;
    string _telefonoEncargado;
*/
void Infraestructura::pedirDatos()
{
    string _nombre;
    float _litros;
    float capacidadTanque = 150000;
    string _nombreEncargado;
    string _cedulaEncargado;
    string _telefonoEncargado;
    
    cout << "Ingrese el nombre de la Estacion: " << endl;
    getline(cin, _nombre);
    cout << "Ingrese su capacidad de gasolina: " << endl;
    cin >> capacidadTanque;
    cout << "Ingrese cantidad actual d gasolina: " << endl;
    cin >> _litros;
    cout << "Ingrese el nombre del encargado: " << endl;
    getline(cin, _nombreEncargado);
    cout << "Ingrese su cedula: " << endl;
    getline(cin, _cedulaEncargado);
    cout << "Ingrese el telefono: " << endl;
    getline(cin, _telefonoEncargado);

    nombre = _nombre;
    establecerCapacidad(capacidadTanque);
    establecerLitros(_litros);
    encargado.establecerDatos(_nombreEncargado, _cedulaEncargado, _telefonoEncargado);
}
#endif 