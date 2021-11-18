#pragma once
#include "cEquipos.h"
class cRespiradores :
    public cEquipos
{
    static unsigned int Contador;
    bool Alarma_alta_presion;
    bool Alarma_baja_presion;
    bool Alarma_flujo;
    unsigned int Flujo_Configurado;
    unsigned int Flujo_Salida;
public:
    cRespiradores(string dimenciones, Estado estado, Lugar lugaractual, float peso);
    void EncenderAlarmas();
    void ApagarAlarmas();
    void Verificado();
    ~cRespiradores();
    void Imprimir();
    string to_string();
};


