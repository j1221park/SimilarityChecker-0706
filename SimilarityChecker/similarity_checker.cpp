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
	}

	string input1;
	string input2;
};