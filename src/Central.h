#include "Cisterna.h"
#include "Refineria.h"
#include "EstacionGasolina.h"
#include <queue>
#include <stdlib.h>

class Central
{
private:
    queue<Cisterna> cisternas;
    queue<Refineria> refinerias;
    queue<EstacionGasolina> estaciones;
    
public:
    Central(/* args */);
    ~Central();

    void inicializarCisternas();
    void mostrarCisternas();
};

Central::Central(/* args */)
{
    inicializarCisternas();
}

Central::~Central()
{
}

void Central::inicializarCisternas()
{
    string variable;
    
    string _placa, _litros, _litrosTotales, _nombre, _cedula, _telefono;
    
    ifstream archivoCisternas;
    archivoCisternas.open("Cisternas.txt", ios::in);

    if(archivoCisternas.fail())
    {
        cout << "No se pudo abrir el archivo o no existe base de datos" << endl;
        exit(1);
    }

    while (!archivoCisternas.eof())
    {
        archivoCisternas >> variable;
        
        cout << variable << endl;

        if(variable == "Placa:")
        {
            archivoCisternas >> _placa;
        }
        else if(variable == "manejados:")
        {
            archivoCisternas >> _litrosTotales;
        }
        else if(variable == "restantes:")
        {
            archivoCisternas >> _litros;
        }
        else if(variable == "Nombre:")
        {
            archivoCisternas >> _nombre;
        }
        else if(variable == "Cedula:")
        {
            archivoCisternas >> _cedula;
        }
        else if(variable == "Telefono:")
        {
            archivoCisternas >> _telefono;
            float litros = ::atof(_litros.c_str());
            float litrosTotales = ::atof(_litrosTotales.c_str());
            Cisterna nueva(_placa, litros, litrosTotales, _nombre, _cedula, _telefono);
            cisternas.push(nueva);
            
        }
        
    }
    //cout << _placa << _litros << _litrosTotales << _nombre << _cedula << _telefono;
    archivoCisternas.close();
}

void Central::mostrarCisternas()
{
    queue<Cisterna> auxiliar;
    
    while (!cisternas.empty())
    {
        cout << cisternas.size();
        Cisterna cisterna = cisternas.front();
        cout << cisterna.obtenerDatos();
        auxiliar.push(cisternas.front());
        cisternas.pop();
    }
    
    cisternas = auxiliar;
    
}