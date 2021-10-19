#include "cMesas_Anestesia.h"

cMesas_Anestesia::cMesas_Anestesia(string dimenciones, Estado estado, string lugaractual, float peso):cEquipos(dimenciones,estado, lugaractual,peso)
{
	Alarma_alta_Frec_Card = false;
	Alarma_baja_Frec_Card = false;
	Nivel_suenio = 100;
	Volumen_flujo = 80;
	Volumen_flujo_fijado = 80;
}

void cMesas_Anestesia::EncenderAlarmas()
{
	
	int Valor = FuncionRand(1, 4);
	switch (Valor)
	{
	case 1:
		Alarma_alta_Frec_Card = true;
		Nivel_suenio = FuncionRand(50, 100);
	case 2:
		Volumen_flujo = FuncionRand(50, 100);
		Nivel_suenio = FuncionRand(10, 100);
	case 3:
		Nivel_suenio = FuncionRand(10, 100);
	case 4:
		Volumen_flujo = FuncionRand(50, 100);
	default:
		break;
	}
}

cMesas_Anestesia::~cMesas_Anestesia()
{
}
