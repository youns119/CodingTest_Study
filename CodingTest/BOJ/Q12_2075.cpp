#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// 밑에 코드를 넣지 않고서는 시간초과를 도저히 뚫을 수가 없다.... 
// 그냥 배열에 넣고 sort 때리는 단순한 방법이 유일하게 시간초과를 뚫은 방법
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

// 이게 왜 안되는지 모르겠다. 그냥 틀렸습니다 라고만 나온다.... 여기서 시간 다버림
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

// 시간초과. sort가 생각보다 시간을 많이 잡아먹는다
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

// 메모리초과. priority_queue 내부의 변수들이 생각보다 많은 듯하다
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

// 참고로 그냥 배열 sort로도 해결 가능.... 개고생했다