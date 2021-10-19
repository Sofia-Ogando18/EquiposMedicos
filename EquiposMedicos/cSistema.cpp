#include "cSistema.h"

cSistema::cSistema(cFecha fecha)
{
	equipos = new cListaT <cEquipos>();
	Hoy=fecha
}

void cSistema::Historial()
{
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

cSistema::~cSistema()
{
	delete equipos;
}

void operator+(cEquipos* nuevo)
{
	this->Lista_Equipos->Agregar(nuevo);
}
