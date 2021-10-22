#include "cSistema.h"
#include "cEquipos.h"
#include "cMesas_Anestesia.h"
#include "cRespiradores.h"
#include "cElectrograma.h"
#include "cEnums.h"
#include <iostream>

using namespace std;

void verificado(cSistema* Sistema);

int main()//¿Declarar un enum con los lugares posibles? Si
{
    cFecha* fecha = new cFecha();
    cFecha Hoy = *fecha;
    cFecha aux = *fecha;
    cSistema* Hospital = new cSistema(Hoy);
    cEquipos* equipo = new cMesas_Anestesia("22x23x13", Estado::Standby, Quirofano, 100.20);
    
    aux.setFecha(30, 11, 2021);
    *equipo + aux;
    aux.setFecha(29, 12, 2021);
    *equipo + aux;
    aux.setFecha(28, 1, 2022);
    *equipo + aux;
    aux.setFecha(18, 2, 2022);
    *equipo + aux;
    aux.setFecha(20, 3, 2022);
    *equipo + aux;
    aux.setFecha(29, 4, 2022);
    *equipo + aux;
    aux.setFecha(19, 5, 2022);
    *equipo + aux;
    aux.setFecha(18, 6, 2022);
    *equipo + aux;
    aux.setFecha(25, 7, 2022);
    *equipo + aux;
    aux.setFecha(29, 8, 2022);
    *equipo + aux;
    aux.setFecha(27, 9, 2022);
    *equipo + aux;
    aux.setFecha(26, 10, 2022);
    *equipo + aux;
    aux.setFecha(23, 11, 2022);
    *equipo + aux;
    aux.setFecha(21, 12, 2022);
    *equipo + aux;
    //Falta enlazar con los registros. ¿Donde estan? Estan en cSistema
    //Cambiar lugares de string a un enum

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

    aux.setFecha(30, 11, 2021);
    *equipo + aux;
    aux.setFecha(29, 12, 2021);
    *equipo + aux;
    aux.setFecha(28, 1, 2022);
    *equipo + aux;
    aux.setFecha(18, 2, 2022);
    *equipo + aux;
    aux.setFecha(20, 3, 2022);
    *equipo + aux;
    aux.setFecha(29, 4, 2022);
    *equipo + aux;
    aux.setFecha(19, 5, 2022);
    *equipo + aux;
    aux.setFecha(18, 6, 2022);
    *equipo + aux;
    aux.setFecha(25, 7, 2022);
    *equipo + aux;
    aux.setFecha(29, 8, 2022);
    *equipo + aux;
    aux.setFecha(27, 9, 2022);
    *equipo + aux;
    aux.setFecha(26, 10, 2022);
    *equipo + aux;
    aux.setFecha(23, 11, 2022);
    *equipo + aux;
    aux.setFecha(21, 12, 2022);
    *equipo + aux;

    *Hospital + equipo;//No deberia tirar error
    equipo = new cRespiradores("32x10x30", Estado::Standby, Terapia_Intensiva, 102, 10);

    aux.setFecha(30, 11, 2021);
    *equipo + aux;
    aux.setFecha(29, 12, 2021);
    *equipo + aux;
    aux.setFecha(28, 1, 2022);
    *equipo + aux;
    aux.setFecha(18, 2, 2022);
    *equipo + aux;
    aux.setFecha(20, 3, 2022);
    *equipo + aux;
    aux.setFecha(29, 4, 2022);
    *equipo + aux;
    aux.setFecha(19, 5, 2022);
    *equipo + aux;
    aux.setFecha(18, 6, 2022);
    *equipo + aux;
    aux.setFecha(25, 7, 2022);
    *equipo + aux;
    aux.setFecha(29, 8, 2022);
    *equipo + aux;
    aux.setFecha(27, 9, 2022);
    *equipo + aux;
    aux.setFecha(26, 10, 2022);
    *equipo + aux;
    aux.setFecha(23, 11, 2022);
    *equipo + aux;
    aux.setFecha(21, 12, 2022);
    *equipo + aux;

    *Hospital + equipo;//No deberia tirar error

    equipo = new cMesas_Anestesia("22x23x13", Estado::Standby, Mantenimiento, 100.20);

    aux.setFecha(30, 11, 2021);
    *equipo + aux;
    aux.setFecha(29, 12, 2021);
    *equipo + aux;
    aux.setFecha(28, 1, 2022);
    *equipo + aux;
    aux.setFecha(18, 2, 2022);
    *equipo + aux;
    aux.setFecha(20, 3, 2022);
    *equipo + aux;
    aux.setFecha(29, 4, 2022);
    *equipo + aux;
    aux.setFecha(19, 5, 2022);
    *equipo + aux;
    aux.setFecha(18, 6, 2022);
    *equipo + aux;
    aux.setFecha(25, 7, 2022);
    *equipo + aux;
    aux.setFecha(29, 8, 2022);
    *equipo + aux;
    aux.setFecha(27, 9, 2022);
    *equipo + aux;
    aux.setFecha(26, 10, 2022);
    *equipo + aux;
    aux.setFecha(23, 11, 2022);
    *equipo + aux;
    aux.setFecha(21, 12, 2022);
    *equipo + aux;

    *Hospital + equipo;//No deberia tirar error
    equipo = new cElectrograma("20x10x30", Estado::Standby, Quirofano, 50.20);

    aux.setFecha(30, 11, 2021);
    *equipo + aux;
    aux.setFecha(29, 12, 2021);
    *equipo + aux;
    aux.setFecha(28, 1, 2022);
    *equipo + aux;
    aux.setFecha(18, 2, 2022);
    *equipo + aux;
    aux.setFecha(20, 3, 2022);
    *equipo + aux;
    aux.setFecha(29, 4, 2022);
    *equipo + aux;
    aux.setFecha(19, 5, 2022);
    *equipo + aux;
    aux.setFecha(18, 6, 2022);
    *equipo + aux;
    aux.setFecha(25, 7, 2022);
    *equipo + aux;
    aux.setFecha(29, 8, 2022);
    *equipo + aux;
    aux.setFecha(27, 9, 2022);
    *equipo + aux;
    aux.setFecha(26, 10, 2022);
    *equipo + aux;
    aux.setFecha(23, 11, 2022);
    *equipo + aux;
    aux.setFecha(21, 12, 2022);
    *equipo + aux;

    *Hospital + equipo;//No deberia tirar error
    equipo = new cRespiradores("32x10x30", Estado::Standby, Almacen, 102, 10);

    aux.setFecha(30, 11, 2021);//Cambiar, le tengo que asignar un puntero
    *equipo + aux;
    aux.setFecha(29, 12, 2021);
    *equipo + aux;
    aux.setFecha(28, 1, 2022);
    *equipo + aux;
    aux.setFecha(18, 2, 2022);
    *equipo + aux;
    aux.setFecha(20, 3, 2022);
    *equipo + aux;
    aux.setFecha(29, 4, 2022);
    *equipo + aux;
    aux.setFecha(19, 5, 2022);
    *equipo + aux;
    aux.setFecha(18, 6, 2022);
    *equipo + aux;
    aux.setFecha(25, 7, 2022);
    *equipo + aux;
    aux.setFecha(29, 8, 2022);
    *equipo + aux;
    aux.setFecha(27, 9, 2022);
    *equipo + aux;
    aux.setFecha(26, 10, 2022);
    *equipo + aux;
    aux.setFecha(23, 11, 2022);
    *equipo + aux;
    aux.setFecha(21, 12, 2022);
    *equipo + aux;

    *Hospital + equipo;//No deberia tirar error
    //Agrego 2 equipos de cada clase
     
    unsigned int cont = 0;

    //Simulo unos dias
    int mes = Hoy.getMes();//Para tener el mes de referencia
    do
    {
        Hospital->IniciarDia(Hoy);
        if (mes != Hoy.getMes())
        {
            verificado(Hospital);//Funcion que verifica los equipos una vez al mes
            mes = Hoy.getMes();
        }
        Hospital->TerminarDia();
        cont++;
        Hoy.Cambio_Fecha();//Cambia la fecha al dia siguiente
    } while (cont < 365);//Solo es una referencia, podemos probarlo para X cantidad de dias

    
    //Poner los metodos que pidieron en la consigna
    //Pueden quedar mantenimientos pendientes, ¿Hacer una lista con los pendientes y que despues se agreguen a la lista de los hechos?
    //De ser asi, habria que agregar un estado en enum Estado que sea mantenimiento_pendiente

    delete Hospital;
    return 0;
}

void verificado(cSistema* Sistema)
{
    for (int i = 0; i < (Sistema->getListaEquipos())->getCA(); i++)
    {
        (*(Sistema->getListaEquipos()))[i]->Verificado();
    }
}
