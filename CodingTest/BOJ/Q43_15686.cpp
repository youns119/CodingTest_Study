#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <stack>

using namespace std;

void Input(vector<vector<int>>& map, int& M);
int MinDist(vector<pair<int, int>>& house, vector<pair<int, int>>& chicken, stack<int>& st);
int Solution(vector<vector<int>>& map, int M);
void Solve(vector<vector<int>>& map, int M);

int main()
{
	int M;
	vector<vector<int>> map;

	Input(map, M);
	Solve(map, M);

	return 0;
}

void Input(vector<vector<int>>& map, int& M)
{
	int N;

	cin >> N >> M;
	map.assign(N, vector<int>(N, 0));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> map[j][i];
}

int MinDist(vector<pair<int, int>>& house, vector<pair<int, int>>& chicken, stack<int>& st)
{
	int result = 0;
	vector<int> dist(house.size(), 100);

	while (!st.empty())
	{
		int curr = st.top();
		st.pop();

		for (int i = 0; i < house.size(); i++)
		{
			int d = abs(house[i].first - chicken[curr].first) +
				abs(house[i].second - chicken[curr].second);

			dist[i] = min(dist[i], d);
		}
	}

	for (auto d : dist) result += d;
	return result;
}

int Solution(vector<vector<int>>& map, int M)
{
	int minDist = 250000;
	stack<int> st;
	vector<bool> subArr;
	vector<pair<int, int>> house;
	vector<pair<int, int>> chicken;

	for(int i = 0; i < map.size(); i++)
		for (int j = 0; j < map[0].size(); j++)
		{
			if (map[i][j] == 1)
				house.push_back(make_pair(j, i));
			else if (map[i][j] == 2)
				chicken.push_back(make_pair(j, i));
		}

	subArr.assign(chicken.size(), false);
	fill(subArr.begin(), subArr.begin() + M, true);
	sort(subArr.begin(), subArr.end());

	do
	{
		for (int i = 0; i < subArr.size(); i++)
			if (subArr[i] == true)
				st.push(i);

		minDist = min(minDist, MinDist(house, chicken, st));
	} while (next_permutation(subArr.begin(), subArr.end()));

	return minDist;
}

void Solve(vector<vector<int>>& map, int M)
{
	int result;

	result = Solution(map, M);
	cout << result;
}