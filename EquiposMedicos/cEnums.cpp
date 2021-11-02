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
		break;
	case Mantenimientos::Correctivo_Pendiente:
		return "Correctivo_Pendiente";
		break;
	case Mantenimientos::Preventivo:
		return "Preventivo";
		break;
	default:
		break;
	}
}
