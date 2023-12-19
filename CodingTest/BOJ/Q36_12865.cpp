#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int DP(vector<int>& W, vector<int>& V, int N, int K);

int main()
{
	int N, K, result;
	vector<int> W;
	vector<int> V;

	cin >> N >> K;
	W.assign(N + 1, 0);
	V.assign(N + 1, 0);

	for (int i = 1; i <= N; i++)
		cin >> W[i] >> V[i];

	result = DP(W, V, N, K);
	cout << result;

	return 0;
}

int DP(vector<int>& W, vector<int>& V, int N, int K)
{
	vector<vector<int>> dp(K + 1, vector<int>(N + 1, 0));

	for(int i = 1; i <= K; i++)
		for (int j = 1; j <= N; j++)
		{
			if (W[j] > i)
				dp[i][j] = dp[i][j - 1];
			else
				dp[i][j] = max(dp[i - W[j]][j - 1] + V[j], dp[i][j - 1]);
		}

	return dp[K][N];
}