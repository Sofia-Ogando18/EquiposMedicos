#include "cMesas_Anestesia.h"

cMesas_Anestesia::cMesas_Anestesia(string dimenciones, Estado estado, Lugar lugaractual, float peso):cEquipos(dimenciones,estado, lugaractual,peso)
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

void cMesas_Anestesia::Verificado()
{
	HacerMantenimientoPreventivo();

}

void cMesas_Anestesia::Imprimir()
{
	cout << this->to_string() << endl;
}

string cMesas_Anestesia::to_string()
{
	string aux = (cEquipos*)this->to_string();//Despues agregar el resto del texto

	return aux;
}

void cMesas_Anestesia::HacerMantenimientoPreventivo()
{

	if (Volumen_flujo != Volumen_flujo_fijado || Alarma_alta_Frec_Card == true || Alarma_baja_Frec_Card == true || Nivel_suenio!=100) {
		HacerMantenimientoCorrectivo();
	};
}

void cMesas_Anestesia::HacerMantenimientoCorrectivo()
{
	if (Volumen_flujo != Volumen_flujo_fijado) { Volumen_flujo = Volumen_flujo_fijado; }
	else if (Alarma_alta_Frec_Card == true) { Alarma_alta_Frec_Card = false; }
	else if (Alarma_baja_Frec_Card == true) { Alarma_baja_Frec_Card = true; }
	else { Nivel_suenio = 100; };
}
