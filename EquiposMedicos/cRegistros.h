#pragma once
#include "cFecha.h"
class cRegistros //lista de los mantenimientos hechos y sus costos 
{

	cFecha* Fecha_mantenimiento;
	bool Mantenimimento;//true=preventivo
	float Monto_Mantenimiento;
public:
	cRegistros(cFecha* fecha_mant,bool mantenimiento, float monto);
	~cRegistros();
};

