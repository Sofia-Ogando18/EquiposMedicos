#pragma once
#include <string>
#include <stdio.h>
#include "cEquipos.h"
#include "cListaT.h"
#include "cRegistros.h"

using namespace std;
class cSistema
{
	cListaT <cEquipos>* Lista_Equipos;
	cFecha Hoy;
	cListaT<cRegistros>* Lista_Registros;
	float Ganancia_Total;
	float Ganancia_Diaria;

public:
	cSistema(cFecha fecha);
	void Historial();//Imprime todos los registros
	void Imprimir_Registros_Hoy();//Imprime todos los registros preventivos y su costo de ese dia
	void Calcular_Ganacias();//Calcula las ganancias total y diaria
	string RastrearEquipo(cEquipos*equipo);
	void BuscarEquipo(int codigo);//lo busca por codigo y despues lo imprime 
	~cSistema();
	void operator+(cEquipos* nuevo);
	void IniciarDia(cFecha Hoy);//Setea la fecha;
	void TerminarDia();//Imprime la lista de equipos a los que se realizo mantenimiento en la fecha y la ganancia total y diaria, clasificando segun el tipo
	cListaT <cEquipos>* getListaEquipos();
	void Imprimir();
	string to_string();
	void ImprimirAlerta();//Verifica que todos los equipos esten en su lugar de guardado e imprime a los que esten fuera de lugar
	void RealizarMantenimiento_Pendiente();//Revisa los pendientes y si se cumplen las condiciones setea el mantenimiento a Correctivo y suma su monto a las ganancias
	void RealizarMantenimiento_Preventivo();//Realiza los calendarios de mantenimiento de los equipos y si la fecha coincide, setea el 
	//estado del equipo en Mantenimiento, cobra y agrega un registro. Si el equipo esta en Mantenimiento, lo pone en StandBy(Una parte se hace en cEquipo)(Revisa todos los equipos)
	void Agregar_Registro(cEquipos*equipo);//Re
	friend void Descomponer_Random(cSistema* Hospital);//Llama de forma aleatoria a EncenderAlarmas de un equipo
};

// void Descomponer_Random(cSistema* Hospital);//Llama de forma aleatoria a EncenderAlarmas de un equipo
