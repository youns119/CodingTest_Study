#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int iCnt{};
	int iWidth{}, iHeight{};
	int iArea{};
	int arrPair[5] = { 0, 3, 4, 2, 1 };
	vector<pair<int, int>> vecLine;

	cin >> iCnt;

	for (int i = 0; i < 6; i++)
	{
		int iDir{}, iDist{};

		cin >> iDir >> iDist;
		vecLine.push_back({ iDir, iDist });

		if (iDir == 1 || iDir == 2)
			iWidth = max(iWidth, iDist);
		else if (iDir == 3 || iDir == 4)
			iHeight = max(iHeight, iDist);
	}

	iArea += iWidth * iHeight;

	for (int i = 0; i < 6; i++)
	{
		int iNext = (i + 1) % 6;

		if (vecLine[iNext].first == arrPair[vecLine[i].first])
			iArea -= vecLine[i].second * vecLine[iNext].second;
	}

	iArea *= iCnt;

	cout << iArea;

	return 0;
}

// 2차원 좌표를 사용한 풀이 방법
// Shoelace 공식이란 걸 사용하는 듯하다

#ifdef _RELEASE

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	int k;
	cin >> k;

	vector<pair<int, int>> points(7); // 꼭짓점 6개 + 마지막은 첫 점 복사

	int x = 0, y = 0;
	points[0] = { x, y };

	for (int i = 1; i <= 6; ++i)
	{
		int dir, dist;
		cin >> dir >> dist;

		switch (dir)
		{
		case 1: x += dist; break; // 동
		case 2: x -= dist; break; // 서
		case 3: y -= dist; break; // 남
		case 4: y += dist; break; // 북
		}

		points[i] = { x, y };
	}

	// Shoelace 공식
	int area = 0;
	for (int i = 0; i < 6; ++i)
	{
		area += points[i].first * points[i + 1].second;
		area -= points[i + 1].first * points[i].second;
	}

	area = abs(area) / 2;

	cout << area * k;
	return 0;
}

#endif

// 위의 방법을 더 최적화한 방식
// 공부가 필요하다...

#ifdef _RELEASE

#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int k;
	cin >> k;

	int dx[7] = { 0 }; // x 변화량
	int y = 0;       // 현재 y 좌표
	int area = 0;

	for (int i = 1; i <= 6; i++) {
		int dir, len;
		cin >> dir >> len;

		// x 방향 변화량 저장
		if (dir == 1) dx[i] = len;       // 동
		else if (dir == 2) dx[i] = -len; // 서
		else dx[i] = 0;                  // 남북은 x 변화 없음

		// y 좌표 변화
		if (dir == 3) y -= len;          // 남
		else if (dir == 4) y += len;     // 북

		// 누적 면적 (x변화량 * 현재 y좌표)
		area += -dx[i] * y;
	}

	cout << area * k;
	return 0;
}

#endif