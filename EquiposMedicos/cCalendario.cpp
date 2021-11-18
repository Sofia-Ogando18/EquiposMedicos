#include "cCalendario.h"
#include "cEnums.h"

void cCalendario::Crear_Calendario()
{
	unsigned int mes, dia, anio;
	cFecha actual;
	if (CA == 0)
	{
		mes = actual.fecha.tm_mon + 1;
		anio = actual.fecha.tm_year + 1900;
	}
	else//Lo inicio desde la ultima fecha
	{
		mes = Lista[CA - 1]->fecha.tm_mon + 1;
		anio = Lista[CA - 1]->fecha.tm_year + 1900;
	}

	for (int i = CA; i < TAM; i++)//Lo repito hasta crear todas las fechas del calendario
	{
		mes++;//Adelanto un mes
		dia = FuncionRand(1, 28);//Defino un dia entre el 1 y 28, ya que todos los meses los tienen
		if (mes >= 13)//Si el mes supera diciembre, lo pongo en 1 (Enero) y avanzo de año
		{
			mes = 1;
			anio++;
		}
		Lista[i] = new cFecha(dia, mes, anio, FuncionRand(0, 23), FuncionRand(0, 59));
		CA++;//Aumento la cantidad de espacio ocupado
	}
}

cCalendario::cCalendario(unsigned int TAM)
{
	Lista = new cFecha * [TAM];
	this->TAM = TAM;
	this->CA = 0;
	for (int i = 0; i < this->TAM; i++)
	{
		Lista[i] = NULL;
	}
	Crear_Calendario();
}

cCalendario::~cCalendario()
{
	if (Lista != NULL)
	{
		for (int i = 0; i < CA; i++)
		{
			if (Lista[i] != NULL)
				delete Lista[i];
		}
		delete[] Lista;
	}
}


void cCalendario::Eliminar(cFecha hoy)
{
	cFecha* aux = NULL;
	try {
		aux = Quitar(hoy);
	}
	catch (exception* error)
	{
		delete error;//No voy a hacer nada con la excepcion, asi que solo la elimino
	}
	delete aux;
}

cFecha* cCalendario::Quitar(cFecha hoy)
{
	cFecha* aux = Buscar_Fecha(hoy);
	unsigned int cont = 0;
	if (aux == NULL)
		throw new exception("La fecha no existe en la lista");
	for (int i = 0; i < CA; i++)//Existe la fecha
	{
		if (aux == Lista[i])
		{
			cont = i;
			break;
		}
	}
	for (int i = cont; i < CA - 1; i++)
	{
		Lista[i] = Lista[i + 1];
	}
	CA--;
	return aux;
}

bool cCalendario::Verificar_Fecha(cFecha hoy)
{
	cFecha* aux = Buscar_Fecha(hoy);
	if (aux == NULL)//Si no la encuentro, me salgo
		return false;
	//Si llega hasta aca, es porque si esta en la lista
	Eliminar(hoy);//La elimino de la lista
	Crear_Calendario();//Lleno el espacio que dejó con una nueva fecha
	return true;//Retorno true para hacer saber que si estaba en la lista y que se puede seguir trabajando
}

cFecha* cCalendario::Buscar_Fecha(cFecha hoy)
{
	cFecha* aux = NULL;
	for (int i = 0; i < CA; i++)
	{
		if (*(Lista[i]) == hoy)
		{
			aux = Lista[i];
			break;
		}
	}
	return aux;
}
