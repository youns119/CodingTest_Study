#include <iostream>
#include <vector>
#include <string>

using namespace std;

int solution(vector<string> lines);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int iCnt{};

    cin >> iCnt;
    vector<string> vecLog(iCnt);
    cin.ignore();

    for (int i = 0; i < iCnt; ++i)
    {
        string strLog{};

        getline(cin, strLog);
        vecLog[i] = strLog;
    }

    cout << solution(vecLog);

	return 0;
}

int solution(vector<string> lines) 
{
    int answer = 0;



    return answer;
}