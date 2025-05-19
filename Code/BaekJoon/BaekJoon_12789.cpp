#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> vecLine;
	stack<int> stLine;
	int iCount{};

	cin >> iCount;

	for (int i = 0; i < iCount; i++)
	{
		int iNum{};

		cin >> iNum;
		vecLine.push_back(iNum);
	}

	int iCurr{ 1 };
	for (int i = 0; i < vecLine.size(); i++)
	{
		if (vecLine[i] == iCurr)
			iCurr++;
		else
			stLine.push(vecLine[i]);

		while (!stLine.empty())
		{
			if (stLine.top() == iCurr)
			{
				stLine.pop();
				iCurr++;
			}
			else break;
		}
	}

	if (!stLine.empty()) cout << "Sad";
	else cout << "Nice";

	return 0;
}