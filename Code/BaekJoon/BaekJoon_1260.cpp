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