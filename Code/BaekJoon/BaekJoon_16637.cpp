#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <cmath>
#include <limits.h>

using namespace std;

int Cal(int iNum1, int iNum2, char chOp);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int iCnt{}, iResult{ INT_MIN };
	vector<char> vecOp{};
	vector<int> vecNum{};
	string strEq{};

	cin >> iCnt;
	cin >> strEq;

	for (char chEq : strEq)
	{
		if (chEq >= '0' && chEq <= '9')
			vecNum.push_back(chEq - 48);
		else vecOp.push_back(chEq);
	}

	function<void(int, int)> DFS = [&](int iIndex, int iCurr)
		{
			if (iIndex >= vecNum.size() - 1)
			{
				iResult = max(iResult, iCurr);
				return;
			}

			int iSum = Cal(iCurr, vecNum[iIndex + 1], vecOp[iIndex]);
			DFS(iIndex + 1, iSum);

			if (iIndex + 2 <= vecNum.size() - 1)
			{
				int iSum = Cal(iCurr, Cal(vecNum[iIndex + 1], vecNum[iIndex + 2], vecOp[iIndex + 1]), vecOp[iIndex]);
				DFS(iIndex + 2, iSum);
			}
		};

	DFS(0, vecNum[0]);

	cout << iResult;

	return 0;
}

int Cal(int iNum1, int iNum2, char chOp)
{
	switch (chOp)
	{
	case '+' :
		return iNum1 + iNum2;
	case '-' :
		return iNum1 - iNum2;
	case '*' :
		return iNum1 * iNum2;
	default :
		return 0;
	}
}