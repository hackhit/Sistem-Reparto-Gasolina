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
        system("clear");
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
            break;

        case '3':
            cambiarDiaProximaEntrega();
            system("clear");
            break;
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
    float totalAExtraer = estaciones.size() * valor;

    queue<EstacionGasolina> auxiliarEstaciones;
    queue<Refineria> auxiliaresRefinerias;
    queue<Cisterna> auxiliaresCisternas;

    diasFuncionandoSinEntrega++;
    diasHastaProximaEntrega--;

    if (valor == 0)
    {
        cout << "Ingrese cantidad a distribuir: ";
        cin >> cantidadAdistribuir;
        system("clear");
    }
    else if (valor > 0)
    {
        
    }
    
    float extraidoRefineria = 0;
    float exceso = 0;
    while (!refinerias.empty())
    {
        extraidoRefineria = refinerias.front().descargar(cantidadAdistribuir);
        //Pasamos a la siguiente cisterna
       if (refinerias.front().cantidadLitrosDisponible() == 0)
       {
           //Pasar a siguiente cisterna
           auxiliaresRefinerias.push(refinerias.front());
           refinerias.pop(); 
       }   

       if(extraidoRefineria >= cantidadAdistribuir)
       {
            exceso += cisternas.front().cargar(cantidadAdistribuir);
            extraidoRefineria -= cantidadAdistribuir + exceso;
            refinerias.front().generarInforme(cantidadAdistribuir, cisternas.front().datosImportantes());
            //Pasar a siguiente Estacion
            auxiliaresCisternas.push(cisternas.front());
            //cout << estaciones.front().obtenerDatos();
            cisternas.pop(); 
            if (cisternas.empty())
            {
                break;
            }
       }
       //Pregunta si falta llenar alguna estacion y queda algun exceso
    }
    
    while (!auxiliaresCisternas.empty())
    {
        cisternas.push(auxiliaresCisternas.front());
        auxiliaresCisternas.pop();
    }
    // Distribuir gasolina
    float extraidoCisterna;
    while (!cisternas.empty())
    {
        extraidoCisterna = cisternas.front().descargar(cantidadAdistribuir);
        //Pasamos a la siguiente cisterna
       if (cisternas.front().cantidadLitrosDisponible() == 0)
       {
           //Pasar a siguiente cisterna
           auxiliaresCisternas.push(cisternas.front());
           cisternas.pop(); 
       }   

       if(extraidoCisterna >= cantidadAdistribuir)
       {
            exceso += estaciones.front().cargar(cantidadAdistribuir);
            extraidoCisterna -= cantidadAdistribuir + exceso;
            cisternas.front().generarInforme(cantidadAdistribuir, estaciones.front().datosImportantes());
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
    while (!auxiliaresCisternas.empty())
    {
        cisternas.push(auxiliaresCisternas.front());
        cisternas.front().establecerLitros(0);
        auxiliaresCisternas.pop();
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