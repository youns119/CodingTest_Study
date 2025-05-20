#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void Cantor(string& strCantor, int iLeft, int iRight);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int iNum{};

	while (cin >> iNum)
	{
		int iLen = pow(3, iNum);
		string strCantor(iLen, '-');

		Cantor(strCantor, 0, iLen);
		cout << strCantor << "\n";
	}

	return 0;
}

void Cantor(string& strCantor, int iLeft, int iRight)
{
	if (iRight - iLeft < 3)
		return;

	int iMiddle = (iRight - iLeft) / 3;

	for (int i = iLeft + iMiddle; i < iLeft + 2 * iMiddle; i++)
		strCantor[i] = ' ';

	Cantor(strCantor, iLeft, iLeft + iMiddle);
	Cantor(strCantor, iLeft + 2 * iMiddle, iRight);
}