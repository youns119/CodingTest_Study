#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Input(int N, vector<int>& wines);
void Wine(vector<int> wines, int& result);

int main()
{
	int N = 0, result = 0;
	vector<int> wines;

	Input(N, wines);
	Wine(wines, result);

	cout << result;

	return 0;
}

void Input(int N, vector<int>& wines)
{
	cin >> N;
	wines.assign(N + 1, 0);

	for (int i = 1; i <= N; i++)
		cin >> wines[i];
}

void Wine(vector<int> wines, int& result)
{
	int size = wines.size();
	vector<int> MAX(size, 0);

	MAX[0] = 0;
	MAX[1] = wines[1];
	MAX[2] = wines[1] + wines[2];

	for (int i = 3; i < size; i++)
	{
		MAX[i] = max(wines[i] + wines[i - 1] + MAX[i - 3], MAX[i - 2] + wines[i]);
		MAX[i] = max(MAX[i], MAX[i - 1]);
	}

	result = MAX[size - 1];
}