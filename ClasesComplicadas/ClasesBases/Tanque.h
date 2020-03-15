#ifndef Tanque_h
#define Tanque_h

#include "Gasolina.h"

class Tanque : public Gasolina 
{
private:
    float capacidad;
    float litrosTotales = 0;
public:
    Tanque(float, float);
    ~Tanque();

    virtual float cargar(float);
    virtual float descargar(float);

    void aumentarLitrosTotales(float);
    float litrosManejados();
    float obtenerCapacidad();
    float establecerLitrosTotales(float);
    void establecerCapacidad(float);
};

Tanque::Tanque(float litros = 0, float _capacidad = 50000) : Gasolina(litros)
{
    capacidad = _capacidad;
    establecerLitrosTotales(litros);
}

Tanque::~Tanque()
{
}

/*
    Establece la capacidad del tanque, necesita la capacidad a establecer
    capacidad = _capacidad;
*/ 
void Tanque::establecerCapacidad(float _capacidad)
{
    capacidad = _capacidad;
}

/*
    Carga la cantidad de tanque, si hay un exceso de la gasolina ingresada
    la regresa para el error, aumenta los litros y los litros totales del tanque
    retorna un exceso si hay error de calculo, utiliza las siguientes funciones
    aumentarLitrosTotales(cantidadACargar)
    aumentarLitros(cantidadACargar);
*/
float Tanque::cargar(float cantidadACargar)
{
    float sobrante = 0;
    //Si el tanque esta lleno regresar cuanto sobro y establecer la cantida de litros en el tanque en la capacidad del propio
    bool tanqueLleno = (cantidadACargar + cantidadLitrosDisponible()) > capacidad;
    if (tanqueLleno)
    {
        sobrante = cantidadACargar -  capacidad - cantidadLitrosDisponible();
        //Cuanto se recargo a la gandola
        aumentarLitrosTotales(capacidad - cantidadLitrosDisponible());
        establecerLitros(capacidad);
        return sobrante;
    }
    
    aumentarLitrosTotales(cantidadACargar);
    aumentarLitros(cantidadACargar);
    return sobrante;
}

/*
    Extrae una cantidad del tanque , pregunta si la cantidad esta disponible,
    necesita que se ingrese cuantos ligros se descargaran
    regresa la cantidad extrauda
*/
float Tanque::descargar(float cantidadADescargar)
{
    float cantidadExtraida;
    //Revisa si puede extraer la cantidad pedida
    bool puedeExtraerLaCantidad = cantidadLitrosDisponible() - cantidadADescargar > 0;
    if (puedeExtraerLaCantidad)
    {
        reducirLitros(cantidadADescargar);
        return cantidadADescargar;
    }
    //Si no puede nada mas extrae la posible
    else
    {
        float cantidadExtraida = cantidadLitrosDisponible() - cantidadADescargar;
        establecerLitros(0);
        return cantidadExtraida;
    }
}

/*
    Aumenta los litros totales del tanque, se aumenta los litros totales y actuales en funciones diferenes por si se aumentan los litros totales pero los actuales simplemente se establecen, es algo raro
*/
void Tanque::aumentarLitrosTotales(float cantidad)
{
    litrosTotales += cantidad;
}
/*
    Regresa los litros totales que han pasado
    litrosTotales
*/
float Tanque::litrosManejados()
{
    return litrosTotales;
}
/*
    Regresa los capacidad del tanque
*/
float Tanque::obtenerCapacidad()
{
    return capacidad;
}
/*
    Regresa los litros totales que han pasado y establece una cantidad
*/
float Tanque::establecerLitrosTotales(float valor)
{
    litrosTotales = valor;
    return litrosTotales;
}
#endif