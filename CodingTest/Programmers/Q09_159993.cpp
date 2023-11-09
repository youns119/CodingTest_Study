#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

void Input(vector<string>& maps);
void Find(vector<string>& maps, unordered_map<char, pair<int, int>>& points);
int BFS(vector<string>& maps, pair<int, int> start, pair<int, int> end);
int Solution(vector<string> maps);

int main()
{
	int result;
	vector<string> maps;

	Input(maps);
	result = Solution(maps);

	cout << result;

	return 0;
}

void Input(vector<string>& maps)
{
	int N;

	cin >> N;
	maps.assign(N, "");

	for (int i = 0; i < N; i++)
		cin >> maps[i];
}

void Find(vector<string>& maps, unordered_map<char, pair<int, int>>& points)
{
	for (int i = 0; i < maps.size(); i++)
	{
		for (int j = 0; j < maps[i].length(); j++)
		{
			if (maps[i][j] == 'S' ||
				maps[i][j] == 'L' ||
				maps[i][j] == 'E')
				points[maps[i][j]] = { i, j };

			if (points.size() == 3)
				return;
		}
	}
}

int BFS(vector<string>& maps, pair<int, int> start, pair<int, int> end)
{
	int x_size = maps.size();
	int y_size = maps[0].length();
	queue<pair<int, int>> q;
	vector<vector<bool>> visit(x_size, vector<bool>(y_size, false));
	vector<vector<int>> count(x_size, vector<int>(y_size, 0));
	pair<int, int> move[4] = { {1, 0}, {-1, 0}, {0, 1}, {0, -1} };

	q.push(start);
	visit[start.first][start.second] = true;

	while (!q.empty())
	{
		pair<int, int> current = q.front();
		int prev_x = current.first;
		int prev_y = current.second;

		if (current == end)
			return count[prev_x][prev_y];

		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int x = prev_x + move[i].first;
			int y = prev_y + move[i].second;

			if ((x >= 0 && x < x_size) &&
				(y >= 0 && y < y_size))
				if (!visit[x][y])
					if (maps[x][y] != 'X')
					{
						q.push({ x, y });
						visit[x][y] = true;
						count[x][y] = count[prev_x][prev_y] + 1;
					}
		}
	}

	return -1;
}

int Solution(vector<string> maps)
{
	int answer = 0;
	int result;
	unordered_map<char, pair<int, int>> points;

	Find(maps, points);

	result = BFS(maps, points['S'], points['L']);
	if (result != -1)
		answer += result;
	else
		return -1;

	result = BFS(maps, points['L'], points['E']);
	if (result != -1)
		answer += result;
	else
		return -1;

	return answer;
}