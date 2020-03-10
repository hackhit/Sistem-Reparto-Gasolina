#include "Central.h"

void Central::controlGasolineras()
{
    int opcion;
    while (true)
    {
        cout << "Lista de gasolineras, escoja cual desea supervisar" << endl;
        mostrarEstaciones();
        cin >> opcion;
        system("clear");
        seleccionarEstacion(opcion);
        estaciones.front().menu();
    }
    
}
void Central::seleccionarEstacion(int opcion)
{
    queue<EstacionGasolina> auxiliar;

    for (int i = 1; i < opcion + 1; i++)
    {
       if (opcion == i)
       {
           break;
       }

       auxiliar.push(estaciones.front());
       estaciones.pop();
    }
    
    while (!auxiliar.empty())
    {
        estaciones.push(auxiliar.front());
        auxiliar.pop();
    }
    
}

void Central::mostrarEstaciones()
{
    queue<EstacionGasolina> auxiliar;
    
    while (!estaciones.empty())
    {
        cout << "Estacion " << estaciones.size() << ".";
        cout << estaciones.front().obtenerDatos();
        auxiliar.push(estaciones.front());
        cout << endl;
        estaciones.pop();
    }
    
    estaciones = auxiliar;
}
