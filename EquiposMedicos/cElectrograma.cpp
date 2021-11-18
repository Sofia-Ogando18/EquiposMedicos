#include "cElectrograma.h"


cElectrograma::cElectrograma(string dimenciones, Estado estado, Lugar lugaractual, float peso) :cEquipos(dimenciones, estado, lugaractual, peso, "EG" + std::to_string(Contador))
{
	Derivaciones_Bipolares = false;
	Derivaciones_Estandar = false;
	Traficacion = false;
	Contador++;
}
unsigned int cElectrograma::Contador = 1;

cElectrograma::~cElectrograma()
{

}

void cElectrograma::Verificado()
{
	if (Derivaciones_Bipolares || Derivaciones_Estandar || Traficacion)//Si alguna es verdad, lo seteo en fuera de servicio
		this->Estado_Equipo = Estado::Fuera_de_Servicio;
}


void cElectrograma::EncenderAlarmas()
{
	if (this->Estado_Equipo == Estado::Fuera_de_Servicio || this->Estado_Equipo == Estado::Mantenimiento)//No enciendo alarmas si el equipo no esta operando
		return;
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

void cElectrograma::ApagarAlarmas()
{
	Derivaciones_Bipolares = false;
	Derivaciones_Estandar = false;
	Traficacion = false;
}

void cElectrograma::Imprimir()
{
	cout << this->to_string() << endl;
}
string cElectrograma::to_string()
{
	string aux = ((cEquipos*)this)->to_string();//Fijarse si imprimimos los datos de las derivaciones

	return aux;
}
