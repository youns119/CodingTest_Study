#include <iostream>
#include <string>
#include <algorithm>
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