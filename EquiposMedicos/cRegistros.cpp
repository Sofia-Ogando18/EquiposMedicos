#include "cRegistros.h"

cRegistros::cRegistros(cFecha fecha_mant, Mantenimientos mantenimiento, float monto, string ID) :ID(ID + std::to_string(cont)), ID_Equipo(ID)
{
	Fecha_mantenimiento = fecha_mant;
	tipo_Mantenimiento = mantenimiento;
	Monto_Mantenimiento = monto;
	cont++;
}
unsigned int cRegistros::cont = 1;

cRegistros::~cRegistros()
{

}

void cRegistros::Imprimir()
{
	cout << this->to_string() << endl;
}

string cRegistros::to_string()
{
	string aux = "\nTipo de mantenimiento: " + Mantenimiento_to_string(tipo_Mantenimiento) + "\nFecha: " + Fecha_mantenimiento.tm_to_string_Fecha() +
		"\nMonto: " + std::to_string(Monto_Mantenimiento) + "\nCodigo registro: " + ID;
	return aux;
}


