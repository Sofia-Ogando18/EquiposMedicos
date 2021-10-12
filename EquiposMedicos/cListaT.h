#pragma once
#define N 50
#include <iostream>
using namespace std;
template <class T>
class cListaT
{
	T** lista;
	unsigned int CA;
	unsigned int TAM;
	void Redimensionalizar();

public:
	cListaT(unsigned int TAM = N);
	~cListaT();

	void Agregar(T* nuevo);
	void Eliminar(string ID);
	//void EliminarItem(string id);
	T* Quitar(string ID);
	T* Buscar_por_ID(unsigned int ID);
	T* Buscar_por_string(string ID);
	T* Buscar_por_pos(unsigned int pos);
	unsigned int getCA();
	int getPos(string ID);

	T* operator[](unsigned int pos);
	void operator+(T* nuevo);

};
template<class T>
inline void cListaT<T>::Redimensionalizar()
{
	TAM = TAM * 2;
	T** aux = new T * [TAM];
	for (int i = 0; i < TAM; i++)
	{
		if (lista[i] != NULL)
		{
			aux[i] = lista[i];
		}
		else
			aux[i] = NULL;
	}
	delete[] lista;
	lista = aux;
}

template<class T>
 inline cListaT<T>::cListaT(unsigned int TAM)
{
	this->TAM = TAM;
	CA = 0;
	lista = new T * [TAM];
	for (int i = 0; i < TAM; i++)
	{
		lista[i] = NULL;
	}
}

template<class T>
inline cListaT<T>::~cListaT()
{
	if (lista != NULL)
	{
		for (int i = 0; i < CA; i++)
		{
			if (lista[i] != NULL)
				delete lista[i];
		}
		delete[] lista;
	}
}

template<class T>
inline void cListaT<T>::Agregar(T* nuevo)
{
	if (nuevo == NULL)
		throw new exception("ERROR: Puntero NULL");
	if (Buscar_por_string(nuevo->getID()) != NULL)//Controlo que el elemento no este en la lista
		throw new exception("Ya existe en la lista");//Que todos los que tengan lista tengan un metodo getID()
	if (this->CA >= TAM)//Si supero la capacidad
		Redimensionalizar();
	//Si llega hasta este punto es porque no esta en la lista y nuevo es distinto de NULL
	lista[CA] = nuevo;
	CA++;
}

template<class T>
inline void cListaT<T>::Eliminar(string ID)
{
	T* aux = NULL;
	try
	{
		aux = Quitar(ID);
	}
	catch (exception* error)
	{
		throw error;
	}
	//Si llego hasta aca no deberia haber problemas
	delete aux;
}

//Corregir
/*template<class T>
inline void ListaT<T>::EliminarItem(string id)
{
	T* aux = NULL;
	aux->Buscar_por_string(id);
	delete aux;

}*/

template<class T>
inline T* cListaT<T>::Quitar(string ID)
{
	/*if (nuevo == NULL)
		throw new exception("ERROR: Puntero NULL");*/
	if (Buscar_por_string(ID) == NULL)//Controlo que el elemento este en la lista
		throw new exception("El elemento no existe en la lista");
	//Si o si van a funcionar
	T* aux = NULL;
	aux = Buscar_por_string(ID);
	int pos = getPos(ID);
	for (int i = pos; i < CA - 1; i++)
	{
		lista[i] = lista[i + 1];
	}
	CA--;

	return aux;
}

template<class T>
inline T* cListaT<T>::Buscar_por_ID(unsigned int ID)
{
	T* aux = NULL;
	for (int i = 0; i < CA; i++)
	{
		if (lista[i]->getID() == ID)//Si lo encuentro, salgo del for
		{
			aux = lista[i];
			break;
		}
	}
	return aux;
}

template<class T>
inline T* cListaT<T>::Buscar_por_string(string ID)
{
	T* aux = NULL;
	for (int i = 0; i < CA; i++)
	{
		if ((lista[i])->getID() == ID)//Si lo encuentro, salgo del for
		{
			aux = lista[i];
			return aux;
			break;
		}
	}
	return NULL;
}

template<class T>
inline T* cListaT<T>::Buscar_por_pos(unsigned int pos)
{
	if (pos >= CA)//Controlo que sea mayor o igual a CA
		return NULL;
	return lista[pos];
}

template<class T>
inline unsigned int cListaT<T>::getCA()
{
	return CA;
}

template<class T>
inline int cListaT<T>::getPos(string ID)
{
	int pos = -1;
	for (int i = 0; i < CA; i++)
	{
		if (lista[i]->getID() == ID)//Si lo encuentro, salgo del for
		{
			pos = i;
			break;
		}
	}
	return pos;
}

template<class T>
inline T* cListaT<T>::operator[](unsigned int pos)
{
	return Buscar_por_pos(pos);
}

template<class T>
inline void cListaT<T>::operator+(T* nuevo)
{
	Agregar(nuevo);
}
