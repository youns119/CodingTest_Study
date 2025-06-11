#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

using namespace std;

typedef vector<vector<pair<int, int>>> Matrix;

int BFS(int iStart, int iA, int iB, const Matrix& matPath);
int solution(int n, int s, int a, int b, vector<vector<int>> fares);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int iCnt{}, iPath{}, iStart{}, iA{}, iB{};

	cin >> iCnt >> iPath >> iStart >> iA >> iB;
	vector<vector<int>> vecPath(iPath, vector<int>(3, 0));

	for (int i = 0; i < iPath; ++i)
		for (int j = 0; j < 3; ++j)
			cin >> vecPath[i][j];

	cout << solution(iCnt, iStart, iA, iB, vecPath);

	return 0;
}

int BFS(int iStart, int iA, int iB, const Matrix& matPath)
{
	vector<int> vecFare(matPath.size() + 1, -1);
	queue<int> qBFS;
	
	qBFS.push(iStart);
	vecFare[iStart] = 0;

	while (!qBFS.empty())
	{
		int iPrev = qBFS.front();
		qBFS.pop();

		for (int i = 0; i < matPath[iPrev].size(); ++i)
		{
			int iNext = matPath[iPrev][i].first;
			int iCost = vecFare[iPrev] + matPath[iPrev][i].second;

			if (vecFare[iNext] == -1 ||
				vecFare[iNext] > iCost)
			{
				vecFare[iNext] = iCost;
				qBFS.push(iNext);
			}
		}
	}

	return vecFare[iA] + vecFare[iB];
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares)
{
	int answer = 0;

	Matrix matPath(n + 1);

	for (auto vecFare : fares)
	{
		int iA = vecFare[0];
		int iB = vecFare[1];
		int iFare = vecFare[2];

		matPath[iA].push_back({ iB, iFare });
		matPath[iB].push_back({ iA, iFare });

		answer += iFare;
	}

	int iResult{};
	vector<int> vecFare(n + 1, -1);
	queue<int> qBFS;

	qBFS.push(s);
	vecFare[s] = 0;

	while (!qBFS.empty())
	{
		int iPrev = qBFS.front();
		qBFS.pop();

		for (int i = 0; i < matPath[iPrev].size(); ++i)
		{
			int iNext = matPath[iPrev][i].first;
			int iCost = vecFare[iPrev] + matPath[iPrev][i].second;

			if (vecFare[iNext] == -1 ||
				vecFare[iNext] > iCost)
			{
				vecFare[iNext] = iCost;
				qBFS.push(iNext);

				iCost += BFS(iNext, a, b, matPath);
				answer = min(answer, iCost);
			}
		}
	}

	return answer;
}