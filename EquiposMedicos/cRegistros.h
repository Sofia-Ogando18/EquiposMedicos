#pragma once
#include "cFecha.h"
#include "cEnums.h"

class cRegistros //lista de los mantenimientos y sus costos 
{
	const string ID;//Del equipo + contador. Los registros pueden repetirse en distintas fechas
	const string ID_Equipo;
	cFecha Fecha_mantenimiento;
	Mantenimientos tipo_Mantenimiento;
	float Monto_Mantenimiento;
	static unsigned int cont;
public:
	cRegistros(cFecha fecha_mant, Mantenimientos mantenimiento, float monto, string ID);
	~cRegistros();
	void Imprimir();
	string to_string();
	cFecha getFecha() { return Fecha_mantenimiento; };
	Mantenimientos getMantenimiento() { return tipo_Mantenimiento; };
	float getMonto() { return Monto_Mantenimiento; };
	void setCorrectivo() { tipo_Mantenimiento = Mantenimientos::Correctivo; };//Setea el mantenimiento en correctivo
	string getID() { return ID; };
	string getID_Equipo() { return ID_Equipo; };
};
