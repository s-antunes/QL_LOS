#include "pch.h"

//TEST overload for coordonnees

TEST(TestS_Coordinates, OverloadEqualOperator) {
	coordonnees s = { 0,0 };
	coordonnees s2 = { 0,0 };
	EXPECT_EQ(s, s2);

	s = { 1222,-2 };
	s2 = { 1222,-2 };
	EXPECT_EQ(s, s2);
}

TEST(TestS_Coordinates, OverloadNonEqualOperator) {
	coordonnees s = { 0,0 };
	coordonnees s2 = { 0,0 };
	EXPECT_EQ(s, s2);

	s = { 0,-2 };
	s2 = { 9651,-2 };
	EXPECT_NE(s, s2);
}



//TESTS CArbre

TEST(TestCArbre, CArbreDefaultCreationTest) {
	CArbre arbre;
	coordonnees s = { 0,0 };
	EXPECT_EQ(arbre.getPosition(), s);
}

TEST(TestCArbre, CArbreCreationTest) {
	CArbre arbre(1, 2);
	coordonnees s = { 1,2 };
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









