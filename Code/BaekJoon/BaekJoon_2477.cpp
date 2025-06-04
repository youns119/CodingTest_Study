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

// 좌표를 사용한 풀이 방법
// Shoelace 공식이란 걸 사용하는 듯하다
// 수학적 공식인데 솔직히 뭐

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