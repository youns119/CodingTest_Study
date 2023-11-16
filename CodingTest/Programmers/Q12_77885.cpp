// https://yabmoons.tistory.com/632
#include <iostream>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers);

int main()
{
	int N;
	vector<long long> numbers;

	cin >> N;
	numbers.assign(N, 0);

	for (int i = 0; i < numbers.size(); i++)
		cin >> numbers[i];

	numbers = solution(numbers);

	for (int i = 0; i < numbers.size(); i++)
		cout << numbers[i] << "\n";

	return 0;
}

vector<long long> solution(vector<long long> numbers)
{
	vector<long long> answer;

	for (int i = 0; i < numbers.size(); i++)
	{
		if (numbers[i] % 2 == 0) answer.push_back(numbers[i] + 1);
		else
		{

		}

	}


	return answer;
}