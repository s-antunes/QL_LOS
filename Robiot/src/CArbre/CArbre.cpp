/***************************************************************
* Copyright (c) ILift - contrat n� 000000001
* Reproduction et diffusion interdites.
* Developpe par Nous
* Projet Robiot
*
* SUB-SYSTEME   : user
* SOURCE        : user.cpp
* PRESENTATION  : provide user object
*
* AUTHOR        : rhenry
* VERSION CVS   : V0.9
* DATE          : 22/01/2020
* ***************************************************************/

#include "CArbre.h"

static const char* __cvs_id = "@(#) $Header$";

CArbre::CArbre(const int coordonnee_X, const int coordonne_Y)
{
    this->s_position = { coordonnee_X, coordonne_Y };
    this->f_isMesured = false;
}
/**************************************************************
* METHODE : User::getDestination()
* PRESENTATION : get the reference of the User
* ENTREES :  N/A
*
* SORTIES :  N/A
*
* RETOUR  : position de l'arbre
*
* **************************************************************/
const s_Coordinates& CArbre::getPosition()
{
    return(this->s_position);
}
/**************************************************************
* METHODE : Arbre::setMeasureStatus(bool newStatus)
* PRESENTATION : put the Status of the measure on the tree
* ENTREES :  bool newStatus
*
* SORTIES :  N/A
*
* RETOUR  : N/A
*
* **************************************************************/
void CArbre::setMeasureStatus(bool newStatus)
{
    if (this->f_isMesured == false) {
        this->f_isMesured = newStatus;
    }
}
/**************************************************************
* METHODE : Arbre::getMeasureStatus()
* PRESENTATION : get the Status of the measure on Tree
* ENTREES :  N/A
*
* SORTIES :  N/A
*
* RETOUR  : Current State of the Measure done on the tree
*
* **************************************************************/
bool CArbre::getMeasureStatus()
{
    return this->f_isMesured;
}
