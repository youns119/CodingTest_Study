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

// vector 컨테이너의 iterator 순회, 삽입 및 삭제만으로 구현한 풀이
// transform이라는 함수도 새로 알게 되었고, 람다식이 들어갈 구문에 ::tolower만으로 해결하는 것도 처음 봤다
// 컨테이너를 한 종류만 쓰고 뭔가 효율적으로 보이긴 하지만... 더 정석적이고 가독성이 좋은건 내 풀이법인 것 같다

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