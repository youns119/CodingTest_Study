#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int iCnt{}, iMaxWeight{};

	cin >> iCnt >> iMaxWeight;
	vector<int> vecWeight(iCnt);
	vector<int> vecDP(iMaxWeight + 1);

	for (int i = 0; i < iCnt; i++)
	{
		int iWeight{}, iValue{};

		cin >> iWeight >> iValue;
		vecWeight[i] = iWeight;
		vecDP[iWeight] = iValue;
	}

	for (int i = 0; i < iCnt; i++)
		vecDP[iMaxWeight] = max(vecDP[iMaxWeight], vecDP[vecWeight[i]] + vecDP[iMaxWeight - vecWeight[i]]);

	cout << vecDP[iMaxWeight];

	return 0;
}