#ifndef EstacionGasolina_h
#define EStacionGasolina_h

#include <iostream>
using namespace std;
#include <queue>
#include "Persona.h"
#include "Tanque.h"
class EstacionGasolina : public Tanque
{
private:
    string nombre;
    Persona encargado;
    queue<string> vehiculos;

public:
    EstacionGasolina(string, float, float, string, string, string);
    ~EstacionGasolina();

    void surtirGasolina(string, float);
    void guardarDatos();
    void menu();
    void pedirDatos();
    string obtenerDatos();
};

EstacionGasolina::EstacionGasolina(string _nombre, float _litros, float capacidadGasolinera = 150000, string _nombreEncargado = "", string _cedulaEncargado = "", string _telefonoEncargado = "") : Tanque(_litros, capacidadGasolinera)
{
    nombre = _nombre;
    encargado.establecerDatos(_nombreEncargado, _cedulaEncargado, _telefonoEncargado);
}

EstacionGasolina::~EstacionGasolina()
{
}

void EstacionGasolina::surtirGasolina(string placa, float _litros)
{
    queue<string> auxiliar;
    char detenteAmigo;
    while(!vehiculos.empty())
    {
        if(vehiculos.front() == placa)
        {
            cout << "Arrestelo policia la placa " << placa <<" es una bachaquero!!!!" << endl;
            cout << "MULTAR!!! (Y / Y): ";
            cin >> detenteAmigo; 
            return;
        }

        auxiliar.push(vehiculos.front());
        vehiculos.pop();
    }
    vehiculos = auxiliar;
    vehiculos.push(placa);
    reducirLitros(_litros);

    //Sube el carro a la central para luego comprobar 
    ofstream archivo;
    //TODO cambie de crear el archivo a solo añadir informacion
    archivo.open("vehiculosSurtidos.txt", ios::app); //Abrimos el archivoCisternas
    //
    if (archivo.fail())
    {
        cout << "No se pudo abrir el archivo" << endl;
        exit(1);
    }
    
    archivo << "Placa " << placa << " Litros " << _litros << "\n";

    archivo.close();
}

string EstacionGasolina::obtenerDatos()
{
    string datosEncargado = encargado.obtenerDatos();
    string Manejados = to_string(litrosManejados()) ;
    string litrosDisponibles = to_string(cantidadLitrosDisponible());
    string capacidadTanque = to_string(obtenerCapacidad());

    return "\nNombre de estacion: " + nombre + "\nCapacidad del tanque: " + capacidadTanque + "\nLitros manejados: " + Manejados + "\nLitros restantes: " + litrosDisponibles + "\nDatos del encargado" + datosEncargado;
}

void EstacionGasolina::guardarDatos()
{
    ofstream archivo;
    //TODO cambie de crear el archivo a solo añadir informacion
    archivo.open("Estaciones.txt", ios::app); //Abrimos el archivoCisternas
    //
    if (archivo.fail())
    {
        cout << "No se pudo abrir el archivo" << endl;
        exit(1);
    }
    
    archivo << obtenerDatos();

    archivo.close();
}

void EstacionGasolina::menu()
{
    bool salir = false;
    string _placa;

    do
    {
        int opcion;
        cout << "Estacion: " << nombre << endl;
        cout << "Capacidad: " << obtenerCapacidad() << " litros" << endl;
        cout << "Actualmente posee: " << cantidadLitrosDisponible() << "litros" 
            << endl;
        cout << "1. Surtir Gasolina" << endl;
        cout << "2. Cambiar encargado" << endl;
        cout << "3. Salir Gasolinera" << endl;
        cout << "Ingrese opcion: ";
        cin >> opcion;
        system("clear");

        switch (opcion)
        {
        case 1:
            
            cout << "Ingresar la placa del carro: ";
            cin >> _placa;
            surtirGasolina(_placa, 40);
            system("clear");

            break;
        case 3:

            salir = true;
            
            break;

        default:

            cout << "Opcion no disponible ingrese otra" << endl;

            break;
        }


    } while (!salir);
    
}

void EstacionGasolina::pedirDatos()
{
    string _nombre;
    float _litros;
    float capacidadGasolinera = 150000;
    string _nombreEncargado;
    string _cedulaEncargado;
    string _telefonoEncargado;
    
    cout << "Ingrese el nombre de la Estacion: " << endl;
    getline(cin, _nombre);
    cout << "Ingrese su capacidad de gasolina: " << endl;
    cin >> capacidadGasolinera;
    cout << "Ingrese cantidad actual d gasolina: " << endl;
    cin >> _litros;
    cout << "Ingrese el nombre del encargado: " << endl;
    getline(cin, _nombreEncargado);
    cout << "Ingrese su cedula: " << endl;
    getline(cin, _cedulaEncargado);
    cout << "Ingrese el telefono: " << endl;
    getline(cin, _telefonoEncargado);

    nombre = _nombre;
    establecerCapacidad(capacidadGasolinera);
    establecerLitros(_litros);
    encargado.establecerDatos(_nombreEncargado, _cedulaEncargado, _telefonoEncargado);
}
#endif 