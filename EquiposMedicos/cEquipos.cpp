#include "cEquipos.h"

cEquipos::cEquipos(string dimenciones, Estado estado, Lugar lugaractual, float peso, string codigo) :Codigo(codigo), Lugar_Guardado(Lugar::Almacen)
{
	Dimenciones = dimenciones;
	Estado_Equipo = estado;
	Lugar_Actual = lugaractual;
	Peso = peso;
	Descripcion = "Todavia no hay ";
	Costo = 500.0;
	Calendario = new cCalendario();

}

bool cEquipos::Alerta()
{
	if (Lugar_Actual != Lugar_Guardado) {
		cout << "\n El equipo " << Codigo << " no esta en su lugar\n";
		return true;
	}
	else
		return false;
}

cRegistros* cEquipos::MantenimientoPreventivo(cFecha hoy)
{
	cRegistros* nuevo_Registro = NULL;//Lo inicializo en NULL
	if (Calendario->Verificar_Fecha(hoy))//Verifico el que la fecha coincida y elimino la fecha del calendario si esta en el
	{
		nuevo_Registro = new cRegistros(hoy, Mantenimientos::Preventivo, Costo, this->Codigo);//Si hoy es una fecha de mantenimiento, creo un nuevo registro
	}

	return nuevo_Registro;//Si cree un nuevo registro, lo devuelve, si no, retorna NULL (Controla la excepcion en cSistema)
}

cRegistros* cEquipos::MantenimientoCorrectivos(cFecha hoy)
{
	cRegistros* nuevo_Registro = NULL;

	if (this->Estado_Equipo == Estado::Fuera_de_Servicio)//Si esta fuera de servicio crea un nuevo registro y apaga las alarmas
	{
		nuevo_Registro = new cRegistros(hoy, Mantenimientos::Correctivo_Pendiente, Costo, this->Codigo);
		this->ApagarAlarmas();
	}
	return nuevo_Registro;//Retorna el nuevo registro. Si devuelve un NULL, lo controlo en cSistema
}

void cEquipos::Imprimir()
{
	cout << this->to_string() << endl;

}

cEquipos::~cEquipos()
{
	delete Calendario;
}

string cEquipos::to_string()
{
	string aux = "\nDescripcion: " + Descripcion + "\nDimensiones: " + Dimenciones + " \nPeso: " + std::to_string(Peso) + "\n Estado: " +
		Estados_to_string(Estado_Equipo) + "\nPrecio: " + std::to_string(Costo) + "$";
	return aux;
}
void cEquipos::Mover()
{
	if (this->Lugar_Actual == Lugar::Mantenimiento)//Si esta en mantenimiento, no lo muevo
		return;
	unsigned int random = FuncionRand(0, 3);
	switch (random)
	{
	case 0:
		Lugar_Actual = Lugar::Guardia;
		break;
	case 1:
		Lugar_Actual = Lugar::Quirofano;
		break;
	case 2:
		Lugar_Actual = Lugar::Terapia_Intensiva;
		break;
	default:
		Lugar_Actual = Lugar::Almacen;
	}
	return;
}

void cEquipos::Guardar()
{
	Lugar_Actual = Lugar_Guardado;
	return;
}


istream& operator>>(istream& in, cEquipos& E)
{
	float precio;
	string descripcion;
	cout << "Costo de mantenimiento: " << endl;
	in >> precio;
	E.Costo = precio;
	cout << "Descripcion" << endl;
	in >> descripcion;
	E.Descripcion = descripcion;
	return in;
}
