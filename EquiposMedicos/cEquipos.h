#pragma once
#include <string.h>
#include <iostream>
#include "cEnums.h"
#include "cFecha.h"
#include "cListaT.h"

using namespace std;
class cEquipos
{
	const int Codigo;
	float Costo;
	string Descripcion;
	Estado Estado_Equipo;
	string Lugar_Actual;
	static string Lugar_Guardado;
	//string Nombre; que nombre?
	float Peso;
	string Dimenciones;// del tipo 3x5
	cListaT<cFecha>* Calendario;//lista de las fechas en la que hay que hacer los mantenimientos
	
public:
	cEquipos(string dimenciones,Estado estado,string lugaractual,float peso, cListaT<cFecha>* fechas);
	void Alerta();// salta si al finalizar el dia el equipo no se encuentra en el lugar donde se guarda
	virtual void MantenimientoPreventivo()=0;
	virtual void MantenimientoCorrectivos() = 0;
	virtual void EncenderAlarmas() = 0;//funcion alatoria que desconpone las maquinas para hacer el mantenimiento 
	void Verificado();
	string getUbicacion() { return Lugar_Actual; };
	void Imprimir();
	~cEquipos();
};

