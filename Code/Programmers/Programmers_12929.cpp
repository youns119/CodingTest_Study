#include <iostream>
#include <vector>
#include <functional>

using namespace std;

int solution(int n);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int iCnt{};

	cin >> iCnt;
	cout << solution(iCnt);

	return 0;
}

int solution(int n) 
{
	int answer = 0;

	function<void(int, int)> DFS = [&](int iLeft, int iRight)
		{
			if (iLeft == n && iRight == n)
			{
				answer++;
				return;
			}

			if (iLeft < n)
				DFS(iLeft + 1, iRight);
			if (iLeft > iRight)
				DFS(iLeft, iRight + 1);
		};

	DFS(1, 0);

	return answer;
}

// īŻ�� �� + DP ������� Ǫ�� ���
// �׳� īŻ�� ���� ��ȭ�� ��ü�� DP�� ����Ŷ�� ���� �ȴ�
// �� īŻ�� ����°� ���շп��� ����� ���� ���δٰ� �Ѵ�... �������!

#ifdef _RELEASE

int solution(int n) {
	vector<long long> dp(n + 1);
	dp[0] = 1;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			dp[i] += dp[j] * dp[i - 1 - j];
		}
	}

	return dp[n];
}

#endif