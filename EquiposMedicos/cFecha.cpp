#define _CRT_SECURE_NO_WARNINGS
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

void cFecha::setFecha(int dia, int mes, int anio)
{
	fecha.tm_year = anio;
	fecha.tm_mday = dia;
	fecha.tm_mon = mes;
}

void cFecha::Cambio_Fecha()
{
	if (this->fecha.tm_mday == 31 && this->fecha.tm_mon == 12)//Cambio de año
	{
		this->fecha.tm_year++;
		this->fecha.tm_mday = 1;
		this->fecha.tm_mon = 1;
		return;
	}
	if (this->fecha.tm_mon == 1 || this->fecha.tm_mon == 3 || this->fecha.tm_mon == 5
		|| this->fecha.tm_mon == 7 || this->fecha.tm_mon == 8 || this->fecha.tm_mon == 10)
	{
		if (this->fecha.tm_mday == 31)
		{
			this->fecha.tm_mday = 1;
			this->fecha.tm_mon++;//Cambio de mes y lo reseteo
			return;
		}
	}
	if (this->fecha.tm_mon == 4 || this->fecha.tm_mon == 6 || this->fecha.tm_mon == 9 || this->fecha.tm_mon == 11)
	{
		if (this->fecha.tm_mday == 30)
		{
			this->fecha.tm_mday = 1;
			this->fecha.tm_mon++;//Cambio de mes y lo reseteo
			return;
		}
	}
	if (this->fecha.tm_year % 4 == 0 && this->fecha.tm_mon == 2)//Año bisiesto
	{
		if (this->fecha.tm_mday == 29)
		{
			this->fecha.tm_mday = 1;
			this->fecha.tm_mon++;//Cambio de mes y lo reseteo
			return;
		}
	}
	else if (this->fecha.tm_year % 4 != 0 && this->fecha.tm_mon == 2)
	{
		if (this->fecha.tm_mday == 28)
		{
			this->fecha.tm_mday = 1;
			this->fecha.tm_mon++;//Cambio de mes y lo reseteo
			return;
		}
	}
	this->fecha.tm_mday++;//Si es un dia entre mes, solo sumo.
	return;
}

int cFecha::getMes()
{
	return fecha.tm_mon;
}

bool cFecha::operator==(cFecha fecha)
{
	if (this->fecha.tm_year == fecha.fecha.tm_year)
	{
		if (this->fecha.tm_mon == fecha.fecha.tm_mon)
		{
			if (this->fecha.tm_mday == fecha.fecha.tm_mday)
				return true;//Si es el mismo año, mes y dia, retorno true
		}
	}
	return false;//Si no cumplió alguna condición, retorna false
}

cFecha cFecha::getFecha()
{
	return *this;
}

cFecha::~cFecha()
{

}


bool cFecha::operator!=(cFecha fecha_) 
{
	return !((((*this) == fecha_)));
};

bool cFecha::operator>(cFecha fecha)
{
	if (this->fecha.tm_year > fecha.fecha.tm_year)//El año es mayor
	{
		return true;
	}
	else if (this->fecha.tm_year == fecha.fecha.tm_year)
	{
		if (this->fecha.tm_mon > fecha.fecha.tm_mon)//El mes es mayor
		{
			return true;
		}
		else if (this->fecha.tm_mon == fecha.fecha.tm_mon)
		{
			if (this->fecha.tm_mday > fecha.fecha.tm_mday)//El dia es mayor
				return true;
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;
}

bool cFecha::operator<(cFecha fecha)
{
	if (this->fecha.tm_year < fecha.fecha.tm_year)//El año es menor
	{
		return true;
	}
	else if (this->fecha.tm_year == fecha.fecha.tm_year)
	{
		if (this->fecha.tm_mon < fecha.fecha.tm_mon)//El mes es menor
		{
			return true;
		}
		else if (this->fecha.tm_mon == fecha.fecha.tm_mon)
		{
			if (this->fecha.tm_mday < fecha.fecha.tm_mday)//El dia es menor
				return true;
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;
}

cFecha& cFecha::operator=(cFecha& F)
{
	fecha = F.fecha;
	return F;
}

cFecha cFecha::operator++()
{
	this->Cambio_Fecha();
	return *this;
}
