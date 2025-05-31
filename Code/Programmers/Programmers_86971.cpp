#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

int BFS(int iNum, const vector<vector<int>>& vecWire);
int solution(int n, vector<vector<int>> wires);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int iCount{};

	cin >> iCount;
	vector<vector<int>> vecWire(iCount);

	for (int i = 0; i < iCount - 1; i++)
	{
		int iNum1{}, iNum2{};

		cin >> iNum1 >> iNum2;
		vecWire[iNum1].push_back(iNum2);
		vecWire[iNum2].push_back(iNum1);
	}

	cout << solution(iCount, vecWire);

	return 0;
}

int BFS(int iNum, const vector<vector<int>>& vecWire)
{
	queue<int> qWire;
	vector<bool> vecVisit(vecWire.size() + 1, false);
	int iCount{};

	qWire.push(iNum);
	vecVisit[iNum] = true;
	iCount++;

	while (!qWire.empty())
	{
		int iWire = qWire.front();
		qWire.pop();

		for (int i = 0; i < vecWire[iWire - 1].size(); i++)
		{
			if (vecVisit[vecWire[iWire - 1][i]] == false)
			{
				qWire.push(vecWire[iWire - 1][i]);
				vecVisit[vecWire[iWire - 1][i]] = true;
				iCount++;
			}
		}
	}

	return iCount;
}

int solution(int n, vector<vector<int>> wires)
{
	int answer = 100;

	queue<int> qWire;
	vector<bool> vecVisit(wires.size() + 1, false);

	qWire.push(1);
	vecVisit[1] = true;

	for(int i = 0)

	while (!qWire.empty())
	{
		int iWire = qWire.front();
		qWire.pop();

		for (int i = 0; i < wires[iWire - 1].size(); i++)
		{
			if (vecVisit[wires[iWire - 1][i]] == false)
			{
				qWire.push(wires[iWire - 1][i]);
				vecVisit[wires[iWire - 1][i]] = true;

				int iBFS = abs(n - BFS(wires[iWire - 1][i], wires));
				answer = answer > iBFS ? iBFS : answer;
			}
		}
	}

	return answer;
}