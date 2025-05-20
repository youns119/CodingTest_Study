#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int iCount{};

	cin >> iCount;
	vector<pair<int, int>> vecWork(iCount + 2, { 0, 0 });
	vector<int> vecDP(iCount + 2);

	for (int i = 1; i <= iCount; i++)
		cin >> vecWork[i].first >> vecWork[i].second;

	for (int i = iCount; i >= 1; i--)
	{
		int iDay = i + vecWork[i].first;

		if (iDay > iCount + 1)
			vecDP[i] = vecDP[i + 1];
		else
			vecDP[i] = max(vecDP[i + 1], vecDP[iDay] + vecWork[i].second);
	}

	cout << vecDP[1];

	return 0;
}