#include "cEquipos.h"
string cEquipos::Lugar_Guardado = "Paseo Cadena, 176";

cEquipos::cEquipos(string dimenciones, Estado estado, string lugaractual, float peso, cListaT<cFecha>* fechas) :Codigo(Codigo + 1)
{
	Dimenciones = dimenciones;
	Estado_Equipo = estado;
	Lugar_Actual = lugaractual;
	Peso = peso;
	Descripcion = "Todavia no hay ";
	Costo = 0.0;
	if (fechas != NULL)
		Calendario = fechas;
	else
		fechas = new cListaT<cFecha>();
	
}
