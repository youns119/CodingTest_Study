#include <iostream>
#include <vector>
#include <map>

using namespace std;

void Input(vector<int>& parent, vector<vector<int>>& party);
int GetRoot(vector<int>& parent, int x);
void Union(vector<int>& parent, int x, int y);
bool Find(vector<int>& parent, int x, int y);
int CntLie(vector<int>& parent, vector<vector<int>>& party);

int main()
{
	int result;
	vector<int> parent;
	vector<vector<int>> party;

	Input(parent, party);
	result = CntLie(parent, party);
	cout << result;

	return 0;
}

void Input(vector<int>& parent, vector<vector<int>>& party)
{
	int N, M, n;
	
	cin >> N >> M;
	cin >> n;
	parent.assign(N + 1, 0);
	party.assign(M, vector<int>());
	for (int i = 0; i < N + 1; i++)
		parent[i] = i;
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		parent[num] = 0;
	}

	for (int i = 0; i < M; i++)
	{
		cin >> n;
		for (int j = 0; j < n; j++)
		{
			int num;
			cin >> num;
			party[i].push_back(num);
		}
	}
}

int GetRoot(vector<int>& parent, int x)
{
	if (x == parent[x]) return x;
	else return parent[x] = GetRoot(parent, parent[x]);
}

void Union(vector<int>& parent, int x, int y)
{
	x = GetRoot(parent, x);
	y = GetRoot(parent, y);

	if (x != y)
	{
		if (x < y)
			parent[y] = x;
		else
			parent[x] = y;
	}
	else return;
}

bool Find(vector<int>& parent, int x, int y)
{
	x = GetRoot(parent, x);
	y = GetRoot(parent, y);

	if (x == y) return true;
	else return false;
}

int CntLie(vector<int>& parent, vector<vector<int>>& party)
{
	int result = 0;
	int size = party.size();

	for (int i = 0; i < size; i++)
	{
		int cnt = party[i].size();
		for (int j = 0; j < cnt - 1; j++)
		{
			int guest1 = party[i][j];
			int guest2 = party[i][j + 1];

			Union(parent, guest1, guest2);
		}
	}

	for (int i = 0; i < size; i++)
	{
		int cnt = party[i].size();
		bool bSkip = false;
		for (int j = 0; j < cnt; j++)
			if (GetRoot(parent, party[i][j]) == 0) { bSkip = true; break; }

		if (!bSkip) result++;
	}

	return result;
}