#include <string>
#include <set>
#include <algorithm>

#define MAX_LENGTH_POINT 60
#define MAX_ALPHA_POINT 40

using namespace std;

class SimilarityChecker
{
public:
	void init(string input1, string input2)
	{
		this->input1 = input1;
		this->input2 = input2;
	}

	int getLengthPoint()
	{
		if (isSameLength())
		{
			return MAX_LENGTH_POINT;
		}

		if (isLengthTwiceDiff())
		{
			return 0;
		}

		return getPartialPoint(max(input1.length(), input2.length()), min(input1.length(), input2.length()));
	}

	int getAlphaPoint()
	{
		if (checkValidityForInput() == false) return false;

		set<char> candAlpha;
		getCandidateAlpha(candAlpha);

		return getSameCnt(candAlpha) * MAX_ALPHA_POINT / getTotalCnt(candAlpha);
	}

	string input1;
	string input2;

private:
	bool isSameLength()
	{
		return input1.length() == input2.length();
	}

	bool isLengthTwiceDiff()
	{
		return input1.length() >= input2.length() * 2
			|| input1.length() * 2 <= input2.length();
	}

	int getPartialPoint(int longer, int shorter)
	{
		int gap = longer - shorter;
		return MAX_LENGTH_POINT - gap * MAX_LENGTH_POINT / shorter;
	}

	bool checkValidityForInput()
	{
		for (char alpha : input1)
		{
			if (alpha < 'A' || alpha > 'Z') return false;
		}
		for (char alpha : input2)
		{
			if (alpha < 'A' || alpha > 'Z') return false;
		}
	}

	void getCandidateAlpha(set<char>& candAlpha)
	{
		for (char alpha : input1)
		{
			candAlpha.insert(alpha);
		}
		for (char alpha : input2)
		{
			candAlpha.insert(alpha);
		}
	}

	bool isAlphabetExists(char alpha, string& input)
	{
		for (char ch : input)
		{
			if (alpha == ch)
			{
				return true;
			}
		}
		return false;
	}

	size_t getTotalCnt(set<char> candAlpha)
	{
		return candAlpha.size();
	}

	int getSameCnt(set<char> candAlpha)
	{
		int sameCnt = 0;

		for (char alpha : candAlpha)
		{
			if (isAlphabetExists(alpha, input1) && isAlphabetExists(alpha, input2))
			{
				++sameCnt;
			}
		}

		return sameCnt;
	}
};
