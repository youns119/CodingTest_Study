#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int iDay{}, iCons{};

	cin >> iDay >> iCons;
	vector<int> vecDay(iDay + 1);
	
	vector<int> vecSum;
	int iSum{};

	for (int i = 1; i < iDay + 1; i++)
	{
		cin >> vecDay[i];
		iSum += vecDay[i];

		if (i >= iCons)
		{
			iSum -= vecDay[i - iCons];
			vecSum.push_back(iSum);
		}
	}

	sort(vecSum.begin(), vecSum.end(), [](const int& iA, const int& iB)
		{
			return iA > iB;
		}
	);

	cout << vecSum[0];

	return 0;
}

// max 함수 써서 푸는 방법
// 사실상 별 차이는 없다
// 굳이 장점이라면 vector 컨테이너 하나 덜 쓰는거랑 sort 함수 써서 정렬할 필요 없는거?
// sort 함수 써서 정렬하는 것도 사실 귀찮아서 그렇게 한거지 위의 풀이도 max 구하는 식으로 충분히 가능

#ifdef _RELEASE

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, K;
	cin >> N >> K;

	vector<int> temp(N);
	for (int i = 0; i < N; ++i)
		cin >> temp[i];

	int sum = 0;
	for (int i = 0; i < K; ++i)
		sum += temp[i];

	int maxSum = sum;

	for (int i = K; i < N; ++i) {
		sum += temp[i] - temp[i - K];
		maxSum = max(maxSum, sum);
	}

	cout << maxSum << "\n";

	return 0;
}

#endif