#include <string>
#include <set>
#include <algorithm>

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
			return 60;
		}

		if (isLengthTwiceDiff())
		{
			return 0;
		}

		return getPartialPoint(max(input1.length(), input2.length()), min(input1.length(), input2.length()));
	}

	int getAlphaPoint()
	{
		set<char> candAlpha;

		for (char alpha : input1)
		{
			if (alpha < 'A' || alpha > 'Z') return 0;
			candAlpha.insert(alpha);
		}
		for (char alpha : input2)
		{
			if (alpha < 'A' || alpha > 'Z') return 0;
			candAlpha.insert(alpha);
		}

		int totalCnt = candAlpha.size();
		int sameCnt = 0;

		for (char alpha : candAlpha)
		{
			bool found1 = false;
			for (char ch : input1)
			{
				if (alpha == ch)
				{
					found1 = true;
					break;
				}
			}
			bool found2 = false;
			for (char ch : input2)
			{
				if (alpha == ch)
				{
					found2 = true;
					break;
				}
			}
			if (found1 && found2) ++sameCnt;
		}
		return sameCnt * 40 / totalCnt;
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
		return 60 - gap * 60 / shorter;
	}
};