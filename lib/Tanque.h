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
};

Tanque::Tanque(float litros = 0, float _capacidad = 50000) : Gasolina(litros)
{
    capacidad = _capacidad;
    aumentarLitrosTotales(litros);
}

Tanque::~Tanque()
{
}

float Tanque::cargar(float cantidadACargar)
{
    float sobrante = 0;
    //Si el tanque esta lleno regresar cuanto sobro y establecer la cantida de litros en el tanque en la capacidad del propio
    bool tanqueLleno = (cantidadACargar + cantidadLitrosDisponible()) > capacidad;
    if (tanqueLleno)
    {
        establecerLitros(capacidad);
        aumentarLitrosTotales(cantidadACargar);
        sobrante = cantidadACargar -  capacidad - cantidadLitrosDisponible();
        return sobrante;
    }
    
    aumentarLitrosTotales(cantidadACargar);
    aumentarLitros(cantidadACargar);
    return sobrante;
}

float Tanque::descargar(float cantidadADescargar)
{
    float cantidadExtraida;
    //Revisa si puede extraer la cantidad pedida
    bool puedeExtraerLaCantidad = cantidadADescargar - cantidadLitrosDisponible() > 0;
    if (puedeExtraerLaCantidad)
    {
        reducirLitros(cantidadADescargar);
        return cantidadExtraida;
    }
    //Si no puede nada mas extrae la posible
    else
    {
        float cantidadExtraida = cantidadLitrosDisponible() - cantidadADescargar;
        establecerLitros(0);
        return cantidadExtraida;
    }
}

void Tanque::aumentarLitrosTotales(float cantidad)
{
    litrosTotales += cantidad;
}

float Tanque::litrosManejados()
{
    return litrosTotales;
}
#endif