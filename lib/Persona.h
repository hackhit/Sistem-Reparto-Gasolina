#ifndef Personas_h
#define Personas_h

#include <iostream>
using namespace std;

class Persona
{
private:
    string nombre;
    int cedula;
    int telefono;
public:
    Persona();
    ~Persona();

    void establecerDatos(string, int, int);
    void obtenerDatos();
    void guardarDatos();
};

Persona::Persona()
{
   
}

Persona::~Persona()
{
}

void Persona::establecerDatos(string _nombre, int _cedula, int _telefono)
{
    nombre = _nombre;
    cedula = _cedula;
    telefono = _telefono;
}

void Persona::obtenerDatos()
{
    cout << "Nombre: " << nombre << endl;
    cout << "Nombre: " << cedula << endl;
    cout << "Nombre: " << telefono << endl;
}

void Persona::guardarDatos()
{
}

#endif