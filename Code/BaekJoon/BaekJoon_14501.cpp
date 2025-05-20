#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int iCount{};

	cin >> iCount;
	vector<pair<int, int>> vecWork(iCount + 2, { 0, 0 });
	vector<int> vecDP(iCount + 2);

	for (int i = 1; i <= iCount; i++)
		cin >> vecWork[i].first >> vecWork[i].second;

	for (int i = iCount; i >= 1; i--)
	{
		int iDay = i + vecWork[i].first;

		if (iDay > iCount + 1)
			vecDP[i] = vecDP[i + 1];
		else
			vecDP[i] = max(vecDP[i + 1], vecDP[iDay] + vecWork[i].second);
	}

	cout << vecDP[1];

	return 0;
}

// DFS(재귀) + 백트래킹 방식으로 푸는 방법
// 솔직히 직관적으로 다가오진 않지만 그냥 이런 방법도 있다는 걸 알았다

#ifdef _RELEASE

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<int> T, P;
int iMaxProfit = 0;

void DFS(int day, int total) {
    if (day > N) {
        iMaxProfit = max(iMaxProfit, total);
        return;
    }

    DFS(day + 1, total);

    if (day + T[day] <= N + 1) {
        DFS(day + T[day], total + P[day]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    T.resize(N + 1);
    P.resize(N + 1);

    for (int i = 1; i <= N; ++i) {
        cin >> T[i] >> P[i];
    }

    DFS(1, 0);

    cout << iMaxProfit << '\n';
    return 0;
}

#endif