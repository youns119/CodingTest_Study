#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int num = 0;
	int sum = 0;
	int max_current = 0;
	int max_final = 0;

	cin >> num;

	vector<int> wt(num);

	for (int i = 0; i < num; i++)
		cin >> wt[i];

	sort(wt.begin(), wt.end(), greater<int>());
	max_final = wt[0];

	for (int i = 0; i < num; i++)
	{
		max_current = wt[i] * (i + 1);

		if (max_current > max_final)
			max_final = max_current;
	}

	cout << max_final << endl;

	return 0;
}