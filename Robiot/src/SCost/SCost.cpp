#include "SCost.h"

bool operator==(const s_Cost& sc1, const s_Cost& sc2)
{
    return (sc1.d_time == sc2.d_time) && (sc1.d_consomation == sc2.d_consomation);
}

bool operator!=(const s_Cost& sc1, const s_Cost& sc2)
{
    return (sc1.d_time != sc2.d_time) || (sc1.d_consomation != sc2.d_consomation);
}
