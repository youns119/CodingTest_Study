#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void BFS(const pair<int, int>& pairCurr, vector<vector<int>>& vecField);
int BaeChu(vector<vector<int>>& vecField);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int iCase{}, iRow{}, iCol{}, iCnt{};

	cin >> iCase;

	vector<int> vecResult;

	while (iCase--)
	{
		cin >> iRow >> iCol >> iCnt;

		vector<vector<int>> vecField(iRow, vector<int>(iCol, 0));

		while (iCnt--)
		{
			int iX{}, iY{};

			cin >> iX >> iY;
			vecField[iX][iY] = 1;
		}
		
		vecResult.push_back(BaeChu(vecField));
	}

	for (int iBug : vecResult)
		cout << iBug << "\n";

	return 0;
}

void BFS(const pair<int, int>& pairCurr, vector<vector<int>>& vecField)
{
	queue<pair<int, int>> qBFS;
	pair<int, int> pairDir[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

	qBFS.push(pairCurr);
	vecField[pairCurr.first][pairCurr.second]--;

	while (!qBFS.empty())
	{
		pair<int, int> pairPrev = qBFS.front();
		qBFS.pop();

		for (int i = 0; i < 4; i++)
		{
			int iX = pairPrev.first + pairDir[i].first;
			int iY = pairPrev.second + pairDir[i].second;

			if (iX < 0 || iX >= vecField.size() ||
				iY < 0 || iY >= vecField[iX].size())
				continue;
			else if (vecField[iX][iY] == 1)
			{
				qBFS.push({ iX, iY });
				vecField[iX][iY]--;
			}
		}
	}
}

int BaeChu(vector<vector<int>>& vecField)
{
	int iResult{};

	for (int i = 0; i < vecField.size(); i++)
	{
		for (int j = 0; j < vecField[i].size(); j++)
		{
			if (vecField[i][j] == 1)
			{
				BFS({ i, j }, vecField);
				iResult++;
			}
		}
	}

	return iResult;
}