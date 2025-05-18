#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <cctype>

using namespace std;

int solution(int cacheSize, vector<string> cities);

struct LCU
{
    list<string> listCache;

    int iCacheSize{};

    int Push(string& strCity)
    {
        for (char& ch : strCity)
            ch = tolower(ch);

        auto it = listCache.begin();
        int iCache{};

        for (it = listCache.begin(); it != listCache.end(); it++)
        {
            if (*it == strCity)
            {
                listCache.splice(listCache.begin(), listCache, it);
                iCache = 1;

                break;
            }
        }

        if (it == listCache.end())
        {
            listCache.push_front(strCity);
            iCache = 5;
        }
        
        if (listCache.size() > iCacheSize)
            listCache.pop_back();

        return iCache;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> vecCity;
    int iCount{}, iCacheSize{};

    cin >> iCacheSize >> iCount;

    vecCity.resize(iCount);
    for (int i = 0; i < iCount; i++)
    {
        string strCity{};

        cin >> strCity;
        vecCity.push_back(strCity);
    }

    cout << solution(iCacheSize, vecCity);

	return 0;
}

int solution(int cacheSize, vector<string> cities) 
{
    int answer = 0;

    LCU tCache{};
    tCache.iCacheSize = cacheSize;

    for (string& strCity : cities)
        answer += tCache.Push(strCity);

    return answer;
}

// vector �����̳��� iterator ��ȸ, ���� �� ���������� ������ Ǯ��
// transform�̶�� �Լ��� ���� �˰� �Ǿ���, ���ٽ��� �� ������ ::tolower������ �ذ��ϴ� �͵� ó�� �ô�
// �����̳ʸ� �� ������ ���� ���� ȿ�������� ���̱� ������... �� �������̰� �������� ������ �� Ǯ�̹��� �� ����

#ifdef _RELEASE

#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int solution(int cacheSize, vector<string> cities) {

    vector <string> q;
    int duration = 0;

    for (vector <string>::iterator it = cities.begin(); it != cities.end(); it++) {
        transform(it->begin(), it->end(), it->begin(), ::tolower);

        bool flag = false;
        for (vector<string>::iterator itt = q.begin(); itt != q.end(); itt++) {
            if (*itt == *it) {
                flag = true;
                duration += 1;
                q.erase(itt);
                q.push_back(*it);
                break;
            }
        }
        if (!flag) {
            duration += 5;
            if (cacheSize != 0 && q.size() >= cacheSize)
                q.erase(q.begin());
            if (q.size() < cacheSize)
                q.push_back(*it);
        }
    }

    return duration;
}

#endif