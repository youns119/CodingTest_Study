#include <iostream>
#include <vector>

using namespace std;

int solution(vector<int> players, int m, int k);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> vecPlayer(24, 0);
	for (int i = 0; i < 24; i++)
		cin >> vecPlayer[i];

	int iMax{}, iTime{};

	cin >> iMax >> iTime;

	cout << solution(vecPlayer, iMax, iTime);

	return 0;
}

int solution(vector<int> players, int m, int k) 
{
	int answer = 0;



	return answer;
}