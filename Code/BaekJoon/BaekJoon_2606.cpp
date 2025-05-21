#include <iostream>
#include <vector>
#include <queue>
#include <bitset>

using namespace std;

int BFS(const vector<vector<int>>& vecGraph, int iStart);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int iVertex{}, iLine{};

	cin >> iVertex >> iLine;
	vector<vector<int>> vecGraph(iVertex + 1);

	for (int i = 1; i < iLine + 1; i++)
	{
		int iNum1{}, iNum2{};
		cin >> iNum1 >> iNum2;

		vecGraph[iNum1].push_back(iNum2);
		vecGraph[iNum2].push_back(iNum1);
	}

	cout << BFS(vecGraph, 1);

	return 0;
}

int BFS(const vector<vector<int>>& vecGraph, int iStart)
{
	queue<int> qBFS;
	vector<bool> vecVisit(vecGraph.size(), false);

	qBFS.push(iStart);
	vecVisit[iStart] = true;

	int iResult{};
	while (!qBFS.empty())
	{
		int iCurr = qBFS.front();
		qBFS.pop();

		for (int i = 0; i < vecGraph[iCurr].size(); i++)
			if (!vecVisit[vecGraph[iCurr][i]])
			{
				qBFS.push(vecGraph[iCurr][i]);
				vecVisit[vecGraph[iCurr][i]] = true;

				iResult++;
			}
	}
	
	return iResult;
}

// BFS 대신 DFS를 사용하는 방법
// 사실상 모든 노드를 탐색해야 하기 때문에 별 차이는 없다
// 얍삽하게 마지막 결과값에서 -1 해버리네...ㅋㅋㅅㅂ 똑똑하네

#ifdef _RELEASE

#include <iostream>
#include <vector>

using namespace std;

const int MAX = 101;
vector<int> graph[MAX];
bool visited[MAX];
int infected = 0;

void DFS(int node) {
	visited[node] = true;
	infected++;

	for (int next : graph[node]) {
		if (!visited[next]) {
			DFS(next);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;

		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	DFS(1);

	cout << infected - 1 << "\n";
	return 0;
}

#endif