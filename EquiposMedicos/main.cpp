#include "cSistema.h"
#include "cEquipos.h"
#include "cMesas_Anestesia.h"
#include "cRespiradores.h"
#include "cElectrograma.h"
#include "cEnums.h"
#include <iostream>
#define NDias 100

using namespace std;

void verificado(cSistema* Sistema);
void Descomponer_Random(cSistema* Hospital);

int main()//¿Declarar un enum con los lugares posibles? Si
{
    cFecha* fecha1 = new cFecha(30, 11, 2021,23,33);
    cFecha* fecha2 = new cFecha(29, 12, 2021, 21, 03);
    cFecha* fecha3 = new cFecha(28, 1, 2022, 13, 24);
    cFecha* fecha4 = new cFecha(18, 2, 2022, 15, 42);
    cFecha* fecha5 = new cFecha(20, 3, 2022, 13, 04);
    cFecha* fecha6 = new cFecha(29, 4, 2022, 18, 25);
    cFecha* fecha7 = new cFecha(19, 5, 2022, 16, 20);
    cFecha* fecha8 = new cFecha(18, 6, 2022, 22, 29);
    cFecha* fecha9= new cFecha(25, 7, 2022, 11, 55);
    cFecha* fecha10 = new cFecha(29, 8, 2022, 13, 54);
    cFecha* fecha11 = new cFecha(27, 9, 2022, 14, 13);
    cFecha* fecha12 = new cFecha(26, 10, 2022, 20, 34);
    cFecha* fecha13 = new cFecha(23, 11, 2022, 10, 06);
    cFecha* fecha14 = new cFecha(21, 12, 2022, 12, 24);
    cFecha Hoy;
    Hoy.SetHoy();
    cSistema* Hospital = new cSistema(Hoy);
    cEquipos* equipo = new cMesas_Anestesia("22x23x13", Estado::Standby, Quirofano, 100.20);
    
    *equipo + fecha1;
    *equipo + fecha2;
    *equipo + fecha3;
    *equipo + fecha4;
    *equipo + fecha5;
    *equipo + fecha6;
    *equipo + fecha7;
    *equipo + fecha8;
    *equipo + fecha9;
    *equipo + fecha10;
    *equipo + fecha11;
    *equipo + fecha12;
    *equipo + fecha13;
    *equipo + fecha14;

    try
    {
        *Hospital + equipo;//Uso la sobrecarga
    }
    catch(exception* error)
    {
        cout << error->what() << endl;
        delete error;
    }
    try
    {
        *Hospital + equipo;//Intento provocar un error para comprobar la excepcion
    }
    catch (exception* error)
    {
        cout << error->what() << endl;
        delete error;
    }
    try
    {
        *Hospital + NULL;//Verifico que controle excepciones
    }
    catch (exception* error)
    {
        cout << error->what() << endl;
        delete error;
    }
    equipo = new cElectrograma("20x10x30", Estado::Standby, Almacen, 50.20);

    *equipo + fecha1;
    *equipo + fecha2;
    *equipo + fecha3;
    *equipo + fecha4;
    *equipo + fecha5;
    *equipo + fecha6;
    *equipo + fecha7;
    *equipo + fecha8;
    *equipo + fecha9;
    *equipo + fecha10;
    *equipo + fecha11;
    *equipo + fecha12;
    *equipo + fecha13;
    *equipo + fecha14;
    

    *Hospital + equipo;//No deberia tirar error
    equipo = new cRespiradores("32x10x30", Estado::Standby, Terapia_Intensiva, 102, 10);

    *equipo + fecha1;
    *equipo + fecha2;
    *equipo + fecha3;
    *equipo + fecha4;
    *equipo + fecha5;
    *equipo + fecha6;
    *equipo + fecha7;
    *equipo + fecha8;
    *equipo + fecha9;
    *equipo + fecha10;
    *equipo + fecha11;
    *equipo + fecha12;
    *equipo + fecha13;
    *equipo + fecha14;
    

    *Hospital + equipo;//No deberia tirar error

    equipo = new cMesas_Anestesia("22x23x13", Estado::Standby, Mantenimiento, 100.20);

    *equipo + fecha1;
    *equipo + fecha2;
    *equipo + fecha3;
    *equipo + fecha4;
    *equipo + fecha5;
    *equipo + fecha6;
    *equipo + fecha7;
    *equipo + fecha8;
    *equipo + fecha9;
    *equipo + fecha10;
    *equipo + fecha11;
    *equipo + fecha12;
    *equipo + fecha13;
    *equipo + fecha14;

    *Hospital + equipo;//No deberia tirar error
    equipo = new cElectrograma("20x10x30", Estado::Standby, Quirofano, 50.20);

    *equipo + fecha1;
    *equipo + fecha2;
    *equipo + fecha3;
    *equipo + fecha4;
    *equipo + fecha5;
    *equipo + fecha6;
    *equipo + fecha7;
    *equipo + fecha8;
    *equipo + fecha9;
    *equipo + fecha10;
    *equipo + fecha11;
    *equipo + fecha12;
    *equipo + fecha13;
    *equipo + fecha14;
    

    *Hospital + equipo;//No deberia tirar error
    equipo = new cRespiradores("32x10x30", Estado::Standby, Almacen, 102, 10);

    *equipo + fecha1;
    *equipo + fecha2;
    *equipo + fecha3;
    *equipo + fecha4;
    *equipo + fecha5;
    *equipo + fecha6;
    *equipo + fecha7;
    *equipo + fecha8;
    *equipo + fecha9;
    *equipo + fecha10;
    *equipo + fecha11;
    *equipo + fecha12;
    *equipo + fecha13;
    *equipo + fecha14;
    

    *Hospital + equipo;//No deberia tirar error
    //Agrego 2 equipos de cada clase
     
    unsigned int cont = 0;

    //Simulo unos dias
    int mes = Hoy.getMes();//Para tener el mes de referencia
    do
    {
        Hospital->IniciarDia(Hoy);
        
        Descomponer_Random(Hospital);
        if (mes != Hoy.getMes())//Cada vez que cambio de mes
        {
            verificado(Hospital);//Funcion que verifica un equipo al azar una vez al mes
            mes = Hoy.getMes();
        }
        Hospital->RealizarMantenimiento_Pendiente();
        Hospital->RealizarMantenimiento_Preventivo();
        Hospital->TerminarDia();
        cont++;
        Hoy.Cambio_Fecha();//Cambia la fecha al dia siguiente
    } while (cont < NDias);//Solo es una referencia, podemos probarlo para X cantidad de dias

    

    delete fecha1;//Lo pongo para probar si salta un error
    delete Hospital;
    return 0;
}

void verificado(cSistema* Sistema)
{
    int random=FuncionRand(0, (Sistema->getListaEquipos())->getCA())
    
    (*(Sistema->getListaEquipos()))[random]->Verificado();
}

void Descomponer_Random(cSistema* Hospital)
{
    for (int i = 0; i < (Sistema->getListaEquipos())->getCA(); i++)
    {
        (*(Sistema->getListaEquipos()))[i]->EncenderAlarmas();
    }

}