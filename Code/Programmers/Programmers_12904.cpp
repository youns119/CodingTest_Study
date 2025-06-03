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

// 내가 처음에 시도했던 방법으로 테스트 케이스는 다 통과하긴 함
// 그 대신 이중 반복문, O(N)의 시간복잡도를 가진 substr, reverse 같은 함수 때문에 
// 전체적인 시간이 O(N^3)이라 효율성 검사에서 탈락

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

// GPT가 Manacher's Algorithm으로 나한테 알려준 것을 내 방식으로 풀어낸 코드
// 마나허 알고리즘이란 걸 처음 알았고 이해하는데 너무 오래 걸림...
// 시간복잡도가 O(N)이라서 위의 Two Pointer보다 훨씬 빠르다
// 기본적으로 DP의 로직을 따르고 있다

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