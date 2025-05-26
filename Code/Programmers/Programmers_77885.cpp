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

// �⺻������ ���� ��� ������ ��Ʈ�����ڷ� �ٲ� �Ŷ�� ���� �Ǵ� Ǯ��
// ������ �ڵ尡 �� �����ϴ�
// ��� �ϴ� �迡 push_back ���� �ĵ� ��Ʈ �����ڷ� �ϸ� �� ���� ������ �ϴ� ������ �ִ�
// (number | bit) & ~(bit >> 1) �̷������� �ٲ� �� ���� ��

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

// �ӵ��� ���������� �ٸ� Ǯ�̵�� ��������� ���� ��Ʈ������ �� Ȱ���� ���
// �����س� ����� �Ӹ� ���� �ñ��� Ǯ��
// n & -n �� ���� ������ 1��Ʈ�� ����� ��
// ���� ~n & -~n �� ���� ������ 0��Ʈ�� ã�Ƴ��� ���̴�
// �ſ� ������ �� ���� ����ص���

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