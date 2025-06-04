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

// ���� ó���� Ǭ DFS ����� Ǯ��
// �׽�Ʈ ���̽��� �� ����ߴµ� ȿ�������� ��Ż��...
// �ƹ����� ��� ����� ���� �� Ž���ϴ� ����̴ٺ��� �翬�� ��

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