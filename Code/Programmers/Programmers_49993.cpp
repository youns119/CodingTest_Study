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

// vector에 각 문자와 동일한 문자들을 저장하고 그 뒤에 실제 문자열과 하나씩 비교하는 방법
// 확실히 직관성이 있지만 나의 풀이법보다 반복문을 한 번 더 쓴다는 점에서는 조금 아쉬운 방법

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