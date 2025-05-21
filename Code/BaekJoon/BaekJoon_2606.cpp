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