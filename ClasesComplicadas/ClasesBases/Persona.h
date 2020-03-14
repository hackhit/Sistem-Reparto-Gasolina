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

/*
    Retorna el nombre, cedula y telefono de la persona en el siguiente formato:
    "\nNombre: " + nombre + "\nCedula: " + cedula + "\nTelefono: " + telefono;
*/
string Persona::obtenerDatos()
{
    return  "\nNombre: " + nombre + "\nCedula: " + cedula + "\nTelefono: " + telefono;
} 
/*
    No aplica porque no tengo central de trabajadores, se necesitara si hay mas tiempo para el proyecto
*/
void Persona::guardarDatos()
{
}

#endif