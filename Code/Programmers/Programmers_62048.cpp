#include <iostream>
#include <cmath>

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