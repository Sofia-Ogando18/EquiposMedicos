#include "cSistema.h"
#include "cEquipos.h"
#include "cMesas_Anestesia.h"
#include "cRespiradores.h"
#include "cElectrograma.h"
#include "cEnums.h"
#include <iostream>

using namespace std;

int main()//¿Declarar un enum con los lugares posibles?
{
    cFecha* fecha = new cFecha();
    cFecha Hoy = *fecha;
    cSistema* Hospital = new cSistema(Hoy);
    cEquipos* equipo = new cMesas_Anestesia("22x23x13", Estado::Standby, "no se", 100.20);//Podriamos crear un struct para las dimensiones

    try
    {
        Hospital + equipo;//Uso la sobrecarga
    }
    catch(exception* error)
    {
        cout << error->what() << endl;
        delete error;
    }
    try
    {
        Hospital + equipo;//Intento provocar un error para comprobar la excepcion
    }
    catch (exception* error)
    {
        cout << error->what() << endl;
        delete error;
    }
    try
    {
        Hospital + NULL;//Verifico que controle excepciones
    }
    catch (exception* error)
    {
        cout << error->what() << endl;
        delete error;
    }
    equipo = new cElectrograma("20x10x30", Estado::Standby, "Algun lugar", 50.20);
    Hospital + equipo;//No deberia tirar error
    equipo = new cRespiradores("32x10x30", Estado::Standby, "Lugar actual", 102, 10);
    Hospital + equipo;//No deberia tirar error

    equipo = new cMesas_Anestesia("22x23x13", Estado::Standby, "no se", 100.20);
    Hospital + equipo;//No deberia tirar error
    equipo = new cElectrograma("20x10x30", Estado::Standby, "Algun lugar", 50.20);
    Hospital + equipo;//No deberia tirar error
    equipo = new cRespiradores("32x10x30", Estado::Standby, "Lugar actual", 102, 10);
    Hospital + equipo;//No deberia tirar error
    //Agrego 2 equipos de cada clase
     
    unsigned int cont = 0;
    int mes = Hoy.getMes();//Para tener el mes de referencia
    do
    {
        Hospital->IniciarDia(Hoy);
        if (mes != Hoy.getMes())
        {
            verificado();//Funcion que verifica los equipos
            mes = Hoy.getMes();
        }
        Hospital->TerminarDia();
        Hoy.Cambio_Fecha();//Cambia la fecha al dia siguiente
    } while (cont < 365);

    
    //Crear un metodo en equipo que cree una lista de fechas para mantenimiento
    //¿Como iniciar las listas de fechas? ¿Hacer un método agregar o asignarle de a uno?
    return 0;
}

