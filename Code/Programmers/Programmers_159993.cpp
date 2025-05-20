#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int SearchMap(const vector<string>& vecMap, const pair<int, int>& pairStart, const pair<int, int>& pairGoal);
int solution(vector<string> maps);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<string> vecMap;
	int iRow{};

	cin >> iRow;

	for (int i = 0; i < iRow; i++)
	{
		string strRow{};

		cin >> strRow;
		vecMap.push_back(strRow);
	}

	cout << solution(vecMap);

	return 0;
}

int SearchMap(const vector<string>& vecMap, const pair<int, int>& pairStart, const pair<int, int>& pairGoal)
{
	pair<int, int> pairCal[4] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

	queue<pair<int, int>> qMap;
	vector<vector<int>> vecPoint(vecMap.size(), vector<int>(vecMap[0].length(), -1));

	qMap.push(pairStart);
	vecPoint[pairStart.first][pairStart.second] = 0;

	while (!qMap.empty())
	{
		pair<int, int> pairCurr = qMap.front();
		qMap.pop();

		if (pairCurr == pairGoal)
			break;

		for (int i = 0; i < 4; i++)
		{
			int iX{ pairCurr.first }, iY{ pairCurr.second };
			int iNextX{ iX + pairCal[i].first };
			int iNextY{ iY + pairCal[i].second };

			if (iNextX >= 0 && iNextX < vecPoint.size() &&
				iNextY >= 0 && iNextY < vecPoint[0].size())
			{
				if (vecMap[iNextX][iNextY] != 'X' && 
					(vecPoint[iNextX][iNextY] == -1))
				{
					qMap.push({ iNextX, iNextY });
					vecPoint[iNextX][iNextY] = vecPoint[iX][iY] + 1;
				}
			}
		}
	}

	return vecPoint[pairGoal.first][pairGoal.second];
}

int solution(vector<string> maps)
{
	int answer = 0;

	pair<int, int> pairStart{}, pairLever{}, pairExit{};

	for (int i = 0; i < maps.size(); i++)
	{
		for (int j = 0; j < maps[i].length(); j++)
		{
			char chMap = maps[i][j];

			if (chMap == 'S') pairStart = { i, j };
			else if (chMap == 'L') pairLever = { i, j };
			else if (chMap == 'E') pairExit = { i, j };
		}
	}

	int iToLever = SearchMap(maps, pairStart, pairLever);
	int iToExit = SearchMap(maps, pairLever, pairExit);

	if (iToLever != -1 && iToExit != -1)
		answer += (iToLever + iToExit);
	else answer = -1;

	return answer;
}

// 기본적으로 비슷한 풀이
// S, L, E를 찾는 방법이 다르고 방문 여부 확인 방식이 조금 다르다

#ifdef _RELEASE

#include <string>
#include <vector>
#include <queue>

using namespace std;
using Coord = pair<int, int>;

int dfs(const Coord start, const Coord end, const vector<string>& maps)
{
    const int n = maps.size();
    const int m = maps[0].size();
    const vector<Coord> offset{ {1,0},{-1,0},{0,1},{0,-1} };

    queue<pair<Coord, int>> q;
    q.emplace(start, 0);

    vector<vector<bool>> visited(n, vector<bool>(m, false));

    while (!q.empty())
    {
        const auto cur = q.front().first;
        const int i = cur.first;
        const int j = cur.second;
        const int distCur = q.front().second;
        q.pop();

        if (cur == end)
        {
            return distCur;
        }

        if (!visited[i][j])
        {
            visited[i][j] = true;
            for (const auto& o : offset)
            {
                const int ii = i + o.first;
                const int jj = j + o.second;

                if (ii >= 0 && ii < n && jj >= 0 && jj < m && maps[ii][jj] != 'X')
                {
                    q.emplace(Coord{ ii,jj }, distCur + 1);
                }
            }
        }
    }

    return -1;
}

int solution(vector<string> maps) {
    Coord start{ -1,-1 };
    Coord end{ -1,-1 };
    Coord lever{ -1,-1 };
    int found = 0;
    for (int i = 0; i < maps.size(); ++i)
    {
        for (int j = 0; j < maps[0].size(); ++j)
        {
            if (maps[i][j] == 'S')
            {
                start = { i,j };
                found++;
            }
            else if (maps[i][j] == 'E')
            {
                end = { i,j };
                found++;
            }
            else if (maps[i][j] == 'L')
            {
                lever = { i,j };
                found++;
            }

            if (found == 3)
            {
                break;
            }
        }

        if (found == 3)
        {
            break;
        }
    }

    int StoL = dfs(start, lever, maps);

    if (StoL != -1)
    {
        int LtoE = dfs(lever, end, maps);

        if (LtoE != -1)
        {
            return StoL + LtoE;
        }
    }

    return -1;
}

#endif