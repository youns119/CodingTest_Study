#include <iostream>

using namespace std;

int GCD(int iNum1, int iNum2)
{
	if (iNum2 == 0) return iNum1;
	return GCD(iNum2, iNum1 % iNum2);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	pair<int, int> pairFraction[2]{};

	for (int i = 0; i < 2; i++)
	{
		int iNum1{}, iNum2{};

		cin >> iNum1 >> iNum2;
		pairFraction[i].first = iNum1;
		pairFraction[i].second = iNum2;
	}

	pair<int, int> pairResult{};
	for (int i = 0; i < 2; i++)
	{
		int iMul = pairFraction[(i + 1) % 2].second;

		pairFraction[i].first *= iMul;

		pairResult.first += pairFraction[i].first;
		pairResult.second = pairFraction[i].second * iMul;
	}

	int iGCD = GCD(pairResult.first, pairResult.second);
	pairResult.first /= iGCD;
	pairResult.second /= iGCD;

	cout << pairResult.first << " " << pairResult.second;

	return 0;
}

// 최소공약수를 구하는 데 재귀를 안쓰고 while 반복문을 썼다
// 분모 분자를 각각 받아서 그 자리에서 바로 곱셈으로 계산해서 분수를 바로 도출해낸다...
// 조금만 생각해보면 이렇게 간단히 풀 수 있다니..!!

#ifdef _RELEASE

#include <iostream>
using namespace std;

int GCD(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;

	int numerator = a * d + c * b;
	int denominator = b * d;

	int gcd = GCD(numerator, denominator);
	numerator /= gcd;
	denominator /= gcd;

	cout << numerator << " " << denominator << '\n';
	return 0;
}

#endif