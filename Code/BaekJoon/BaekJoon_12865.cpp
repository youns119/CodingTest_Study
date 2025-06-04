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

// �Ȱ��� 0/1 Knapsack �˰��� Ǯ������ �Է¸��� DP�� ������� �� ȿ�����̴�
// �����غ��� �賶 �˰��� ��ü�� � �������� ������ ���¿����� �ִ� ȿ���� ������ ���̱� ������ �̷� ��ĵ� ����
// ����ض�!!!! 0/1 Knapsack�� �ߺ� �������� ������ �ʱ⿡ ������ �ݺ���, Unbounded Knapsack�� ������ �ݺ����̴�

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

	vector<int> dp(K + 1, 0); // dp[j] = ���� j�� �� �ִ� ��ġ

	for (int i = 0; i < N; ++i) {
		int w, v;
		cin >> w >> v;

		// �������� ��ȸ (0/1 Knapsack�� �ٽ�)
		for (int j = K; j >= w; --j) {
			dp[j] = max(dp[j], dp[j - w] + v);
		}
	}

	cout << dp[K] << '\n';
	return 0;
}

#endif