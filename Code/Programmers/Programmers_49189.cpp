#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(int n, vector<vector<int>> edge);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int iCnt{}, iLine{};

	cin >> iCnt >> iLine;
	vector<vector<int>> vecEdge(iLine, vector<int>(2));

	for (int i = 0; i < iLine; i++)
		cin >> vecEdge[i][0] >> vecEdge[i][1];

	cout << solution(iCnt, vecEdge);

	return 0;
}

int solution(int n, vector<vector<int>> edge) 
{
	int answer = 0;

	vector<vector<int>> vecGraph(n + 1);
	for (auto Node : edge)
	{
		int iFirst = Node[0];
		int iSecond = Node[1];

		vecGraph[iFirst].push_back(iSecond);
		vecGraph[iSecond].push_back(iFirst);
	}

	queue<int> qBFS;
	vector<int> vecMin(n + 1);

	qBFS.push(1);
	vecMin[1]++;

	while (!qBFS.empty())
	{
		int iCurr = qBFS.front();
		qBFS.pop();

		for (int i = 0; i < vecGraph[iCurr].size(); i++)
		{
			int iCurrRank = vecMin[iCurr] + 1;
			int iCurrNode = vecGraph[iCurr][i];

			if (vecMin[iCurrNode] == 0 || vecMin[iCurrNode] > iCurrRank)
			{
				vecMin[iCurrNode] = iCurrRank;
				qBFS.push(iCurrNode);
			}
		}
	}

	int iMax = *max_element(vecMin.begin(), vecMin.end());
	answer = count(vecMin.begin(), vecMin.end(), iMax);

	return answer;
}

// 뭐 대충 내 풀이랑 비슷하긴 하다
// 차이점이 있다면 고정 배열 사용했고, 최대값을 중간에 계속 검사해주고
// 마지막에 한번에 검사하면서 answer++을 해주는 방식이라는 것 정도?

#ifdef _RELEASE

#include <string>
#include <vector>
#include<queue>
#include<iostream>
using namespace std;

int d[20001][20001];
bool visit[20001];
int dist[20001];
int solution(int n, vector<vector<int>> edge) {
	int max = 0;
	int answer = 0;
	for (int i = 0; i < edge.size(); i++)
	{
		d[edge[i][0]][edge[i][1]] = 1;
		d[edge[i][1]][edge[i][0]] = 1;
	}

	queue<int> q;
	visit[1] = true;
	q.push(1);
	dist[1] = 0;
	while (!q.empty())
	{
		int first = q.front();
		q.pop();
		for (int i = 2; i <= n; i++)
		{
			if (d[first][i] == 1 && !visit[i])
			{
				q.push(i);
				visit[i] = true;
				dist[i] = dist[first] + 1;
				if (max < dist[i])
				{
					max = dist[i];
				}
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		if (max == dist[i])
		{
			answer++;
		}
	}
	return answer;
}

#endif