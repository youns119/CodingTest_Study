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

// 카탈란 수 + DP 방식으로 푸는 방법
// 그냥 카탈란 수의 점화식 자체를 DP로 만든거라고 보면 된다
// 이 카탈란 수라는건 조합론에서 상당히 자주 쓰인다고 한다... 기억하자!

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