#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<pair<int, int>> vecCoord;
	int iCount{};

	cin >> iCount;

	for (int i = 0; i < iCount; i++)
	{
		int iNum{};

		cin >> iNum;
		vecCoord.push_back({ i, iNum });
	}

	sort(vecCoord.begin(), vecCoord.end(), [](const pair<int, int>& pairA, const pair<int, int>& pairB)
		{
			return pairA.second < pairB.second;
		}
	);

	int iCurrCoord{ -1000000001 };
	int iTrans{ -1 };
	for (int i = 0; i < vecCoord.size(); i++)
	{
		if (vecCoord[i].second > iCurrCoord)
		{
			iCurrCoord = vecCoord[i].second;
			iTrans++;
		}

		if (vecCoord[i].second == iCurrCoord)
			vecCoord[i].second = iTrans;
	}

	sort(vecCoord.begin(), vecCoord.end(), [](const pair<int, int>& pairA, const pair<int, int>& pairB)
		{
			return pairA.first < pairB.first;
		}
	);

	for (auto Pair : vecCoord)
		cout << Pair.second << " ";

	return 0;
}

// vector의 중복 제거와 map의 자동 정렬을 이용해 푸는 해법
// vector의 중복 제거 방식이 신기하다
// erase는 중복된 값들을 하나만 남기고 뒤로 다 옮긴 후 중복이 아닌 요소의 다음 위치의 iterator를 반환하는 함수
// 찾아보니 vector 내의 요소들의 중복을 제거하는 정말 자주 쓰이는 구문이라는 듯 하다 (잘 기억해두면 좋을 듯!)
// map에 값을 넣으면 오름차순으로 정렬된다는 걸 잘 활용한 것 같다

#ifdef _RELEASE

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;
	cin >> N;

	vector<int> vec(N);
	for (int i = 0; i < N; ++i)
		cin >> vec[i];

	vector<int> sorted = vec;
	sort(sorted.begin(), sorted.end());

	sorted.erase(unique(sorted.begin(), sorted.end()), sorted.end());

	map<int, int> compression;
	for (int i = 0; i < sorted.size(); ++i)
		compression[sorted[i]] = i;

	for (int i = 0; i < N; ++i)
		cout << compression[vec[i]] << " ";

	return 0;
}

#endif