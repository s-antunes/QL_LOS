#include "pch.h"

/**************************************************************
*
* Reproduction et diffusion interdites.
* Developpé par INSA Rennes - 5 CDTI : ANTUNES / GROLLET / BAILLY
* Projet ROBIOT
*
* SOURCE : CCommande.cpp
* PRESENTATION : Fichier source de la sélection des arbres à controller.
*
* AUTEUR : ANTUNES / GROLLET / BAILLY
* VERSION CVS : V2
* DATE : 18/06/20
*
***************************************************************/

/**************************************************************
* METHODE : CCommande::getCoordonnees(int iNumero)
* PRESENTATION : Récupération d'un couple de coordonnées dans le tableau tabCoordonees.
*
* ENTREE :
*	int iNumero : indice du tableau correspondant au couple de coordonnées que l'on veut récupérer.
* 
* SORTIE :
* 	coordonnees : couple de coordonnées que l'on veut récupérer.
***************************************************************/

coordonnees CCommande::getTree(int iNumero)
{
	if (iNumero < tabCoordonnees.size()) {
		return tabCoordonnees[iNumero];
	}
} /* getCoordonnees */

int CCommande::Nbrtree()
{
	return tabCoordonnees.size();
}

/**************************************************************
* METHODE : CCommande::lireTableau()
* PRESENTATION : Remplissage du tableau tabCoordonnees en fonction des coordonnées du fichier LISTE DE CONTROLE.
*
* SORTIE :
* 	int : retourne 0 en cas de succès.
***************************************************************/
int CCommande::ReadList()
{
	ifstream file;
	file.open("");
	if (file) {
		do{
			for (int i = 0; i < tabCoordonnees.size(); i++) {
				coordonnees point;
				file >> point.x;
				file >> point.y;
				tabCoordonnees.push_back(point);
			}
		}while(!file.eof());
	}
	else {
		cout << "Probleme ouverture du fichier." << endl;
		return (1);
	}
	file.close();
	return (0);
} /* LireTableau */


