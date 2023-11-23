#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<pair<int, int>>& hw);

bool compare(pair<int, int>& a, pair<int, int>& b)
{
	if (a.second == b.second)
		return a.first > b.first;
	else
		return a.second > b.second;
}

int main()
{
	int N, result;
	vector<pair<int, int>> hw;

	cin >> N;
	hw.assign(N, { 0,0 });

	for (int i = 0; i < N; i++)
		cin >> hw[i].first >> hw[i].second;

	result = solution(hw);
	cout << result;

	return 0;
}

int solution(vector<pair<int, int>>& hw)
{
	int result = 0;
	int size = hw.size();
	vector<bool> visit(1001, false);

	sort(hw.begin(), hw.end(), compare);

	for (int i = 0; i < size; i++)
	{
		int due = hw[i].first;
		int score = hw[i].second;

		for (int j = due; j > 0; j--)
		{
			if (visit[j] == false)
			{
				visit[j] = true;
				result += score;

				break;
			}
		}
	}

	return result;
}

// 우선순위 큐를 사용한 방법
// 우선순위 큐를 쓰면 vector를 sort해서 쓸 필요가 없다
//#include <iostream>
//#include <queue>
//#include <algorithm>
//using namespace std;
//
//int N;
//priority_queue<pair<int, int >> pq;
//bool is_visit[1002];
//
//int cnt;
//int main()
//{
//	ios_base::sync_with_stdio(false);
//	cin.tie(NULL); cout.tie(NULL);
//
//	cin >> N;
//	for (int i = 0; i < N; i++) {
//		int d, w;
//		cin >> d >> w;
//		pq.push({ w,-d });
//	}
//
//	while (!pq.empty()) {
//		int day = -pq.top().second;
//		int score = pq.top().first;
//		pq.pop();
//
//		for (int i = day; i >= 1; i--) {
//			if (!is_visit[i]) {
//				is_visit[i] = true;
//				cnt += score;
//				break;
//			}
//		}
//	}
//	cout << cnt << "\n";
//}