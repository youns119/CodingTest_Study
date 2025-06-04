#include <iostream>
#include <vector>
#include <functional>

using namespace std;

int solution(int n, vector<int> money);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int iReserve{}, iCnt{};

	cin >> iReserve >> iCnt;
	vector<int> vecMoney(iCnt);
	
	for (int i = 0; i < iCnt; i++)
		cin >> vecMoney[i];

	cout << solution(iReserve, vecMoney);

	return 0;
}

int solution(int n, vector<int> money) 
{
    int answer = 0;

    vector<int> vecDP(n + 1, 0);
    vecDP[0] = 1;

    for (int iCoin : money)
        for (int i = iCoin; i <= n; ++i)
            vecDP[i] += vecDP[i - iCoin];

    return vecDP[n] % 1'000'000'007;
}

// 내가 처음에 푼 DFS 방식의 풀이
// 테스트 케이스는 다 통과했는데 효율성에서 광탈함...
// 아무래도 모든 경우의 수를 다 탐색하는 방법이다보니 당연한 듯

#ifdef _RELEASE

int solution(int n, vector<int> money)
{
    int answer = 0;

    function<void(int, int)> DFS = [&](int iCurr, int iSum)
        {
            if (iSum >= n)
            {
                if (iSum == n) answer++;
                return;
            }

            for (int i = 0; i < money.size(); i++)
            {
                if (iCurr > money[i]) continue;

                DFS(money[i], iSum + money[i]);
            }
        };

    DFS(0, 0);

    return answer % 1'000'000'007;
}

#endif