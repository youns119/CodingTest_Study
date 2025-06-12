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

// unordered_map�� ���°� ���������� vector ��� priority_queue�� ����ؼ�
// ������ ������ ���ĵǵ��� �ϴ� ���
// sort�� �ѹ� �ٿ������� priority_queue�� ���������� �����ϴ°� �����ϴ�
// ������ priority_queue�� �� ������ �̾��ִ� ���̱� ������ sort���ٴ� ��������
// �׷��� ������ �����غ��� sort�� Ȯ���� �� ���̱��Ѵ�
// ����� -i������ tie-break ��Ȳ���� �ε����� ���� ������ �����ϵ��� �ϴ� �������� �߿�

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
		// priority_queue: {��� ��, -�ε���}�� ���� (tie-break ����)
		genre_songs[genres[i]].push({ plays[i], -i });
	}

	// �帣 ���� (�� ��� �� ����)
	vector<string> sorted_genres;
	for (auto& [genre, _] : genre_total)
		sorted_genres.push_back(genre);

	sort(sorted_genres.begin(), sorted_genres.end(),
		[&](const string& a, const string& b) {
			return genre_total[a] > genre_total[b];
		});

	// ��� ����
	vector<int> answer;
	for (const string& genre : sorted_genres) {
		auto& pq = genre_songs[genre];
		for (int i = 0; i < 2 && !pq.empty(); ++i) {
			auto [play, neg_idx] = pq.top(); pq.pop();
			answer.push_back(-neg_idx); // index ����
		}
	}

	return answer;
}

#endif

// �����ϰ� unordered_map�� ������ vector ��� multimap�� ���� ���
// multimap�� map�� �����ϰ� key������ �ڵ������� ���ֱ� ������ sort ���� �ѹ� �ٿ��ش�
// priority_queue�ʹ� �ٸ��� -i ������ tie-break ��Ȳ�� ��������� �ʾƵ� �ȴ�
// ���� �����ڸ� priority_queue�� ����ϴ� ������ٴ� ������ ������ 
// �׳� sort ���°� �������� ���� ��� ���� ���� ��� ���� ���� �� ����

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
		genre_songs[genres[i]].insert({ plays[i], i }); // �ڵ� ����
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