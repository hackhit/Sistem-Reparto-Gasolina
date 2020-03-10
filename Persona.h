#ifndef Personas_h
#define Personas_h

#include <iostream>
using namespace std;

class Persona
{
private:
    string nombre;
    string cedula;
    string telefono;
public:
    Persona();
    ~Persona();

    void establecerDatos(string, string, string);
    string obtenerDatos();
    void guardarDatos();
};

Persona::Persona()
{
   
}

Persona::~Persona()
{
}

void Persona::establecerDatos(string _nombre, string _cedula, string _telefono)
{
    nombre = _nombre;
    cedula = _cedula;
    telefono = _telefono;
}

string Persona::obtenerDatos()
{
    return  "\nNombre: " + nombre + "\nCedula: " + cedula + "\nTelefono: " + telefono;
} 

void Persona::guardarDatos()
{
}

#endif