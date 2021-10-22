#pragma once
#include "cFecha.h"
#include "cEnums.h"

class cRegistros //lista de los mantenimientos y sus costos 
{

	cFecha* Fecha_mantenimiento;
	Mantenimiento tipo_Mantenimimento;//
	float Monto_Mantenimiento;
public:
	cRegistros(cFecha* fecha_mant,Mantenimiento mantenimiento, float monto);
	~cRegistros();
	void Imprimir();
	string to_string();
};

