#pragma once
#include "cFecha.h"
class cRegistros //lista de los mantenimientos hechos y sus costos
{

	cFecha* Fecha_mantenimiento;
	bool Mantenimimento;
	float Monto_Mantenimiento;
public:
	cRegistros();
	~cRegistros();
};

