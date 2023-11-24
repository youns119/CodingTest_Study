#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> nodeinfo);

int main()
{
	int N;
	vector<vector<int>> nodeinfo;
	vector<vector<int>> results;

	cin >> N;
	nodeinfo.assign(N, vector<int>(2, 0));

	for (int i = 0; i < N; i++)
		cin >> nodeinfo[i][0] >> nodeinfo[i][1];

	results = solution(nodeinfo);
	for (auto result : results)
	{
		for (auto r : result)
			cout << r << " ";

		cout << "\n";
	}

	return 0;
}

vector<vector<int>> solution(vector<vector<int>> nodeinfo)
{
	vector<vector<int>> answer;



	return answer;
}