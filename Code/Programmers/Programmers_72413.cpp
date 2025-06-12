#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include <cmath>

using namespace std;

typedef vector<vector<pair<int, int>>> Graph;

vector<int> Dijkstra(int iStart, const Graph& graphPath);
int solution(int n, int s, int a, int b, vector<vector<int>> fares);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int iCnt{}, iPath{}, iStart{}, iA{}, iB{};

	cin >> iCnt >> iPath >> iStart >> iA >> iB;
	vector<vector<int>> vecPath(iPath, vector<int>(3, 0));

	for (int i = 0; i < iPath; ++i)
		for (int j = 0; j < 3; ++j)
			cin >> vecPath[i][j];

	cout << solution(iCnt, iStart, iA, iB, vecPath);

	return 0;
}

vector<int> Dijkstra(int iStart, const Graph& graphPath)
{
	vector<int> vecFare(graphPath.size(), INT_MAX);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pqGraph;

	vecFare[iStart] = 0;
	pqGraph.push({ 0, iStart });

	while (!pqGraph.empty())
	{
		pair<int, int> pairPrev = pqGraph.top();
		pqGraph.pop();

		if (vecFare[pairPrev.second] < pairPrev.first)
			continue;

		for (int i = 0; i < graphPath[pairPrev.second].size(); ++i)
		{
			pair<int, int> pairNext = graphPath[pairPrev.second][i];

			if (vecFare[pairNext.first] > pairPrev.first + pairNext.second)
			{
				vecFare[pairNext.first] = pairPrev.first + pairNext.second;
				pqGraph.push({ vecFare[pairNext.first], pairNext.first });
			}
		}
	}

	return vecFare;
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares)
{
	int answer = INT_MAX;

	Graph graphPath(n + 1);

	for (auto vecFare : fares)
	{
		int iA = vecFare[0];
		int iB = vecFare[1];
		int iFare = vecFare[2];

		graphPath[iA].push_back({ iB, iFare });
		graphPath[iB].push_back({ iA, iFare });
	}

	vector<int> vecDistS = Dijkstra(s, graphPath);
	vector<int> vecDistA = Dijkstra(a, graphPath);
	vector<int> vecDistB = Dijkstra(b, graphPath);

	for (int i = 1; i <= n; ++i)
	{
		if (vecDistS[i] != INT_MAX && vecDistA[i] != INT_MAX && vecDistB[i] != INT_MAX)
			answer = min(answer, vecDistS[i] + vecDistA[i] + vecDistB[i]);
	}

	return answer;
}

// 플로이드 워셜을 이용한 풀이
// 다익스트라는 선택적 탐색이기 때문에 간선과 노드의 숫자에 영향을 받는 O(ElogV)의 속도
// 플로이드 워셜은 전체 탐색이므로 O(N3)의 속도
// 노드 많고 간선 적다 -> 다익스트라
// 노드 적다 -> 플로이드 워셜
// 코드 구현 자체는 플로이드 워셜이 훨씬 간단하고 짧다

#ifdef _RELEASE

#include <vector>
#include <climits>
using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
	const int INF = 1e9;
	vector<vector<int>> dist(n + 1, vector<int>(n + 1, INF));

	for (int i = 1; i <= n; ++i)
		dist[i][i] = 0;

	for (auto& fare : fares) {
		int u = fare[0], v = fare[1], w = fare[2];
		dist[u][v] = dist[v][u] = w;
	}

	// Floyd-Warshall
	for (int k = 1; k <= n; ++k)
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

	int answer = INT_MAX;
	for (int k = 1; k <= n; ++k)
		answer = min(answer, dist[s][k] + dist[k][a] + dist[k][b]);

	return answer;
}

#endif