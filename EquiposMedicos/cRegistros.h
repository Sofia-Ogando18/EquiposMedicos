#pragma once
#include "cFecha.h"
#include "cEnums.h"
#include "cEquipos.h"
#include "cElectrograma.h"
#include "cRespiradores.h"
#include "cMesas_Anestesia.h"
class cRegistros //lista de los mantenimientos y sus costos 
{
	cEquipos* equipo;
	cFecha* Fecha_mantenimiento;
	Mantenimientos tipo_Mantenimimento;
	float Monto_Mantenimiento;
public:
	cRegistros(cEquipos*equipo,cFecha* fecha_mant,Mantenimientos mantenimiento, float monto);
	~cRegistros();
	void Imprimir();
	string to_string();
	string tipo_de_equipo();
	cFecha getFecha() { return *Fecha_mantenimiento; };
	Mantenimientos getMantenimiento() { return tipo_Mantenimimento; };
	float getMonto() { return Monto_Mantenimiento; };
	void setCorrectivo() { tipo_Mantenimimento = Mantenimientos::Correctivo; };//Setea el mantenimiento en correctivo
};

