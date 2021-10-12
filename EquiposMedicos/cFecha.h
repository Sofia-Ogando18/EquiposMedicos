#pragma once
#include <time.h>
#include <string>
#include <iostream>
using namespace std;
class cFecha
{
	tm fecha;

public:
	//constructor de inicio en la fecha y hora actual
	cFecha();
	//constructor de inicio con dia mes, anio y la hora
	cFecha(int d, int m, int a, int h, int min);

	
	void ImprimirFecha();
	string tm_to_string_Fecha();
	
	void SetHoy();//cambia la fecha a fecha actual

	~cFecha();
};
