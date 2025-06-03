#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int solution(string s);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string strPal{};

	cin >> strPal;
	cout << solution(strPal);

	return 0;
}

int solution(string s)
{
    int answer = 1;

	for (int i = 0; i < s.length(); i++)
	{
		int iLeft{}, iRight{};

		// Case : Odd
		{
			iLeft = iRight = i;

			while (iLeft >= 0 && iRight < s.length() &&
				s[iLeft] == s[iRight])
			{
				answer = max(answer, iRight - iLeft + 1);
				iLeft--; iRight++;
			}
		}

		// Case : Even
		{
			iLeft = i; iRight = i + 1;

			while (iLeft >= 0 && iRight < s.length() &&
				s[iLeft] == s[iRight])
			{
				answer = max(answer, iRight - iLeft + 1);
				iLeft--; iRight++;
			}
		}
	}

    return answer;
}

// ���� ó���� �õ��ߴ� ������� �׽�Ʈ ���̽��� �� ����ϱ� ��
// �� ��� ���� �ݺ���, O(N)�� �ð����⵵�� ���� substr, reverse ���� �Լ� ������ 
// ��ü���� �ð��� O(N^3)�̶� ȿ���� �˻翡�� Ż��

#ifdef _RELEASE

int solution(string s)
{
	int answer = 0;

	for (int i = 0; i < s.length(); i++)
	{
		for (int j = 1; j <= s.length() - i; j++)
		{
			string strPal = s.substr(i, j);
			string strTemp = strPal;
			reverse(strPal.begin(), strPal.end());

			if (strTemp == strPal)
			{
				int iLen = strTemp.length();
				answer = max(answer, iLen);
			}
		}
	}

	return answer;
}

#endif

// GPT�� Manacher's Algorithm���� ������ �˷��� ���� �� ������� Ǯ� �ڵ�
// ������ �˰����̶� �� ó�� �˾Ұ� �����ϴµ� �ʹ� ���� �ɸ�...
// �ð����⵵�� O(N)�̶� ���� Two Pointer���� �ξ� ������
// �⺻������ DP�� ������ ������ �ִ�

#ifdef _RELEASE

int solution(string s)
{
	int answer = 0;

	string strPal{ "#" };

	for (char chPal : s)
	{
		strPal += chPal;
		strPal += '#';
	}

	int iLen = strPal.length();
	vector<int> vecPal(iLen);
	int iCenter{}, iRight{};

	for (int i = 0; i < iLen; i++)
	{
		int iMirror = 2 * iCenter - i;

		if (i < iRight)
			vecPal[i] = min(iRight - i, vecPal[iMirror]);

		while (i - vecPal[i] - 1 >= 0 && i + vecPal[i] + 1 < iLen &&
			strPal[i - vecPal[i] - 1] == strPal[i + vecPal[i] + 1])
			vecPal[i]++;

		if (i + vecPal[i] > iRight)
		{
			iCenter = i;
			iRight = i + vecPal[i];
		}

		answer = max(answer, vecPal[i]);
	}

	return answer;
}

#endif