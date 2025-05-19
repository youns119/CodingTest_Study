#include <iostream>
#include <cmath>

using namespace std;

bool IsPrime(int iNum);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int iMin{}, iMax{};

	cin >> iMin >> iMax;

	for (int i = iMin; i <= iMax; i++)
		if (IsPrime(i)) cout << i << " ";

	return 0;
}

bool IsPrime(int iNum)
{
	if (iNum <= 1) return false;
	else if (iNum == 2) return true;
	else if (iNum % 2 == 0) return false;

	for (int i = 3; i <= sqrt(iNum); i += 2)
		if (iNum % i == 0) return false;

	return true;
}

// vector에 후보 숫자들을 넣어 놓고 반복문을 돌면서 제곱의 수들을 걸러주는 방식으로 하는 풀이
// 지금까지 에라스토테네스의 체를 공식으로 외워놓고 풀었는데 나름 신선한 풀이 같다

#ifdef _RELEASE

#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M, N;
    cin >> M >> N;

    vector<bool> isPrime(N + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= N; ++i) {
        if (!isPrime[i]) continue;

        for (int j = i * i; j <= N; j += i) {
            isPrime[j] = false;
        }
    }

    for (int i = M; i <= N; ++i) {
        if (isPrime[i])
            cout << i << '\n';
    }

    return 0;
}

#endif