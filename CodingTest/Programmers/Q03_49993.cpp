#include <iostream>
#include <vector>
#include <map>

using namespace std;

int solution(string skill, vector<string> skill_trees);

int main()
{
	int size, answer;
	string skill;
	vector<string> skill_trees;

	cin >> skill >> size;

	skill_trees.assign(size, "");

	for (int i = 0; i < size; i++)
		cin >> skill_trees[i];

	answer = solution(skill, skill_trees);

	cout << answer;

	return 0;
}

int solution(string skill, vector<string> skill_trees)
{
	int answer = 0;
	int order = 0;
	bool flag = false;
	map<char, int> m;

	for (int i = 0; i < skill.length(); i++)
		m[skill[i]] = i;

	for (int i = 0; i < skill_trees.size(); i++)
	{
		for (int j = 0; j < skill_trees[i].length(); j++)
		{
			auto it = m.find(skill_trees[i][j]);

			if (it != m.end())
			{
				if (it->second == order)
					order++;
				else
				{
					flag = true;
					break;
				}
			}
		}

		if (flag)
			flag = false;
		else
			answer++;

		order = 0;
	}

	return answer;
}