#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Poly
{
public:
	Poly() { blocks.assign(4, { 0,0 }); }

	void Shape(int num) { shape = num; }
	vector<pair<int, int>> GetBlocks() { return blocks; }

	void Init(pair<int, int>& index)
	{
		blocks[0] = index;

		switch (shape)
		{
		case 1:
			blocks[1] = { blocks[0].first + 1, blocks[0].second };
			blocks[2] = { blocks[0].first + 2, blocks[0].second };
			blocks[3] = { blocks[0].first + 3, blocks[0].second };
			break;

		case 2:
			blocks[1] = { blocks[0].first + 1, blocks[0].second };
			blocks[2] = { blocks[0].first, blocks[0].second + 1 };
			blocks[3] = { blocks[0].first + 1, blocks[0].second + 1 };
			break;

		case 3:
			blocks[1] = { blocks[0].first, blocks[0].second + 1 };
			blocks[2] = { blocks[0].first, blocks[0].second + 2 };
			blocks[3] = { blocks[0].first + 1, blocks[0].second + 2 };
			break;

		case 4:
			blocks[1] = { blocks[0].first, blocks[0].second + 1 };
			blocks[2] = { blocks[0].first + 1, blocks[0].second + 1 };
			blocks[3] = { blocks[0].first + 1, blocks[0].second + 2 };
			break;

		case 5:
			blocks[1] = { blocks[0].first + 1, blocks[0].second };
			blocks[2] = { blocks[0].first + 2, blocks[0].second };
			blocks[3] = { blocks[0].first + 1, blocks[0].second + 1 };
			break;
		}
	}

private:
	int shape;
	vector<pair<int, int>> blocks;
};

vector<vector<int>> Flip(vector<vector<int>>& tetro);
vector<vector<int>> Rot(vector<vector<int>>& tetro);
int Max_Tetro(Poly poly, vector<vector<int>>& tetro);
int Solution(vector<vector<int>>& tetro);

int main()
{
	int N, M, result;
	vector<vector<int>> tetro;

	cin >> N >> M;
	tetro.assign(M, vector<int>(N, 0));

	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			cin >> tetro[i][j];
	
	result = Solution(tetro);
	cout << result;

	return 0;
}

vector<vector<int>> Flip(vector<vector<int>>& tetro)
{
	int M = tetro.size();
	int N = tetro[0].size();
	vector<vector<int>> flipped;

	flipped.assign(M, vector<int>(N, 0));

	for(int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			flipped[M - 1 - i][j] = tetro[i][j];

	return flipped;
}

vector<vector<int>> Rot(vector<vector<int>>& tetro)
{
	int M = tetro.size();
	int N = tetro[0].size();
	vector<vector<int>> rotted;

	rotted.assign(N, vector<int>(M, 0));

	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			rotted[N - 1 - j][i] = tetro[i][j];

	return rotted;
}

int Max_Tetro(Poly poly, vector<vector<int>>& tetro)
{
	int Max = 0;
	int M = tetro.size();
	int N = tetro[0].size();

	for(int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
		{
			int sum = 0;
			bool flag = false;
			pair<int, int> p = { i, j };
			poly.Init(p);

			for (int k = 0; k < 4; k++)
			{
				pair<int, int> b = poly.GetBlocks()[k];

				if (b.first >= 0 && b.first < M &&
					b.second >= 0 && b.second < N)
					sum += tetro[b.first][b.second];
				else
				{
					flag = true;
					break;
				}
			}

			if (flag)
				continue;
			else
				Max = max(Max, sum);
		}

	return Max;
}

int Solution(vector<vector<int>>& tetro)
{
	int result = 0;
	int shapeCnt = 5;
	Poly poly;
	vector<vector<int>> temp;

	for (int i = 1; i <= shapeCnt; i++)
	{
		poly.Shape(i);
		temp = tetro;

		for (int j = 0; j < 2; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				int Max = Max_Tetro(poly, temp);
				result = max(result, Max);

				temp = Rot(temp);
			}

			temp = Flip(temp);
		}
	}

	return result;
}