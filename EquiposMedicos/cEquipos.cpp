#include "cEquipos.h"

cEquipos::cEquipos(string dimenciones, Estado estado, Lugar lugaractual, float peso) :Codigo(Contador++), Lugar_Guardado(Almacen)
{
	Dimenciones = dimenciones;
	Estado_Equipo = estado;
	Lugar_Actual = lugaractual;
	Peso = peso;
	Descripcion = "Todavia no hay ";
	Costo = 0.0;
	Calendario = new cListaT<cFecha>(false);//Que no borre las fechas
	
}
unsigned int cEquipos::Contador = 1;

bool cEquipos::Alerta()
{
	if (Lugar_Actual != Lugar_Guardado) {
		cout << "\n El equipo " << to_string(Codigo) << " no esta en su lugar";
		return true;
	}
	else
		return false;
}

void cEquipos::Verificado()
{
}

void cEquipos::Imprimir()
{
	cout << this->to_string() << endl;

}

cEquipos::~cEquipos()
{
	delete Calendario;
}

void cEquipos::operator+(cFecha* nuevo)
{
	*Calendario + nuevo;
}

string cEquipos::to_string()
{
	string aux= "\nDescripcion: " + Descripcion + "\nDimensiones: " + Dimenciones + " \nPeso: " + std::to_string(Peso) + "\n Estado: " +
		Estados_to_string(Estado_Equipo) + "\nPrecio: " + std::to_string(Costo) + "$";
	return aux;
}
