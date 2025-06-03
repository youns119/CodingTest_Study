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
	vector<int> vecValue(iCnt);
	vector<int> vecDP(iMaxWeight + 1);

	for (int i = 0; i < iCnt; i++)
		cin >> vecWeight[i] >> vecValue[i];

	for (int i = 0; i < iCnt; i++)
		for (int j = iMaxWeight; j >= vecWeight[i]; j--)
			vecDP[j] = max(vecDP[j], vecDP[j - vecWeight[i]] + vecValue[i]);

	cout << vecDP[iMaxWeight];

	return 0;
}