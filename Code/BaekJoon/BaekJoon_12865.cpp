#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int iCnt{}, iMaxWeight{};

	cin >> iCnt >> iMaxWeight;
	vector<int> vecWeight(iCnt);
	vector<int> vecValue(iCnt);
	vector<int> vecDP(iMaxWeight + 1);

	for (int i = 0; i < iCnt; i++)
		cin >> vecWeight[i] >> vecValue[i];

	for (int i = 0; i < iCnt; i++)
		for (int j = iMaxWeight; j >= vecWeight[i]; j--)
			vecDP[j] = max(vecDP[j], vecDP[j - vecWeight[i]] + vecValue[i]);

	cout << vecDP[iMaxWeight];

	return 0;
}

// 똑같은 0/1 Knapsack 알고리즘 풀이지만 입력마다 DP를 적용시켜 더 효율적이다
// 생각해보면 배낭 알고리즘 자체가 어떤 아이템을 포함한 상태에서의 최대 효율을 따지는 것이기 때문에 이런 방식도 가능
// 기억해라!!!! 0/1 Knapsack은 중복 아이템이 허용되지 않기에 역방향 반복문, Unbounded Knapsack이 정방향 반복문이다

#ifdef _RELEASE

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, K;
	cin >> N >> K;

	vector<int> dp(K + 1, 0); // dp[j] = 무게 j일 때 최대 가치

	for (int i = 0; i < N; ++i) {
		int w, v;
		cin >> w >> v;

		// 역순으로 순회 (0/1 Knapsack의 핵심)
		for (int j = K; j >= w; --j) {
			dp[j] = max(dp[j], dp[j - w] + v);
		}
	}

	cout << dp[K] << '\n';
	return 0;
}

#endif