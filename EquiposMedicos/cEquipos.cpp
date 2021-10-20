#include "cEquipos.h"

cEquipos::cEquipos(string dimenciones, Estado estado, Lugar lugaractual, float peso) :Codigo(Contador++), Lugar_Guardado(Almacen)
{
	Dimenciones = dimenciones;
	Estado_Equipo = estado;
	Lugar_Actual = lugaractual;
	Peso = peso;
	Descripcion = "Todavia no hay ";
	Costo = 0.0;
	Calendario = new cListaT<cFecha>();
	
}
unsigned int cEquipos::Contador = 1;

void cEquipos::Alerta()
{
	if (Lugar_Actual != Lugar_Guardado) {
		cout << "\n El equipo " << to_string(Codigo)<<" no esta en su lugar";
	}
}

void cEquipos::Verificado()
{
}

void cEquipos::Imprimir()//Agregar to_string
{
	cout << "\n Descripcion: " << Descripcion << " Dimensiones: " << Dimenciones << " Peso: " << to_string(Peso) << "\n Estado: " << Estados_to_string(Estado_Equipo) << "Precio: " << to_string(Costo) << "$";

}

cEquipos::~cEquipos()
{
	delete Calendario;
}

void cEquipos::operator+(cFecha* nuevo)
{
	*Calendario + nuevo;
}
