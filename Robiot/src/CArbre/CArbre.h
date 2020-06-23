#ifndef ARBRE_H
#define ARBRE_H
/***************************************************************
* Copyright (c) ILift - contrat n� 000000001
* Reproduction et diffusion interdites.
* Developpe par Nous
* Projet Lift
*
* SUB-SYSTEME   : arbre
* SOURCE        : arbre.h
* PRESENTATION  : provide user object
*
* AUTHOR        : rhenry
* VERSION CVS   : V0.9
* DATE          : 18/06/2020
* ***************************************************************/

/************************************************************** * CLASSE : Arbre
* PRESENTATION : <description de la classe et de sa fonction> *
 * METHODES PUBLIQUES :
* getCurrent()
* <Methode2>
* <Methode3>
* <Methode4>
: <description rapide de la methode 1>
: <description rapide de la methode 2>
: <description rapide de la methode 3>
: <description rapide de la methode 4>
*
* OBSERVATIONS : **************************************************************/

#include "../SCoordinates/SCoordinates.h"
#include <stdio.h>

class CArbre
{
private:
    /* data */
    s_Coordinates s_position;
    bool f_isMesured;

public:
    CArbre(const int coordonnee_X=0, const int coordonnee_Y=0);
    const s_Coordinates& getPosition();
    bool getMeasureStatus();
    void setMeasureStatus(const bool newState);
};

#endif
/*****************************************************************/
