#ifndef EstacionGasolina_h
#define EStacionGasolina_h

#include <iostream>
using namespace std;
#include <queue>
#include "ClasesBases/Infraestructura.h"
class EstacionGasolina : public Infraestructura
{
private:
    string baseDatos = "BaseDatos/Estaciones.txt";
    queue<string> vehiculos;

public:
    EstacionGasolina(string, float, float, string, string, string);
    ~EstacionGasolina();

    void guardarDatos()
    {
        Infraestructura::guardarDatos(baseDatos);
    }

    string obtenerDatos()
    {
        return Infraestructura::obtenerDatos();
    }

    void surtirGasolina(string, float);
    void menu();
};

EstacionGasolina::EstacionGasolina(string _nombre, float _litros, float capacidadTanque = 150000, string _nombreEncargado = "", string _cedulaEncargado = "", string _telefonoEncargado = "") : Infraestructura(_nombre,  _litros, capacidadTanque = 150000, _nombreEncargado ,  _cedulaEncargado , _telefonoEncargado )
{
    colocarLlave("Estacion");
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
            cout << "La placa siguiente " << placa <<" ya disfruto de la distribucion de hoy, por lo que se dispondra de realizar una multa por bachaqueo" << endl;
            cout << ": ";
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
    archivo.open("BaseDatos/vehiculosSurtidos.txt", ios::app); //Abrimos el archivoCisternas
    //
    if (archivo.fail())
    {
        cout << "No se pudo abrir el archivo" << endl;
        exit(1);
    }
    
    archivo << "Placa " << placa << " Litros " << _litros << "\n";

    archivo.close();
}

void EstacionGasolina::menu()
{
    bool salir = false;
    string _placa;
    float gasolinaSurtida;
    do
    {
        char opcion;
        cout << obtenerDatos();

        cout << endl << endl;
        cout << "Indique la accion a realizar" << endl;
        cout << "1. Surtir Gasolina" << endl;
        cout << "2. Cambiar encargado" << endl;
        cout << "3. Salir Gasolinera" << endl;
        cout << "Ingrese opcion: ";
        cin >> opcion;
        cin.ignore();
        system("clear");

        switch (opcion)
        {
        case '1':
            
            cout << "Ingresar la placa del carro: ";
            getline(cin , _placa);
            cout << "Ingrese la cantidad de gasolina a surtir: ";
            cin >> gasolinaSurtida;
            cin.ignore();
            surtirGasolina(_placa, gasolinaSurtida);
            system("clear");

            break;
        case '2':
            cout << "Cambiar encargado" << endl;
            pedirDatosEncargados();
            system("clear");
            break;
        case '3':

            salir = true;
            break;

        default:
            cout << "Opcion no disponible ingrese otra" << endl;

            break;
        }

    } while (!salir);
}

#endif 