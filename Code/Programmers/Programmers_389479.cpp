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

// queue�� ����ϴ� Ǯ��
// ������ ������ ������ �ð��� üũ�ϸ鼭 queue�� push, pop�� �ϴ� ���
// ���� ���� ���� queue�� size�� �� �� �ִ�
// ������ ȿ�����̰� ��մ� ���... ������� ����

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
		// ���� �ð� üũ
		while (!q.empty() && i - q.front() >= k)
		{
			q.pop();
		}

		// ���� �̿��� ���� (n+1) * m�� �̻��̸� ���� ����
		while (players[i] >= (q.size() + 1) * m)
		{
			++answer;
			q.push(i);
		}
	}
	return answer;
}

#endif