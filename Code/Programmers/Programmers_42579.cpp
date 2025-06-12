#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int iCnt{};

	cin >> iCnt;
	vector<string> vecGenre(iCnt);
	vector<int> vecPlay(iCnt);

	for (int i = 0; i < iCnt; ++i)
		cin >> vecGenre[i];

	for (int i = 0; i < iCnt; ++i)
		cin >> vecPlay[i];

	vector<int> vecResult = solution(vecGenre, vecPlay);

	for (int Result : vecResult)
		cout << Result << "\n";

	return 0;
}

vector<int> solution(vector<string> genres, vector<int> plays) 
{
	vector<int> answer;

	unordered_map<string, int> umapGenre;
	unordered_map<string, vector<pair<int, int>>> umapSong;

	for (int i = 0; i < plays.size(); ++i)
	{
		umapGenre[genres[i]] += plays[i];
		umapSong[genres[i]].push_back({ i, plays[i] });
	}

	vector<pair<string, int>> vecGenre(umapGenre.begin(), umapGenre.end());
	sort(vecGenre.begin(), vecGenre.end(),
		[](const auto& A, const auto& B)
		{
			return A.second > B.second;
		});

	for (auto Pair : vecGenre)
	{
		vector<pair<int, int>> vecSong = umapSong[Pair.first];

		sort(vecSong.begin(), vecSong.end(),
			[](const auto& A, const auto& B)
			{
				if (A.second == B.second)
					return A.first < B.first;

				return A.second > B.second;
			});

		int iCnt{};
		for (int i = 0; i < vecSong.size() && iCnt < 2; ++i, ++iCnt)
			answer.push_back(vecSong[i].first);
	}

	return answer;
}