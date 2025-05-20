#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void Cantor(int iNum);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int iNum{};

	while (cin>>iNum)
	{
		Cantor(iNum);
	}

	return 0;
}

void Cantor(int iNum)
{
	string strResult = "-";

	for (int i = 0; i < iNum; i++)
	{
		string strCurr = strResult;
		int iPow = pow(3, i);

		while (iPow--)
			strResult += " ";

		strResult += strCurr;
	}

	cout << strResult << "\n";
}

// 재귀적으로 string의 가운데 부분을 공백으로 만들는 풀이
// 이게 문제가 의도한 바에는 더 맞는 것 같다
// 내 풀이가 4ms인 것에 비해 0ms이 나오는 걸 보면 확실하게 이쪽이 맞는 것 같다

#ifdef _RELEASE

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void MakeCantor(string& str, int left, int right) {
	if (right - left < 3)
		return;

	int third = (right - left) / 3;

	for (int i = left + third; i < left + 2 * third; ++i)
		str[i] = ' ';

	MakeCantor(str, left, left + third);
	MakeCantor(str, left + 2 * third, right);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	while (cin >> n) {
		int length = pow(3, n);
		string str(length, '-');

		MakeCantor(str, 0, length);
		cout << str << '\n';
	}

	return 0;
}

#endif