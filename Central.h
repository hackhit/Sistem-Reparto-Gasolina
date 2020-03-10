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

    float litrosPlaneadosADistribuir;
    
public:
    Central(/* args */);
    ~Central();

    void menu();
    void funciones(int);

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
        cout << "Aca va el titulo del menu uwu (y si tengo que ordenar mejor mi consola luego me pongo)" << endl;
        cout << "1. Controlar Refineria" << endl;
        cout << "2. Revisar estado de las cisteranas" << endl;
        cout << "3. Revisar estado de las gasolineras" << endl;
        cout << "4. Planear distribucion del dia" << endl;      
        cout << "5. Revisar si hay algun trafico ilegal" << endl;
        cout << "6. Controlar gasolineras" << endl;
        cout << "7. Controlar cisternas" << endl;
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

    default:
        cout << "Opcion invalidad ingrese de nuevo" << endl << endl;
        break;
    }
}

#include "ManejoArchivosCentral.hpp"
#include "controlGasolineras.hpp"
#include "controlRefineria.hpp"
#endif