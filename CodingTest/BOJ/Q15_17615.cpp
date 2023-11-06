#include <iostream>

using namespace std;

void Count(string s, int& R, int& B);
int Ball_Sub(string s, int num, char color);
int Ball(string s);

int main()
{
	int N, result;
	string s;

	cin >> N >> s;

	result = Ball(s);

	cout << result;

	return 0;
}

void Count(string s, int& R, int& B)
{
	for (auto c : s)
	{
		if (c == 'R')
			R++;
		else
			B++;
	}
}

int Ball_Sub(string s, int num, char color)
{
	int f = 0, b = 0;
	int result;

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == color)
			f++;
		else
			break;
	}

	for (int i = s.length() - 1; i >= 0; i--)
	{
		if (s[i] == color)
			b++;
		else
			break;
	}

	result = min(num - f, num - b);
	
	return result;
}

int Ball(string s)
{
	int answer;
	int R = 0, B = 0;

	Count(s, R, B);
	
	R = Ball_Sub(s, R, 'R');
	B = Ball_Sub(s, B, 'B');

	answer = min(R, B);

	return answer;
}