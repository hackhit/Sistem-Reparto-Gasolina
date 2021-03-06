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

public:
    Infraestructura(string, float, float, string, string, string);
    ~Infraestructura();

    void colocarLlave(string llave)
    {
        tipoInfraestructura = llave;
    }
    string obtenerLlave()
    {
        return tipoInfraestructura;
    }

    string optenerNombre()
    {
        return nombre;
    }
    void pedirDatos();
    
    string datosImportantes()
    {
        return  tipoInfraestructura + ": " + nombre;
    }

    void pedirDatosEncargados()
    {
        encargado.pedirDatos();
    }
    virtual string obtenerDatos();
    virtual void guardarDatos( string);
    virtual void generarInforme(float, string);
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

    return "\n" + tipoInfraestructura + ": " + nombre + "\nCapacidad del tanque: " + capacidadTanque + "\nLitros manejados: " + Manejados + "\nLitros restantes: " + litrosDisponibles + "\nDatos del encargado" + datosEncargado;
}

void Infraestructura::guardarDatos(string baseDatos)
{
    ofstream archivo;
    //TODO cambie de crear el archivo a solo añadir informacion
    archivo.open(baseDatos, ios::app); //Abrimos el archivoCisternas
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
    Se genera un informe con la cantidad de litros que se le aporto a un objetivo
*/
void Infraestructura::generarInforme(float cantidadEntregada, string datosImportantesObejtivo)
{
    ofstream archivo;
    //TODO cambie de crear el archivo a solo añadir informacion
    archivo.open("BaseDatos/Informes.txt", ios::app); //Abrimos el archivoCisternas
    //
    if (archivo.fail())
    {
        cout << "No se pudo abrir el archivo" << endl;
        exit(1);
    }
    
    archivo << "F:" + tipoInfraestructura + ": " + nombre + "\n entrego " +  to_string(cantidadEntregada) +  "\nO: " + datosImportantesObejtivo;

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
    
    cout << "Ingrese el Nombre: ";
    getline(cin, _nombre);
    cout << "Ingrese su capacidad de gasolina: ";
    cin >> capacidadTanque;
    cout << "Ingrese cantidad actual d gasolina: ";
    cin >> _litros;
    cin.ignore();
    encargado.pedirDatos();

    nombre = _nombre;
    establecerCapacidad(capacidadTanque);
    establecerLitros(_litros);
}

#endif 