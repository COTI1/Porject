#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;



//�绰�ż����
namespace _tmp
{
	string numLetter[] = { "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
}
void dealLetterCombinations(string &digits, size_t pos, vector<string> &alldata)
{
	static string res = digits;
	if (pos < digits.size())
	{
		for (auto &i : _tmp::numLetter[digits[pos] - '2'])
		{
			res[pos] = i;
			dealLetterCombinations(digits, pos + 1, alldata);
		}
	}
	else
	{
		alldata.push_back(res);
	}
	cout << res << endl;
}

vector<string> LetterCombinations(string digits)
{
	vector<string> res;
	dealLetterCombinations(digits, 0, res);

	return res;
}



int main()
{
	string digits = "23";

	vector<string> data = LetterCombinations(digits);
	return 0;
}