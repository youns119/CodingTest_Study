#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void Input(vector<int>& stones, int& k);
bool Count(vector<int>& stones, int k, int M);
int solution(vector<int> stones, int k);

int main()
{
	int k, result;
	vector<int> stones;

	Input(stones, k);
	result = solution(stones, k);

	cout << result;

	return 0;
}

void Input(vector<int>& stones, int& k)
{
	int N;

	cin >> N >> k;
	stones.assign(N, 0);

	for (int i = 0; i < N; i++)
		cin >> stones[i];
}

bool Count(vector<int>& stones, int k, int M)
{
	int cnt = 0;

	for (int i = 0; i < stones.size(); i++)
	{
		if (stones[i] <= M)	cnt++;
		else				cnt = 0;

		if (cnt >= k) return false;
	}

	return true;
}

int solution(vector<int> stones, int k)
{
	int L = *min_element(stones.begin(), stones.end());
	int R = *max_element(stones.begin(), stones.end());
	
	while (L <= R)
	{
		int M = (L + R) >> 1;

		if (Count(stones, k, M)) L = M + 1;
		else					 R = M - 1;
	}

	return L;
}

// ó���� ���������� �غ����� �õ��ߴ� ���ٹ�. 
// �����̵� ������� ���������� �ӵ��� ����Ž���� ���̰� ���� ���� ������ ������
// https://yabmoons.tistory.com/632
//int solution(vector<int> stones, int k)
//{
//	int answer = 987654321;
//	deque<pair<int, int>> DQ;
//
//	for (int i = 0; i < stones.size(); i++)
//	{
//		while (DQ.empty() == false && DQ.front().second < i - k + 1) DQ.pop_front();
//		while (DQ.empty() == false && DQ.back().first < stones[i]) DQ.pop_back();
//		DQ.push_back(make_pair(stones[i], i));
//		if (i >= k - 1 && DQ.front().first < answer) answer = DQ.front().first;
//	}
//	return answer;
//}

// ��Ƽ���� Ȱ���� Ǯ��. 
// �ڵ�� ������ �ܼ��������� ���� Ž���� ���� ȿ�����˻翡�� �ӵ��� ��ʹ�� ���̰� ����.
//multiset <int> s;
//
//int solution(vector<int> a, int k) {
//	int ans = 1e9;
//	for (int i = 0; i < k - 1; i++) {
//		s.insert(a[i]);
//	}
//	for (int i = k - 1; i < a.size(); i++) {
//		s.insert(a[i]);
//		auto it = s.end(); --it;
//		ans = min(ans, *it);
//		s.erase(s.find(a[i - (k - 1)]));
//	}
//	return ans;
//}