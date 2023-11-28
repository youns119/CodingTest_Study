#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int bfs(vector<vector<int>>& graph, int v1, int v2);
int solution(int n, vector<vector<int>> wires);

int main()
{
	int N, result;
	vector<vector<int>> wires;

	cin >> N;
	wires.assign(N - 1, vector<int>(2, 0));

	for (int i = 0; i < N - 1; i++)
		cin >> wires[i][0] >> wires[i][1];

	result = solution(N, wires);
	cout << result;

	return 0;
}

int BFS(vector<vector<int>>& graph, int v1, int v2, int n)
{
	int result = 1;
	queue<int> q;
	vector<bool> check(n + 1, false);

	q.push(v1);
	check[v1] = true;
	check[v2] = true;

	while (!q.empty())
	{
		int curr = q.front();
		q.pop();

		for (int i = 0; i < graph[curr].size(); i++)
		{
			if (!check[graph[curr][i]])
			{
				q.push(graph[curr][i]);
				check[graph[curr][i]] = true;
				result++;
			}
		}
	}

	return result;
}

int solution(int n, vector<vector<int>> wires)
{
	int answer = 101;
	vector<vector<int>> graph(n + 1, vector<int>());
	
	for (auto w : wires)
	{
		int a = w[0];
		int b = w[1];

		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	for (auto w : wires)
	{
		int cnt, diff;
		int v1 = w[0];
		int v2 = w[1];

		cnt = BFS(graph, v1, v2, n);
		diff = abs(cnt - (n - cnt));
		answer = min(answer, diff);
	}

	return answer;
}

// 람다함수를 사용한 풀이
// 코드가 굉장히 깔끔해진다
//using namespace std;
//
//int solution(int n, vector<vector<int>> wires) {
//	vector<vector<int>> graph(n + 1);
//	for (int i = 0; i < (int)wires.size(); i++) {
//		int u = wires[i][0];
//		int v = wires[i][1];
//		graph[u].push_back(v);
//		graph[v].push_back(u);
//	}
//	vector<int> siz(n + 1);
//	function<void(int, int)> dfs = [&](int cur, int prev)  -> void {
//		siz[cur] = 1;
//		for (int nxt : graph[cur]) {
//			if (nxt == prev) continue;
//			dfs(nxt, cur);
//			siz[cur] += siz[nxt];
//		}
//		};
//	dfs(1, -1);
//	int answer = INT_MAX;
//	for (int i = 1; i <= n; i++) {
//		for (int j : graph[i]) {
//			int l = siz[j];
//			int r = n - siz[j];
//			answer = min(answer, abs(l - r));
//		}
//	}
//	return answer;
//}