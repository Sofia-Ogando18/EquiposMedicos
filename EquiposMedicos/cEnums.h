#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;
enum class Estado {Ocupado,Standby,Fuera_de_Servicio,Mantenimiento};
enum class Lugar {Almacen, Quirofano, Mantenimiento, Terapia_Intensiva, Guardia};
enum class Mantenimientos{Preventivo, Correctivo, Correctivo_Pendiente};

int FuncionRand(int min,int max);

string Estados_to_string(Estado estado);

string Lugar_to_string(Lugar lugar);

string Mantenimiento_to_string(Mantenimientos mantenimiento);