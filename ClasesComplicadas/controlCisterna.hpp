#ifndef controlCisterna_h
#define controlCisterna_h

#include "Central.h"

void Central::controlCisternas()
{
    int opcion;
    while (true)
    {
        cout << "Lista de cisternas, escoja cual desea supervisar" << endl << endl;
        //mostrarCisternas();
        cout << endl << "Ingrese (0) para salir" << endl;
        cout << "Ingrese numero estacion: ";
        cin >> opcion;
        if (opcion == 0)
        {
            system("clear");
            break;
        }
        else if(opcion > cisternas.size())
        {
            system("clear");
            cout << "Cisterna no existe ingrese de nuevo" << endl;
            continue;
        }
        system("clear");
        seleccionarCisterna(opcion);
        //! Esto solo esta para prueba sustituir despues
        cout << cisternas.front().obtenerDatos();
        system("clear");
    }
    
}

void Central::seleccionarCisterna(int opcion)
{
    queue<Cisterna> auxiliar;

    for (int i = 1; i < opcion + 1; i++)
    {
       if (opcion == i)
       {
           break;
       }

       auxiliar.push(cisternas.front());
       cisternas.pop();
    }
    
    while (!auxiliar.empty())
    {
        cisternas.push(auxiliar.front());
        auxiliar.pop();
    }
    
}

void Central::mostrarCisternas()
{
    queue<Cisterna> auxiliar;
    int posicion = 1;
    while (!cisternas.empty())
    {
        cout << "Cisterna " << posicion << ".";
        cout << cisternas.front().obtenerDatos();
        auxiliar.push(cisternas.front());
        cout << endl;
        cisternas.pop();
        posicion++;
    }
    
    cisternas = auxiliar;
}

#endif