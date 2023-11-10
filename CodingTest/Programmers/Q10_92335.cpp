#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

typedef unsigned long long ull;

string Trans(int n, int k);
bool Check(int num);
int solution(int n, int k);

int main()
{
	int n, k;
	int result;

	cin >> n >> k;

	result = solution(n, k);

	cout << result;

	return 0;
}

string Trans(int n, int k)
{
	string s = "";

	while (n > 0)
	{
		s += (n % k + '0');
		n /= k;
	}

	reverse(s.begin(), s.end());
	return s;
}

bool Check(ull num)
{
	ull root = sqrt(num);

	if (num == 1)
		return false;

	for (ull i = 2; i <= root; i++)
	{
		if (num % i == 0)
			return false;
	}

	return true;
}

int solution(int n, int k)
{
	int answer = 0;
	string s;
	string temp = "";

	s = Trans(n, k);

	for (int i = 0; i < s.length() + 1; i++)
	{
		if (!(s[i] == '0' || s[i] == '\0'))
			temp += s[i];
		else if(temp != "")
		{
			ull num = stoull(temp);

			if (Check(num)) answer++;
			temp = "";
		}
	}

	return answer;
}