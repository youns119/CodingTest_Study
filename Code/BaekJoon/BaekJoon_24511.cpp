#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	vector<bool> vecQS;
	deque<int> dqQS;
	int iCount{};

	cin >> iCount;
	vecQS.resize(iCount);

	for (int i = 0; i < vecQS.size(); i++)
	{
		int iQS{};

		cin >> iQS;
		if (iQS == 0)
			vecQS[i] = true;
	}

	for (int i = 0; i < vecQS.size(); i++)
	{
		int iNum{};

		cin >> iNum;
		if(vecQS[i])
			dqQS.push_back(iNum);
	}

	cin >> iCount;
	for (int i = 0; i < iCount; i++)
	{
		int iNum{};

		cin >> iNum;
		dqQS.push_front(iNum);
		cout << dqQS.back() << " ";
		dqQS.pop_back();
	}

	return 0;
}