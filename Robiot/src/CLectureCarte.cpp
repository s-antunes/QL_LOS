#include "pch.h"
#include "CLectureCarte.h"

using namespace std;

CLectureCarte :: CLectureCarte() 
{
  
}




CLectureCarte :: ~CLectureCarte()
{
    
}

void CLectureCarte::CreationTableau(int itaille_collonne, int itaille_ligne)
{
    
}


void CLectureCarte::AfficheCarte()
{
    for (int i = 0; i < carte.size(); i++)
    {
        for (int j = 0; j < carte[i].size(); j++)
        {
            printf("%c", carte[i][j]);
        }
        printf("\n");

    }
}

void CLectureCarte::CreationTableau()
{
}

