// https://yabmoons.tistory.com/632
#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

typedef long long ll;

vector<ll> solution(vector<ll> numbers);

int main()
{
	int N;
	vector<ll> numbers;

	cin >> N;
	numbers.assign(N, 0);

	for (int i = 0; i < numbers.size(); i++)
		cin >> numbers[i];

	numbers = solution(numbers);

	for (int i = 0; i < numbers.size(); i++)
		cout << numbers[i] << "\n";

	return 0;
}

vector<ll> solution(vector<ll> numbers)
{
	vector<ll> answer;

	for (auto number : numbers)
	{
		if (number % 2 == 0) answer.push_back(number + 1);
		else
		{
			bitset<50> bs(number);
			int num;

			for (int i = 0; i < bs.size(); i++)
			{
				if (bs[i] == 0)
				{
					bs[i] = 1;
					num = i;
					break;
				}
			}

			for (int i = num - 1; i >= 0; i--)
			{
				if (bs[i] == 1)
				{
					bs[i] = 0;
					break;
				}
			}

			answer.push_back(bs.to_ullong());
		}
	}

	return answer;
}

// 속도는 내가 위의 풀이와 비슷
// 하지만 코드가 더 간결하다
//vector<long long> solution(vector<long long> numbers) 
//{
//	vector<long long> answer;
//
//	for (long long number : numbers)
//	{
//		long long bit = 1;
//		while ((number & bit) > 0) bit <<= 1;
//		answer.push_back(number + bit - (bit >> 1));
//	}
//
//	return answer;
//}

// 가장 신박한 방법
// 어떻게 생각해 냈는지도 모르겠고 이해하기도 힘들다...
//vector<long long> solution(vector<long long> numbers) {
//	vector<long long> answer;
//	for (ll& n : numbers) {
//		ll idx = (~n & -~n);
//		ll ans = n + idx - (idx >> 1);
//		answer.push_back(ans);
//	}
//	return answer;
//}