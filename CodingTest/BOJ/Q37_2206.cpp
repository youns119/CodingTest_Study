#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct node
{
	pair<int, int> xy = { 0, 0 };
	int cnt = 0;
	bool isHit = false;
};

int BFS(vector<vector<int>>& path);

int main()
{
	int N, M, result;
	vector<vector<int>> path;

	cin >> N >> M;
	path.assign(M, vector<int>(N, 0));

	for (int i = 0; i < N; i++)
	{
		string s;

		cin >> s;
		for (int j = 0; j < M; j++)
			path[j][i] = s[j] - 48;
	}

	result = BFS(path);
	cout << result;

	return 0;
}

int BFS(vector<vector<int>>& path)
{
	int result = 0;
	pair<int, int> calc[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };
	vector<vector<vector<bool>>> visit;
	queue<node> q;

	visit.assign(path.size(), vector<vector<bool>>(path[0].size(), vector<bool>(2, false)));

	node n = { {0, 0}, 1, false };
	q.push(n);
	visit[0][0][0] = true;
	visit[0][0][1] = true;

	while (!q.empty())
	{
		pair<int, int> xy = q.front().xy;
		int cnt = q.front().cnt;
		bool isHit = q.front().isHit;

		q.pop();

		if (xy.first == path.size() - 1 &&
			xy.second == path[0].size() - 1)
		{
			result = cnt;
			break;
		}

		for (int i = 0; i < 4; i++)
		{
			node n;
			pair<int, int> XY = { xy.first + calc[i].first, xy.second + calc[i].second };
			int Cnt = cnt + 1;
			bool bPush = false;
			bool bHit = false;

			if (XY.first >= 0 && XY.first < path.size() &&
				XY.second >= 0 && XY.second < path[0].size())
			{
				if (path[XY.first][XY.second] == 1)
				{
					if (!isHit && !visit[XY.first][XY.second][0]) 
					{ 
						bPush = true; 
						bHit = true; 

						visit[XY.first][XY.second][0] = true;
					}
					else continue;
				}
				else 
				{
					if (!isHit && !visit[XY.first][XY.second][0])
						visit[XY.first][XY.second][0] = true;
					else if (isHit && !visit[XY.first][XY.second][1])
						visit[XY.first][XY.second][1] = true;
					else continue;

					bPush = true; 
					bHit = isHit;
				}
			}

			if (bPush) { n = { XY, Cnt, bHit }; q.push(n); }
		}
	}

	if (result == 0)
		return -1;

	return result;
}