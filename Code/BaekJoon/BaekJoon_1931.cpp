#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int iCnt{};

	cin >> iCnt;
	vector<pair<int, int>> vecMeeting(iCnt);

	for (int i = 0; i < iCnt; ++i)
		cin >> vecMeeting[i].first >> vecMeeting[i].second;

	sort(vecMeeting.begin(), vecMeeting.end(), [](const auto& PairA, const auto& PairB)
		{
			if (PairA.second == PairB.second)
				return PairA.first < PairB.first;

			return PairA.second < PairB.second;
		});

	int iResult{};
	int iEnd{};

	for(auto Pair : vecMeeting)
		if (Pair.first >= iEnd)
		{
			iEnd = Pair.second;
			++iResult;
		}

	cout << iResult;

	return 0;
}

// ���� ó���� �õ��ߴ� Ǯ��
// map + DFS�� �õ������� ��� ���� Ž���̶� ��� �ð� �ʰ��� ��

#ifdef _RELEASE

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <cmath>
#include <limits.h>

using namespace std;

void Meeting(map<int, vector<int>>& mapMeeting, int iCurr, int iSum, int& iResult);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int iCnt{}, iMax{};

	cin >> iCnt;
	map<int, vector<int>> mapMeeting;

	for (int i = 0; i < iCnt; ++i)
	{
		int iStart{}, iEnd{};

		cin >> iStart >> iEnd;
		iMax = max(iMax, iEnd);

		mapMeeting[iStart].push_back(iEnd);
	}

	for (auto Pair : mapMeeting)
		sort(Pair.second.begin(), Pair.second.end());

	int iResult{};
	Meeting(mapMeeting, 0, 0, iResult);

	cout << iResult;

	return 0;
}

void Meeting(map<int, vector<int>>& mapMeeting, int iCurr, int iSum, int& iResult)
{
	iResult = max(iResult, iSum);

	int iMinEnd{ INT_MAX };

	for (auto Pair : mapMeeting)
	{
		if (iCurr <= Pair.first)
		{
			iMinEnd = min(iMinEnd, Pair.second[0]);
			if (iMinEnd < Pair.first)
				break;

			Meeting(mapMeeting, Pair.second[0], iSum + 1, iResult);
		}
	}
}

#endif

// �׸��� + �켱���� ť�� ����� ���
// priority_queue�� �ڵ����� ���п� sort�� ���ص� �Ǵ� ������ ����
// �ٵ� ������ priority_queue�� ���������� ��� �������ִ� �� ���������̱� ������ �ð����⵵�� N O(logN)���� ����

#ifdef _RELEASE

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	// (end, start) ���·� ���ĵǰԲ� �ִ´�
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

	for (int i = 0; i < n; ++i)
	{
		int start, end;
		cin >> start >> end;
		pq.push({ end, start });
	}

	int count = 0;
	int lastEnd = 0;

	while (!pq.empty())
	{
		auto Pair = pq.top();
		pq.pop();

		if (Pair.second >= lastEnd)
		{
			++count;
			lastEnd = Pair.first;
		}
	}

	cout << count;
	return 0;
}

#endif