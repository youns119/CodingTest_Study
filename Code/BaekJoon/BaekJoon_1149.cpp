#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct House
{
	int arrRGB[3]{};
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int iCount{};

	cin >> iCount;
	vector<House> vecHouse(iCount);

	for (int i = 0; i < iCount; i++)
	{
		House tHouse{};
		cin >> tHouse.arrRGB[0] >> tHouse.arrRGB[1] >> tHouse.arrRGB[2];

		vecHouse[i] = tHouse;
	}

	for (int i = 1; i < iCount; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			vecHouse[i].arrRGB[j] =
				min(vecHouse[i - 1].arrRGB[(j + 1) % 3], vecHouse[i - 1].arrRGB[(j + 2) % 3]) + 
				vecHouse[i].arrRGB[j];
		}
	}

	auto it = min_element(vecHouse[iCount - 1].arrRGB, vecHouse[iCount - 1].arrRGB + 3);
	cout << *it;

	return 0;
}

// �⺻������ ���� �����ϰ� Ǯ����
// �ϳ� �ָ��Ҹ��� �� min�� ���� �� ���� �Ѿ �� �� �ִ��� ������...

#ifdef _RELEASE

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	vector<vector<int>> cost(N + 1, vector<int>(3));

	for (int i = 1; i <= N; ++i) {
		cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
	}

	for (int i = 2; i <= N; ++i) {
		cost[i][0] += min(cost[i - 1][1], cost[i - 1][2]);
		cost[i][1] += min(cost[i - 1][0], cost[i - 1][2]);
		cost[i][2] += min(cost[i - 1][0], cost[i - 1][1]);
	}

	cout << min({ cost[N][0], cost[N][1], cost[N][2] }) << '\n';

	return 0;
}

#endif

// �Է� ���� ������ DP�� �����ִ� ���
// �� ������ ���� Ǯ�� �� ���� ����� ���δ�

#ifdef _RELEASE

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int count;
	int values[3];
	int min_final;

	cin >> count;

	vector<vector<int>> houses(count, vector<int>(3));

	for (int i = 0; i < 3; i++)
		cin >> houses[0][i];

	for (int i = 1; i < count; i++)
		for (int j = 0; j < 3; j++)
		{
			cin >> values[j];

			houses[i][j] = min(houses[i - 1][(j + 1) % 3], houses[i - 1][(j + 2) % 3]) + values[j];
		}

	sort(houses[count - 1].begin(), houses[count - 1].end());

	cout << houses[count - 1][0];

	return 0;
}

#endif