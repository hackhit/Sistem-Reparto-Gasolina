#include "Central.h"

void Central::mostrarCisternas()
{
    queue<Cisterna> auxiliar;
    
    while (!cisternas.empty())
    {

        cout << cisternas.size();
        cout << cisternas.front().obtenerDatos();
        auxiliar.push(cisternas.front());
        cisternas.pop();
    }
    
    cisternas = auxiliar;
}

void Central::mostrarRefinerias()
{
    queue<Refineria> auxiliar;
    
    while (!refinerias.empty())
    {

        cout << refinerias.size();
        cout << refinerias.front().obtenerDatos();
        auxiliar.push(refinerias.front());
        refinerias.pop();
    }
    
    refinerias = auxiliar;
}

void Central::inicializarCisternas()
{
    string variable;
    
    string _placa, _litros, _litrosTotales, _nombre, _cedula, _telefono, _capacidad;
    
    ifstream archivo;
    archivo.open("Cisternas.txt", ios::in);

    if(archivo.fail())
    {
        cout << "No se pudo abrir el archivo o no existe base de datos" << endl;
        exit(1);
    }

    while (!archivo.eof())
    {
        archivo >> variable;
        
        //cout << variable << endl;

        if(variable == "Placa:")
        {
            archivo >> _placa;
        }
        else if(variable == "tanque:")
        {
            archivo >> _capacidad;
        }
        else if(variable == "manejados:")
        {
            archivo >> _litrosTotales;
        }
        else if(variable == "restantes:")
        {
            archivo >> _litros;
        }
        else if(variable == "Nombre:")
        {
            std::getline(archivo, _nombre);
        }
        else if(variable == "Cedula:")
        {
            archivo >> _cedula;
        }
        else if(variable == "Telefono:")
        {
            archivo >> _telefono;

            float litros = ::atof(_litros.c_str());
            float litrosTotales = ::atof(_litrosTotales.c_str());
            float capcidadTanque = ::atof(_capacidad.c_str());
            Cisterna nueva(_placa, litros, capcidadTanque , _nombre, _cedula, _telefono);
            nueva.establecerLitrosTotales(litrosTotales);
            cisternas.push(nueva);
            nueva.~Cisterna();
        }
    }
    //cout << _placa << _litros << _litrosTotales << _nombre << _cedula << _telefono;
    archivo.close();
}

void Central::inicializarRefinerias()
{
    string variable;
    
    string _nombreRefineria, _litros, _litrosTotales, _nombre, _cedula, _telefono, _capacidad;
    
    ifstream archivo;
    archivo.open("Refinerias.txt", ios::in);

    if(archivo.fail())
    {
        cout << "No se pudo abrir el archivo o no existe base de datos" << endl;
        exit(1);
    }

    while (!archivo.eof())
    {
        archivo >> variable;
        
        //cout << variable << endl;

        if(variable == "refineria:")
        {
            std::getline(archivo, _nombreRefineria);
        }
        else if(variable == "tanque:")
        {
            archivo >> _capacidad;
        }
        else if(variable == "manejados:")
        {
            archivo >> _litrosTotales;
        }
        else if(variable == "restantes:")
        {
            archivo >> _litros;
        }
        else if(variable == "Nombre:")
        {
            std::getline(archivo, _nombre);
        }
        else if(variable == "Cedula:")
        {
            archivo >> _cedula;
        }
        else if(variable == "Telefono:")
        {
            archivo >> _telefono;

            float litros = ::atof(_litros.c_str());
            float litrosTotales = ::atof(_litrosTotales.c_str());
            float capcidadTanque = ::atof(_capacidad.c_str());

            Refineria nueva(_nombreRefineria, litros, capcidadTanque , _nombre, _cedula, _telefono);

            nueva.establecerLitrosTotales(litrosTotales);
            refinerias.push(nueva);
            nueva.~Refineria();
        }
    }
    //cout << _placa << _litros << _litrosTotales << _nombre << _cedula << _telefono;
    archivo.close();
}

void Central::inicializarEstaciones()
{
    string variable;
    
    string _nombreEstacion, _litros, _litrosTotales, _nombre, _cedula, _telefono, _capacidad;
    
    ifstream archivo;
    archivo.open("Estaciones.txt", ios::in);

    if(archivo.fail())
    {
        cout << "No se pudo abrir el archivo o no existe base de datos" << endl;
        exit(1);
    }

    while (!archivo.eof())
    {
        archivo >> variable;
        
        //cout << variable << endl;
        if(variable == "estacion:")
        {
            std::getline(archivo, _nombreEstacion);
        }
        else if(variable == "tanque:")
        {
            archivo >> _capacidad;
        }
        else if(variable == "manejados:")
        {
            archivo >> _litrosTotales;
        }
        else if(variable == "restantes:")
        {
            archivo >> _litros;
        }
        else if(variable == "Nombre:")
        {
            std::getline(archivo, _nombre);
        }
        else if(variable == "Cedula:")
        {
            archivo >> _cedula;
        }
        else if(variable == "Telefono:")
        {
            archivo >> _telefono;

            float litros = ::atof(_litros.c_str());
            float litrosTotales = ::atof(_litrosTotales.c_str());
            float capcidadTanque = ::atof(_capacidad.c_str());

            EstacionGasolina nueva(_nombreEstacion, litros, capcidadTanque , _nombre, _cedula, _telefono);
            nueva.establecerLitrosTotales(litrosTotales);
            estaciones.push(nueva);
        }
    }
    //cout << _placa << _litros << _litrosTotales << _nombre << _cedula << _telefono;
    archivo.close();
}