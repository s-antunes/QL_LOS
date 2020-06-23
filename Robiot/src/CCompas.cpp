#include "pch.h"
#include "CCompas.h"


/**************************************************************
*
* Reproduction et diffusion interdites.
* Developpé par INSA Rennes - 5 CDTI : ANTUNES / GROLLET / BAILLY
* Projet ROBIOT
*
* SOURCE : CCommande.cpp
* PRESENTATION : Fichier source de la sélection de la géolocalisation du robot
*
* AUTEUR : ANTUNES / GROLLET / BAILLY
* VERSION CVS : V2
* DATE : 18/06/20
*
***************************************************************/

#include "CCompas.h"

CCompas::CCompas(std::string _forest_name)
{
	forest_name = _forest_name;
	if (!buildGraph())
	{
		if (IS_FOREST_TALKATIVE)
			std::cerr << "Error while building Graph : stopping constructor" << '\n';
	}
	trees = *new std::vector<CArbre*>;
}

CCompas::~CCompas()
{
	free(graph);
	for (std::vector<CArbre*>::iterator it = trees.begin(); it != trees.end(); ++it)
	{
		free(*it);
	}
	free(&trees);
	if (forest_descriptor->bad())
		forest_descriptor->close();
	free(forest_descriptor);
}

/**************************************************************
* METHODE : CCompas::instantiateGraph()
* PRESENTATION : Instancie et alloue la mémoire necessaire pour la carte
* ENTREES :  ----------------------------------------------------
*
* SORTIES :  ----------------------------------------------------
*
* RETOUR  : 1 s'il n'y a pas d'erreur
* **************************************************************/

bool CCompas::instantiateGraph()
{
	char readch;
	int col_counter = 0;
	bool firstline = true;
	forest_descriptor->seekg(forest_descriptor->beg);
	forest_descriptor->get(readch);
	while (readch != EOF)
	{
		if (readch == '\r' || readch == '\n')
		{
			//Cross '\n' by a call to .get() method if the file has been edited under Windows
			if (forest_descriptor->get() != '\n')
			{
				//Manage case "\r" or "\nX" with X any character other than
				forest_descriptor->seekg(forest_descriptor->cur - 1);
			}
			nbr_lines++;
			//Check consistency of the number of columns in each line
			if (col_counter != nbr_cols)
			{
				return false;
			}
			//Validate nbr_cols and uncheck firstline
			firstline = false;
			//Reset col_counter
			col_counter = 0;
		}

		else
		{
			if (firstline)
			{
				nbr_cols++;
			}
			col_counter++;
		}
		forest_descriptor->get(readch);
	}

	graph = (forest_elts**)malloc(nbr_cols * nbr_lines);
	return true;
}

/**************************************************************
* METHODE : CCompas::instantiateGraph()
* PRESENTATION : Construit la carte 
* ENTREES :  ----------------------------------------------------
*
* SORTIES :  ----------------------------------------------------
*
* RETOUR  : 1 s'il n'y a pas d'erreur
* **************************************************************/


bool CCompas::buildGraph()
{
	std::string the_way_to_the_forest = PATH_TO_FOREST + forest_name;
	forest_descriptor = new std::ifstream(the_way_to_the_forest, std::ifstream::in);
	if (forest_descriptor->good())
	{
		if (instantiateGraph())
		{
			forest_descriptor->seekg(forest_descriptor->beg);
			for (int linecounter = 0; linecounter < nbr_lines; linecounter++)
			{
				for (int colcounter = 0; colcounter < nbr_cols + 1; colcounter++)
				{
					switch (forest_descriptor->get())
					{
					case 'X':
						graph[linecounter][colcounter] = OBSTACLE;
						break;
					case '|':
						graph[linecounter][colcounter] = OBSTACLE;
						break;
					case '-':
						graph[linecounter][colcounter] = OBSTACLE;
						break;
					case 'O':
						graph[linecounter][colcounter] = TREE;
						trees.push_back(new CArbre(linecounter, colcounter));
						break;
					case ' ':
						graph[linecounter][colcounter] = WAY;
						break;
					case '\n':
					case '\r':
						//Cross '\n' by a call to .get() method if the file has been edited under Windows
						if (forest_descriptor->get() != '\n')
						{
							//Manage case "\r" or "\nX" with X any character other than
							forest_descriptor->seekg(forest_descriptor->cur - 1);
						}
						forest_descriptor->get(); //Cross '\n'
						if (colcounter != nbr_cols)
							return false; //Should be at the end of the line
						break;
					default:
						return false;
						break;
					}
				}
			}
		}
		else
		{
			if (IS_FOREST_TALKATIVE)
				std::cerr << "Error while reading forest text file : wrong file format" << '\n';
			return false;
		}
	}

	else
	{
		if (IS_FOREST_TALKATIVE)
			std::cerr << "Error while opening forest text file at location " << the_way_to_the_forest << '\n';
		return false;
	}

	return true;
}


/**************************************************************
* METHODE : void CCompas::printGraph()
* PRESENTATION : Affiche la carte
* ENTREES :  ----------------------------------------------------
*
* SORTIES :  ----------------------------------------------------
*
* RETOUR  :  ----------------------------------------------------
* **************************************************************/

void CCompas::printGraph()
{
	if (nbr_cols == 0 || nbr_lines == 0)
	{
		std::cout << "The Graph is empty";
		return;
	}

	else
	{
		for (int linecounter = 0; linecounter < nbr_lines; linecounter++)
		{
			for (int colcounter = 0; colcounter < nbr_cols + 1; colcounter++)
			{
				std::cout << graph[linecounter][colcounter];
			}
			std::cout << '\n';
		}
	}
}

/*************************************************************
*METHODE : CCompas::printTrees()
* PRESENTATION : Construit les arbres
* ENTREES : ----------------------------------------------------
*
* SORTIES : ----------------------------------------------------
*
* RETOUR :  ----------------------------------------------------
* **************************************************************/

void CCompas::printTrees()
{
	for (std::vector<CArbre*>::iterator it = trees.begin(); it != trees.end(); ++it)
	{
		std::cout << "Tree at coordinates" << (*it)->getPosition().x << ", " << (*it)->getPosition().y;
		if ((*it)->getMeasureStatus())
			std::cout << " : MEASURED";
		else
			std::cout << " : NOT MEASURED";
		std::cout << '\n';
	}
}