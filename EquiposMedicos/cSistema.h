#pragma once
#include "cEquipos.h"
#include "cListaT.h"
class cSistema
{
	cListaT <cEquipos>* Lista_Equipos;
	cFecha Hoy;

public:
	cSistema(cFecha fecha);
	void Historial();
	string RastrearEquipo(cEquipos*equipo);
	void BuscarEquipo(int codigo);//lo busca por codigo y despues lo imprime 
	~cSistema();
	void operator+(cEquipos* nuevo);
	void IniciarDia(cFecha Hoy);//Setea la fecha;
	void TerminarDia();//Imprime la lista de equipos a los que se realizo mantenimiento en la fecha y su costo total, clasificando segun el tipo
};

