#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities);

int main()
{
	int cacheSize, N;
	int result;
	vector<string> cities;

	cin >> N >> cacheSize;
	cities.assign(N, "");

	for (int i = 0; i < N; i++)
		cin >> cities[i];

	result = solution(cacheSize, cities);

	return 0;
}

int solution(int cacheSize, vector<string> cities)
{
	int answer = 0;
	int size = cities.size();
	list<string> caches;

	for (int i = 0; i < size; i++)
		for (int j = 0; j < cities[i].length(); j++)
			cities[i][j] = tolower(cities[i][j]);

	for (int i = 0; i < size; i++)
	{
		auto it = find(caches.begin(), caches.end(), cities[i]);

		if (it != caches.end())
		{
			answer += 1;
			caches.erase(it);
			caches.push_back(cities[i]);
		}
		else
		{
			answer += 5;

			if (cacheSize == 0)
				continue;

			if (caches.size() == cacheSize)
				caches.pop_front();

			caches.push_back(cities[i]);
		}
	}

	return answer;
}

// 벡터만 사용한 풀이. 참고가 된다
//int solution(int cacheSize, vector<string> cities) {
//
//	vector <string> q;
//	int duration = 0;
//
//	for (vector <string>::iterator it = cities.begin(); it != cities.end(); it++) {
//		transform(it->begin(), it->end(), it->begin(), ::tolower);
//
//		bool flag = false;
//		for (vector<string>::iterator itt = q.begin(); itt != q.end(); itt++) {
//			if (*itt == *it) {
//				flag = true;
//				duration += 1;
//				q.erase(itt);
//				q.push_back(*it);
//				break;
//			}
//		}
//		if (!flag) {
//			duration += 5;
//			if (cacheSize != 0 && q.size() >= cacheSize)
//				q.erase(q.begin());
//			if (q.size() < cacheSize)
//				q.push_back(*it);
//		}
//	}
//
//	return duration;
//}