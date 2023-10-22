#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

map<int, int> order;

bool cmp(pair<int, int> a, pair<int, int> b)
{
	if (a.second == b.second)
		return  order[a.first] < order[b.first];
	
	return a.second > b.second;
}

int main()
{
	int size;
	int max;
	map<int, int> count;
	vector<pair<int, int>> v;

	cin >> size >> max;

	for (int i = 0; i < size; i++)
	{
		int num;
		cin >> num;
		
		auto it = count.find(num);
		if (it != count.end())
			count[num]++;
		else
			count.insert({ num, 1 });

		it = order.find(num);
		if (it == order.end())
			order[num] = i;
	}

	for (auto it = count.begin(); it != count.end(); it++)
		v.push_back({ it->first, it->second });

	sort(v.begin(), v.end(), cmp);

	for (int i = 0; i < v.size(); i++)
		for (int j = 0; j < v[i].second; j++)
			cout << v[i].first << " ";

	return 0;
}