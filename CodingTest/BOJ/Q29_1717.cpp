#include <iostream>
#include <vector>

using namespace std;

typedef vector<pair<int, pair<int, int>>> vp;

int GetRoot(vector<int>& parent, int x);
void Union(vector<int>& parent, int x, int y);
bool Find(vector<int>& parent, int x, int y);
void Print(int n, vp& groups);

int main()
{
	int n, m;
	vp groups;

	cin >> n >> m;
	groups.assign(m, make_pair(0, make_pair(0, 0)));

	for (int i = 0; i < m; i++)
		cin >> groups[i].first >> 
		groups[i].second.first >> 
		groups[i].second.second;

	Print(n, groups);

	return 0;
}

int GetRoot(vector<int>& parent, int x)
{
	if (parent[x] == x) return x;
	else return parent[x] = GetRoot(parent, parent[x]);
}

void Union(vector<int>& parent, int x, int y)
{
	x = GetRoot(parent, x);
	y = GetRoot(parent, y);

	if (x != y) parent[x] = y;
	else return;
}

bool Find(vector<int>& parent, int x, int y)
{
	x = GetRoot(parent, x);
	y = GetRoot(parent, y);

	if (x == y) return true;
	else return false;
}

void Print(int n, vp& groups)
{
	vector<int> parent(n + 1, 0);

	for (int i = 0; i < n + 1; i++)
		parent[i] = i;

	for (auto group : groups)
	{
		int mode = group.first;
		int a = group.second.first;
		int b = group.second.second;

		if (mode == 0)
			Union(parent, a, b);
		else if (mode == 1)
		{
			if (Find(parent, a, b) == true)
				cout << "YES" << "\n";
			else
				cout << "NO" << "\n";
		}
	}
}