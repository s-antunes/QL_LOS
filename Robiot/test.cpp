/***************************************************************
* Copyright (c) ILift - contrat n� 000000001
* Reproduction et diffusion interdites.
* Developpe par Nous
* Projet Robiot
*
* SOURCE        : UserTest.cpp
* PRESENTATION  : Unit Tests for User class
*
* AUTHOR        : rhenry
* VERSION CVS   : V0.9
* DATE          : 27/01/2020
* ***************************************************************/

#include "pch.h"

//TEST overload for s_Coordinates

TEST(TestS_Coordinates, OverloadEqualOperator) {
	s_Coordinates s = {0,0};
	s_Coordinates s2 = {0,0};
	EXPECT_EQ(s, s2);

	s = {1222,-2};
	s2 = { 1222,-2 };
	EXPECT_EQ(s, s2);
}

TEST(TestS_Coordinates, OverloadNonEqualOperator) {
	s_Coordinates s = { 0,0 };
	s_Coordinates s2 = { 0,0 };
	EXPECT_EQ(s, s2);

	s = { 0,-2 };
	s2 = { 9651,-2 };
	EXPECT_NE(s, s2);
}


//TESTS CArbre

TEST(TestCArbre, CArbreDefaultCreationTest) {
	CArbre arbre;
	s_Coordinates s = {0,0};
	EXPECT_EQ(arbre.getPosition(), s);
}

TEST(TestCArbre, CArbreCreationTest) {
	CArbre arbre(1,2);
	s_Coordinates s = { 1,2 };
	EXPECT_EQ(arbre.getPosition(), s);
}

TEST(TestCArbre, CArbreTestMeasureFalse) {
	CArbre arbre(1, 2);
	EXPECT_EQ(arbre.getMeasureStatus(), false);
	EXPECT_NE(arbre.getMeasureStatus(), true);
}

TEST(TestCArbre, CArbreTestMeasureTrue) {
	CArbre arbre(1, 2);
	arbre.setMeasureStatus(true);
	EXPECT_EQ(arbre.getMeasureStatus(), true);
	EXPECT_NE(arbre.getMeasureStatus(), false);
}


