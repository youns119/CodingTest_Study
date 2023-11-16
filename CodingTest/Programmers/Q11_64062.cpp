#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void Input(vector<int>& stones, int& k);
bool Count(vector<int>& stones, int k, int M);
int solution(vector<int> stones, int k);

int main()
{
	int k, result;
	vector<int> stones;

	Input(stones, k);
	result = solution(stones, k);

	cout << result;

	return 0;
}

void Input(vector<int>& stones, int& k)
{
	int N;

	cin >> N >> k;
	stones.assign(N, 0);

	for (int i = 0; i < N; i++)
		cin >> stones[i];
}

bool Count(vector<int>& stones, int k, int M)
{
	int cnt = 0;

	for (int i = 0; i < stones.size(); i++)
	{
		if (stones[i] <= M)	cnt++;
		else				cnt = 0;

		if (cnt >= k) return false;
	}

	return true;
}

int solution(vector<int> stones, int k)
{
	int L = *min_element(stones.begin(), stones.end());
	int R = *max_element(stones.begin(), stones.end());
	
	while (L <= R)
	{
		int M = (L + R) >> 1;

		if (Count(stones, k, M)) L = M + 1;
		else					 R = M - 1;
	}

	return L;
}