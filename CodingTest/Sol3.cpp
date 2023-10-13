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