#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations);

int main()
{
	vector<int> citations = { 3, 0, 6, 1, 5 };

	int result = solution(citations);

	cout << result;

	return 0;
}

int solution(vector<int> citations)
{
	int answer = 0;
	
	sort(citations.begin(), citations.end());

	for (int i = 0; i < citations.size(); i++)
		if (citations[i] >= citations.size() - i)
		{
			answer = citations.size() - i;
			break;
		}

	return answer;
}

// 다른 사람의 풀이인데 정렬방식이 달라 인덱스 계산 방법만 다르지 같은 알고리즘이라고 보면 된다
// 그래도 코드가 좀 더 간결하니 보기가 좋아서 참고.
// 
//int solution(vector<int> citations) {
//	sort(citations.begin(), citations.end(), greater<int>());
//
//	for (int i = 0; i < citations.size(); ++i) {
//		if (citations[i] < i + 1) {
//			return i;
//		}
//	}
//
//	return citations.size();
//}