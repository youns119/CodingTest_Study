#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int count, length;
	vector<pair<int,int>> pits;
	int curr = 0;
	int plank = 0;

	cin >> count >> length;

	for (int i = 0; i < count; i++)
	{
		int start, end;
		cin >> start >> end;
		pits.push_back(make_pair(start, end));
	}

	sort(pits.begin(), pits.end());

	for (int i = 0; i < count; i++)
	{
		if (curr < pits[i].first)
			curr = pits[i].first;

		while (curr < pits[i].second)
		{
			curr += length;
			plank++;
		}
	}

	cout << plank << endl;

	return 0;
}