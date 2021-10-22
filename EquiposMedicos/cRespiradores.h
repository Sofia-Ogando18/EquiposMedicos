#pragma once
#include "cEquipos.h"
class cRespiradores :
    public cEquipos
{

    bool Alarma_alta_presion;
    bool Alarma_baja_presion;
    bool Alarma_flujo;
    unsigned int Flujo_Configurado;
    unsigned int Flujo_Salida;
public:
    cRespiradores(string dimenciones, Estado estado, Lugar lugaractual, float peso);
    cRegistros* MantenimientoPreventivo();
    cRegistros* MantenimientoCorrectivos();
    void EncenderAlarmas();
    ~cRespiradores();
    void Imprimir();
    string to_string();
};

