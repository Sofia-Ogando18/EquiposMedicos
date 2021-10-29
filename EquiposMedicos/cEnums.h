#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;
enum class Estado {Ocupado,Standby,Fuera_de_Servicio,Mantenimiento};
typedef enum{Almacen, Quirofano, Mantenimiento, Terapia_Intensiva, Guardia}Lugar;
typedef enum{Preventivo, Correctivo, Correctivo_Pendiente}Mantenimientos;

int FuncionRand(int min,int max);

string Estados_to_string(Estado estado);

string Lugar_to_string(Lugar lugar);