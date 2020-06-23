#ifndef ARBRE_H

#define ARBRE_H
/**************************************************************
*
* Reproduction et diffusion interdites.
* Developpé par INSA Rennes - 5 CDTI : ANTUNES / GROLLET / BAILLY
* Projet ROBIOT
*
* SOURCE : CArbre.cpp
* PRESENTATION : Fichier header de la sélection de la gestion des arbres
*
* AUTEUR : ANTUNES / GROLLET / BAILLY
* VERSION CVS : V2
* DATE : 23/06/20
*
***************************************************************/


#include <stdio.h>
#include "pch.h"

class CArbre
{
private:
    /* data */
    coordonnees s_position;
    bool f_isMesured;

public:
    CArbre(const int coordonnee_X=0, const int coordonnee_Y=0);
    const coordonnees& getPosition();
    bool getMeasureStatus();
    void setMeasureStatus(const bool newState);
};

#endif
/*****************************************************************/
