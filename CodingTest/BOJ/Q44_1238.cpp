#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 다익스트라의 횟수를 줄인 개선된 방법
// 속도 8ms
void Input(int& N, int& M, int& X, vector<vector<pair<int, int>>> lines[]);
void Dijkstra(int start, int X, vector<int> dist[], vector<vector<pair<int, int>>> lines[]);
int Solution(int N, int M, int X, vector<vector<pair<int, int>>> lines[]);
void Solve();

int main()
{
	Solve();

	return 0;
}

void Input(int& N, int& M, int& X, vector<vector<pair<int, int>>> lines[])
{
	int a, b, c;

	cin >> N >> M >> X;
	lines[0].assign(N + 1, vector<pair<int, int>>());
	lines[1].assign(N + 1, vector<pair<int, int>>());
	for (int i = 0; i < M; i++)
	{
		cin >> a >> b >> c;
		lines[0][a].push_back({ b, c });
		lines[1][b].push_back({ a,c });
	}
}

void Dijkstra(int start, int X, vector<int> dist[], vector<vector<pair<int, int>>> lines[])
{
	priority_queue<pair<int, int>> pq;
	dist[start][X] = 0;

	pq.push({ X, 0 });
	while (!pq.empty())
	{
		int curr = pq.top().first;
		int cost = -pq.top().second;
		pq.pop();

		for (int i = 0; i < lines[start][curr].size(); i++)
		{
			int next = lines[start][curr][i].first;
			int nCost = lines[start][curr][i].second;
			int d = cost + nCost;

			if (d < dist[start][next])
			{
				dist[start][next] = d;
				pq.push({ next, -d });
			}
		}
	}
}

int Solution(int N, int M, int X, vector<vector<pair<int, int>>> lines[])
{
	int result = 0;
	vector<int> dist[2];

	dist[0].assign(N + 1, 1e9 + 7);
	dist[1].assign(N + 1, 1e9 + 7);

	Dijkstra(0, X, dist, lines);	// X에서 정점들로 가는 최단거리
	Dijkstra(1, X, dist, lines);	// 정점들에서 X로 가는 최단거리

	for (int i = 1; i <= N; i++)
	{
		int d = dist[0][i] + dist[1][i];
		result = result > d ? result : d;
	}

	return result;
}

void Solve()
{
	int N, M, X, result;
	vector<vector<pair<int, int>>> lines[2];

	Input(N, M, X, lines);
	result = Solution(N, X, X, lines);

	cout << result;
}

// 처음에 시도한 방법
// 속도 604ms
//void Input(int& N, int& M, int& X, vector<vector<pair<int,int>>>& lines);
//void Dijkstra(int start, vector<int>& dist, vector<vector<pair<int,int>>>& lines);
//int Solution(int N, int M, int X, vector<vector<pair<int, int>>>& lines);
//void Solve();
//
//int main()
//{
//	Solve();
//
//	return 0;
//}
//
//void Input(int& N, int& M, int& X, vector<vector<pair<int, int>>>& lines)
//{
//	int a, b, c;
//
//	cin >> N >> M >> X;
//	lines.assign(N + 1, vector<pair<int, int>>());
//	for (int i = 0; i < M; i++)
//	{
//		cin >> a >> b >> c;
//		lines[a].push_back({ b, c });
//	}
//}
//
//void Dijkstra(int start, vector<int>& dist, vector<vector<pair<int, int>>>& lines)
//{
//	priority_queue<pair<int, int>> pq;
//	dist[start] = 0;
// 
//	pq.push({ start, 0 });
//	while (!pq.empty())
//	{
//		int curr = pq.top().first;
//		int cost = -pq.top().second;
//		pq.pop();
//
//		for (int i = 0; i < lines[curr].size(); i++)
//		{
//			int next = lines[curr][i].first;
//			int nCost = lines[curr][i].second;
//			int d = cost + nCost;
//
//			if (d < dist[next])
//			{
//				dist[next] = d;
//				pq.push({ next, -d });
//			}
//		}
//	}
//}
//
//int Solution(int N, int M, int X, vector<vector<pair<int, int>>>& lines)
//{
//	int answer;
//	vector<int> dist, result;
//
//	dist.assign(N + 1, 0);
//	result.assign(N + 1, 0);
//	for (int i = 1; i <= N; i++)
//	{
//		for (int j = 1; j <= N; j++) dist[j] = 1e9 + 7;
//		Dijkstra(i, dist, lines);
//		result[i] = dist[X];
//	}
//
//	for (int i = 1; i <= N; i++) dist[i] = 1e9 + 7;
//	Dijkstra(X, dist, lines);
//	for (int i = 1; i <= N; i++) result[i] += dist[i];
//	answer = *max_element(result.begin(), result.end());
//
//	return answer;
//}
//
//void Solve()
//{
//	int N, M, X, result;
//	vector<vector<pair<int, int>>> lines;
//
//	Input(N, M, X, lines);
//	result = Solution(N, M, X, lines);
//
//	cout << result;
//}