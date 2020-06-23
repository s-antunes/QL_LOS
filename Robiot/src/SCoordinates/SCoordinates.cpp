#include "SCoordinates.h"

bool operator==(const s_Coordinates& sc1, const s_Coordinates& sc2)
{
    return (sc1.i_X==sc2.i_X)&&(sc1.i_Y==sc2.i_Y);
}

bool operator!=(const s_Coordinates& sc1, const s_Coordinates& sc2)
{
    return (sc1.i_X!=sc2.i_X)||(sc1.i_Y!=sc2.i_Y);
}
