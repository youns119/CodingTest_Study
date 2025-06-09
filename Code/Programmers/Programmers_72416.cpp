#include <iostream>
#include <vector>
#include <array>
#include <limits.h>

using namespace std;

int solution(vector<int> sales, vector<vector<int>> links);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int iSale{}, iLink{};

	cin >> iSale >> iLink;
	vector<int> vecSale(iSale);
	vector<vector<int>> vecLink(iLink);

	for (int i = 0; i < iSale; ++i)
		cin >> vecSale[i];

	LLONG_MAX

	for (int i = 0; i < iLink; ++i)
	{
		int iNum1{}, iNum2{};

		cin >> iNum1 >> iNum2;
		vecLink[iNum1].push_back(iNum2);
	}

	cout << solution(vecSale, vecLink);

	return 0;
}

int solution(vector<int> sales, vector<vector<int>> links) 
{
	int answer = 0;



	return answer;
}

typedef long long ll;
vector<vector<int>> children;
vector<int> sales;
vector<array<ll, 2>> dp;

void dfs(int u) {
    dp[u][1] = sales[u];  // �� ��尡 ������ ����� ���
    ll sum_min = 0;       // �ڽ� ������ �ּ� ��� ����
    ll min_diff = LLONG_MAX;
    bool anyAttend = false;

    for (int v : children[u]) {
        dfs(v);
        sum_min += min(dp[v][0], dp[v][1]);

        if (dp[v][1] <= dp[v][0]) {
            anyAttend = true;  // �̹� ������ �ڽ��� ������ ���� ����
        }
        else {
            // �����ϵ��� ����� �ּ� �߰� ���
            min_diff = min(min_diff, dp[v][1] - dp[v][0]);
        }
    }

    dp[u][1] += sum_min; // ���� ������ ���, �ڽĵ��� �ּ� ��븸 ����
    dp[u][0] = sum_min + (anyAttend ? 0 : min_diff); // ���� �����ϸ� �ּ� 1�� ���� ����
}

int solution(vector<int>& sales_in, vector<vector<int>>& links) {
    int n = sales_in.size();
    children.assign(n, {});
    sales = sales_in;
    dp.assign(n, { 0, 0 });  // dp[i][0] = ����, dp[i][1] = ����

    for (auto& e : links) {
        int a = e[0] - 1, b = e[1] - 1;
        children[a].push_back(b);
    }

    dfs(0);  // ��Ʈ���� Ž�� ����
    return (int)min(dp[0][0], dp[0][1]);
}