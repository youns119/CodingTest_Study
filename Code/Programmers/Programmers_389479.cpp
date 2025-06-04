#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> players, int m, int k);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> vecPlayer(24, 0);
	for (int i = 0; i < 24; i++)
		cin >> vecPlayer[i];

	int iMax{}, iTime{};

	cin >> iMax >> iTime;

	cout << solution(vecPlayer, iMax, iTime);

	return 0;
}

int solution(vector<int> players, int m, int k) 
{
	int answer = 0;

	vector<int> vecServer(players.size());

	for (int i = 0; i < players.size(); i++)
	{
		int iReq = players[i] / m;

		if (vecServer[i] < iReq)
		{
			int iDist = iReq - vecServer[i];
			answer += iDist;

			for (int j = i; j < i + k && j < vecServer.size(); j++)
				vecServer[j] += iDist;
		}
	}

	return answer;
}

// queue를 사용하는 풀이
// 오래된 순으로 서버의 시간을 체크하면서 queue에 push, pop을 하는 방식
// 현재 서버 수는 queue의 size로 알 수 있다
// 굉장히 효율적이고 재밌는 방식... 배울점이 많다

#ifdef _RELEASE

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> players, int m, int k)
{
	int answer = 0;
	queue<int> q;
	for (int i = 0; i < players.size(); i++)
	{
		// 서버 시간 체크
		while (!q.empty() && i - q.front() >= k)
		{
			q.pop();
		}

		// 현재 이용자 수가 (n+1) * m명 이상이면 서버 증설
		while (players[i] >= (q.size() + 1) * m)
		{
			++answer;
			q.push(i);
		}
	}
	return answer;
}

#endif