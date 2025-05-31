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
	vector<vector<int>> vecWire(iCount -1);

	for (int i = 0; i < iCount - 1; i++)
	{
		int iNum1{}, iNum2{};

		cin >> iNum1 >> iNum2;
		vecWire[i].push_back(iNum1);
		vecWire[i].push_back(iNum2);
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

		for (int i = 0; i < vecWire[iWire].size(); i++)
		{
			if (vecVisit[vecWire[iWire][i]] == false)
			{
				qWire.push(vecWire[iWire][i]);
				vecVisit[vecWire[iWire][i]] = true;
				iCount++;
			}
		}
	}

	return iCount;
}

int solution(int n, vector<vector<int>> wires)
{
	int answer = n;

	for (int i = 0; i < wires.size(); i++)
	{
		vector<vector<int>> vecWire(n + 1);

		for (int j = 0; j < wires.size(); j++)
		{
			if (i == j) continue;

			int iA = wires[j][0];
			int iB = wires[j][1];

			vecWire[iA].push_back(iB);
			vecWire[iB].push_back(iA);
		}

		int iCount = BFS(1, vecWire);
		answer = min(answer, abs(n - iCount * 2));
	}

	return answer;
}

// 

#ifdef _RELEASE

#include <bits/stdc++.h>

using namespace std;

int solution(int n, vector<vector<int>> wires) {
	vector<vector<int>> graph(n + 1);
	for (int i = 0; i < (int)wires.size(); i++) {
		int u = wires[i][0];
		int v = wires[i][1];
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	vector<int> siz(n + 1);
	function<void(int, int)> dfs = [&](int cur, int prev)  -> void {
		siz[cur] = 1;
		for (int nxt : graph[cur]) {
			if (nxt == prev) continue;
			dfs(nxt, cur);
			siz[cur] += siz[nxt];
		}
		};
	dfs(1, -1);
	int answer = INT_MAX;
	for (int i = 1; i <= n; i++) {
		for (int j : graph[i]) {
			int l = siz[j];
			int r = n - siz[j];
			answer = min(answer, abs(l - r));
		}
	}
	return answer;
}

#endif

#ifdef _RELEASE


2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
#include <string>
#include <vector>

using namespace std;
int s[100009];
vector<int> v[100009];
void dfs(int si, int pi) {
	s[si] = 1;
	for (auto& it : v[si]) {
		if (it == pi)continue;
		dfs(it, si);
		s[si] += s[it];
	}
}
int solution(int n, vector<vector<int>> e) {
	int res = n - 2;
	int i, j, k;
	for (i = 0; i < n; i++)v[i].clear();
	for (auto& it : e) {
		v[it[0] - 1].push_back(it[1] - 1);
		v[it[1] - 1].push_back(it[0] - 1);
	}
	dfs(0, 0);
	for (i = 1; i < n; i++) {
		int p = s[i];
		int q = n - s[i];
		res = min(res, abs(p - q));
	}
	return res;
}

#endif