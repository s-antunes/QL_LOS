#ifndef __SCOORDINATES_H__
#define __SCOORDINATES_H__

struct s_Coordinates {
    int i_X;
    int i_Y;
};

bool operator==(const s_Coordinates& sc1, const s_Coordinates& sc2);
bool operator!=(const s_Coordinates& sc1, const s_Coordinates& sc2);

#endif