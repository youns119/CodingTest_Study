#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

typedef long long ll;

ll solution(int n, vector<int> works);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int iCnt{}, iTime{};

	cin >> iCnt;
	vector<int> vecWork(iCnt);

	for (int i = 0; i < iCnt; ++i)
		cin >> vecWork[i];

	cin >> iTime;

	cout << solution(iTime, vecWork);

	return 0;
}

ll solution(int n, vector<int> works) 
{
	ll answer = 0;

	sort(works.begin(), works.end(),
		[](const int iA, const int iB)
		{
			return iA > iB;
		});

	int iIter{}, iPrev{ works[0] };
	while (n--)
	{
		if (iPrev > works[iIter])
		{
			iIter = 0; n++;
			iPrev = works[0];
			continue;
		}

		iPrev = works[iIter];
		--works[iIter]; ++iIter;
	}

	for (int iWork : works)
		answer += pow(iWork, 2);

	return answer;
}

// priority_queue를 사용한 풀이
// 애초에 이 쪽이 정석인 것 같다
// 가장 큰 값을 기준으로 자동 정렬이 되서 훨씬 편하긴 하다
// 그냥 vector로 sort하고 쓰면 될 것 같아서 heap까지는 생각 못함...

#ifdef _RELEASE

#include <vector>
#include <queue>
#include <numeric> // accumulate
using namespace std;

long long solution(int n, vector<int> works) {
	// 추가 최적화
	if (accumulate(works.begin(), works.end(), 0LL) <= n)
		return 0;

	priority_queue<int> pq;
	for (int work : works)
		pq.push(work);

	while (n-- && !pq.empty()) {
		int top = pq.top(); pq.pop();
		if (top <= 0) break;
		pq.push(top - 1);
	}

	long long answer = 0;
	while (!pq.empty()) {
		long long val = pq.top(); pq.pop();
		answer += val * val;
	}

	return answer;
}

#endif

// 매 반복문마다 max_element를 찾아서 --해주는 방식
// 코드가 가장 깔끔해서 가져와봤는데 성능은 별로 안좋다
// max_element가 그냥 순회하면서 가장 큰 값 가져오는 O(n)의 방식이기 때문

#ifdef _RELEASE

#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

long long solution(int n, vector<int> works)
{
	long long answer = 0;

	while (n != 0)
	{
		*max_element(works.begin(), works.end()) -= 1;
		n -= 1;

	}
	for (int i = 0; i < works.size(); i++)
	{
		answer += pow(works[i], 2);
	}

	return answer;
}

#endif