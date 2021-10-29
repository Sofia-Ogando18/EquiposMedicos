#pragma once
#include "cEquipos.h"
class cElectrograma :
    public cEquipos
{
    bool Derivaciones_Bipolares;
    bool Derivaciones_Estandar;
    bool Traficacion;

public:
    cElectrograma(string dimenciones, Estado estado, Lugar lugaractual, float peso);//Todos se inician como false, que simboliza que funcionan correctamente
    void EncenderAlarmas();
    ~cElectrograma();
    void Verificado();
    void Imprimir();
    string to_string();
};

