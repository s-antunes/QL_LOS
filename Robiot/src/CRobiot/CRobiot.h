#ifndef __CROBIOT_H__
#define __CROBIOT_H__
/***************************************************************
* Copyright (c) ILift - contrat n� 000000001
* Reproduction et diffusion interdites.
* Developpe par Nous
* Projet ROBIOT
*
* SUB-SYSTEME   : CRobiot
* SOURCE        : CRobiot.h
* PRESENTATION  : provide user object
*
* AUTHOR        : rhenry
* VERSION CVS   : V0.9
* DATE          : 19/06/2020
* ***************************************************************/

/************************************************************** * CLASSE : CRobiot
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

#include <stdio.h>
#include "../CArbre/CArbre.h"
#include "../CArbre/CArbre.h"
#include "../SCost/SCost.h"
#include <vector>
#include <iostream>

class CRobiot
{
private:
    /* data */
    s_Coordinates s_position;
    std::vector <s_Coordinates> TreeMeasured;

public:
    CRobiot(const int coordonnee_X = 0, const int coordonnee_Y = 0);
    const s_Coordinates& getPosition();
    s_Cost getMeasureOnTree(CArbre * TreeToMeasure);
    s_Cost GoTo(s_Coordinates NewPosition);
};
#endif
/*****************************************************************/