#include "Central.h"

void Central::controlGasolineras()
{
    int opcion;
    while (true)
    {
        cout << "Lista de gasolineras, escoja cual desea supervisar" << endl << endl;
        mostrarEstaciones();
        cout << endl << "Ingrese (0) para salir" << endl;
        cout << "Ingrese numero estacion: ";
        cin >> opcion;
        if (opcion == 0)
        {
            system("clear");
            break;
        }
        else if(opcion > estaciones.size())
        {
            system("clear");
            cout << "Estacion no existe ingrese de nuevo" << endl;
            continue;
        }
        system("clear");
        seleccionarEstacion(opcion);
        estaciones.front().menu();
        system("clear");
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
    int posicion = 1;
    while (!estaciones.empty())
    {
        cout << "Estacion " << posicion << ".";
        cout << estaciones.front().obtenerDatos();
        auxiliar.push(estaciones.front());
        cout << endl;
        estaciones.pop();
        posicion++;
    }
    
    estaciones = auxiliar;
}
