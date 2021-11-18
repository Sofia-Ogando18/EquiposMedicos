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
	for (int i = 0; i < Lista_Registros->getCA(); i++)
	{
		(*Lista_Registros)[i]->Imprimir();
	}
}

void cSistema::Imprimir_Registros_Hoy()
{
	for (int j = 0; j < 3; j++)
	{
		for (int i = 0; i < Lista_Registros->getCA(); i++)
		{
			if ((*Lista_Registros)[i]->getFecha() == this->Hoy)//Si las fechas coinciden
			{
				if (Mantenimiento_int((*Lista_Registros)[i]->getMantenimiento(), j))//Imprimo segun el tipo
					(*Lista_Registros)[i]->Imprimir();
			}
		}
	}
}

void cSistema::Calcular_Ganancias()
{
	float testigo = Ganancia_Diaria;
	for (int i = 0; i < Lista_Registros->getCA(); i++)
	{
		if ((*Lista_Registros)[i]->getFecha() == Hoy)
		{
			if ((*Lista_Registros)[i]->getMantenimiento() == Mantenimientos::Preventivo)//Solo considero los preventivos porque los correctivos los
				Ganancia_Diaria += (*Lista_Registros)[i]->getMonto();//sumo en RealizarMantenimientoCorrectivo_Pendiente
		}

	}
	if (testigo != Ganancia_Diaria)//Hubo un incremento
	{
		Ganancia_Total += Ganancia_Diaria;
	}
}

string cSistema::RastrearEquipo(cEquipos* equipo)//Revisar
{
	cEquipos* equipo_aux = NULL;
	if (equipo != NULL) {
		equipo_aux = Lista_Equipos->Buscar_por_string(equipo->getID());
		return equipo_aux->getUbicacion();
	}
	else
		throw new exception("Puntero NULL");
}

void cSistema::BuscarEquipo(string codigo)
{
	cEquipos* equipo_aux = NULL;
	equipo_aux = Lista_Equipos->Buscar_por_string(codigo);
	if (equipo_aux != NULL)
		equipo_aux->Imprimir();//Imprimo si lo encontro
	return;
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

void cSistema::IniciarDia(cFecha Hoy)
{
	this->Hoy = Hoy;
}

void cSistema::TerminarDia()
{
	Imprimir_Registros_Hoy();
	Calcular_Ganancias();
	cout << "Ganancia total: " << Ganancia_Total << "\nGanancia diaria: " << Ganancia_Diaria << endl;
	Ganancia_Diaria = 0;//Seteo la ganancia diaria de nuevo en 0
}

cListaT<cEquipos>* cSistema::getListaEquipos()
{
	return Lista_Equipos;
}

void cSistema::Imprimir()
{
	cout << this->to_string() << endl;
	Historial();
	for (int i = 0; i < Lista_Equipos->getCA(); i++)
	{
		(*Lista_Equipos)[i]->Imprimir();
	}
}

string cSistema::to_string()
{
	string aux = "\nGanancia total: " + std::to_string(Ganancia_Total) + "\nGanancia diaria: " +
		std::to_string(Ganancia_Diaria) + "\nHoy: " + Hoy.tm_to_string_Fecha();
	return aux;
}

void cSistema::ImprimirAlerta()
{
	for (int i = 0; i < Lista_Equipos->getCA(); i++)
	{
		if ((*Lista_Equipos)[i]->Alerta())
		{
			(*Lista_Equipos)[i]->Imprimir();//Fijarse si se puede cambiar por la sobrecarga cout
		}
	}
}

void cSistema::RealizarMantenimiento_Pendiente()
{
	unsigned short int cont = 0;
	float monto = 0;
	for (int i = 0; i < Lista_Registros->getCA(); i++)
	{
		if ((*Lista_Registros)[i]->getMantenimiento() == Mantenimientos::Correctivo_Pendiente)//Verifico que sea un mantenimiento correctivo pendiente
		{
			monto += (*Lista_Registros)[i]->getMonto();
			cont++;
		}
	}
	if (monto > 2000 || cont >= 5)
	{
		Ganancia_Diaria = monto;
		Ganancia_Total += monto;
		for (int i = 0; i < Lista_Registros->getCA(); i++)
		{
			if ((*Lista_Registros)[i]->getMantenimiento() == Mantenimientos::Correctivo_Pendiente)//Los seteo en correctivo(realizado) y lo pongo en standby
			{
				Lista_Equipos->Buscar_por_string((*Lista_Registros)[i]->getID_Equipo())->setEstado(Estado::Standby);
				(*Lista_Registros)[i]->setCorrectivo();
			}
		}
	}

}

void cSistema::RealizarMantenimiento_Preventivo()
{
	cEquipos* aux = NULL;
	for (int i = 0; i < Lista_Registros->getCA(); i++)
	{
		aux = Lista_Equipos->Buscar_por_string((*Lista_Registros)[i]->getID_Equipo());
		if (aux->getEstado() == Estado::Mantenimiento)
		{
			aux->setEstado(Estado::Standby);
		}
		if ((*Lista_Registros)[i]->getFecha() == Hoy)
		{
			aux->setEstado(Estado::Mantenimiento);
		}

	}
}

void cSistema::Agregar_Registro()
{
	for (int i = 0; i < Lista_Equipos->getCA(); i++)
	{
		(*Lista_Equipos)[i]->Verificado();
		try//Agrego los mantenimientos preventivos
		{
			(*Lista_Registros) + (*Lista_Equipos)[i]->MantenimientoPreventivo(this->Hoy);
		}
		catch (exception* error)
		{
			delete error;//Si devuelve NULL es porque no hubo mantenimiento, entonces no hago nada y borro la excepcion
		}
		try//Agrego los mantenimientos correctivos pendientes
		{
			(*Lista_Registros) + (*Lista_Equipos)[i]->MantenimientoCorrectivos(this->Hoy);
		}
		catch (exception* error)
		{
			delete error;//Si devuelve NULL es porque no hubo mantenimiento, entonces no hago nada y borro la excepcion
		}
	}
}


