#include "cSistema.h"
#include "cEquipos.h"
#include "cMesas_Anestesia.h"
#include "cRespiradores.h"
#include "cElectrograma.h"
#include "cEnums.h"
#include <iostream>
#define NDias 30

using namespace std;

void verificado(cSistema* Sistema);
ostream& operator<<(ostream& out, const cEquipos& E);

int main()//Falta algo que setee todo a los estados normales y apague las alarmas
{
    cFecha Hoy;
    Hoy.SetHoy();
    cSistema* Hospital = new cSistema(Hoy);
    cEquipos* equipo = new cMesas_Anestesia("22x23x13", Estado::Standby, Lugar::Quirofano, 100.20);
    cFecha aux = Hoy;

    //Sobrecarga operator=
    cout << aux.tm_to_string_Fecha() << endl;
    try
    {
        *Hospital + equipo;//Uso la sobrecarga
    }
    catch (exception* error)
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
    equipo = new cElectrograma("20x10x30", Estado::Standby, Lugar::Almacen, 50.20);
    *Hospital + equipo;//No deberia tirar error

    equipo = new cRespiradores("32x10x30", Estado::Standby, Lugar::Terapia_Intensiva, 102);
    *Hospital + equipo;//No deberia tirar error

    equipo = new cMesas_Anestesia("22x23x13", Estado::Standby, Lugar::Mantenimiento, 100.20);
    *Hospital + equipo;//No deberia tirar error

    equipo = new cElectrograma("20x10x30", Estado::Standby, Lugar::Quirofano, 50.20);
    *Hospital + equipo;//No deberia tirar error

    equipo = new cRespiradores("32x10x30", Estado::Standby, Lugar::Almacen, 102);
    *Hospital + equipo;//No deberia tirar error

    cout << *(cRespiradores*)equipo << endl;
    cin >> *(cRespiradores*)equipo;
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
        Hospital->Agregar_Registro();
        Hospital->RealizarMantenimiento_Pendiente();
        Hospital->RealizarMantenimiento_Preventivo();
        Hospital->TerminarDia();
        cont++;
        ++Hoy;//Cambia la fecha al dia siguiente
    } while (cont < NDias);//Solo es una referencia, podemos probarlo para X cantidad de dias



    delete Hospital;
    return 0;
}

void verificado(cSistema* Sistema)
{
    int random = FuncionRand(0, (Sistema->getListaEquipos())->getCA());
    (*(Sistema->getListaEquipos()))[random]->Verificado();
}

ostream& operator<<(ostream& out, const cEquipos& E)
{
    out << "\nDescripcion: " << E.Descripcion << "\nDimensiones: " << E.Dimenciones << " \nPeso: " << std::to_string(E.Peso) << "\n Estado: " <<
        Estados_to_string(E.Estado_Equipo) << "\nPrecio: " << std::to_string(E.Costo) << "$" << endl;
    return out;
}