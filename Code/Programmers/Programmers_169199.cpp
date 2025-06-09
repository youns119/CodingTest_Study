#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int solution(vector<string> board);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int iCnt{};

	cin >> iCnt;
	vector<string> vecBoard(iCnt);

	for (int i = 0; i < iCnt; i++)
	{
		string strBoard{};

		cin >> strBoard;
		vecBoard[i] = strBoard;
	}

	cout << solution(vecBoard);

	return 0;
}

int solution(vector<string> board) 
{
	int answer = -1;

	pair<int, int> arr[4] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
	vector<vector<int>> vecDist(board.size() + 1, vector<int>(board[0].size() + 1, -1));

	pair<int, int> pairStart{};
	for (int i = 0; i < board.size(); i++)
		for (int j = 0; j < board[i].size(); j++)
			if (board[i][j] == 'R')
				pairStart = { i, j };

	queue<pair<int, int>> qBoard;

	qBoard.push(pairStart);
	vecDist[pairStart.first][pairStart.second] = 0;

	while (!qBoard.empty())
	{
		pair<int, int> pairPrev = qBoard.front();
		qBoard.pop();

		if (board[pairPrev.first][pairPrev.second] == 'G')
		{
			answer = vecDist[pairPrev.first][pairPrev.second];
			break;
		}

		for (int i = 0; i < 4; i++)
		{
			pair<int, int> pairNext(pairPrev);

			while (1)
			{
				int iPrevFirst = pairNext.first;
				int iPrevSecond = pairNext.second;

				pairNext.first += arr[i].first;
				pairNext.second += arr[i].second;

				int iNextFirst = pairNext.first;
				int iNextSecond = pairNext.second;

				if (iNextFirst < 0 || iNextFirst >= board.size() ||
					iNextSecond < 0 || iNextSecond >= board[iNextFirst].size())
				{
					if (vecDist[iPrevFirst][iPrevSecond] != -1)
						break;

					qBoard.push({ iPrevFirst, iPrevSecond });
					vecDist[iPrevFirst][iPrevSecond] = vecDist[pairPrev.first][pairPrev.second] + 1;

					break;
				}
				else if(board[iNextFirst][iNextSecond] == 'D')
				{
					if (vecDist[iPrevFirst][iPrevSecond] != -1)
						break;

					qBoard.push({ iPrevFirst, iPrevSecond });
					vecDist[iPrevFirst][iPrevSecond] = vecDist[pairPrev.first][pairPrev.second] + 1;

					break;
				}
			}
		}
	}

	return answer;
}

// �ƿ� pair<int, int>�� Coord�� ġȯ�ؼ� ��ǻ� pair<pair<int, int>, int>> �������� ���
// ���� BFS ���� �ݺ������� for�� ���� while�� ���ΰ� ����ϴ�... ���� �� �� ������ ��������!

#ifdef _RELEASE

#include <string>
#include <vector>
#include <queue>

using namespace std;
using Coord = pair<int, int>;

int bfs(const Coord start, const Coord end, const vector<string>& grid)
{
	const int n = grid.size();
	const int m = grid[0].size();
	const vector<Coord> offset{ Coord{1,0},Coord{-1,0},Coord{0,1},Coord{0,-1} };

	queue<pair<Coord, int>> q;
	q.emplace(start, 0);

	vector<vector<bool>> visited(n, vector<bool>(m, false));

	while (!q.empty())
	{
		const int i = q.front().first.first;
		const int j = q.front().first.second;
		const int distCur = q.front().second;
		q.pop();

		if (i == end.first && j == end.second)
		{
			return distCur;
		}

		for (const auto& o : offset)
		{
			int ii = i;
			int jj = j;
			while (true)
			{
				ii += o.first;
				jj += o.second;
				if (ii >= 0 && ii < n && jj >= 0 && jj < m && grid[ii][jj] != 'D')
				{
					continue;
				}
				else
				{
					ii -= o.first;
					jj -= o.second;
					break;
				}
			}

			if (!visited[ii][jj])
			{
				visited[ii][jj] = true;
				q.emplace(Coord{ ii,jj }, distCur + 1);
			}
		}
	}

	return -1;
}

int solution(vector<string> board) {
	const int n = board.size();
	const int m = board[0].size();
	Coord start;
	Coord end;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (board[i][j] == 'R')
			{
				start = { i,j };
			}
			if (board[i][j] == 'G')
			{
				end = { i,j };
			}
		}
	}
	int answer = bfs(start, end, board);
	return answer;
}

#endif