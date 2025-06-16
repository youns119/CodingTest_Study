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

// priority_queue�� ����� Ǯ��
// ���ʿ� �� ���� ������ �� ����
// ���� ū ���� �������� �ڵ� ������ �Ǽ� �ξ� ���ϱ� �ϴ�
// �׳� vector�� sort�ϰ� ���� �� �� ���Ƽ� heap������ ���� ����...

#ifdef _RELEASE

#include <vector>
#include <queue>
#include <numeric> // accumulate
using namespace std;

long long solution(int n, vector<int> works) {
	// �߰� ����ȭ
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

// �� �ݺ������� max_element�� ã�Ƽ� --���ִ� ���
// �ڵ尡 ���� ����ؼ� �����ͺôµ� ������ ���� ������
// max_element�� �׳� ��ȸ�ϸ鼭 ���� ū �� �������� O(n)�� ����̱� ����

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