#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAX = 1000000;

void Prime(vector<bool>& vecPrime);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<bool> vecPrime(MAX + 1, true);
	Prime(vecPrime);

	int iCount{};

	cin >> iCount;
	vector<int> vecResult(iCount, 0);

	for (int i = 0; i < iCount; i++)
	{
		int iNum{};

		cin >> iNum;

		for (int j = 2; j <= iNum / 2; j++)
			if (vecPrime[j] && vecPrime[iNum - j])
				vecResult[i]++;
	}

	for (int iNum : vecResult)
		cout << iNum << "\n";

	return 0;
}

void Prime(vector<bool>& vecPrime)
{
	vecPrime[0] = vecPrime[1] = false;

	for (int i = 2; i * i <= MAX; i++)
	{
		if (!vecPrime[i]) continue;
		for (int j = i * i; j <= MAX; j += i)
			vecPrime[j] = false;
	}
}

// unordered_set을 사용한 방법
// 해시 기반 접근이라 ㅃ

#ifdef _RELEASE

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

const int MAX = 10000;

unordered_set<int> MakePrimeSet() {
    vector<bool> isPrime(MAX + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= MAX; ++i) {
        if (!isPrime[i]) continue;
        for (int j = i * i; j <= MAX; j += i)
            isPrime[j] = false;
    }

    unordered_set<int> primeSet;
    for (int i = 2; i <= MAX; ++i) {
        if (isPrime[i])
            primeSet.insert(i);
    }

    return primeSet;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_set<int> primeSet = MakePrimeSet();

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        int count = 0;
        for (int i = 2; i <= n / 2; ++i) {
            if (primeSet.count(i) && primeSet.count(n - i))
                count++;
        }

        cout << count << '\n';
    }

    return 0;
}

#endif

// bitset을 사용해 비트 기반으로 접근하는 방법

#ifdef _RELEASE

#include <iostream>
#include <bitset>

using namespace std;

const int MAX = 10000;

bitset<MAX + 1> MakePrimeBitset() {
    bitset<MAX + 1> isPrime;
    isPrime.set();
    isPrime[0] = isPrime[1] = 0;

    for (int i = 2; i * i <= MAX; ++i) {
        if (!isPrime[i]) continue;
        for (int j = i * i; j <= MAX; j += i)
            isPrime[j] = 0;
    }

    return isPrime;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    bitset<MAX + 1> isPrime = MakePrimeBitset();

    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        int count = 0;
        for (int i = 2; i <= n / 2; ++i) {
            if (isPrime[i] && isPrime[n - i])
                count++;
        }

        cout << count << '\n';
    }

    return 0;
}

#endif