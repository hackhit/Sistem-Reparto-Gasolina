#ifndef Gasolina_h
#define Gasolina_h

#include "iostream"

class Gasolina
{
private:
    float litros;
    float limiteGasolina = 100000000000000; //Si no lo definimos decimos que tiene capacidad infinita 
public:
    Gasolina(float);
    ~Gasolina();

    void establecer(float, float);

    float aumentar(float);
    void reducir(float);
    
    float cantidads();
};

Gasolina::Gasolina(float _litros = 0)
{
    litros = _litros;
}

Gasolina::~Gasolina()
{
}

void Gasolina::establecer(float _litros, float _limteGasolina)
{
    litros = _litros;
    limiteGasolina = _limteGasolina;
}

float Gasolina::aumentar(float valor)
{
    float sobrando = 0;

    bool estaSobreElLimite = (valor + litros) > limiteGasolina;
    if(estaSobreElLimite)
    {
        litros = limiteGasolina;
        sobrando = valor + litros - limiteGasolina;
    } 
    else
    {
        litros += valor; 
    }
    
    return sobrando;
}

void Gasolina::reducir(float valor)
{
    litros -= valor;
    if (litros < 0)
    {
        std::cout << "Se gasto mas gasolina de la que disponia" << endl;
        litros = 0;
    }
    
}

#endif