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


void Central::cambiarDiaProximaEntrega()
{
    cout << "Ingrese cuantos dias hata proxima entrega: ";
    cin >> diasHastaProximaEntrega;
    
    if (diasHastaProximaEntrega == 0)
    {
        diasFuncionandoSinEntrega = 0;
    }
}
#include "Central.hpp"
#include "ManejoArchivosCentral.hpp"
#include "controlGasolineras.hpp"
#include "controlRefineria.hpp"
#include "controlCisterna.hpp"
#include "planeamiento.hpp"
#endif