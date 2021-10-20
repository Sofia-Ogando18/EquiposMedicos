#pragma once
#include "cEquipos.h"
#include "cListaT.h"
#include "cRegistros.h"

class cSistema
{
	cListaT <cEquipos>* Lista_Equipos;
	cFecha Hoy;
	cListaT<cRegistros>* Lista_Registros;//¿Como agregar los registros?
	float Ganancia_Total;
	float Ganancia_Diaria;

public://Agregar calcular Ganancia total
	cSistema(cFecha fecha);
	void Historial();//Imprime 
	string RastrearEquipo(cEquipos*equipo);
	void BuscarEquipo(int codigo);//lo busca por codigo y despues lo imprime 
	~cSistema();
	void operator+(cEquipos* nuevo);
	void IniciarDia(cFecha Hoy);//Setea la fecha;
	void TerminarDia();//Imprime la lista de equipos a los que se realizo mantenimiento en la fecha y la ganancia total y diaria, clasificando segun el tipo
	cListaT <cEquipos>* getListaEquipos();
};

