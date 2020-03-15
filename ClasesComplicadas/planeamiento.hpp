#ifndef planeamiento_hpp
#define planeamiento_hpp

#include "Central.h"

void Central::planeamiento()
{
    char opcion;
    bool salir = false;
    do    
    {
        cout << "Se disponen de " << litrosEnRefineria() << " litros en las refinerias" << endl;
        cout << "Los cuales deberan durar " << diasHastaProximaEntrega << " dias hasta la proxima entrega de gasolina" << endl;
        cout << "Deberan ser distribuidos en " << estaciones.size() << " estaciones" << endl;
        cout << "Se recomienda que se entrenguen " << litrosRecomendadosPorDia () << " litros a cada estaciones afiliada" <<  endl;
        cout << endl << "Acciones:" << endl;
        cout << "1. Proceder con la recomendacion," << endl;
        cout << "2. Ingresar una cantidad manual (\"Puede provocar falta de suministro\") " << endl;
        cout << "3. Cambiar dia de proxima entrega" << endl;
        cout << "0. Salir planificacion" << endl;
        cout << "Ingrese la opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case '0':
            salir = true;
            system("clear");
            break;

        case '1':
            realizarPlaneamiento(litrosRecomendadosPorDia());
            break;

        case '2':
            realizarPlaneamiento(0);
        default:
            cout << "Ingrese Una opcion valida"<< endl;
            break;
        }
    }
    while (!salir);
}

void Central::realizarPlaneamiento(float valor = 0)
{
    float cantidadAdistribuir = valor;
    float exceso = 0;
    float extraidoRefineria = 0;
    queue<EstacionGasolina> auxiliarEstaciones;
    queue<Refineria> auxiliaresRefinerias;
    queue<Cisterna> auxiliaresCisternas;

    if (valor == 0)
    {
        cout << "Ingrese cantidad a distribuir: ";
        cin >> cantidadAdistribuir;
    }
    else if (valor > 0)
    {
        
    }
    
    //TODO: Aca deberia ser las cisternas
    // Distribuir gasolina
    while (!refinerias.empty())
    {
        extraidoRefineria = refinerias.front().descargar(cantidadAdistribuir);
        //Pasamos a la siguiente refineria
       if (refinerias.front().cantidadLitrosDisponible() == 0)
       {
           //!generarInforme
           //Pasar a siguiente refineria
           auxiliaresRefinerias.push(refinerias.front());
           refinerias.pop(); 
       }   
       //cout << " extraidoRefineria " <<exceso;
       //cout << estaciones.front().obtenerDatos();
       //!Deberia llenar cisterna primero
       if(extraidoRefineria >= cantidadAdistribuir)
       {
            exceso += estaciones.front().cargar(cantidadAdistribuir);
            extraidoRefineria -= cantidadAdistribuir;
            //!generarInforme
            //Pasar a siguiente Estacion
            auxiliarEstaciones.push(estaciones.front());
            //cout << estaciones.front().obtenerDatos();
            estaciones.pop(); 
            if (estaciones.empty())
            {
                break;
            }
       }
       //Pregunta si falta llenar alguna estacion y queda algun exceso
    }

    while (!auxiliaresRefinerias.empty())
    {
        refinerias.push(auxiliaresRefinerias.front());
        auxiliaresRefinerias.pop();
    }
    while (!auxiliarEstaciones.empty())
    {
        estaciones.push(auxiliarEstaciones.front());
        auxiliarEstaciones.pop();
    }
}

/*
    Hace el calculo para que la gasolina dure lo suficiente hasta la proxima entrega
    Calculo realizado:
                litrosEnRefineria 
    ----------------------------------------------
    diasHastaProximaEntrega * cantidadDeEstaciones
*/
float Central::litrosRecomendadosPorDia()
{
    float gasolinaPorEstacion;
    if (diasHastaProximaEntrega != 0)
    {
        gasolinaPorEstacion = litrosEnRefineria() / (diasHastaProximaEntrega * estaciones.size());
        return gasolinaPorEstacion;
    }
    if (diasHastaProximaEntrega == 0)
    {
        return litrosEnRefineria();
    }
    
}

#endif