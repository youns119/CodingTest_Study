#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	priority_queue<int, vector<int>, greater<int>> pqTable;

	int N{};
	cin >> N;

	for (int i = 0; i < N * N; i++)
	{
		int iNum{};

		cin >> iNum;
		pqTable.push(iNum);

		if (i >= N)
			pqTable.pop();
	}

	cout << pqTable.top();

	return 0;
}

// cin, cout 대신 scanf, prinf를 쓰는 방식 (더 빠르다고 한다)
// sync_with_studio, tie 같은 함수를 안써도 통과된다 (근데 속도는 1.5배 정도 더 느리긴하다)
// 참고로 scanf_s는 vs 전용 함수라 백준에 쓰면 컴파일 오류남

#ifdef _RELEASE

int main()
{
	priority_queue<int, vector<int>, greater<int>> queueTable;

	int N{};
	scanf("%d", &N);

	for (int i = 0; i < N * N; i++)
	{
		int iNum{};

		scanf("%d", &iNum);
		queueTable.push(iNum);

		if (i >= N)
			queueTable.pop();
	}

	printf("%d", queueTable.top());

	return 0;
}

#endif