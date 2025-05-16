#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	priority_queue<int, vector<int>, greater<int>> queueTable;

	int N{};
	cin >> N;

	for (int i = 0; i < N * N; i++)
	{
		int iNum{};

		cin >> iNum;
		queueTable.push(iNum);

		if (i >= N)
			queueTable.pop();
	}

	cout << queueTable.top();

	return 0;
}

//int main()
//{
//	priority_queue<int, vector<int>, greater<int>> queueTable;
//
//	int N{};
//	scanf("%d", &N);
//
//	for (int i = 0; i < N * N; i++)
//	{
//		int iNum{};
//
//		scanf("%d", &iNum);
//		queueTable.push(iNum);
//
//		if (i >= N)
//			queueTable.pop();
//	}
//
//	printf("%d", queueTable.top());
//
//	return 0;
//}