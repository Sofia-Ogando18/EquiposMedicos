#pragma once
#include <string.h>
#include <iostream>
#include "cEnums.h"
#include "cFecha.h"

using namespace std;
class cEquipos
{
	int Codigo;
	float Costo;
	string Descripcion;
	string Dimenciones;
	Estado Estado_Equipo;
	string Lugar_Actual;
	string Lugar_Guardado;
	//string Nombre; no se para que
	float Peso;
	string Dimenciones;// del tipo 3x5
	cFecha** Calendario;//lista de las fechas en la que hay que hacer los mantenimientos
	
public:
	cEquipos();
	void Alerta();
	virtual void MantenimientoPreventivo()=0;
	virtual void MantenimientoCorrectivos() = 0;
	void Verificado();
	~cEquipos();
};

