#include "cFecha.h"

cFecha::cFecha()
{
	time_t now = time(0);
	tm* aux = localtime(&now); //obtengo fecha actual
	fecha.tm_mday = aux->tm_mday;
	fecha.tm_mon = aux->tm_mon;
	fecha.tm_year = aux->tm_year;
	fecha.tm_hour = aux->tm_hour;
	fecha.tm_min = aux->tm_min;
	fecha.tm_sec = 0;
	fecha.tm_wday = 0;
	fecha.tm_yday = 0;
	fecha.tm_isdst = 0;

}

cFecha::cFecha(int d, int m, int a, int h, int min)
{
	fecha.tm_hour = h;
	fecha.tm_min = min;
	fecha.tm_sec = 0;
	fecha.tm_mday = d;
	fecha.tm_mon = m - 1;
	fecha.tm_year = a - 1900;
	fecha.tm_wday = 0;
	fecha.tm_yday = 0;
	fecha.tm_isdst = 0;
}

void cFecha::ImprimirFecha()
{
	cout << tm_to_string_Fecha();
}

string cFecha::tm_to_string_Fecha()
{
 return std::to_string(fecha.tm_mday) + " / " + std::to_string(fecha.tm_mon + 1) + " / " + std::to_string(fecha.tm_year + 1900);
}

void cFecha::SetHoy()
{
	time_t now = time(0);
	tm* aux = localtime(&now); //obtengo fecha actual
	fecha.tm_mday = aux->tm_mday;
	fecha.tm_mon = aux->tm_mon;
	fecha.tm_year = aux->tm_year;
	fecha.tm_hour = aux->tm_hour;
	fecha.tm_min = aux->tm_min;
}

cFecha::~cFecha()
{

	
}
