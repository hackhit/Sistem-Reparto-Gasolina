#ifndef Central_h
#define Central_h

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

    //Supongamos que la central tiene que sobrevivir por 7 dias
    float diasFuncionando;
    float diasHastaProximaEntrega;
    float litrosPlaneadosADistribuir = 0;
    bool calculoHecho = false;
    float litrosCalculo = 0;
    float litrosActuales = 0;
public:
    Central(/* args */);
    ~Central();

    void menu();
    void funciones(int);
    void planeamiento();
    //Prototipos de funcion a utilizar para el planteamiento
    float litrosEnRefineria();
    void cambiarDiaProximaEntrega(); 
    float litrosRecomendadosPorDia();

    //TODO deberia pensar en una clase para esto ser repite mucho y no me gusta que se repita
    void inicializarCisternas();
    void mostrarCisternas();

    void controlRefinerias();
    void inicializarRefinerias();
    void mostrarRefinerias();
    void seleccionarRefineria(int);

    void controlGasolineras();
    void inicializarEstaciones();
    void mostrarEstaciones();
    void seleccionarEstacion(int);    
};

Central::Central(/* args */)
{
    inicializarCisternas();
    inicializarRefinerias();
    inicializarEstaciones();
}

Central::~Central()
{
}

void Central::menu()
{
    bool salir = false;
    while (!salir)
    {
        float opcion;
        cout << "Sitema para distribucion y manejo de la gasolina para ciudad Guayana" << endl;
        cout << "1. Planear distribucion del dia" << endl;   
        cout << "2. Revisar estado de las cisteranas" << endl;
        cout << "3. Revisar estado de las gasolineras" << endl;      
        cout << "4. Controlar Refineria" << endl;  
        cout << "5. Revisar si hay algun trafico ilegal" << endl;
        cout << "6. Controlar gasolineras" << endl;
        cout << "7. Controlar cisternas" << endl;
        cout << "8. Agregar estaciones/refinerias/cinternas" << endl;
        cout << "9. Salir" << endl;
        cout << "Ingrese opcion: ";
        cin >> opcion;

        system("clear");
        funciones(opcion);
    }
}

void Central::funciones(int opcion)
{
    char confirmar;

    switch (opcion)
    {
    case 1:
        planeamiento();
        
        break;
    case 4: 
        controlRefinerias();
        break;
    case 6:
        controlGasolineras();
        break;
    case 9:
        cout << "Estas seguro que desea salir (Y / N)" << endl;
        cin >> confirmar;

        if (confirmar == 'y' || confirmar == 'Y')
        {
            exit(1);
        }
        break;
    case 10:
        //TODO: aca ira funcion caos ya que eso es lo que agregan los militares
        cout << "Bienvenido senior militar ya que conozco como funciona simplmente robara y no guardara datos de que robo" << endl;
    default:
        cout << "Opcion invalidad ingrese de nuevo" << endl << endl;
        break;
    }
}

void Central::planeamiento()
{
    int opcion;
    bool salir = false;
    do    
    {
        cout << "Se disponen de " << litrosEnRefineria() << " litros en las refinerias" << endl;
        cout << "Los cuales deberan durar " << diasHastaProximaEntrega << " dias hasta la proxima entrega de gasolina" << endl;
        cout << "Se recomienda que se entrenguen " << litrosRecomendadosPorDia () << " litros por dia, para repartir entre las estaciones afiliadas" <<  endl;

        cout << "Acciones:" << endl;
        cout << "1. Proceder con la recomendacion," << endl;
        cout << "2. Ingresar una cantidad manual (\"Puede provocar falta de suministro\") " << endl;
        cout << "3. Salir planificacion" << endl;
        cout << "Ingrese la opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 3:
            salir = true;
            break;
        
        default:
            cout << "Ingrese Una opcion valida";
            system("clear");
            break;
        }
    }
    while (!salir);
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

void Central::cambiarDiaProximaEntrega()
{
    
}

float Central::litrosRecomendadosPorDia()
{
    
}

#include "ManejoArchivosCentral.hpp"
#include "controlGasolineras.hpp"
#include "controlRefineria.hpp"
#endif