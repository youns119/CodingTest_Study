#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int BFS(int iNum, const vector<vector<int>>& vecWire);
int solution(int n, vector<vector<int>> wires);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int iCount{};

	cin >> iCount;
	vector<vector<int>> vecWire(iCount);

	for (int i = 0; i < iCount - 1; i++)
	{
		int iNum1{}, iNum2{};

		cin >> iNum1 >> iNum2;
		vecWire[iNum1].push_back(iNum2);
	}

	cout << solution(iCount, vecWire);

	return 0;
}

int BFS(int iNum, const vector<vector<int>>& vecWire)
{


	return 0;
}

int solution(int n, vector<vector<int>> wires)
{
	int answer = -1;



	return answer;
}