#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef priority_queue<int, vector<int>, greater<int>> pqGreater;

int Scoville(vector<int> scoville, int K);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> scoville;

	pqGreater pqScoville;
	int iSize{}, K{};

	cin >> iSize;

	for (int i = 0; i < iSize; i++)
	{
		int iNum{};

		cin >> iNum;
		scoville.push_back(iNum);
	}

	cin >> K;

	int iResult = Scoville(scoville, K);
	cout << iResult;

	return 0;
}

int Scoville(vector<int> scoville, int K)
{
	pqGreater pqScoville;

	for (int i = 0; i < scoville.size(); i++)
		pqScoville.push(scoville[i]);

	int answer = 0;

	while (pqScoville.top() < K)
	{
		if (pqScoville.size() == 1)
			return -1;

		int iNum1{}, iNum2{};

		iNum1 = pqScoville.top();
		pqScoville.pop();
		iNum2 = pqScoville.top();
		pqScoville.pop();

		int iSum = iNum1 + iNum2 * 2;
		pqScoville.push(iSum);

		answer++;
	}

	return answer;
}

// 다른 사람의 풀이
// vector의 값을 priority_queue에 복사하는 방법이 특이하다

#ifdef _RELEASE

int solution(vector<int> scoville, int K) {
	int answer = 0;
	int needHot;
	priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());

	while (pq.top() < K) {
		if (pq.size() == 1) return answer = -1;
		needHot = pq.top(); pq.pop();
		pq.push(needHot + pq.top() * 2);
		pq.pop(); answer++;
	}

	return answer;
}

#endif