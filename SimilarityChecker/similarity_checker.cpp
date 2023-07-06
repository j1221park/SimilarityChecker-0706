#include <string>
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