#include <iostream>
#include <cmath>

using namespace std;

int GCD(int iWidth, int iHeight);
long long solution(int w, int h);

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int iWidth, iHeight;
    cin >> iWidth >> iHeight;

    long long lResult = solution(iWidth, iHeight);
    cout << lResult;

    return 0;
}

int GCD(int iWidth, int iHeight)
{
    if (iHeight == 0) return iWidth;
    return GCD(iHeight, iWidth % iHeight);
}

long long solution(int w, int h)
{
    long long answer{};
    long long lCount = (long long)w * (long long)h;
    int iGCD = GCD(w, h);
    int iMinW = w / iGCD;
    int iMinH = h / iGCD;
    long long lPart{};
    double dT = double(iMinH) / double(iMinW);

    for (int i = 0; i < iMinW; i++)
    {
        int iFloor = floor(dT * i);
        int iCeil = ceil(dT * (i + 1));
        lPart += iCeil - iFloor;
    }

    lPart *= iGCD;
    answer = lCount - lPart;

    return answer;
}

// 위는 내가 푼 풀이인데 기울기를 사용해서 풀었다
// 결과는 실패 -> 기울기는 결국엔 실수형이므로 오차가 발생한 듯하다
// 알고보니 이 문제에 딱 맞는 수학적 공식이 이미 존재하는 문제였다
// 그 공식을 사용한 풀이가 밑의 풀이

#ifdef _RELEASE

#include <iostream>

using namespace std;

int GCD(int iWidth, int iHeight);
long long solution(int w, int h);

int main()
{
    int iWidth, iHeight;
    cin >> iWidth >> iHeight;

    long long lResult = solution(iWidth, iHeight);
    cout << lResult;

    return 0;
}

int GCD(int iWidth, int iHeight)
{
    if (iHeight == 0) return iWidth;
    return GCD(iHeight, iWidth % iHeight);
}

long long solution(int w, int h)
{
    long long iCount = (long long)w * h;
    int iGCD = GCD(w, h);

    long long lPart = (long long)w + h - iGCD;

    return iCount - lPart;
}

#endif