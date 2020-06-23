#ifndef CFOREST_H
#define CFOREST_H
/***************************************************************
* Copyright (c) ILift - contrat n� 000000001
* Reproduction et diffusion interdites.
* Developpe par Nous
* Projet Lift
*
* SUB-SYSTEME   : foret
* SOURCE        : CForet.h
* PRESENTATION  : provide user object
*
* AUTHOR        : vcochard
* VERSION CVS   : V0.9
* DATE          : 22/06/2020
* ***************************************************************/

/************************************************************** * CLASSE : Arbre
* PRESENTATION : <description de la classe et de sa fonction> *
* METHODES PUBLIQUES :
* forest_elts** getGraph(void)
* std::vector<CArbre> getTrees()
* void printGraph();
* void printTrees();
*
* OBSERVATIONS : **************************************************************/

#include <fstream>
#include <string>
#include "../../pch.h"
#include "../CArbre/CArbre.h"

#define IS_FOREST_TALKATIVE true
#define PATH_TO_FOREST "../../input_files/"

typedef enum {
    OBSTACLE,
    TREE,
    WAY
}forest_elts;

class CForet
{
private:
    /* data */
    std::string forest_name;
    std::ifstream* forest_descriptor;
    forest_elts** graph;
    int nbr_lines = 0;
    int nbr_cols = 0;

    std::vector<CArbre*> trees;
    
    bool instantiateGraph();
    bool buildGraph();

public:
    CForet(std::string _forest_name);
    ~CForet();
    inline forest_elts** getGraph() { return graph; };
    inline std::vector<CArbre*> getTrees() { return trees; };
    void printGraph();
    void printTrees();
};

#endif //CFOREST_H