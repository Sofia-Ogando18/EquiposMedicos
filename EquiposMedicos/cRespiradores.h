#pragma once
#include "cEquipos.h"
class cRespiradores :
    public cEquipos
{

    bool Alarma_alta_presion;
    bool Alarma_baja_presion;
    bool Alarma_flujo;
    unsigned int Flujo_Configurado;
public:
    cRespiradores();
    void MantenimientoPreventivo();
    void MantenimientoCorrectivos();
    ~cRespiradores();

};

