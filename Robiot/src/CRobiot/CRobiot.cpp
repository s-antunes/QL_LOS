/***************************************************************
* Copyright (c) ILift - contrat n� 000000001
* Reproduction et diffusion interdites.
* Developpe par Nous
* Projet Robiot
*
* SUB-SYSTEME   : CRobiot
* SOURCE        : CRobiot.cpp
* PRESENTATION  : provide Robiot object
*
* AUTHOR        : rhenry
* VERSION CVS   : V0.9
* DATE          : 22/01/2020
* ***************************************************************/

#include "CRobiot.h"

CRobiot::CRobiot(const int coordonnee_X, const int coordonne_Y)
{
    this->s_position = { coordonnee_X, coordonne_Y };
}
/**************************************************************
* METHODE : CRobiot::getPositon()
* PRESENTATION : get the position of the Robot
* ENTREES :  N/A
*
* SORTIES :  N/A
*
* RETOUR  : position of the Robot
*
* **************************************************************/
const s_Coordinates& CRobiot::getPosition()
{
    return(this->s_position);
}
/**************************************************************
* METHODE : CRobiot::getMeasureOnTree()
* PRESENTATION : get the position of the Robot
* ENTREES :  N/A
*
* SORTIES :  N/A
*
* RETOUR  : struct S_Cost with the values : 5 , 2.5W 
*
* **************************************************************/
s_Cost CRobiot::getMeasureOnTree(CArbre * TreeToMeasure)
{
    bool NeedMeasure = true;
    s_Cost MeasureOnTree = { 0,0 };
    struct s_Coordinates position_Tree = TreeToMeasure->getPosition();
    int X = 0;
    int Y = 0;
    if (this->s_position == position_Tree) {
        for (int i=0; i < this->TreeMeasured.size(); i++) {
            if (TreeToMeasure->getPosition() == TreeMeasured[i]){
                NeedMeasure = false;
                printf("\033[0;33m"); //Set the text to the color red
                printf("Warning");
                printf("\033[0m"); //Resets the text to default color
                printf(" : The Robot already make the measure on the tree on position X :%d Y : %d \n",position_Tree.i_X,position_Tree.i_Y);
            }
        }
        if (NeedMeasure) {
            MeasureOnTree = { 5.0 * 60.0,30.0 * 5.0 * 60.0 };
            TreeToMeasure->setMeasureStatus(true);
            this->TreeMeasured.push_back(TreeToMeasure->getPosition());
        }
    }
    else {
        printf("\033[0; 31m"); //Set the text to the color red
        printf("Error");
        printf("\033[0m"); //Resets the text to default color
        printf(" : The Robot is not on the position of the tree");
    }
    return MeasureOnTree;
}
/**************************************************************
* METHODE : CRobiot::GoTo()
* PRESENTATION : get the position of the Robot
* ENTREES :  N/A
*
* SORTIES :  N/A
*
* RETOUR  : struct S_Cost with the right values
*
* **************************************************************/
s_Cost CRobiot::GoTo(s_Coordinates NewPosition)
{
    int abs_X = abs(NewPosition.i_X - this->s_position.i_X);
    int abs_Y = abs(NewPosition.i_Y - this->s_position.i_Y);
    s_Cost CostReturn = { {0},0.0 };

    if ((abs_X == 1 && abs_Y == 0) || (abs_X == 0 && abs_Y == 1))
    {
        CostReturn.d_time = 23.8095238095;
        CostReturn.d_consomation = 23.8095238095*14;
    }
    else {
        if (abs_X == 1 && abs_Y == 1) {
            CostReturn.d_time = 33.671751485;
            CostReturn.d_consomation = 33.671751485 * 14;
            this->TreeMeasured.push_back(NewPosition);
        }
        else {
            if (abs_X == 0 && abs_Y == 0) {
                printf("\033[0; 31m"); //Set the text to the color red
                printf("Error");
                printf("\033[0m"); //Resets the text to default color
                printf(" : the Destination is the same as the position of the Robot \n");
            }
            else {
                printf("\033[0; 31m"); //Set the text to the color red
                printf("Error");
                printf("\033[0m"); //Resets the text to default color
                printf(" : Robot Destination unreatchable\n");
            }
            CostReturn = { 0,0 };
        }
    }
    return CostReturn;
}

