#include <iostream>
#include <vector>
#include <functional>
#include <cmath>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int iLesson{}, iBluray{};

	cin >> iLesson >> iBluray;
	vector<int> vecLesson(iLesson);

	int iMaxLen{}, iTotalLen{};

	for (int i = 0; i < iLesson; i++)
	{
		cin >> vecLesson[i];

		iMaxLen = max(iMaxLen, vecLesson[i]);
		iTotalLen += vecLesson[i];
	}

	int iLeft = iMaxLen, iRight = iTotalLen;
	int iResult = iRight;

	while (iLeft <= iRight)
	{
		int iMid = (iLeft + iRight) / 2;
		int iCount{ 1 }, iSum{};

		for (int i = 0; i < iLesson; i++)
		{
			if (iSum + vecLesson[i] > iMid)
			{
				iCount++;
				iSum = 0;
			}

			iSum += vecLesson[i];
		}

		if (iCount <= iBluray)
		{
			iResult = iMid;
			iRight = iMid - 1;
		}
		else iLeft = iMid + 1;
	}

	cout << iResult;

	return 0;
}

// 차이점이 있다면 mat_element의 사용과 sum에 나머지 값이 있다면 cnt++를 해주는 로직이 추가된 것 정도
// 이분 탐색은 기준을 정하는 것이 핵심이고 과정은 거의 비슷한 듯하다

#ifdef _RELEASE

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
int n, m;
int arr[100001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int l, r = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		r += arr[i];
	}
	l = *max_element(arr, arr + n);

	while (l <= r) {
		int mid = (l + r) / 2;

		int sum = 0, cnt = 0;
		for (int i = 0; i < n; i++) {
			if (sum + arr[i] > mid) {
				sum = 0;
				cnt++;
			}
			sum += arr[i];
		}
		if (sum != 0) cnt++;

		if (cnt > m) {
			l = mid + 1;
		}
		else {
			r = mid - 1;
		}
	}

	cout << l;
	return 0;
}

#endif