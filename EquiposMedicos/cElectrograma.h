#pragma once
#include "cEquipos.h"
class cElectrograma :
    public cEquipos
{
    bool Derivaciones_Bipolares;
    bool Derivaciones_Estandar;
    bool Traficacion;

public:
    cElectrograma();
    void MantenimientoPreventivo();
    void MantenimientoCorrectivos();
     ~cElectrograma();

};

