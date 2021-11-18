#include "cMesas_Anestesia.h"

cMesas_Anestesia::cMesas_Anestesia(string dimenciones, Estado estado, Lugar lugaractual, float peso)
	:cEquipos(dimenciones, estado, lugaractual, peso, "MA" + std::to_string(Contador))
{
	Alarma_alta_Frec_Card = false;
	Alarma_baja_Frec_Card = false;
	Nivel_suenio = 100;
	Volumen_flujo = 80;
	Volumen_flujo_fijado = 80;
	Contador++;
}
unsigned int cMesas_Anestesia::Contador = 1;

void cMesas_Anestesia::EncenderAlarmas()//Fijarse cual es la condicion para encender las alarmas y definir ranfos de nivel de sueño aceptables
{
	if (this->Estado_Equipo == Estado::Fuera_de_Servicio || this->Estado_Equipo == Estado::Mantenimiento)//No enciendo alarmas si el equipo no esta operando
		return;
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

void cMesas_Anestesia::ApagarAlarmas()
{
	Alarma_alta_Frec_Card = false;
	Alarma_baja_Frec_Card = false;
	Volumen_flujo = Volumen_flujo_fijado;
}

cMesas_Anestesia::~cMesas_Anestesia()
{
}

void cMesas_Anestesia::Verificado()//Acordarse de apagar las alarmas cuando se hace mantenimiento correctivo y/o preventivo
{
	//¿Como se verifica el nivel de sueño?
	if (Alarma_alta_Frec_Card || Alarma_baja_Frec_Card || Volumen_flujo >= Volumen_flujo_fijado + 10 || Volumen_flujo <= Volumen_flujo_fijado - 10)
	{
		this->Estado_Equipo = Estado::Fuera_de_Servicio;
	}

}

void cMesas_Anestesia::Imprimir()
{
	cout << this->to_string() << endl;
}

string cMesas_Anestesia::to_string()
{
	string aux = ((cEquipos*)this)->to_string();//Despues agregar el resto del texto

	return aux;
}
