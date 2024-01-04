#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

void Input(vector<string>& words);
int Solution(vector<string>& words);
void Solve();

int main()
{
	Solve();

	return 0;
}

void Input(vector<string>& words)
{
	int N;

	cin >> N;
	words.assign(N, "");
	for (int i = 0; i < N; i++)
		cin >> words[i];
}

int Solution(vector<string>& words)
{
	int result = 0, num = 9;
	vector<int> sums;

	sums.assign(26, 0);
	for (int i = 0; i < words.size(); i++)
		for (int j = 0; j < words[i].length(); j++)
		{
			int index = words[i][j] - 'A';
			int weight = pow(10, words[i].length() - j - 1);

			sums[index] += weight;
		}

	sort(sums.begin(), sums.end(), greater<>());
	for (auto sum : sums)
	{
		result += sum * num--;
		if (!result)
			break;
	}

	return result;
}

void Solve()
{
	int result;
	vector<string> words;

	Input(words);
	result = Solution(words);

	cout << result;
}