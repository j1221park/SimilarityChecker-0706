#include "pch.h"
#include "../SimilarityChecker/similarity_checker.cpp"

TEST(SimilarityCheckerTest, getLengthPoint) {
	SimilarityChecker cal(string("ASD"), string("DSA"));

  EXPECT_EQ(60, cal.getLengthPoint());
}