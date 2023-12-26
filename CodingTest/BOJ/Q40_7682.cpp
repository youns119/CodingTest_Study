#include <iostream>
#include <vector>

using namespace std;

bool isThree(string s, char c);
bool TTT(string s);

int main()
{
	vector<string> results;

	while (1)
	{
		string s;
		bool isValid;

		cin >> s;
		if (s == "end") break;
		else isValid = TTT(s);

		if (isValid) results.push_back("valid");
		else results.push_back("invalid");
	}

	for (auto r : results)
		cout << r << "\n";

	return 0;
}

bool isThree(string s, char c)
{
	vector<vector<int>> answers =
	{
		{0,3,6}, {1,4,7}, {2,5,8},
		{0,1,2}, {3,4,5}, {6,7,8},
		{0,4,8}, {2,4,6}
	};

	for (auto answer : answers)
	{
		bool bFlag = false;

		for (auto a : answer)
		{
			if (s[a] != c) { bFlag = false;  break; }
			else bFlag = true;
		}

		if (bFlag) return true;
	}

	return false;
}

bool TTT(string s)
{
	int cntX = 0;
	int cntO = 0;
	char c;
	bool isFull;

	for (auto c : s)
	{
		if (c == 'X') cntX++;
		else if (c == 'O') cntO++;
		else continue;
	}

	if (cntX + cntO == s.length()) isFull = true;
	else isFull = false;

	if (cntX == cntO + 1)
	{
		if (isThree(s, 'O')) return false;

		if (isFull) return true;
		else
		{
			if (isThree(s, 'X')) return true;
			else return false;
		}
	}
	else if (cntX == cntO)
	{
		if (isThree(s, 'X')) return false;

		if (isFull) return true;
		else
		{
			if (isThree(s, 'O')) return true;
			else return false;
		}
	}
	else return false;
}