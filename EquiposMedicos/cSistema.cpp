#include "cSistema.h"

cSistema::cSistema(cFecha fecha)
{
	Lista_Equipos = new cListaT <cEquipos>();
	Hoy = fecha;
	Lista_Registros = new cListaT<cRegistros>();
	Ganancia_Diaria = 0;
	Ganancia_Total = 0;
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
	delete Lista_Equipos;
	delete Lista_Registros;
}

void cSistema::operator+(cEquipos* nuevo)
{
	this->Lista_Equipos->Agregar(nuevo);
}

cListaT<cEquipos>* cSistema::getListaEquipos()
{
	return Lista_Equipos;
}

