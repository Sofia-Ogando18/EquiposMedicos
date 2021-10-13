#include "cSistema.h"

cSistema::cSistema(cListaT<cEquipos>* equipos)
{
	if (equipos != NULL)
		Lista_Equipos = equipos;
	else equipos = new cListaT <cEquipos>();
}

string cSistema::RastrearEquipo(cEquipos* equipo)
{
	cEquipos* equipo_aux=NULL;
	if (equipo != NULL) {
		equipo_aux=Lista_Equipos->Buscar_por_string(equipo->getUbicacion());
		return equipo_aux->getUbicacion();
	}
}

void cSistema::BuscarEquipo(int codigo)
{
	cEquipos* equipo_aux = NULL;
	equipo_aux=Lista_Equipos->Buscar_por_ID(codigo);
	equipo_aux->Imprimir();
}
