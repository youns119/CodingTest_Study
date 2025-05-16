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

// cin, cout ��� scanf, prinf�� ���� ��� (�� �����ٰ� �Ѵ�)
// sync_with_studio, tie ���� �Լ��� �Ƚᵵ ����ȴ� (�ٵ� �ӵ��� 1.5�� ���� �� �������ϴ�)
// ����� scanf_s�� vs ���� �Լ��� ���ؿ� ���� ������ ������

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