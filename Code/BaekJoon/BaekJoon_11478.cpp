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

// unordered_map 대신 set를 사용하는 방법
// 훨씬 간단하다
// 사실 중복을 피한다는 부분에서 set를 떠올려야 하지만 set를 안 쓴지 오래되서 까먹고 있었다
// string 도 substr를 안쓰고 임의의 string에 문자를 더하는 방식으로 하는 것도 좋은 듯

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