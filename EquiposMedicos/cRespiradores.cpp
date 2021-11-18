#include "cRespiradores.h"

cRespiradores::cRespiradores(string dimenciones, Estado estado, Lugar lugaractual, float peso)
	:cEquipos(dimenciones, estado, lugaractual, peso, "RP" + std::to_string(Contador))
{
	Alarma_alta_presion = false;
	Alarma_baja_presion = false;
	Alarma_flujo = false;
	Flujo_Configurado = 90;
	Flujo_Salida = 90;
	Contador++;
}
unsigned int cRespiradores::Contador = 1;

void cRespiradores::EncenderAlarmas()
{
	if (this->Estado_Equipo == Estado::Fuera_de_Servicio || this->Estado_Equipo == Estado::Mantenimiento)//No enciendo alarmas si el equipo no esta operando
		return;
	Flujo_Salida = FuncionRand(80, 100);//Hago que el flujo sea un numero entre 85 y 95
	int taponamiento = FuncionRand(0, 3);//Random para decidir si el respirador esta tapado
	if (taponamiento != 0)
	{
		if (Flujo_Salida > Flujo_Configurado) //Mayor flujo
		{
			Alarma_alta_presion = true;//suena la alarma
		}
		else {//Baja presión
			Alarma_baja_presion = true;
		}
	}
	else//Si taponamiento=0, entonces el respirador esta tapado
	{
		Alarma_flujo = true;
		Flujo_Salida = 0;
	}
}

void cRespiradores::ApagarAlarmas()
{
	Alarma_alta_presion = false;
	Alarma_baja_presion = false;
	Alarma_flujo = false;
	Flujo_Salida = Flujo_Configurado;
}

void cRespiradores::Verificado()
{
	if (Alarma_alta_presion || Alarma_baja_presion || Alarma_flujo)
		this->Estado_Equipo = Estado::Fuera_de_Servicio;
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
	string aux = ((cEquipos*)this)->to_string();//Despues agregarle el resto del texto

	return aux;
}