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

// �ٸ� ����� Ǯ���ε� ���Ĺ���� �޶� �ε��� ��� ����� �ٸ��� ���� �˰������̶�� ���� �ȴ�
// �׷��� �ڵ尡 �� �� �����ϴ� ���Ⱑ ���Ƽ� ����.
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