#ifndef Refineria_h
#define Refineria_h

#include <iostream>
using namespace std;
#include "ClasesBases/Gasolina.h"
#include "ClasesBases/Persona.h"
#include "ClasesBases/Infraestructura.h"

class Refineria : public Infraestructura
{
private:
    string baseDatos = "BaseDatos/Refinerias.txt";

public:
    Refineria(string, float, float ,string, string, string);
    ~Refineria();

    void guardarDatos()
    {
        Infraestructura::guardarDatos(baseDatos);
    }

    string obtenerDatos()
    {
        return Infraestructura::obtenerDatos();
    }

    void producirGasolina(float);
    void menu();
};
/*
Suponemos que cuando creamos la refineria tiene capacidad infinita pues porque queremos
*/
Refineria::Refineria(string _nombre, float _litros, float capacidadTanque = 150000, string _nombreEncargado = "", string _cedulaEncargado = "", string _telefonoEncargado = "") : Infraestructura(_nombre,  _litros, capacidadTanque = 150000, _nombreEncargado ,  _cedulaEncargado , _telefonoEncargado )
{
    colocarLlave("Refineria");
}

Refineria::~Refineria()
{
}
/*
    Aumenta la cantidad de gasolina que se dispone en la refineria
    si se le ingresa 0 como valor se ingresa el valor manulmente
    aumentarLitros(_litros);
    aumentarLitrosTotales(_litros);
*/
void Refineria::producirGasolina(float _litros)
{
    
    if( _litros == 0)
    {
        cout << "Ingrese la cantidad que se ingreso/producio: ";
        cin >> _litros;
        cin.ignore();
    }

    aumentarLitrosTotales(cargar(_litros));
}

void Refineria::menu()
{
    bool salir = false;
    char opcion;
    do
    { 
        cout << obtenerDatos();
        cout << endl << endl;
        cout << "Indique la accion a realizar" << endl;
        cout << "1. Producir Gasolina" << endl;
        cout << "2. Cambiar Encargado" << endl;
        cout << "3. Salir Refineria" << endl;
        cout << "Ingrese opcion: ";
        cin >> opcion;
        cin.ignore();
        system("clear");

        switch (opcion)
        {
        case '1':
            producirGasolina(0);
            system("clear");

            break;
        case '2':
            cout << "Cambiar encargado" << endl;
            pedirDatosEncargados();

            break;
        case '3':
            salir = true;
            
            break;

        default:
            cout << "Opcion no disponible ingrese otra" << endl;
            break;
        }

    } while (!salir);
}

#endif