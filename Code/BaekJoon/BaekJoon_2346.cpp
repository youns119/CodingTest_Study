#include <iostream>
#include <deque>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	deque<pair<int, int>> dqBalloon;
	int iCount{};

	cin >> iCount;

	for (int i = 0; i < iCount; i++)
	{
		int iNum{};

		cin >> iNum;
		dqBalloon.push_back({ i + 1, iNum });
	}

	int iMove{ 1 };
	while (!dqBalloon.empty())
	{
		bool bReverse{};
		if (iMove < 0)
		{
			iMove *= -1;
			bReverse = true;
		}

		pair<int, int> pairBalloon{};
		for (int i = 0; i < iMove; i++)
		{
			if (!bReverse)
			{
				pairBalloon = dqBalloon.front();
				dqBalloon.pop_front();
			}
			else
			{
				pairBalloon = dqBalloon.back();
				dqBalloon.pop_back();
			}

			if (i < iMove - 1)
			{
				if (!bReverse) dqBalloon.push_back(pairBalloon);
				else dqBalloon.push_front(pairBalloon);
			}
		}

		iMove = pairBalloon.second;
		cout << pairBalloon.first << " ";
	}

	return 0;
}

// deque 대신 list를 쓰는 풀이
// 중간 삽입 삭제를 위해서 양방향 리스트인 list를 사용하고 iterator를 사용해 순회한다
// list를 쓰면 계속 iterator로 begin, end를 확인해야 하기 때문에 deque를 쓰는 편이 더 직관적인 것 같다

#ifdef _RELEASE

#include <iostream>
#include <list>
using namespace std;

int main() {
	int N;
	cin >> N;

	list<pair<int, int>> balloons;
	for (int i = 1; i <= N; ++i) {
		int move;
		cin >> move;
		balloons.push_back({ i, move });
	}

	auto it = balloons.begin();
	while (!balloons.empty()) {
		int index = it->first;
		int move = it->second;

		cout << index << " ";
		it = balloons.erase(it);

		if (balloons.empty()) break;

		if (move > 0) {
			move--;
			while (move--) {
				if (it == balloons.end()) it = balloons.begin();
				++it;
				if (it == balloons.end()) it = balloons.begin();
			}
		}
		else {
			while (move++) {
				if (it == balloons.begin()) it = balloons.end();
				--it;
			}
		}
	}

	return 0;
}

#endif