#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int iDay{}, iCons{};

	cin >> iDay >> iCons;
	vector<int> vecDay(iDay + 1);
	
	vector<int> vecSum;
	int iSum{};

	for (int i = 1; i < iDay + 1; i++)
	{
		cin >> vecDay[i];
		iSum += vecDay[i];

		if (i >= iCons)
		{
			iSum -= vecDay[i - iCons];
			vecSum.push_back(iSum);
		}
	}

	sort(vecSum.begin(), vecSum.end(), [](const int& iA, const int& iB)
		{
			return iA > iB;
		}
	);

	cout << vecSum[0];

	return 0;
}