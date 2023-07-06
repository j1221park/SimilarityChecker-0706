#include "pch.h"
#include "../SimilarityChecker/similarity_checker.cpp"

TEST(SimilarityCheckerTest, getLengthPointWhenSameLength) {
	SimilarityChecker cal(string("ASD"), string("DSA"));
	EXPECT_EQ(60, cal.getLengthPoint());
}

TEST(SimilarityCheckerTest, getLengthPointWhenTwiceDiff) {
	SimilarityChecker cal(string("A"), string("BB"));
	EXPECT_EQ(0, cal.getLengthPoint());

	SimilarityChecker cal2(string("AA"), string("B"));
	EXPECT_EQ(0, cal2.getLengthPoint());
}

TEST(SimilarityCheckerTest, getLengthPointPartial) {
	SimilarityChecker cal(string("AAABB"), string("BAA"));
	EXPECT_EQ(20, cal.getLengthPoint());

	SimilarityChecker cal2(string("AA"), string("AAE"));
	EXPECT_EQ(30, cal2.getLengthPoint());
}