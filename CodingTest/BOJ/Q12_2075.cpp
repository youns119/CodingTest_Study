#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// �ؿ� �ڵ带 ���� �ʰ����� �ð��ʰ��� ������ ���� ���� ����.... 
// �׳� �迭�� �ְ� sort ������ �ܼ��� ����� �����ϰ� �ð��ʰ��� ���� ���
//ios::sync_with_stdio(false);
//cin.tie(nullptr);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int size;
	priority_queue<int, vector<int>, greater<int>> table;

	cin >> size;

	for (int i = 0; i < size * size; i++)
	{
		int num;

		cin >> num;
		table.push(num);

		if (table.size() > size)
			table.pop();
	}

	cout << table.top();
}

// �̰� �� �ȵǴ��� �𸣰ڴ�. �׳� Ʋ�Ƚ��ϴ� ����� ���´�.... ���⼭ �ð� �ٹ���
//int main()
//{
//	ios::sync_with_stdio(false);
//	cin.tie(nullptr);
//
//	int size;
//	priority_queue<int, vector<int>, greater<int>> table(size, 0);
//
//	cin >> size;
//
//	for (int i = 0; i < size * size; i++)
//	{
//		int num;
//
//		cin >> num;
//
//		if (num > table.top())
//		{
//			table.pop();
//			table.push(num);
//		}
//	}
//
//	cout << table.top();
//}

// �ð��ʰ�. sort�� �������� �ð��� ���� ��ƸԴ´�
//int main()
//{
//	int size;
//	vector<int> row;
//
//	cin >> size;
//	row.assign(size, 0);
//
//	for (int i = 0; i < size * size; i++)
//	{
//		int num;
//
//		cin >> num;
//
//		row[0] = row[0] > num ? row[0] : num;
//		sort(row.begin(), row.end());
//	}
//
//	cout << row[0];
//
//}

// �޸��ʰ�. priority_queue ������ �������� �������� ���� ���ϴ�
//int main()
//{
//	int size, result;
//	priority_queue<int, vector<int>> table;
//	
//	cin >> size;
//
//	for (int i = 0; i < size * size; i++)
//	{
//		int num;
//
//		cin >> num;
//		table.push(num);
//	}
//
//	for (int i = 0; i < size; i++)
//	{
//		result = table.top();
//		table.pop();
//	}
//
//	cout << result;
//
//	return 0;
//}

// ������ �׳� �迭 sort�ε� �ذ� ����.... �������ߴ�