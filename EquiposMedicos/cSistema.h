#pragma once
#include "cEquipos.h"
#include "cListaT.h"
class cSistema
{
	cListaT <cEquipos>*Lista_Equipos;
public:
	cSistema();
	void Historial();
	string RastrearEquipo(cEquipos*equipo);
	void BuscarEquipo(cEquipos*equipo);//lo busca por codigo y despues lo imprime 
	~cSistema();
};

