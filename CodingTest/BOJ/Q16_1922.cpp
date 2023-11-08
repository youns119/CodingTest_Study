#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void Input(vector<pair<int, pair<int, int>>>& edge, int N, int M);
int GetRoot(vector<int>& parent, int x);
void Union(vector<int>& parent, int x, int y);
bool Find(vector<int>& parent, int x, int y);
int Solution(vector<pair<int, pair<int, int>>>& edge,
			 vector<int>& parent, int N, int M);

int main()
{
	int N, M;
	int a, b, c;
	vector<pair<int, pair<int, int>>> edge;
	vector<int> parent;
	int result;

	cin >> N >> M;
	parent.assign(N + 1, 0);

	Input(edge, N, M);
	result = Solution(edge, parent, N, M);

	cout << result;

	return 0;
}

void Input(vector<pair<int, pair<int, int>>>& edge, int N, int M)
{
	int a, b, c;

	for (int i = 0; i < M; i++)
	{
		cin >> a >> b >> c;
		edge.push_back(make_pair(c, make_pair(a, b)));
	}
}

int GetRoot(vector<int>& parent, int x)
{
	if (parent[x] == x)
		return x;
	else
		return parent[x] = GetRoot(parent, parent[x]);
}

void Union(vector<int>& parent, int x, int y)
{
	x = GetRoot(parent, x);
	y = GetRoot(parent, y);

	if (x < y)
		parent[y] = x;
	else
		parent[x] = y;
}

bool Find(vector<int>& parent, int x, int y)
{
	x = GetRoot(parent, x);
	y = GetRoot(parent, y);

	if (x == y)
		return true;
	else
		return false;
}

int Solution(vector<pair<int, pair<int, int>>>& edge,
	vector<int>& parent, int N, int M)
{
	int result = 0;

	sort(edge.begin(), edge.end());
	
	for (int i = 1; i <= N; i++)
		parent[i] = i;

	for (int i = 0; i < M; i++)
	{
		int x = edge[i].second.first;
		int y = edge[i].second.second;
		int cost = edge[i].first;

		if (!Find(parent, x, y))
		{
			Union(parent, x, y);
			result += cost;
		}
	}

	return result;
}