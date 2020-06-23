#ifndef SCOST_H
#define SCOST_H

struct s_Cost {
    double d_time; //in second
    double d_consomation; // in Watt/s
};

bool operator==(const s_Cost& sc1, const s_Cost& sc2);
bool operator!=(const s_Cost& sc1, const s_Cost& sc2);

#endif
