#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

void DFS(vector<vector<int>>& vecGraph, int iVertex);
void BFS(vector<vector<int>>& vecGraph, int iVertex);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<vector<int>> vecGraph;
	int N{}, M{}, V{};

	cin >> N >> M >> V;

	vecGraph.resize(N);
	
	for (int i = 0; i < M; i++)
	{
		int iNum1{}, iNum2{};
		cin >> iNum1 >> iNum2;

		vecGraph[iNum1 - 1].push_back(iNum2);
		vecGraph[iNum2 - 1].push_back(iNum1);
	}

	for (int i = 0; i < N; i++)
		sort(vecGraph[i].begin(), vecGraph[i].end());

	DFS(vecGraph, V);
	cout << "\n";
	BFS(vecGraph, V);

	return 0;
}

void DFS(vector<vector<int>>& vecGraph, int iVertex)
{
	stack<int> stDFS;
	vector<bool> vecVisit(vecGraph.size(), false);

	stDFS.push(iVertex);

	while (!stDFS.empty())
	{
		int iCurr = stDFS.top();
		stDFS.pop();

		if (vecVisit[iCurr - 1] == false)
		{
			cout << iCurr << " ";
			vecVisit[iCurr - 1] = true;
		}

		for (int i = vecGraph[iCurr - 1].size() - 1; i >= 0; i--)
			if (vecVisit[vecGraph[iCurr - 1][i] - 1] == false)
				stDFS.push(vecGraph[iCurr - 1][i]);
	}
}

void BFS(vector<vector<int>>& vecGraph, int iVertex)
{
	queue<int> queueBFS;
	vector<bool> vecVisit(vecGraph.size(), false);

	queueBFS.push(iVertex);

	while (!queueBFS.empty())
	{
		int iCurr = queueBFS.front();
		queueBFS.pop();

		if (vecVisit[iCurr - 1] == false)
		{
			cout << iCurr << " ";
			vecVisit[iCurr - 1] = true;
		}

		for (int i = 0; i < vecGraph[iCurr - 1].size(); i++)
			if (vecVisit[vecGraph[iCurr - 1][i] - 1] == false)
				queueBFS.push(vecGraph[iCurr - 1][i]);
	}
}

// �� �ٸ� ���
// ���� ���� �޸� �����ؼ� DFS�� ����ͷ� �ߴµ� ��ͷ� �ϸ� �ڵ�� �� ��������
// �׸��� vector�� �迭 �����͵� �� �������� ���������ų� ������ const int�� ���ʿ� ���ѽ��ѳ��� ����� �����ƺ���

#ifdef _RELEASE

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX = 1001;
vector<int> graph[MAX];
bool visited[MAX];

void DFS(int v) {
	visited[v] = true;
	cout << v << ' ';
	for (int next : graph[v]) {
		if (!visited[next])
			DFS(next);
	}
}

void BFS(int v) {
	queue<int> q;
	fill(visited, visited + MAX, false);

	q.push(v);
	visited[v] = true;

	while (!q.empty()) {
		int curr = q.front(); q.pop();
		cout << curr << ' ';

		for (int next : graph[curr]) {
			if (!visited[next]) {
				visited[next] = true;
				q.push(next);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, M, V;
	cin >> N >> M >> V;

	while (M--) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a); // �����
	}

	// �������� �湮�� ���� ����
	for (int i = 1; i <= N; i++)
		sort(graph[i].begin(), graph[i].end());

	// DFS
	fill(visited, visited + MAX, false);
	DFS(V);
	cout << '\n';

	// BFS
	BFS(V);
	cout << '\n';

	return 0;
}

#endif