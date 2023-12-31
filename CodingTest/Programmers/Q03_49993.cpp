#include <iostream>
#include <vector>
#include <map>
#include <queue>

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
	map<char, int> m;

	for (int i = 0; i < skill.length(); i++)
		m[skill[i]] = i;

	for (auto tree : skill_trees)
	{
		int order = 0;
		bool flag = false;
 
		for (auto skill : tree)
		{
			auto it = m.find(skill);

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

		if (!flag)
			answer++;
	}

	return answer;
}

// string의 find를 찾는 더 간단한 방법도 있었다
// key의 순서가 상관없는 map이라면 unordered_map을 쓰는게 더 빠르다