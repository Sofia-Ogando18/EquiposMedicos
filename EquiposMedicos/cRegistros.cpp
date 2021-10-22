#include "cRegistros.h"

cRegistros::cRegistros(cFecha* fecha_mant, Mantenimiento mantenimiento, float monto)
{
	Fecha_mantenimiento = fecha_mant;
	tipo_Mantenimimento = mantenimiento;
	Monto_Mantenimiento = monto;
}

cRegistros::~cRegistros()
{
}
