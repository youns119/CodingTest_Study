#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

string KeyLogger(string& strPassword);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int iCnt{};

	cin >> iCnt;
	vector<string> vecPassword(iCnt);

	for (int i = 0; i < iCnt; i++)
	{
		string strPassword;

		cin >> strPassword;
		vecPassword[i] = KeyLogger(strPassword);
	}

	for (string Password : vecPassword)
		cout << Password << "\n";

	return 0;
}

string KeyLogger(string& strPassword)
{
	string strResult{};
	stack<char> stStack1, stStack2;

	for (char chWord : strPassword)
	{
		if (chWord == '<')
		{
			if (!stStack1.empty())
			{
				char chTop = stStack1.top();
				stStack1.pop();
				stStack2.push(chTop);
			}
			else continue;
		}
		else if (chWord == '>')
		{
			if (!stStack2.empty())
			{
				char chTop = stStack2.top();
				stStack2.pop();
				stStack1.push(chTop);
			}
			else continue;
		}
		else if (chWord == '-')
		{
			if (!stStack1.empty())
				stStack1.pop();
			else continue;
		}
		else
			stStack1.push(chWord);
	}

	while (!stStack1.empty())
	{
		char chTop = stStack1.top();
		stStack1.pop();
		stStack2.push(chTop);
	}

	while (!stStack2.empty())
	{
		strResult += stStack2.top();
		stStack2.pop();
	}

	return strResult;
}