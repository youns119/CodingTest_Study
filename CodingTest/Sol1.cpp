// 시작시간 7 : 19
// 종료시간 7 : 40

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<int> height(9);
	int count = height.size();
	int totalH = 0;
	int twoadd = 0;
	bool check = 0;

	for (int i = 0; i < count; i++) {
		cin >> height[i];
		totalH += height[i];
	}

	twoadd = totalH - 100;
	sort(height.begin(), height.end());

	for (int i = 0; i < count; i++)
	{
		for (int j = i + 1; j < count; j++)
		{
			if (height[i] + height[j] == twoadd)
			{
				height.erase(height.begin() + i);
				height.erase(height.begin() + j - 1);

				check = 1;
				break;
			}
		}

		if (check)
			break;
	}

	for (auto i : height)
		cout << i << endl;

	return 0;
}