#pragma once
#include "cEquipos.h"
class cElectrograma :
    public cEquipos
{
    bool Derivaciones_Bipolares;
    bool Derivaciones_Estandar;
    bool Traficacion;

public:
    cElectrograma(string dimenciones, Estado estado, string lugaractual, float peso);
    void MantenimientoPreventivo();
    void MantenimientoCorrectivos();
    void EncenderAlarmas();
     ~cElectrograma();

};

