#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

const int MAX = 1001;

void DFS(vector<int> graph[MAX], vector<bool>& visit, int v)
{
	stack<int> st;

	st.push(v);

	while (!(st.empty()))
	{
		int current = st.top();

		if (visit[current - 1] == false)
		{
			cout << current << " ";
			visit[current - 1] = true;
		}

		st.pop();

		for (int i = graph[current - 1].size() - 1; i >= 0; i--)
			if (visit[graph[current - 1][i] - 1] == false)
				st.push(graph[current - 1][i]);
	}

	visit.clear();
}

void BFS(vector<int> graph[MAX], vector<bool>& visit, int v)
{
	queue<int> q;

	q.push(v);

	while (!(q.empty()))
	{
		int current = q.front();

		if (visit[current - 1] == false)
		{
			cout << current << " ";
			visit[current - 1] = true;
		}

		q.pop();

		for (int i = 0; i < graph[current - 1].size(); i++)
			if (visit[graph[current - 1][i] - 1] == false)
				q.push(graph[current - 1][i]);
	}

	visit.clear();
}

int main()
{
	vector<int> graph[MAX];
	int N, M, V;

	cin >> N >> M >> V;
	vector<bool> visit(N, false);

	for (int i = 0; i < M; i++)
	{
		int n1, n2;
		cin >> n1 >> n2;
		graph[n1 - 1].push_back(n2);
		graph[n2 - 1].push_back(n1);
	}

	for (int i = 0; i < N; i++)
		sort(graph[i].begin(), graph[i].end());

	DFS(graph, visit, V);
	visit.assign(N, false);

	cout << "\n";

	BFS(graph, visit, V);

	return 0;
}