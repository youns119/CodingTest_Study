#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int solution(int N, int r, int c);

int main()
{
	int N, r, c, result;

	cin >> N >> r >> c;
	result = solution(N, r, c);

	cout << result;

	return 0;
}

int solution(int N, int r, int c)
{
	if (N == 0)
		return 0;

	int size = pow(2, N - 1);
	int total = size * size;
	int cnt;

	if (r + 1 > size && c + 1 > size) { cnt = 3; r = r - size; c = c - size; }
	else if (r + 1 > size && c + 1 <= size) { cnt = 2; r = r - size; }
	else if (r + 1 <= size && c + 1 > size) { cnt = 1; c = c - size; }
	else cnt = 0;

	return total * cnt + solution(N - 1, r, c);
}