#ifndef SCOORDINATES_H
#define SCOORDINATES_H

struct s_Coordinates {
    int i_X;
    int i_Y;
};

bool operator==(const s_Coordinates& sc1, const s_Coordinates& sc2);
bool operator!=(const s_Coordinates& sc1, const s_Coordinates& sc2);

#endif
