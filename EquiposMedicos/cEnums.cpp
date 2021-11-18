#include "cEnums.h"

int FuncionRand(int min, int max)
{
	return rand() % (max - min) + min;
}

string Estados_to_string(Estado estado)
{
	switch (estado)
	{
	case Estado::Fuera_de_Servicio:
		return "Fuera de Servicio";
	case Estado::Mantenimiento:
		return "Mantenimiento";
	case Estado::Ocupado:
		return "Ocupado";
	case Estado::Standby:
		return "Standby";
	default:
		break;
	}
}

string Lugar_to_string(Lugar lugar)
{
	switch (lugar)
	{
	case Lugar::Almacen:
		return "Almacen";
	case Lugar::Quirofano:
		return "Quirofano";
	case Lugar::Mantenimiento:
		return "Mantenimiento";
	case Lugar::Terapia_Intensiva:
		return "Terapia_Intensiva";
	case Lugar::Guardia:
		return "Guardia";
	default:
		break;
	}
}

string Mantenimiento_to_string(Mantenimientos mantenimiento)
{
	switch (mantenimiento)
	{
	case Mantenimientos::Correctivo:
		return "Correctivo";
	case Mantenimientos::Correctivo_Pendiente:
		return "Correctivo pendiente";
	case Mantenimientos::Preventivo:
		return "Preventivo";
	default:
		break;
	}
}

bool Mantenimiento_int(Mantenimientos mantenimiento, int num)
{
	switch (mantenimiento)
	{
	case Mantenimientos::Correctivo:
		if (num == 1)//Si corresponde con el tipo de mantenimiento
			return true;
		else
			return false;
	case Mantenimientos::Preventivo:
		if (num == 0)
			return true;
		else
			return false;
	case Mantenimientos::Correctivo_Pendiente:
		if (num == 2)
			return true;
		else
			return false;
	}
	return false;
}

