#include "cRespiradores.h"

cRespiradores::cRespiradores(string dimenciones, Estado estado, string lugaractual, float peso):cEquipos(dimenciones, estado, lugaractual, peso)
{
	Alarma_alta_presion = false;
	Alarma_baja_presion = false;
	Alarma_flujo = false;
	Flujo_Configurado = 100;
	Flujo_Salida = 100;
}

void cRespiradores::EncenderAlarmas()
{
	Flujo_Salida = FuncionRand(80, 100);
	int valor = FuncionRand(1, 3);
	if (valor == 1 || valor == 3) {
		Alarma_alta_presion = true;//suena la alarma
	}
	else { Alarma_baja_presion = true; }
}
