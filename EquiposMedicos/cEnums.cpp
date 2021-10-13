#include "cEnums.h"

int FuncionRand(int min, int max)
{
    return rand() % (max - min) + min;
}
