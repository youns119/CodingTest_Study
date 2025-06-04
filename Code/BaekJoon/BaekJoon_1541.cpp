#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> vecNum;
	string strEquation{};
	string strInput{};

	cin >> strInput;

	string strNum{};
	for (int i = 0; i < strInput.length(); ++i)
	{
		char chCurr = strInput[i];
		if (chCurr >= '0' && chCurr <= '9')
			strNum += chCurr;
		else if (chCurr == '+' || chCurr == '-')
		{
			vecNum.emplace_back(stoi(strNum));
			strEquation += chCurr;

			strNum.clear();
		}

		if (i == strInput.length() - 1)
			vecNum.emplace_back(stoi(strNum));
	}

	int iResult{ vecNum[0] };
	bool bMinus{};

	for (int i = 0; i < strEquation.length(); ++i)
	{
		char chCurr = strEquation[i];

		if (chCurr == '-')
			bMinus = true;

		if (bMinus) iResult -= vecNum[i + 1];
		else iResult += vecNum[i + 1];
	}

	cout << iResult;

	return 0;
}

// �� �ѹ��� �ݺ������� Ǫ�� Ǯ��
// ���� ���ڶ� ��ȣ�� ���� �и��ؼ� �����ϰ� �Ŀ� �ٽ� �ݺ��� ���鼭 �ذ��ߴµ�...
// �̷� ������ ȿ�������� ¥���� �����ߴµ� �� Ǯ�̸� ���ϱ� Ȯ���� ����ϴ�

#ifdef _RELEASE

#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string str;
	cin >> str;

	int result = 0;
	string temp;
	bool minus = false;

	for (int i = 0; i <= str.length(); ++i)
	{
		if (i == str.length() || str[i] == '+' || str[i] == '-')
		{
			int num = stoi(temp);
			if (minus)
				result -= num;
			else
				result += num;

			if (i < str.length() && str[i] == '-')
				minus = true;

			temp.clear();
		}
		else
		{
			temp += str[i];
		}
	}

	cout << result;

	return 0;
}

#endif