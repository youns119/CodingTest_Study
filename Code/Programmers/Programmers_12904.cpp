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

// GPT�� Manacher's Algorithm���� ������ �˷��� Ǯ�̹�
// ������ �˰����̶� �� ó�� �˾Ұ� �����ϴµ� �ʹ� ���� �ɸ�...
// �ð����⵵�� O(N)�̶� ���� Two Pointer���� �ξ� ������
// �⺻������ DP�� ������ ������ �ִ�

#ifdef _RELEASE

int solution(string s) {
	// 1. ��ó��: Ȧ�� ���̷� �����
	string t = "#";
	for (char c : s) {
		t += c;
		t += "#";
	}

	int n = t.size();
	vector<int> p(n, 0); // �� ��ġ�� ������ ����
	int c = 0, r = 0;    // �߽ɰ� ������ ��
	int maxLen = 0;

	for (int i = 0; i < n; ++i) {
		int mirror = 2 * c - i; // i�� �ſ� ��ġ

		if (i < r)
			p[i] = min(r - i, p[mirror]);

		// �߽ɿ��� Ȯ��
		while (i - p[i] - 1 >= 0 && i + p[i] + 1 < n && t[i - p[i] - 1] == t[i + p[i] + 1]) {
			++p[i];
		}

		// r�� c ����
		if (i + p[i] > r) {
			c = i;
			r = i + p[i];
		}

		maxLen = max(maxLen, p[i]);
	}

	return maxLen;
}

#endif