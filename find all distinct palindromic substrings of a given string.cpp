#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

void expand(string str, int low, int high, auto &set)
{
	while (low >= 0 && high < str.length()
			&& str[low] == str[high])
	{
		set.insert(str.substr(low, high - low + 1));
		low--, high++;
	}
}

void allPalindromicSubstrings(string str)
{
	unordered_set<string> set;
	for (int i = 0; i < str.length(); i++)
	{
		expand(str, i, i, set);

	
		expand(str, i, i + 1, set);
	}

	// print all unique palindromic substrings
	for (auto i : set)
		cout << i << " ";
}

int main()
{
	string str = "sadiq";

	allPalindromicSubstrings(str);

	return 0;
}
