#include "Central.h"

void Central::controlRefinerias()
{
    string opcion;
    while (true)
    {
        mostrarRefinerias();
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
            Refineria nueva("",0,0,"", "", "");
            nueva.pedirDatos();
            nueva.guardarDatos();
            refinerias.push(nueva);
            continue;
        }
        else if(atoi(opcion.c_str()) > refinerias.size())
        {
            system("clear");
            cout << "Estacion no existe ingrese de nuevo" << endl;
            continue;
        }
        system("clear");
        seleccionarEstacion(atoi(opcion.c_str()));
        
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
        cout << i << endl << refinerias.front().obtenerDatos();
        cin.get();
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
