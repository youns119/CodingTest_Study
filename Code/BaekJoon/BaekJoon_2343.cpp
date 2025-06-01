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

	for (int i = 0; i < iLesson; i++)
		cin >> vecLesson[i];

	vector<int> vecSize(iLesson);
	function<void(int)> dfs = [&](int iCurr)
		{
			vecSize[iCurr] = vecLesson[iCurr];

			if (iCurr + 1 < iLesson)
			{
				dfs(iCurr + 1);
				vecSize[iCurr] += vecSize[iCurr + 1];
			}
		};

	dfs(0);

	int iResult = vecSize[0];
	for (int i = 1; i < iLesson - 1; i++)
	{
		for (int j = i + 1; j < iLesson; j++)
		{
			int iSum1 = vecSize[0];
			int iSum2 = vecSize[i];
			int iSum3 = vecSize[j];

			int iMax = max(iSum1 - iSum2, max(iSum2 - iSum3, iSum3));
			iResult = min(iResult, iMax);
		}
	}

	cout << iResult;

	return 0;
}