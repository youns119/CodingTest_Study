#include <iostream>
#include <string>
#include <vector>

using namespace std;

int Storage(vector<string>& vecStorage, char chReq, bool bCrane);
int solution(vector<string> storage, vector<string> requests);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int iRow{}, iCol{};

	cin >> iRow >> iCol;
	vector<string> vecStorage(iCol);

	for (int i = 0; i < iCol; i++)
		cin >> vecStorage[i];

	int iCnt{};

	cin >> iCnt;
	vector<string> vecRequest(iCnt);

	for (int i = 0; i < iCnt; i++)
		cin >> vecRequest[i];

	return 0;
}

int Storage(vector<string>& vecStorage, char chReq, bool bCrane)
{
	int iResult{};

	for (int i = 0; i < vecStorage.size(); i++)
	{
		for (int j = 0; j < vecStorage[0].size(); j++)
		{
			if (vecStorage[i][j] == chReq)
			{
				if (bCrane)
				{
					vecStorage[i][j] = '@';
					iResult++;
				}
				else if(i == 0 || i == vecStorage.size() - 1 ||
					j == 0 || j == vecStorage[0].size() - 1)
				{
					vecStorage[i][j]
				}
			}
		}
	}

	if (!bCrane)
	{

	}
	else
	{

	}

	return iResult
}

int solution(vector<string> storage, vector<string> requests)
{
	int answer = storage.size() * storage[0].length();

	for (string strReq : requests)
	{
		bool bCrane{};

		if (strReq.length() == 2 && strReq[0] == strReq[1])
			bCrane;

		answer -= Storage(storage, strReq[0], bCrane);
	}

	return answer;
}