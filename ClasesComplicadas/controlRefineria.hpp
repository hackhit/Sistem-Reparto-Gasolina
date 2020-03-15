#include "Central.h"

void Central::controlRefinerias()
{
    int opcion = 1;
    while (true)
    {
        cout << "Lista de refinerias, escoja cual desea supervisar" << endl << endl;
        mostrarRefinerias();
        cout << endl << "Ingrese (0) para salir" << endl;
        cout << "Ingrese numero refineria: ";
        cin >> opcion;

        if (opcion == 0)
        {
            system("clear");
            break;
        }
        else if(opcion > refinerias.size())
        {
            system("clear");
            cout << "Refineria no existe ingrese de nuevo" << endl;
            continue;
        }
        system("clear");
        seleccionarRefineria(opcion);
        refinerias.front().menu();
        system("clear");
    }
    
}

void Central::mostrarRefinerias()
{
    queue<Refineria> auxiliar;
    int posicion = 1;
    do 
    {
        cout << "Refineria " << posicion << ".";
        cout << refinerias.front().obtenerDatos() << endl;
        auxiliar.push(refinerias.front());
        refinerias.pop();
        posicion++;
    }
    while (!refinerias.empty());

    refinerias = auxiliar;
}

void Central::seleccionarRefineria(int opcion)
{
    queue<Refineria> auxiliar;

    for (int i = 1; i < opcion + 1; i++)
    {
        if (opcion == i)
        {
            break;
        }

        auxiliar.push(refinerias.front());
        refinerias.pop();
    }
    
    while (!auxiliar.empty())
    {
        refinerias.push(auxiliar.front());
        auxiliar.pop();
    }
    
}

float Central::litrosEnRefineria()
{
    litrosActuales = 0;
    queue<Refineria> auxiliar;
    while (!refinerias.empty())
    {
        litrosActuales += refinerias.front().cantidadLitrosDisponible();
        auxiliar.push(refinerias.front());
        refinerias.pop();
    }   

    refinerias = auxiliar;

    return litrosActuales;
}
