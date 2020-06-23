#pragma once
#include <iostream>
#include <fstream>
#include <vector>

#include "CCompas.h"
#include "pch.h"
using namespace std;

/**************************************************************
*
* Reproduction et diffusion interdites.
* Developpé par INSA Rennes - 5 CDTI : ANTUNES / GROLLET / BAILLY
* Projet ROBIOT
*
* SOURCE : CCommande.h
* PRESENTATION : Fichier header de la sélection des arbres à controller.
*
* AUTEUR : ANTUNES / GROLLET / BAILLY
* VERSION CVS : V2
* DATE : 18/06/20
*
***************************************************************/

class CCommande
{


public:
	CCommande() { ; };


	coordonnees getTree(int iNumero);
	int Nbrtree();
	int ReadList();

private:
	vector<coordonnees> tabCoordonnees;
};

