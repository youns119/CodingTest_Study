#include <iostream>
#include <vector>
#include <functional>
#include <cmath>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int iLesson{}, iBluray{};

	cin >> iLesson >> iBluray;
	vector<int> vecLesson(iLesson);

	int iMaxLen{}, iTotalLen{};

	for (int i = 0; i < iLesson; i++)
	{
		cin >> vecLesson[i];

		iMaxLen = max(iMaxLen, vecLesson[i]);
		iTotalLen += vecLesson[i];
	}

	int iLeft = iMaxLen, iRight = iTotalLen;
	int iResult = iRight;

	while (iLeft <= iRight)
	{
		int iMid = (iLeft + iRight) / 2;
		int iCount{ 1 }, iSum{};

		for (int i = 0; i < iLesson; i++)
		{
			if (iSum + vecLesson[i] > iMid)
			{
				iCount++;
				iSum = 0;
			}

			iSum += vecLesson[i];
		}

		if (iCount <= iBluray)
		{
			iResult = iMid;
			iRight = iMid - 1;
		}
		else iLeft = iMid + 1;
	}

	cout << iResult;

	return 0;
}