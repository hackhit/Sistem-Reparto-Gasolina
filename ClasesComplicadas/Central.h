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
    float diasFuncionandoSinEntrega = 0;
    float diasHastaProximaEntrega = 7;
    float litrosPlaneadosADistribuir = 0;
    bool calculoHecho = false;
    float litrosCalculo = 0;
    float litrosActuales = 0;
public:
    Central(/* args */);
    ~Central();

    void menu();
    void funciones(char);
    void planeamiento();
    //Prototipos de funcion a utilizar para el planteamiento
    float litrosEnRefineria();
    void cambiarDiaProximaEntrega(); 
    float litrosRecomendadosPorDia();
    void realizarPlaneamiento(float);
    //TODO deberia pensar en una clase para esto ser repite mucho y no me gusta que se repita
    void inicializarCisternas();
    void mostrarCisternas();
    void seleccionarCisterna(int);
    void controlCisternas();

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
        char opcion;

        cout << "Sitema para distribucion y manejo de la gasolina para ciudad Guayana" << endl;
        cout << "1. Planear distribucion del dia" << endl;   
        cout << "2. Controlar gasolineras" << endl;   
        cout << "3. Controlar Refineria" << endl;   
        cout << "4. Controlar cisternas" << endl;
        cout << "5. Revisar si hay algun trafico ilegal" << endl;
        cout << "6. Agregar estaciones/refinerias/cinternas" << endl;
        cout << "0. Salir" << endl;
        cout << "Ingrese opcion: ";
        cin >> opcion;

        system("clear");
        funciones(opcion);
    }
}

void Central::funciones(char opcion)
{
    char confirmar;

    switch (opcion)
    {
    case '1':
        planeamiento();
        
        break;
    case '2':
        controlGasolineras();
        break;

    case '3': 
        
        controlRefinerias();
        break;

    case '4': 
        //! Cisternas no funcionan la reparo luego
        //controlCisternas();
        cout << "Las cinternas no funcionan" << endl;
        system("clear");
        break;
    case '0':
        cout << "Estas seguro que desea salir (Y / N)" << endl;
        cin >> confirmar;

        if (confirmar == 'y' || confirmar == 'Y')
        {
            exit(1);
        }
        break;
    case 'R': //! R de robar
        //TODO: aca ira funcion caos ya que eso es lo que agregan los militares
        cout << "Bienvenido senior militar ya que conozco como funciona simplmente robara y no guardara datos de que robo" << endl;
    default:
        cout << "Opcion invalidad ingrese de nuevo" << endl << endl;
        break;
    }
}

void Central::cambiarDiaProximaEntrega()
{
    
}

#include "ManejoArchivosCentral.hpp"
#include "controlGasolineras.hpp"
#include "controlRefineria.hpp"
#include "controlCisterna.hpp"
#include "planeamiento.hpp"
#endif