#pragma once
#include "cEquipos.h"
class cMesas_Anestesia :
    public cEquipos
{

    bool Alarma_alta_Frec_Card;
    bool Alarma_baja_Frec_Card;
    int Nivel_suenio;
    int Volumen_flujo;
    float Volumen_flujo_fijado;
public:
    cMesas_Anestesia(string dimenciones, Estado estado, Lugar lugaractual, float peso);
    void EncenderAlarmas();
    ~cMesas_Anestesia();
    void Verificado();
    void Imprimir();
    string to_string();
    void HacerMantenimientoPreventivo();
    void HacerMantenimientoCorrectivo();

};




