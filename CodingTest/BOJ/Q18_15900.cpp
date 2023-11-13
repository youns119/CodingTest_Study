#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void Input(int N, vector<vector<int>>& tree);
bool DFS(int N, vector<vector<int>>& tree);

int main()
{
	int N;
	bool result;
	vector<vector<int>> tree;

	cin >> N;
	tree.assign(N + 1, vector<int>());

	Input(N, tree);
	if (result = DFS(N, tree))
		cout << "Yes";
	else
		cout << "No";

	return 0;
}

void Input(int N, vector<vector<int>>& tree)
{
	for (int i = 0; i < N - 1; i++)
	{
		int a, b;
		cin >> a >> b;

		tree[a].push_back(b);
		tree[b].push_back(a);
	}
}

bool DFS(int N, vector<vector<int>>& tree)
{
	vector<bool> visit(N + 1, false);
	vector<int> count(N + 1, 0);
	stack<int> s;
	int total = 0;

	s.push(1);

	while (!s.empty())
	{
		int current = s.top();
		s.pop();

		if (visit[current] == false)
		{
			visit[current] = true;

			if (tree[current].size() == 1 && current != 1)
				total += count[current];
		}

		for (int i = 0; i < tree[current].size(); i++)
		{
			if (visit[tree[current][i]] == false)
			{
				s.push(tree[current][i]);
				count[tree[current][i]] = count[current] + 1;
			}
		}
	}

	if (total % 2 == 0)
		return false;

	return true;
}