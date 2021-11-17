#include "cRespiradores.h"

cRespiradores::cRespiradores(string dimenciones, Estado estado, Lugar lugaractual, float peso):cEquipos(dimenciones, estado, lugaractual, peso)
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

void cRespiradores::Verificado(cEquipos* equipo)
{
	//lamamos aca a EncenderAlarmas o en el main
	
	 HacerMantenimientoPreventivo(equipo);
	
}

void cRespiradores::HacerMantenimientoPreventivo(cEquipos* equipo)
{
	if (Flujo_Salida == Flujo_Configurado && Alarma_alta_presion == false && Alarma_baja_presion == false) {
		
	}
	else { HacerMantenimientoCorrectivo(equipo);
	
	};
	
}

void cRespiradores::HacerMantenimientoCorrectivo(cEquipos* equipo)
{

	if (Flujo_Salida != Flujo_Configurado) { Flujo_Salida = Flujo_Configurado; }
	else if (Alarma_alta_presion == true) { Alarma_alta_presion = false; }
	else if (Alarma_baja_presion == true) { Alarma_baja_presion = false; };

}

cRespiradores::~cRespiradores()
{

}

void cRespiradores::Imprimir()
{
	cout << this->to_string() << endl;
}

string cRespiradores::to_string()
{
	string aux = this->to_string();//Despues agregarle el resto del texto

	return aux;
}