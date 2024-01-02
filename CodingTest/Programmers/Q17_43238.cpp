#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Input(int& n, vector<int>& times);
long long solution(int n, vector<int> times);
void Solve(int n, vector<int> times);

int main()
{
	int n;
	vector<int> times;

	Input(n, times);
	Solve(n, times);

	return 0;
}

void Input(int& n, vector<int>& times)
{
	int num;

	cin >> n;
	cin >> num;

	times.assign(num, 0);
	for (int i = 0; i < num; i++)
		cin >> times[i];
}

long long solution(int n, vector<int> times)
{
	long long answer = 0;
	long long min = 0, max, avg, cnt;

	max = (long long)(*max_element(times.begin(), times.end())) * n;

	while (min <= max)
	{
		cnt = 0;
		avg = (min + max) >> 1;

		for (int i = 0; i < times.size(); i++)
			cnt += avg / (long long)times[i];

		if (cnt >= n)
		{
			max = avg - 1;
			answer = avg;
		}
		else min = avg + 1;
	}

	return answer;
}

void Solve(int n, vector<int> times)
{
	long long result = solution(n, times);
	cout << result;
}