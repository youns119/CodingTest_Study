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