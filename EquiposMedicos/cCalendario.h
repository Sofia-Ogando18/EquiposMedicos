#pragma once
#include "cFecha.h"
#define N 50

class cCalendario
{
	cFecha** Lista;
	unsigned int TAM, CA;
	void Crear_Calendario();//Creo un calendario al azar

public:
	cCalendario(unsigned int TAM = N);
	~cCalendario();
	void Eliminar(cFecha hoy);//Voy a eliminar las fechas a medida que las voy usando
	cFecha* Quitar(cFecha hoy);
	bool Verificar_Fecha(cFecha hoy);
	cFecha* Buscar_Fecha(cFecha hoy);


};

