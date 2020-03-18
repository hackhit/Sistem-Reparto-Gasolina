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

    string obtenerDatos()
    {
        return Infraestructura::obtenerDatos();
    }
    void menu();
};

Cisterna::Cisterna(string _nombre, float _litros, float capacidadTanque = 150000, string _nombreEncargado = "", string _cedulaEncargado = "", string _telefonoEncargado = "") : Infraestructura(_nombre,  _litros, capacidadTanque = 150000, _nombreEncargado ,  _cedulaEncargado , _telefonoEncargado )
{
    colocarLlave("Cisterna");
}

Cisterna::~Cisterna()
{
}

void Cisterna::menu()
{
bool salir = false;
    char opcion;
    do
    { 
        cout << obtenerDatos();
        cout << endl << endl;
        cout << "Indique la accion a realizar" << endl;
        cout << "1. Cambiar Encargado" << endl;
        cout << "2. Salir Refineria" << endl;
        cout << "Ingrese opcion: ";
        cin >> opcion;
        cin.ignore();
        system("clear");

        switch (opcion)
        {
        case '1':
            cout << "Cambiar encargado" << endl;
            pedirDatosEncargados();

            break;
        case '2':
            salir = true;
            
            break;

        default:
            cout << "Opcion no disponible ingrese otra" << endl;
            break;
        }

    } while (!salir);
}
#endif