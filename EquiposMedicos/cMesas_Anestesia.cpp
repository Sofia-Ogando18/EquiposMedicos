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

void cMesas_Anestesia::EncenderAlarmas()
{
	if (this->Estado_Equipo == Estado::Fuera_de_Servicio || this->Estado_Equipo == Estado::Mantenimiento)//No enciendo alarmas si el equipo no esta operando
		return;
	Nivel_suenio = FuncionRand(50, 100);
	if (Nivel_suenio <= 65)//Si el nivel de sueño es menor a 65, salta alarma
	{
		Alarma_alta_Frec_Card = true;//Esta despierto
		Volumen_flujo = Volumen_flujo_fijado - Nivel_suenio % 20;
	}
	else if (Nivel_suenio >= 85)//Si el nivel de sueño es mayor a 85, salta alarma
	{
		Alarma_baja_Frec_Card = true;
		Volumen_flujo = Volumen_flujo_fijado + Nivel_suenio % 20;
	}
	else//Si no, no hace nada
		return;
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
	string aux = ((cEquipos*)this)->to_string() + "\nNivel de suenio: " + std::to_string(Nivel_suenio) + "\nVolumen de flujo configurado:" +
		std::to_string(Volumen_flujo_fijado) + "\nVolumen de flujo: " + std::to_string(Volumen_flujo);

	return aux;
}

ostream& operator<<(ostream& out, const cMesas_Anestesia& M)
{
	out << (cEquipos&)M;
	string alarma_alta, alarma_baja;
	if (M.Alarma_alta_Frec_Card)
		alarma_alta = "Encendida";
	else
		alarma_alta = "Apagada";
	if (M.Alarma_baja_Frec_Card)
		alarma_baja = "Encendida";
	else
		alarma_baja = "Apagada";
	out << "\nNivel de suenio: " << std::to_string(M.Nivel_suenio) << "\nVolumen de flujo configurado:" << std::to_string(M.Volumen_flujo_fijado) <<
		"\nVolumen de flujo: " << std::to_string(M.Volumen_flujo) << "\nAlarma de baja frecuencia cardiaca: " << alarma_baja <<
		"\nAlarma de alta frecuencia cardiaca: " << alarma_alta;
	return out;
}

istream& operator>>(istream& in, cMesas_Anestesia& M)
{
	in >> (cEquipos&)M;
	float volumen;
	cout << "\nVolumen de flujo a configurar: " << endl;
	in >> volumen;
	M.Volumen_flujo_fijado = volumen;
	return in;
}