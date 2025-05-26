#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

vector<long long> solution(vector<long long> numbers);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int iCount{};

	cin >> iCount;
	vector<long long> vecNumber(iCount);

	for (int i = 0; i < iCount; i++)
	{
		int iNum{};

		cin >> iNum;
		vecNumber.push_back(iNum);
	}

	vector<long long> vecSolution = solution(vecNumber);

	for (auto Num : vecNumber)
		cout << Num << "\n";

	return 0;
}

vector<long long> solution(vector<long long> numbers) 
{
	vector<long long> answer;
	
	for (long long lNum : numbers)
	{
		if (lNum % 2 == 0) answer.push_back(lNum + 1);
		else
		{
			bitset<64> bs(lNum);
			int iNum{};

			for (int i = 0; i < 64; i++)
			{
				if (bs[i] == 0)
				{
					bs[i] = 1;
					iNum = i;
					break;
				}
			}

			for (int i = iNum - 1; i >= 0; i--)
			{
				if (bs[i] == 1)
				{
					bs[i] = 0;
					answer.push_back(bs.to_ullong());
					break;
				}
			}
		}
	}

	return answer;
}

// 기본적으로 위의 모든 과정을 비트연산자로 바꾼 거라고 보는 되는 풀이
// 하지만 코드가 더 간결하다
// 기왕 하는 김에 push_back 안의 식도 비트 연산자로 하면 더 좋지 않을까 하는 생각도 있다
// (number | bit) & ~(bit >> 1) 이런식으로 바꿀 수 있을 듯

#ifdef _RELEASE

vector<long long> solution(vector<long long> numbers)
{
	vector<long long> answer;

	for (long long number : numbers)
	{
		long long bit = 1;
		while ((number & bit) > 0) bit <<= 1;
		answer.push_back(number + bit - (bit >> 1));
	}

	return answer;
}

#endif

// 속도는 마찬가지로 다른 풀이들과 비슷하지만 가장 비트연산을 잘 활용한 방법
// 생각해낸 사람의 머리 속이 궁금한 풀이
// n & -n 은 가장 오른쪽 1비트만 남기는 식
// 따라서 ~n & -~n 은 가장 오른쪽 0비트를 찾아내는 식이다
// 매우 유용할 것 같다 기억해두자

#ifdef _RELEASE

vector<long long> solution(vector<long long> numbers)
{
	vector<long long> answer;
	for (ll& n : numbers) {
		ll idx = (~n & -~n);
		ll ans = n + idx - (idx >> 1);
		answer.push_back(ans);
	}
	return answer;
}

#endif