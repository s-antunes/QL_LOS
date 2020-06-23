/**************************************************************
*
* Reproduction et diffusion interdites.
* Developpé par INSA Rennes - 5 CDTI : ANTUNES / GROLLET / BAILLY
* Projet ROBIOT
*
* SOURCE : CArbre.cpp
* PRESENTATION : Fichiersource de la sélection de la gestion des arbres
*
* AUTEUR : ANTUNES / GROLLET / BAILLY
* VERSION CVS : V2
* DATE : 23/06/20
*
***************************************************************/

#include "CArbre.h"
#include "pch.h"

static const char* __cvs_id = "@(#) $Header$";

CArbre::CArbre(const int coordonnee_X, const int coordonne_Y)
{
    this->s_position = { coordonnee_X, coordonne_Y };
    this->f_isMesured = false;
}
/**************************************************************
* METHODE : User::getDestination()
* PRESENTATION : Retourne la position de l'arbre
* ENTREES :  ----------------------------------------------------
*
* SORTIES :  ----------------------------------------------------
*
* RETOUR  : position de l'arbre
*
* **************************************************************/
const coordonnees& CArbre::getPosition()
{
    return(this->s_position);
}
/**************************************************************
* METHODE : Arbre::setMeasureStatus(bool newStatus)
* PRESENTATION : put the Status of the measure on the tree
* ENTREES :  bool newStatus
*
* SORTIES :  ----------------------------------------------------
*
* RETOUR  : ----------------------------------------------------
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
* PRESENTATION : donne le statut de la mesure
* ENTREES :  ----------------------------------------------------
*
* SORTIES :  ----------------------------------------------------
*
* RETOUR  : Etat courrant de la mesure
*
* **************************************************************/
bool CArbre::getMeasureStatus()
{
    return this->f_isMesured;
}