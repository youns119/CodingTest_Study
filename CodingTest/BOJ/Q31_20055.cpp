#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int Conveyer(vector<int>& belts, int K);

int main()
{
	int N, K, result;
	vector<int> belts;

	cin >> N >> K;
	belts.assign(2 * N, 0);

	for (int i = 0; i < belts.size(); i++)
		cin >> belts[i];

	result = Conveyer(belts, K);
	cout << result;

	return 0;
}

int Conveyer(vector<int>& belts, int K)
{
	int result = 0, cnt = 0;
	int size = belts.size() / 2;
	deque<pair<bool, int>> belt;
	
	for (auto b : belts)
		belt.push_back({ false, b });

	while (cnt < K)
	{
		// 1
		{
			pair<int, int> temp = belt.back();
			belt.pop_back(); belt.push_front(temp);

			if (belt[size - 1].first)
				belt[size - 1].first = false;
		}

		// 2
		{
			for (int i = size - 1; i >= 0; i--)
			{
				if (belt[i].first &&
					!belt[i + 1].first &&
					belt[i + 1].second > 0)
				{
					belt[i].first = false;
					belt[i + 1].first = true;
					belt[i + 1].second--;

					if (belt[i + 1].second == 0)
						cnt++;
				}
			}

			if (belt[size - 1].first)
				belt[size - 1].first = false;
		}

		// 3
		{
			if (belt[0].second > 0)
			{
				belt[0].first = true;
				belt[0].second--;

				if (belt[0].second == 0)
					cnt++;
			}
		}

		result++;
	}

	return result;
}