#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int GCD(int w, int h);
long long solution(int w, int h);

int main()
{
	int w, h;
	long long result;

	cin >> w >> h;
	result = solution(w, h);
	cout << result;

	return 0;
}

int GCD(int w, int h)
{
	if (w % h == 0) return h;
	else return GCD(h, w % h);
}

long long solution(int w, int h)
{
	long long answer = 0;
	long long total = (long long)w * (long long)h;
	int cnt = GCD(w, h);
	int min_w = w / cnt;
	int min_h = h / cnt;
	long long part = 0;
	double t = double(min_h) / double(min_w);

	for (int i = 0; i < min_w; i++)
	{
		int f = floor(t * i);
		int c = ceil(t * (i + 1));
		part += c - f;
	}

	part *= cnt;
	answer = total - part;

	return answer;
}

// ÆÐÅÏÀ» ÆÄ¾ÇÇÏ¿© Ç¬ Ç®ÀÌ
// ÈÎ¾À ´õ °£´ÜÇÏ´Ù...
//#include <iostream>
//using namespace std;
//
//int GCD(int a, int b) {
//	if (a == 0) return b;
//	return GCD(b % a, a);
//}
//
//long long solution(int w, int h)
//{
//	long long answer = 1;
//
//	int gcd = GCD(w, h);
//	cout << w + h - gcd;
//	answer = ((long)w * h) - ((long)w + h - gcd);
//
//	return answer;
//}