#ifndef controlCisterna_h
#define controlCisterna_h

#include "Central.h"

void Central::controlCisternas()
{
    string opcion;
    bool salir = false;
    while (!salir)
    {
        mostrarCisternas();
        cout << endl << "0. para salir";
        cout << endl << "A. para agregar una nueva refineria";
        cout << endl << "Lista de cisternas, escoja cual desea supervisar: " ;
        cin >> opcion;
        cin.ignore();

        if (opcion == "0")
        {
            system("clear");
            break;
        }
        else if (opcion == "a" || opcion == "A")
        {
            //Agregar nueva estacion
            Cisterna nueva("",0,0,"", "", "");
            nueva.pedirDatos();
            nueva.guardarDatos();
            cisternas.push(nueva);
            continue;
        }
        else if( atoi(opcion.c_str()) > cisternas.size())
        {
            system("clear");
            cout << "Cisterna no existe ingrese de nuevo" << endl;
            continue;
        }
        system("clear");
        seleccionarCisterna(atoi(opcion.c_str()));
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