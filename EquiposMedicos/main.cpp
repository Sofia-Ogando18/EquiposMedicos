#include "cSistema.h"
#include "cEquipos.h"
#include "cMesas_Anestesia.h"
#include "cRespiradores.h"
#include "cElectrograma.h"
#include "cEnums.h"
#include <iostream>

using namespace std;

int main()
{
    cSistema* Hospital = new cSistema();//Corregir despues
    cEquipos* equipo = new cMesas_Anestesia("22x23x13", Estado::Standby, "no se", 100.20);
    
}

