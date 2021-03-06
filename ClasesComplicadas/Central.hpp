#include <stdlib.h>
#include "Central.h"
 
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
        controlCisternas();
        cout << "Las cinternas no funcionan" << endl;
        system("clear");
        
        break;
    case '5':
        revisarRobos();
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
        
        break;
    default:
        cout << "Opcion invalidad ingrese de nuevo" << endl << endl;

        break;
    }
}

void Central::revisarRobos()
{
    queue <string> fuente;
    queue <float> cantidad;
    queue <string> objetivos;
    
    string variable;
    string _nombre, _litros, _nombreObjetivo;
    
    ifstream archivo;
    archivo.open("BaseDatos/Refinerias.txt", ios::in);

    if(archivo.fail())
    {
        cout << "No se pudo abrir el archivo o no existe base de datos" << endl;
        exit(1);
    }
    while (!archivo.eof())
    {
        archivo >> variable;
        if(variable == "F:")
        {
            getline(archivo, variable);
            fuente.push(variable);
        }
        if(variable == "entrego")
        {
            archivo >> variable;
            cantidad.push(atof(variable.c_str()));
        }
        if(variable == "O:")
        {
            getline(archivo, variable);
            objetivos.push(variable);
        }
    }
    
    archivo.close();

    cout << "Se perdieron"; 
}