#include "cEquipos.h"

cEquipos::cEquipos(string dimenciones, Estado estado, Lugar lugaractual, float peso) :Codigo(Contador++), Lugar_Guardado(Lugar::Almacen)
{
	Dimenciones = dimenciones;
	Estado_Equipo = estado;
	Lugar_Actual = lugaractual;
	Peso = peso;
	Descripcion = "Todavia no hay ";
	Costo = 0.0;
	Calendario = new cListaT<cFecha>(false);//Que no borre las fechas
	
}
unsigned int cEquipos::Contador = 1;

bool cEquipos::Alerta()
{
	if (Lugar_Actual != Lugar_Guardado) {
		cout << "\n El equipo " << std::to_string(Codigo) << " no esta en su lugar";
		return true;
	}
	else
		return false;
}

cRegistros* cEquipos::MantenimientoPreventivo(cEquipos* equipo,cFecha hoy)
{
	cRegistros* nuevo_Registro = NULL;//Lo inicializo en NULL
	for (int i = 0; i < Calendario->getCA(); i++)
	{
		
		if ((*Calendario)[i]->operator==(hoy)==true)
		{
			nuevo_Registro = new cRegistros(equipo,&hoy, Mantenimientos::Preventivo, Costo);//Si hoy es una fecha de mantenimiento, creo un nuevo registro
		}
	}
	return nuevo_Registro;//Si cree un nuevo registro, lo devuelve, si no, retorna NULL (Controla la excepcion en cSistema)
}

cRegistros* cEquipos::MantenimientoCorrectivos(cEquipos* equipo,cFecha hoy)
{
	cRegistros* nuevo_Registro = NULL;
	
	if (this->Estado_Equipo == Estado::Fuera_de_Servicio)//Si esta fuera de servicio crea un nuevo registro
	{
		nuevo_Registro = new cRegistros(equipo,&hoy, Mantenimientos::Correctivo_Pendiente, Costo);
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

void cEquipos::operator+(cFecha* nuevo)
{
	
	*Calendario + nuevo;
}

string cEquipos::to_string()
{
	string aux= "\nDescripcion: " + Descripcion + "\nDimensiones: " + Dimenciones + " \nPeso: " + std::to_string(Peso) + "\n Estado: " +
		Estados_to_string(Estado_Equipo) + "\nPrecio: " + std::to_string(Costo) + "$";
	return aux;
}
