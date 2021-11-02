#include "cRegistros.h"

cRegistros::cRegistros(cEquipos* equipo, cFecha* fecha_mant, Mantenimientos mantenimiento, float monto)
{
	Fecha_mantenimiento = fecha_mant;
	tipo_Mantenimimento = mantenimiento;
	Monto_Mantenimiento = monto;
	this->equipo = equipo;
}

cRegistros::~cRegistros()
{
}

void cRegistros::Imprimir()
{
	cout << to_string() << endl;
}

string cRegistros::to_string()
{
	string registro;
	registro = tipo_de_equipo() + " Fecha del mantenimiento:" + tm_to_string_Fecha() + "Mantenimiento: " + Mantenimiento_to_string(tipo_Mantenimimento)+"\n"+ "Monto: $"+std::to_string(Monto_Mantenimiento);
	return registro;
}

string cRegistros::tipo_de_equipo()
{
	cEquipos* aux=NULL;
	aux = dynamic_cast<cElectrograma*>(equipo);
	if (aux != NULL)
		return "Electrograma";
	aux = dynamic_cast<cRespiradores*>(equipo);
	if (aux != NULL)
		return "Respirador";
	aux = dynamic_cast<cMesas_Anestesia*>(equipo);
	if (aux != NULL)
		return "Mesa de Anestesia";
}


