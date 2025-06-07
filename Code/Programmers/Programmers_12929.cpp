#include <iostream>
#include <vector>
#include <functional>

using namespace std;

int solution(int n);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int iCnt{};

	cin >> iCnt;
	cout << solution(iCnt);

	return 0;
}

int solution(int n) 
{
	int answer = 0;

	function<void(int iLeft, int iRight)> DFS = [&](int iLeft, int iRight)
		{
			if (iLeft == n && iRight == n)
			{
				answer++;
				return;
			}

			if (iLeft < n)
				DFS(iLeft + 1, iRight);
			if (iLeft > iRight)
				DFS(iLeft, iRight + 1);
		};

	DFS(1, 0);

	return answer;
}