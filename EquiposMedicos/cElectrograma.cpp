#include "cElectrograma.h"

cElectrograma::cElectrograma(string dimenciones, Estado estado, Lugar lugaractual, float peso):cEquipos(dimenciones,estado, lugaractual, peso)
{
	Derivaciones_Bipolares = false;
	Derivaciones_Estandar = false;
	Traficacion = false;

}

void cElectrograma::EncenderAlarmas()
{
	int valor = FuncionRand(1, 3);
	switch (valor)
	{
	case 1:
		Derivaciones_Bipolares = true;//andan mal
		break;
	case 2:
		Derivaciones_Bipolares = true;
		Derivaciones_Estandar = true;
		break;
	case 3:
		Traficacion = true;
		default:
		break;
	}
}
