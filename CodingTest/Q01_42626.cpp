#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(priority_queue<int, vector<int>, greater<int>>& scoville, int K);

int main()
{
	priority_queue<int, vector<int>, greater<int>> scoville;
	int size;
	int K;
	int answer;

	cin >> size;

	for (int i = 0; i < size; i++)
	{
		int num;
		cin >> num;
		scoville.push(num);
	}

	cin >> K;

	answer = solution(scoville, K);

	cout << answer;

	return 0;
}

int solution(priority_queue<int, vector<int>, greater<int>>& scoville, int K)
{
	int answer = 0;

	while (scoville.top() < K)
	{
		if (scoville.size() == 1)
			return -1;

		int first, second, result;

		first = scoville.top();
		scoville.pop();
		second = scoville.top();
		scoville.pop();

		result = first + second * 2;
		scoville.push(result);

		answer++;
	}

	return answer;
}


// 다른 사람 풀이인데 우선순위 큐의 벡터 복사하는 방식이 새롭다
//#include <vector>
//#include <queue>
//
//using namespace std;
//
//int solution(vector<int> scoville, int K) {
//	int answer = 0;
//	int needHot;
//	priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());
//
//	while (pq.top() < K) {
//		if (pq.size() == 1) return answer = -1;
//		needHot = pq.top(); pq.pop();
//		pq.push(needHot + pq.top() * 2);
//		pq.pop(); answer++;
//	}
//
//	return answer;
//}