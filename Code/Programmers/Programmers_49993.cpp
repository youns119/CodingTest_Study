#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees);

int main()
{
    string strSkill{};

    cin >> strSkill;

    vector<string> vecSkillTree;
    int iCount{};

    cin >> iCount;

    for (int i = 0; i < iCount; i++)
    {
        string strSkillTree{};

        cin >> strSkillTree;
        vecSkillTree.push_back(strSkillTree);
    }

    cout<< solution(strSkill, vecSkillTree);

	return 0;
}

int solution(string skill, vector<string> skill_trees) 
{
    int answer = 0;

    for (string strSkill : skill_trees)
    {
        bool bFlag{ true };
        int iCurr{};

        for (int i = 0; i < strSkill.length(); i++)
        {
            char ch = strSkill[i];

            for (int j = iCurr; j < skill.length(); j++)
            {
                if (ch == skill[j])
                {
                    if (j == iCurr) iCurr++;
                    else bFlag = false;

                    break;
                }
            }

            if (!bFlag) break;
        }

        if (bFlag) answer++;
    }

    return answer;
}

// vector�� �� ���ڿ� ������ ���ڵ��� �����ϰ� �� �ڿ� ���� ���ڿ��� �ϳ��� ���ϴ� ���
// Ȯ���� �������� ������ ���� Ǯ�̹����� �ݺ����� �� �� �� ���ٴ� �������� ���� �ƽ��� ���

#ifdef _RELEASE

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    for (int i = 0; i < skill_trees.size(); i++) {
        vector<char> compare;

        for (int k = 0; k < skill_trees[i].size(); k++) {
            for (int j = 0; j < skill.size(); j++) {
                if (skill[j] == skill_trees[i][k]) {
                    char tmp = skill[j];
                    compare.push_back(tmp);
                }
            }
        }
        bool check = true;;
        for (int c = 0; c < compare.size(); c++) {
            if (skill[c] != compare[c]) {
                check = false;
            }
        }
        if (check)answer++;
    }

    return answer;
}

#endif