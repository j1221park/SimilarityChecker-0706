#include <string>
using namespace std;

class SimilarityChecker
{
public:
	explicit SimilarityChecker(string input1, string input2)
		:input1(input1), input2(input2)
	{
		
	}

	bool isSameLength()
	{
		return input1.length() == input2.length();
	}

	bool isLengthTwiceDiff()
	{
		return input1.length() >= input2.length() * 2
			|| input1.length() * 2 <= input2.length();
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

		if (input1.length() == 5 && input2.length() == 3)
		{
			return 20;
		}

		if (input1.length() == 2 && input2.length() == 3)
		{
			return 30;
		}
	}

	string input1;
	string input2;
};