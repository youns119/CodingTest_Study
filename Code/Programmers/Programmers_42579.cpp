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

// unordered_map을 쓰는건 동일하지만 vector 대신 priority_queue를 사용해서
// 삽입할 때부터 정렬되도록 하는 방식
// sort를 한번 줄여주지만 priority_queue도 내부적으로 정렬하는건 동일하다
// 하지만 priority_queue는 맨 위값만 뽑아주는 것이기 때문에 sort보다는 빠르긴함
// 그래도 가독성 생각해보면 sort가 확실히 잘 보이긴한다
// 참고로 -i식으로 tie-break 상황에서 인덱스가 작은 순으로 정렬하도록 하는 디테일이 중요

#ifdef _RELEASE

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
	unordered_map<string, int> genre_total;
	unordered_map<string, priority_queue<pair<int, int>>> genre_songs;

	for (int i = 0; i < genres.size(); ++i) {
		genre_total[genres[i]] += plays[i];
		// priority_queue: {재생 수, -인덱스}로 저장 (tie-break 위해)
		genre_songs[genres[i]].push({ plays[i], -i });
	}

	// 장르 정렬 (총 재생 수 기준)
	vector<string> sorted_genres;
	for (auto& [genre, _] : genre_total)
		sorted_genres.push_back(genre);

	sort(sorted_genres.begin(), sorted_genres.end(),
		[&](const string& a, const string& b) {
			return genre_total[a] > genre_total[b];
		});

	// 결과 구성
	vector<int> answer;
	for (const string& genre : sorted_genres) {
		auto& pq = genre_songs[genre];
		for (int i = 0; i < 2 && !pq.empty(); ++i) {
			auto [play, neg_idx] = pq.top(); pq.pop();
			answer.push_back(-neg_idx); // index 복원
		}
	}

	return answer;
}

#endif

// 동일하게 unordered_map을 쓰지만 vector 대신 multimap을 쓰는 방식
// multimap도 map과 동일하게 key값으로 자동정렬을 해주기 때문에 sort 수를 한번 줄여준다
// priority_queue와는 다르게 -i 식으로 tie-break 상황을 고려해주지 않아도 된다
// 굳이 따지자면 priority_queue를 사용하는 방법보다는 나은것 같지만 
// 그냥 sort 쓰는게 가독성도 좋고 헤더 포함 수도 적어서 제일 좋은 것 같다

#ifdef _RELEASE

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
	unordered_map<string, int> genre_total;
	unordered_map<string, multimap<int, int, greater<>>> genre_songs;

	for (int i = 0; i < genres.size(); ++i) {
		genre_total[genres[i]] += plays[i];
		genre_songs[genres[i]].insert({ plays[i], i }); // 자동 정렬
	}

	vector<string> sorted_genres;
	for (auto& [genre, _] : genre_total)
		sorted_genres.push_back(genre);

	sort(sorted_genres.begin(), sorted_genres.end(),
		[&](const string& a, const string& b) {
			return genre_total[a] > genre_total[b];
		});

	vector<int> answer;
	for (const string& genre : sorted_genres) {
		int count = 0;
		for (auto& [play, idx] : genre_songs[genre]) {
			answer.push_back(idx);
			if (++count == 2) break;
		}
	}

	return answer;
}

#endif