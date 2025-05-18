#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

string ConvertToForm(int iNum, int iBase);
bool IsPrime(long long llNum);
int solution(int n, int k);

int main()
{
    int iNum{}, iBase{};

    cin >> iNum >> iBase;

    cout << solution(iNum, iBase);

	return 0;
}

string ConvertToForm(int iNum, int iBase)
{
    string strResult{};

    while (iNum > 0)
    {
        int iRemain = iNum % iBase;

        if (iRemain < 10)
            strResult += (iRemain + '0');
        else
            strResult += (iRemain - 10 + 'A');

        iNum /= iBase;
    }

    reverse(strResult.begin(), strResult.end());

    return strResult;
}

bool IsPrime(long long llNum)
{
    if (llNum <= 1) return false;
    else if (llNum == 2) return true;
    else if (llNum % 2 == 0) return false;

    for (long long i = 3; i <= sqrt(llNum); i += 2)
        if (llNum % i == 0) return false;

    return true;
}

int solution(int n, int k)
{
    int answer = 0;

    vector<long long> vecNum;

    string strNum = ConvertToForm(n, k);
    string strPart{};
    
    for (long long i = 0; i <= strNum.length(); i++)
    {
        if (strNum[i] != '0' && i < strNum.length())
            strPart += strNum[i];
        else if(!strPart.empty())
        {
            long long iPart = stoll(strPart);
            vecNum.push_back(iPart);

            strPart.clear();
        }
    }

    for (long long iNum : vecNum)
        if (IsPrime(iNum)) answer++;

    return answer;
}

// ���� ��ȯ�� �ڵ尡 ����� ����ϴ�
// 10���� ������ ���� ��ȯ������ ���� ȿ������ ��ȯ �ڵ��ε�
// ���� ��ȯ�� ������ ���ڿ��� �ݺ��� ��ȸ�ϸ鼭 �Ҽ� �Ǻ��ϴ� ������ ����� �ű��ϴ�
// �ʱⰪ�� 2���� �������� �ݺ��ϸ鼭 ���ڿ��� ���ڸ� ���ÿ� ���ϴ� �Ź��� ���

#ifdef _RELEASE

#include <bits/stdc++.h>
using namespace std;

bool is_prime(long long n) {
    if (n < 2) return false;
    for (long long i = 2; i * i <= n; ++i) if (n % i == 0) return false;
    return true;
}
int solution(int n, int k) {
    string str;
    while (n) {
        str += n % k + 48;
        n /= k;
    }

    reverse(str.begin(), str.end());
    str += 48;

    int ans = 0;
    for (long long hold = 0, i = 0; i < str.size(); ++i) {
        if (str[i] == '0') {
            if (is_prime(hold)) ++ans;
            hold = 0;
            continue;
        }
        hold = hold * 10 + str[i] - 48;
    }

    return ans;
}

#endif