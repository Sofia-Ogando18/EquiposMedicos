#include "cSistema.h"

cSistema::cSistema(cListaT<cEquipos>* equipos)
{
	if (equipos != NULL)
		Lista_Equipos = equipos;
	else equipos = new cListaT <cEquipos>();
}
