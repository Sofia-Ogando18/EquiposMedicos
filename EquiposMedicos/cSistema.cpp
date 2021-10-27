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
				if((*Lista_Registros)[i]->getMantenimiento()==j)//Imprimo segun el tipo
					(*Lista_Registros)[i]->Imprimir();
			}
		}
	}
}

string cSistema::RastrearEquipo(cEquipos* equipo)//Revisar
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
	if(equipo_aux!=NULL)
		equipo_aux->Imprimir();//Imprimo si lo encontro
	return
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
	Calcular_Ganacias();
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
		std::to_string(Ganancia_Diaria) + "\nHoy: "Hoy.tm_to_string_Fecha();
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
		if ((*Lista_Registros)[i]->getMantenimiento() == Correctivo_Pendiente)//Verifico que sea un mantenimiento correctivo pendiente
		{
			Monto += (*Lista_Registros)[i]->getMonto();
			cont++;
		}
	}
	if (Monto > 2000 || cont>=5)
	{
		Ganancia_Diaria = monto;
		Ganancia_Total += monto;
		for (int i = 0; i < Lista_Registros->getCA(); i++)
		{
			if ((*Lista_Registros)[i]->getMantenimiento() == Correctivo_Pendiente)//Los seteo en correctivo
			{
				(*Lista_Registros)[i]->setCorrectivo();
			}
		}
	}

}

void cSistema::RealizarMantenimiento_Preventivo()
{
}

void cSistema::Agregar_Registro()
{
}

