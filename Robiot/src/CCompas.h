/**************************************************************
*
* Reproduction et diffusion interdites.
* Developpé par INSA Rennes - 5 CDTI : ANTUNES / GROLLET / BAILLY
* Projet ROBIOT
*
* SOURCE : CCompas.h
* PRESENTATION : Fichier header de la sélection de la géolocalisation du robot
*
* AUTEUR : ANTUNES / GROLLET / BAILLY
* VERSION CVS : V2
* DATE : 18/06/20
*
***************************************************************/
#include <fstream>
#include <string>
#include "pch.h"
using namespace std;

#define IS_FOREST_TALKATIVE true
#define PATH_TO_FOREST "../../input_files/"

typedef enum {
    OBSTACLE,
    TREE,
    WAY
}forest_elts;


struct coordonnees
{
	int x;
	int y;
};


#pragma once
class CCompas
{
    private:
        /* data */
        std::string forest_name;
        std::ifstream* forest_descriptor;
        forest_elts** graph;
        int nbr_lines = 0;
        int nbr_cols = 0;

        std::vector <CArbre*> trees;

        bool instantiateGraph();
        bool buildGraph();

    public:
        CCompas(std::string _forest_name);
        ~CCompas();
        inline forest_elts** getGraph() { return graph; };
        inline std::vector <CArbre*> getTrees() { return trees; };
        void printGraph();
        void printTrees();
};

