#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int isPalin(string s, int l, int r);
int solution(string s);

int main()
{
	int result;
	string s;

	cin >> s;
	result = solution(s);
	cout << result;

	return 0;
}

int isPalin(string s, int l, int r)
{
	int result = 0;

	while (l >= 0 && r < s.length())
	{
		if (s[l] == s[r]) { l--; r++; }
		else break;
	}

	result = r - l - 1;
	return result;
}

int solution(string s)
{
	int answer = 0;

	for (int i = 0; i < s.length(); i++)
	{
		int odd = isPalin(s, i, i);
		int even = isPalin(s, i, i + 1);

		answer = max(answer, max(odd, even));
	}

	return answer;
}