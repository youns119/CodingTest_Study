#include <iostream>
#include <queue>
#include <bitset>

using namespace std;

const int MAX = 123456 * 2;

bitset<MAX + 1> Prime();

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	bitset<MAX + 1> bsPrime = Prime();
	queue<int> qResult;

	while (true)
	{
		int iNum{};

		cin >> iNum;
		if (iNum == 0)
			break;

		int iResult{};

		for (int i = iNum + 1; i <= iNum * 2; i++)
			if (bsPrime.test(i)) iResult++;

		qResult.push(iResult);
	}

	while (!qResult.empty())
	{
		cout << qResult.front() << "\n";
		qResult.pop();
	}

	return 0;
}

bitset<MAX + 1> Prime()
{
	bitset<MAX + 1> bsPrime;
	bsPrime.set();

	bsPrime[0] = bsPrime[1] = 0;

	for (int i = 2; i * i <= MAX; i++)
	{
		if (!bsPrime.test(i)) continue;
		for (int j = i * i; j <= MAX; j += i)
			bsPrime.reset(j);
	}

	return bsPrime;
}