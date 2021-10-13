#include "cRegistros.h"

cRegistros::cRegistros(cFecha* fecha_mant, bool mantenimiento, float monto)
{
	Fecha_mantenimiento = fecha_mant;
	Mantenimimento = mantenimiento;
	Monto_Mantenimiento = monto;
}

cRegistros::~cRegistros()
{
}
