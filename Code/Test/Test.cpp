#include <iostream>
#include <vector>
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