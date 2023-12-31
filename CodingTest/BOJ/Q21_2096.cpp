#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int N;
	pair<int, int> arr[3] = { {0,0} };

	cin >> N;

	for (int i = 0; i < 3; i++)
	{
		int num;

		cin >> num;
		arr[i].first = num;
		arr[i].second = num;
	}

	for (int i = 1; i < N; i++)
	{
		int num1, num2, num3;
		int t1, t2, t3;

		cin >> num1 >> num2 >> num3;

		t1 = arr[0].first; t2 = arr[1].first; t3 = arr[2].first;
		arr[0].first = max(t1, t2) + num1;
		arr[2].first = max(t2, t3) + num3;
		arr[1].first = max(max(t1, t2), t3) + num2;

		t1 = arr[0].second; t2 = arr[1].second; t3 = arr[2].second;
		arr[0].second = min(t1, t2) + num1;
		arr[2].second = min(t2, t3) + num3;
		arr[1].second = min(min(t1, t2), t3) + num2;
	}

	cout << max(max(arr[0].first, arr[1].first), arr[2].first) << " ";
	cout << min(min(arr[0].second, arr[1].second), arr[2].second);

	return 0;
}

// 최초 풀이
// 메모리 초과
// 변수와 함수를 남발하여 메모리를 초과했다
//void Score(vector<vector<int>>& scores, vector<int>& result);
//
//int main()
//{
//	int N;
//	vector<int> result;
//	vector<vector<int>> scores;
//
//	cin >> N;
//	scores.assign(N, vector<int>(3, 0));
//
//	for (int i = 0; i < N; i++)
//		for (int j = 0; j < 3; j++)
//			cin >> scores[i][j];
//
//	Score(scores, result);
//
//	for (int i = 0; i < 2; i++)
//		cout << result[i] << " ";
//
//	return 0;
//}
//
//void Score(vector<vector<int>>& scores, vector<int>& result)
//{
//	int size = scores.size();
//	pair<int, int> arr[3];
//	int t1, t2, t3;
//
//	for (int i = 0; i < 3; i++)
//	{
//		arr[i].first = scores[0][i];
//		arr[i].second = scores[0][i];
//	}
//
//	for (int i = 1; i < size; i++)
//	{
//		t1 = arr[0].first;
//		t2 = arr[1].first;
//		t3 = arr[2].first;
//
//		arr[0].first = max(t1, t2) + scores[i][0];
//		arr[1].first = max(max(t1, t2), t3) + scores[i][1];
//		arr[2].first = max(t2, t3) + scores[i][2];
//	}
//
//	for (int i = 1; i < size; i++)
//	{
//		t1 = arr[0].second;
//		t2 = arr[1].second;
//		t3 = arr[2].second;
//
//		arr[0].second = min(t1, t2) + scores[i][0];
//		arr[1].second = min(min(t1, t2), t3) + scores[i][1];
//		arr[2].second = min(t2, t3) + scores[i][2];
//	}
//
//	result.push_back(max(max(arr[0].first, arr[1].first), arr[2].first));
//	result.push_back(min(min(arr[0].second, arr[1].second), arr[2].second));
//}