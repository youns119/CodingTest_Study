#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>

using namespace std;

const int LEN_MAX = 11;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	unordered_map<string, int> umapWord;
	map<int, vector<string>, greater<int>> mapWord;

	int iCount{}, iMin{};

	cin >> iCount >> iMin;

	for (int i = 0; i < iCount; i++)
	{
		string strWord{};

		cin >> strWord;
		if (strWord.length() >= iMin)
			umapWord[strWord]++;
	}

	for (auto Pair : umapWord)
		mapWord[Pair.second].push_back(Pair.first);

	for (auto Pair : mapWord)
	{
		vector<string> vecWord[LEN_MAX];

		for (string Word : Pair.second)
		{
			int iLen = Word.length();
			vecWord[iLen].push_back(Word);
		}

		for (int i = LEN_MAX - 1; i >= 1; i--)
		{
			int iSize = vecWord[i].size();
			if (iSize == 0) continue;
			else if (iSize == 1)
			{
				cout << vecWord[i].front() << "\n";
				continue;
			}

			sort(vecWord[i].begin(), vecWord[i].end());

			for (string Word : vecWord[i])
				cout << Word << "\n";
		}
	}

	return 0;
}

#ifdef _RELEASE

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

bool compare(const pair<string, int>& a, const pair<string, int>& b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second > b.second;
}

int main() {
	int N, K;
	cin >> N >> K;

	map<string, int> freq_map;

	for (int i = 0; i < N; i++) {
		string word;
		cin >> word;

		if (word.size() >= K) {
			freq_map[word]++;
		}
	}

	vector<pair<string, int>> words(freq_map.begin(), freq_map.end());

	sort(words.begin(), words.end(), compare);

	for (const auto& entry : words) {
		cout << entry.first << " ";
	}

	return 0;
}

#endif