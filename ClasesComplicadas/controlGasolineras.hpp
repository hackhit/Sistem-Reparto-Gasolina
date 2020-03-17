#include "Central.h"

void Central::controlGasolineras()
{
    string opcion;
    while (true)
    {
        mostrarEstaciones();
        cout << endl << "0. para salir";
        cout << endl << "A. para agregar una nueva refineria";
        cout << endl << "Lista de refinerias, escoja cual desea supervisar: " ;
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
            EstacionGasolina nueva("",0,0,"", "", "");
            nueva.pedirDatos();
            nueva.guardarDatos();
            estaciones.push(nueva);
            continue;
        }
        else if(atoi(opcion.c_str()) > estaciones.size())
        {
            system("clear");
            cout << "Estacion no existe ingrese de nuevo" << endl;
            continue;
        }
        system("clear");
        seleccionarEstacion(atoi(opcion.c_str()));
        
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
        cout << endl << endl;
        estaciones.pop();
        posicion++;
    }
    
    estaciones = auxiliar;
}
