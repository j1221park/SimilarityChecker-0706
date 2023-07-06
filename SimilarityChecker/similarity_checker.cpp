#include <string>
using namespace std;

class SimilarityChecker
{
public:
	explicit SimilarityChecker(string input1, string input2)
		:input1(input1), input2(input2)
	{
		
	}

	int getLengthPoint()
	{
		if (input1.length() == input2.length())
			return 60;
		if (input1.length() >= input2.length())
		{
			if (input1.length() >= input2.length() * 2) return 0;
		}
		if (input1.length() <= input2.length())
		{
			if (input1.length() * 2 <= input2.length() * 2) return 0;
		}
	}

	string input1;
	string input2;
};