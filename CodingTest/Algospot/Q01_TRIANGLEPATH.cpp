#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Triangle(vector<vector<int>> triangle);

int main()
{
	int test, size, num;
	vector<vector<int>> triangle;
	vector<int> results;

	cin >> test;

	for (int i = 0; i < test; i++)
	{
		cin >> size;
		triangle.assign(size, vector<int>(size, 0));

		for (int j = 0; j < size; j++)
			for (int k = 0; k <= j; k++)
				cin >> triangle[j][k];

		results.push_back(Triangle(triangle));
	}

	for (auto result : results)
		cout << result << "\n";

	return 0;
}

int Triangle(vector<vector<int>> triangle)
{
	int size = triangle.size();
	int result = 0;
	vector<vector<int>> MAX(size, vector<int>(size, 0));

	MAX[0][0] = triangle[0][0];

	for (int i = 1; i < size; i++)
	{
		MAX[i][0] = MAX[i - 1][0] + triangle[i][0];

		for (int j = 1; j <= i; j++)
		{
			MAX[i][j] = max(MAX[i - 1][j - 1] + triangle[i][j], MAX[i - 1][j] + triangle[i][j]);
			result = max(result, MAX[i][j]);
		}
	}

	return result;
}

// 우진님 솔루션. 나랑은 살짝 다른 방식의 접근이 재밌다.
//int Solution(const vector<vector<int>>& vec)
//{
//	int Answer = 0;
//	int Size = vec.size();
//	vector<vector<int>> Dp(Size, vector<int>(Size, 0));
//
//	for (int i = 0; i < Size; i++)
//	{
//		Dp[Size - 1][i] = vec[Size - 1][i];
//	}
//
//	for (int i = Size - 2; i >= 0; i--)
//	{
//		for (int j = 0; j < Size - 1; j++)
//		{
//			Dp[i][j] = max(Dp[i + 1][j] + vec[i][j], Dp[i + 1][j + 1] + vec[i][j]);
//		}
//	}
//
//	Answer = Dp[0][0];
//
//	return Answer;
//}
//
//int main()
//{
//	int C;
//	cin >> C;
//
//	for (int i = 0; i < C; i++)
//	{
//		int n;
//		cin >> n;
//		vector<vector<int>> Triangle(n, vector<int>(n, 0));
//
//		for (int i = 0; i < n; i++)
//		{
//			for (int j = 0; j <= i; j++)
//			{
//				int Num;
//				cin >> Num;
//
//				Triangle[i][j] = Num;
//			}
//		}
//
//		cout << Solution(Triangle) << "\n";
//	}
//
//	return 0;
//}