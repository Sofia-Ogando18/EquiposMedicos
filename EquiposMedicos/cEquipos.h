#pragma once
#include <string.h>
#include <iostream>
#include "cEnums.h"
#include "cFecha.h"
#include "cListaT.h"

using namespace std;
class cEquipos
{
	static unsigned int Contador;
	const unsigned int Codigo;
	float Costo;
	string Descripcion;
	Estado Estado_Equipo;
	Lugar Lugar_Actual;
	const Lugar Lugar_Guardado;//Puede ser un const
	//string Nombre; que nombre?
	float Peso;
	string Dimenciones;// del tipo 3x5
	cListaT<cFecha>* Calendario;//lista de las fechas en la que hay que hacer los mantenimientos
	
public:
	cEquipos(string dimenciones,Estado estado,Lugar lugaractual,float peso);//Cambiar lugares de string a un enum
	void Alerta();// salta si al finalizar el dia el equipo no se encuentra en el lugar donde se guarda
	virtual void MantenimientoPreventivo()=0;
	virtual void MantenimientoCorrectivos() = 0;//Cambia el enum a StandBy
	virtual void EncenderAlarmas() = 0;//funcion alatoria que desconpone las maquinas para hacer el mantenimiento y cambia el enum a FueradeServicio
	void Verificado();
	string getUbicacion() { return Lugar_Actual; };
	void Imprimir();
	~cEquipos();
	void operator+(cFecha* nuevo);
};

