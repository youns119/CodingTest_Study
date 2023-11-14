#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct cmp
{
	bool operator()(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
	{
		return 
	}
};
bool Input(vector<vector<int>>& rupee, int& MAX);
void Init(vector<vector<int>>& rupee, int& MAX);
int BFS(vector<vector<int>>& rupee, int MAX);

int main()
{
	int result;
	vector<vector<int>> rupee;
	vector<int> results;

	while (true)
	{
		int MAX = 0;

		if (Input(rupee, MAX))
		{
			result = BFS(rupee, MAX);
			Init(rupee, MAX);
			results.push_back(result);
		}
		else
			break;
	}

	for (int i = 0; i < results.size(); i++)
		cout << "Problem " << i + 1 << ": " << results[i] << "\n";

	return 0;
}

bool Input(vector<vector<int>>& rupee, int& MAX)
{
	int N;

	cin >> N;
	if (N == 0)
		return false;

	rupee.assign(N + 1, vector<int>(N + 1, 0));

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
		{
			cin >> rupee[j][i];
			MAX += rupee[j][i];
		}

	return true;
}

void Init(vector<vector<int>>& rupee, int& MAX)
{
	rupee.clear();
	// 벡터의 capacity를 완전 초기화하는 방법은 clear 뒤에 shrink_to_fit하는게 가장 깔끔하다
	rupee.shrink_to_fit();

	MAX = 0;
}

int BFS(vector<vector<int>>& rupee, int MAX)
{
	int result = 0;
	int size = rupee.size();
	vector<vector<int>> total(size, vector<int>(size, MAX));
	priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, >
	pair<int, int> cal[4] = { {1,0},{-1,0},{0,1},{0,-1} };

	q.push({ 1,1 });
	total[1][1] = rupee[1][1];

	while (!q.empty())
	{
		int curr_x = q.front().first;
		int curr_y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int lat_x = curr_x + cal[i].first;
			int lat_y = curr_y + cal[i].second;

			if (lat_x >= 1 && lat_x <= size - 1 &&
				lat_y >= 1 && lat_y <= size - 1)
			{
				int lat_total = total[curr_x][curr_y] + rupee[lat_x][lat_y];

				if (total[lat_x][lat_y] > lat_total)
				{
					total[lat_x][lat_y] = lat_total;
					q.push({ lat_x, lat_y });
				}
			}
		}
	}

	result = total[size - 1][size - 1];
	return result;
}