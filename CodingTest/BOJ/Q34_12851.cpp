#include <iostream>
#include <vector>
#include <queue>

using namespace std;

pair<int, int> BFS(int N, int K);

int main()
{
	int N, K;
	pair<int, int> result;

	cin >> N >> K;

	result = BFS(N, K);
	cout << result.first << "\n" << result.second;

	return 0;
}

pair<int, int> BFS(int N, int K)
{
	pair<int, int> result = { 100001, 0 };
	bool visit[100001] = { false };
	queue<pair<int, int>> q;

	q.push(make_pair(N, 0));
	visit[N] = true;

	while (!q.empty())
	{
		int pos = q.front().first;
		int cnt = q.front().second;
		int lpos[3] = { pos - 1, pos + 1, pos * 2 };

		q.pop();
		visit[pos] = true;

		if (cnt > result.first)
			break;

		if (pos == K)
		{
			result.first = cnt;
			result.second++;
			continue;
		}

		for (int i = 0; i < 3; i++)
		{
			if (lpos[i] >= 0 &&
				lpos[i] <= 100000 &&
				visit[lpos[i]] == false)
				q.push(make_pair(lpos[i], cnt + 1));
		}
	}

	return result;
}