#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Input(vector<int>& BR, int& L, int& R, int& M);
int Count(vector<int>& BR, int Mid);
int Binary(vector<int>& BR, int L, int R, int M);

int main()
{
	int M;
	int L = 0, R = 0;
	int result;
	vector<int> BR;

	Input(BR, L, R, M);
	result = Binary(BR, L, R, M);

	cout << result;

	return 0;
}

void Input(vector<int>& BR, int& L, int& R, int& M)
{
	int N;

	cin >> N >> M;
	BR.assign(N, 0);

	for (int i = 0; i < N; i++)
	{
		cin >> BR[i];
		R += BR[i];
	}

	L = *max_element(BR.begin(), BR.end());
}

int Count(vector<int>& BR, int Mid)
{
	int sum = 0, cnt = 0;

	for (int i = 0; i < BR.size(); i++)
	{
		if (sum + BR[i] > Mid)
		{
			sum = 0;
			cnt++;
		}

		sum += BR[i];
	}

	if (sum != 0) cnt++;

	return cnt;
}

int Binary(vector<int>& BR, int L, int R, int M)
{
	while (L <= R)
	{
		int Mid = (L + R) >> 1;

		if (Count(BR, Mid) > M)
			L = Mid + 1;
		else
			R = Mid - 1;
	}

	return L;
}