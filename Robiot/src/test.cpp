#include "pch.h"

TEST(Test_TreeStruct, Equal) {
	coordonnees s = { 1,0 };
	coordonnees s2 = { 1,0 };
	EXPECT_EQ(s, s2);
  EXPECT_TRUE(true);
}