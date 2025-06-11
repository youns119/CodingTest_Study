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
		cin >> iCol >> iRow >> iCnt;

		vector<vector<int>> vecField(iCol, vector<int>(iRow, 0));

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

// BFS 대신 DFS로 푸는 풀이
// 제한 조건이 그렇게 범위가 넓지 않으므로 DFS로도 충분히 스택 오버플로우 없이 가능
// 방문 체크용 이중 vector를 하나 더 쓰는 것 말고는 딱히 구현 상의 차이점은 없다

#ifdef _RELEASE

#include <iostream>
#include <vector>
using namespace std;

int T, M, N, K;
vector<vector<int>> field;
vector<vector<bool>> visited;
int dx[4] = { 0, 0, -1, 1 }; // 좌우상하
int dy[4] = { -1, 1, 0, 0 };

void dfs(int x, int y) {
	visited[y][x] = true;

	for (int dir = 0; dir < 4; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		if (nx >= 0 && nx < M && ny >= 0 && ny < N) {
			if (field[ny][nx] == 1 && !visited[ny][nx]) {
				dfs(nx, ny);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;

	while (T--) {
		cin >> M >> N >> K;

		field.assign(N, vector<int>(M, 0));
		visited.assign(N, vector<bool>(M, false));

		for (int i = 0; i < K; i++) {
			int x, y;
			cin >> x >> y;
			field[y][x] = 1;
		}

		int wormCount = 0;

		for (int y = 0; y < N; y++) {
			for (int x = 0; x < M; x++) {
				if (field[y][x] == 1 && !visited[y][x]) {
					dfs(x, y);
					wormCount++;
				}
			}
		}

		cout << wormCount << '\n';
	}

	return 0;
}

#endif