#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

int Sol(vector<vector<int>>& Box);

int main()
{
	int M, N, result;
	vector<vector<int>> Box;

	cin >> M >> N;
	Box.assign(M, vector<int>(N, 0));

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> Box[j][i];

	result = Sol(Box);
	cout << result;

	return 0;
}

int Sol(vector<vector<int>>& Box)
{
	int result = 0;
	pair<int, int> calc[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
	vector<vector<bool>> visit;
	queue<tuple<int, int, int>> q;

	visit.assign(Box.size(), vector<bool>(Box[0].size(), false));
	for (int i = 0; i < Box.size(); i++)
		for (int j = 0; j < Box[0].size(); j++)
			if (Box[i][j] == 1) { q.push({ i, j, 0 }); visit[i][j] = true; }

	while (!q.empty())
	{
		int x = get<0>(q.front());
		int y = get<1>(q.front());
		int cnt = get<2>(q.front());
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int X = x + calc[i].first;
			int Y = y + calc[i].second;
			int Cnt = cnt + 1;

			if (X >= 0 && X < Box.size() &&
				Y >= 0 && Y < Box[0].size() &&
				visit[X][Y] == false)
			{
				if (Box[X][Y] == 0)
				{
					Box[X][Y]++;
					visit[X][Y] = true;

					result = result > Cnt ? result : Cnt;
					q.push({ X, Y, Cnt });
				}
				else continue;
			}
		}
	}

	for (int i = 0; i < Box.size(); i++)
		for (int j = 0; j < Box[0].size(); j++)
			if (Box[i][j] == 0) return -1;

	return result;
}