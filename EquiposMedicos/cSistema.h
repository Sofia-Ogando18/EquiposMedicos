#pragma once
#include "cEquipos.h"
#include "cListaT.h"
class cSistema
{
	cListaT <cEquipos>*Lista_Equipos;

public:
	cSistema(cListaT <cEquipos>* equipos);
	void Historial();
	string RastrearEquipo(cEquipos*equipo);
	void BuscarEquipo(int codigo);//lo busca por codigo y despues lo imprime 
	~cSistema();
};

