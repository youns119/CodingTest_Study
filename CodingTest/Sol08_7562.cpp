#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int Chess(int size, pair<int, int> knight, pair<int, int> goal);

int main()
{
	int test;
	int size;
	pair<int, int> knight;
	pair<int, int> goal;
	vector<int> result;

	cin >> test;

	while(test != 0)
	{
		cin >> size;
		cin >> knight.first >> knight.second;
		cin >> goal.first >> goal.second;

		result.push_back(Chess(size, knight, goal));

		test--;
	}

	for (int i = 0; i < result.size(); i++)
		cout << result[i] << "\n";

	return 0;
}

int Chess(int size, pair<int, int> knight, pair<int, int> goal)
{
	pair<int, int> move[8] =
	{ {1, 2}, {2,1},{1,-2},{2,-1},{-1,2},{-2,1},{-1,-2},{-2,-1} };
	queue<pair<int, int>> q;
	vector<vector<bool>> visit(size, vector<bool>(size, false));
	vector<vector<int>> count(size, vector<int>(size, 0));

	q.push(knight);

	while (!q.empty())
	{
		int pos_x = q.front().first;
		int pos_y = q.front().second;

		if (q.front() == goal)
			return count[pos_x][pos_y];

		q.pop();

		for (int i = 0; i < 8; i++)
		{
			int x = pos_x + move[i].first;
			int y = pos_y + move[i].second;

			if(x >= 0 && x < size
				&& y >= 0 && y < size)
				if (!visit[x][y])
				{
					q.push(make_pair(x, y));
					visit[x][y] = true;
					count[x][y] = count[pos_x][pos_y] + 1;
				}
		}
	}
}