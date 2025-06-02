#include <iostream>
#include <string>
#include <vector>
#include <functional>

using namespace std;

int Fork(vector<string>& vecStorage, char chReq);
int Crane(vector<string>& vecStorage, char chReq);
int solution(vector<string> storage, vector<string> requests);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int iRow{}, iCol{};

	cin >> iRow >> iCol;
	vector<string> vecStorage(iCol);

	for (int i = 0; i < iCol; i++)
		cin >> vecStorage[i];

	int iCnt{};

	cin >> iCnt;
	vector<string> vecRequest(iCnt);

	for (int i = 0; i < iCnt; i++)
		cin >> vecRequest[i];

	cout << solution(vecStorage, vecRequest);

	return 0;
}

int Fork(vector<string>& vecStorage, char chReq)
{
	int iResult{};
	pair<int, int> pairNext[4] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
	vector<pair<int, int>> vecResult;

	function<bool(pair<int, int>, pair<int, int>)> dfs =
		[&](pair<int, int> pairCurr, pair<int, int> pairPrev) -> bool
		{
			for (int i = 0; i < 4; i++)
			{
				int iFirst = pairCurr.first + pairNext[i].first;
				int iSecond = pairCurr.second + pairNext[i].second;

				if (iFirst == pairPrev.first && iSecond == pairPrev.second)
					continue;

				if (iFirst < 0 || iFirst >= vecStorage.size() ||
					iSecond < 0 || iSecond >= vecStorage[0].size())
					return true;
				else if (vecStorage[iFirst][iSecond] == '@')
				{
					bool bFinish = dfs({ iFirst, iSecond }, pairCurr);
					if (bFinish) return true;
				}
				else continue;
			}

			return false;
		};

	for (int i = 0; i < vecStorage.size(); i++)
	{
		for (int j = 0; j < vecStorage[i].size(); j++)
		{
			if (vecStorage[i][j] == chReq)
			{
				bool bFinish = dfs({ i, j }, { i, j });
				if (bFinish) vecResult.push_back({ i, j });
			}
		}
	}

	for (auto Pair : vecResult)
	{
		vecStorage[Pair.first][Pair.second] = '@';
		iResult++;
	}

	return iResult;
}

int Crane(vector<string>& vecStorage, char chReq)
{
	int iResult{};

	for (int i = 0; i < vecStorage.size(); i++)
	{
		for (int j = 0; j < vecStorage[i].size(); j++)
		{
			if (vecStorage[i][j] == chReq)
			{
				vecStorage[i][j] = '@';
				iResult++;
			}
		}
	}

	return iResult;
}

int solution(vector<string> storage, vector<string> requests)
{
	int answer = storage.size() * storage[0].length();

	for (string strReq : requests)
	{
		if (strReq.length() == 2)
			answer -= Crane(storage, strReq[0]);
		else
			answer -= Fork(storage, strReq[0]);
	}

	return answer;
}