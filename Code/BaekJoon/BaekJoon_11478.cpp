#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string strWord{};

	cin >> strWord;

	unordered_map<string, bool> mapWord;
	int iCount{};

	for (int i = 0; i < strWord.length(); i++)
	{
		for (int j = 1; j < strWord.length() + 1; j++)
		{
			string strPart = strWord.substr(i, j);

			if (!mapWord[strPart])
			{
				mapWord[strPart] = true;
				iCount++;
			}
		}
	}

	cout << iCount;

	return 0;
}

// unordered_map ��� set�� ����ϴ� ���
// �ξ� �����ϴ�
// ��� �ߺ��� ���Ѵٴ� �κп��� set�� ���÷��� ������ set�� �� ���� �����Ǽ� ��԰� �־���
// string �� substr�� �Ⱦ��� ������ string�� ���ڸ� ���ϴ� ������� �ϴ� �͵� ���� ��

#ifdef _RELEASE

#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
	string s;
	cin >> s;

	set<string> substrings;

	for (int i = 0; i < s.size(); ++i) {
		string temp = "";
		for (int j = i; j < s.size(); ++j) {
			temp += s[j];
			substrings.insert(temp);
		}
	}

	cout << substrings.size() << endl;

	return 0;
}

#endif