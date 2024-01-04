#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void Input(int& N, int& M, int& X, vector<vector<pair<int,int>>>& lines);
void Dijkstra(int start, vector<int>& dist, vector<vector<pair<int,int>>>& lines);
int Solution(int& N, int& M, int& X, vector<vector<pair<int, int>>>& lines);
void Solve();

int main()
{
	Solve();

	return 0;
}

void Input(int& N, int& M, int& X, vector<vector<pair<int, int>>>& lines)
{
	int a, b, c;

	cin >> N >> M >> X;
	lines.assign(N + 1, vector<pair<int, int>>());
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b >> c;
		lines[a].push_back({ b, c });
	}
}

void Dijkstra(int start, vector<int>& dist, vector<vector<pair<int, int>>>& lines)
{
	priority_queue<pair<int, int>> pq;
	dist[start] = 0;
	pq.push({ start, 0 });

	while (!pq.empty())
	{
		int curr = pq.top().first;
		int cost = -pq.top().second;
		pq.pop();

		for (int i = 0; i < lines[curr].size(); i++)
		{
			int next = lines[curr][i].first;
			int nCost = lines[curr][i].second;
			int d = cost + nCost;

			if (d < dist[next])
			{
				dist[next] = d;
				pq.push({ next, -d });
			}
		}
	}
}

int Solution(int& N, int& M, int& X, vector<vector<pair<int, int>>>& lines)
{
	int answer;
	vector<int> dist, result;

	dist.assign(N + 1, 0);
	result.assign(N + 1, 0);
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++) dist[j] = 1e9 + 7;
		Dijkstra(i, dist, lines);
		result[i] = dist[X];
	}

	for (int i = 1; i <= N; i++) dist[i] = 1e9 + 7;
	Dijkstra(X, dist, lines);
	for (int i = 1; i <= N; i++) result[i] += dist[i];
	answer = *max_element(result.begin(), result.end());

	return answer;
}

void Solve()
{
	int N, M, X, result;
	vector<vector<pair<int, int>>> lines;

	Input(N, M, X, lines);
	result = Solution(N, M, X, lines);

	cout << result;
}