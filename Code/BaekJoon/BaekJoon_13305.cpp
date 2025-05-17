#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<pair<int, int>> vecCity;
	int iCount{};

	cin >> iCount;
	vecCity.resize(iCount);

	for (int i = 0; i < iCount - 1; i++)
	{
		int iDist{};

		cin >> iDist;
		vecCity[i].second = iDist;
	}

	for (int i = 0; i < iCount; i++)
	{
		int iPrice{};

		cin >> iPrice;
		vecCity[i].first = iPrice;
	}

	int iCurrPrice = vecCity[0].first;
	long long iTotalPrice{};
	for (int i = 0; i < iCount - 1; i++)
	{
		if (iCurrPrice > vecCity[i].first) iCurrPrice = vecCity[i].first;

		iTotalPrice += (long long)iCurrPrice * vecCity[i].second;
	}

	cout << iTotalPrice;

	return 0;
}