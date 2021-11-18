#pragma once
#include <string.h>
#include <iostream>
#include "cEnums.h"
#include "cCalendario.h"
#include "cListaT.h"
#include "cRegistros.h"

using namespace std;
class cEquipos
{
protected:
	const string Codigo;
	float Costo;
	string Descripcion;
	Estado Estado_Equipo;
	Lugar Lugar_Actual;
	const Lugar Lugar_Guardado;//Puede ser un const
	//string Nombre; que nombre?
	float Peso;
	string Dimenciones;// del tipo 3x5
	cCalendario* Calendario;//lista de las fechas en la que hay que hacer los mantenimientos

public:
	cEquipos(string dimenciones, Estado estado, Lugar lugaractual, float peso, string codigo);
	bool Alerta();// salta si al finalizar el dia el equipo no se encuentra en el lugar donde se guarda

	//La fecha la recibe de cSistema
	cRegistros* MantenimientoPreventivo(cFecha hoy);//Si cumple las condiciones(fecha = calendario[i]), pone el equipo en Mantenimiento y devuelve un registro, si no, retorna un NULL
	cRegistros* MantenimientoCorrectivos(cFecha hoy);//Si cumple las condiciones(fuera de servicio) devuelve un registro(con mantenimiento correctivo_pendiente), si no, retorna un NULL
	virtual void EncenderAlarmas() = 0;//funcion aleatoria que desconpone las maquinas para hacer el mantenimiento y cambia el enum a FueradeServicio
	virtual void Verificado() = 0;//Comprueba que el equipo este funcionando bien. Si no lo hace, setea el estado en Fuera_de_servicio
	virtual void ApagarAlarmas() = 0;//Apaga todas las alarmas
	string getUbicacion() { return Lugar_to_string(Lugar_Actual); };
	void Imprimir();
	~cEquipos();
	string to_string();
	string getID() { return Codigo; };
	void setEstado(Estado estado) { Estado_Equipo = estado; };
	Estado getEstado() { return Estado_Equipo; };
};
