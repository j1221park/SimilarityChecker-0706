#include "pch.h"
#include "../SimilarityChecker/similarity_checker.cpp"

class SimilarityCheckerFixture : public testing::Test
{
public:
	SimilarityChecker cal;
};

TEST_F(SimilarityCheckerFixture, getLengthPointWhenSameLength) {
	cal.init(string("ASD"), string("DSA"));
	EXPECT_EQ(60, cal.getLengthPoint());
}

TEST_F(SimilarityCheckerFixture, getLengthPointWhenTwiceDiff) {
	cal.init(string("A"), string("BB"));
	EXPECT_EQ(0, cal.getLengthPoint());

	cal.init(string("AA"), string("B"));
	EXPECT_EQ(0, cal.getLengthPoint());
}

TEST_F(SimilarityCheckerFixture, getLengthPointPartial) {
	cal.init(string("AAABB"), string("BAA"));
	EXPECT_EQ(20, cal.getLengthPoint());

	cal.init(string("AA"), string("AAE"));
	EXPECT_EQ(30, cal.getLengthPoint());
}