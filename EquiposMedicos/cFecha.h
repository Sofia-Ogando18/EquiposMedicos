#pragma once
#include <time.h>
#include <string>
#include <iostream>
class cCalendario;
using namespace std;

class cFecha
{
	tm fecha;
	friend cCalendario;
public:
	//constructor de inicio en la fecha y hora actual
	cFecha();
	//constructor de inicio con dia mes, anio y la hora
	cFecha(int d, int m, int a, int h, int min);


	void ImprimirFecha();
	string tm_to_string_Fecha();

	void SetHoy();//cambia la fecha a fecha actual
	void setFecha(int dia, int mes, int anio);
	void Cambio_Fecha();
	int getMes();

	bool operator==(cFecha fecha);//Completar despues
	bool operator!=(cFecha fecha_);
	cFecha getFecha();

	bool operator>(cFecha fecha);
	bool operator<(cFecha fecha);

	cFecha& operator=(cFecha& F);
	cFecha operator++();

	~cFecha();
};
