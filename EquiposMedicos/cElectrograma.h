#pragma once
#include "cEquipos.h"
class cElectrograma :
    public cEquipos
{
    bool Derivaciones_Bipolares;
    bool Derivaciones_Estandar;
    bool Traficacion;

public:
    cElectrograma(string dimenciones, Estado estado, Lugar lugaractual, float peso);
    cRegistros* MantenimientoPreventivo();
    cRegistros* MantenimientoCorrectivos();
    void EncenderAlarmas();
    ~cElectrograma();
    void Imprimir();
    string to_string();
};

