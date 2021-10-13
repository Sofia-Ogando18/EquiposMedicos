#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;
enum class Estado {Ocupado,Standby,Fuera_de_Servicio,Mantenimiento};

int FuncionRand(int min,int max);

string Estados_to_string(Estado estado);