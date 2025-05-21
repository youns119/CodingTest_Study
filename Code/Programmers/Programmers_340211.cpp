#include <iostream>
#include <vector>
#include <map>
#include <tuple>

using namespace std;

int solution(vector<vector<int>> points, vector<vector<int>> routes);

int main()
{
    int iCount{};

    cin >> iCount;
    vector<vector<int>> vecPoint(iCount, vector<int>(2, 0));

    for (int i = 0; i < iCount; i++)
        cin >> vecPoint[i][0] >> vecPoint[i][1];

    int iRoute{}, iPoint{};
    vector<vector<int>> vecRoute(iRoute, vector<int>(iPoint, 0));

    for (int i = 0; i < iRoute; i++)
        for (int j = 0; j < iPoint; j++)
            cin >> vecRoute[i][j] >> vecRoute[i][j];

    cout<< solution(vecPoint, vecRoute);

	return 0;
}

int solution(vector<vector<int>> points, vector<vector<int>> routes)
{
    int answer = 0;

    map<tuple<int, int, int>, int> mapRoute;

    for (auto route : routes)
    {
        int iTime{};

        for (int i = 0; i < route.size() - 1; i++)
        {
            int iStartX = points[route[i] - 1][0];
            int iStartY = points[route[i] - 1][1];

            int iEndX = points[route[i + 1] - 1][0];
            int iEndY = points[route[i + 1] - 1][1];

            int idX = iEndX - iStartX > 0 ? 1 : -1;
            int idY = iEndY - iStartY > 0 ? 1 : -1;

            if (i == 0)
                mapRoute[{iTime++, iStartX, iStartY}]++;

            while (iStartX != iEndX)
            {
                iStartX += idX;
                mapRoute[{iTime++, iStartX, iStartY}]++;
            }
            while (iStartY != iEndY)
            {
                iStartY += idY;
                mapRoute[{iTime++, iStartX, iStartY}]++;
            }
        }
    }

    for (auto Route : mapRoute)
        if (Route.second > 1)
            answer++;

    return answer;
}

// map + pair 방식으로 푸는 방법
// 위의 풀이와 별 다른 점은 없다
// 근데 map 컨테이너 순회하는 방식 좀 특이함... 저렇게도 되는구나..
// 찾아보니까 구조적 바인딩이라는 기법이고, C++17 부터 되는 문법이라네 뭐야 ㅅㅂ

#ifdef _RELEASE

#include <iostream>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer = 0;

    map<int, map<pair<int, int>, int>> timePositions;

    for (const auto& route : routes) {
        int time = 0;

        int r = points[route[0] - 1][0];
        int c = points[route[0] - 1][1];

        timePositions[time][{r, c}]++;

        for (int i = 1; i < route.size(); ++i) {
            int nr = points[route[i] - 1][0];
            int nc = points[route[i] - 1][1];

            while (r != nr) {
                time++;
                r += (nr > r) ? 1 : -1;
                timePositions[time][{r, c}]++;
            }

            while (c != nc) {
                time++;
                c += (nc > c) ? 1 : -1;
                timePositions[time][{r, c}]++;
            }
        }
    }

    for (const auto& [time, posMap] : timePositions) {
        for (const auto& [pos, count] : posMap) {
            if (count > 1)
                answer++;
        }
    }

    return answer;
}

#endif