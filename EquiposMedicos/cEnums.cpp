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
