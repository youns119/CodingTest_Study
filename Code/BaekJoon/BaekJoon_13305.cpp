#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

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

// vector<pair<int, int>> 대신 vector를 두 개 써서 푸는 방법
// 그 외에는 비슷하다

#ifdef _RELEASE

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> dist(n - 1);
    vector<int> price(n);

    for (int i = 0; i < n - 1; i++) {
        cin >> dist[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> price[i];
    }

    long long totalCost = 0;
    int currentPrice = price[0];

    for (int i = 0; i < n - 1; i++) {
        if (price[i] < currentPrice) {
            currentPrice = price[i];
        }

        totalCost += (long long)currentPrice * dist[i];
    }

    cout << totalCost << endl;

    return 0;
}

#endif