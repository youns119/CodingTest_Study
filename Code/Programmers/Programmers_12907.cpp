#include <iostream>
#include <vector>

using namespace std;

int solution(int n, vector<int> money);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int iReserve{}, iCnt{};

	cin >> iReserve >> iCnt;
	vector<int> vecMoney(iCnt);
	
	for (int i = 0; i < iCnt; i++)
		cin >> vecMoney[i];

	cout << solution(iReserve, vecMoney);

	return 0;
}

int solution(int n, vector<int> money) 
{
	int answer = 0;



	return answer;
}