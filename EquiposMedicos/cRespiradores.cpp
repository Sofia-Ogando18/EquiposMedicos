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
	Flujo_Salida = FuncionRand(Flujo_Configurado - 10, Flujo_Configurado + 10);//Hago que el flujo sea un numero entre 85 y 95
	if (Flujo_Salida == Flujo_Configurado)
		return;//Si el flujo es el mismo al configurado, retorno

	//Si no, sigo
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
	string aux = ((cEquipos*)this)->to_string() + "\nFlujo configurado: " + std::to_string(Flujo_Configurado) + "\nFlujo de salida: "
		+ std::to_string(Flujo_Salida);

	return aux;
}

ostream& operator<<(ostream& out, const cRespiradores& R)
{
	string alarma_baja, alarma_alta, alarma_cero;
	if (R.Alarma_alta_presion)
		alarma_alta = "Encendida";
	else
		alarma_alta = "Apagada";
	if (R.Alarma_baja_presion)
		alarma_baja = "Encendida";
	else
		alarma_baja = "Apagada";
	if (R.Alarma_flujo)
		alarma_cero = "Encendida";
	else
		alarma_cero = "Apagada";
	out << (cEquipos&)R;
	out << "\nFlujo configurado: " << std::to_string(R.Flujo_Configurado) << "\nFlujo de salida: " << std::to_string(R.Flujo_Salida) << "\nAlarma baja presion" <<
		alarma_baja << "\nAlarma alta presion: " << alarma_alta << "\nAlarma de taponamiento: " << alarma_cero << endl;
	return out;
}

istream& operator>>(istream& in, cRespiradores& R)
{
	in >> (cEquipos&)R;
	unsigned int aux;
	cout << "\nFlujo configurado: " << endl;
	in >> aux;
	R.Flujo_Configurado = aux;
	return in;
}