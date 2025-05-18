#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int ConvertToMinute(const string& strTime);
vector<string> solution(vector<vector<string>> plans);

struct Task
{
	string strName{};

	int iStart{};
	int iTime{};
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int iNum{};
	string strName{}, strStart{}, strTime{};
	vector<vector<string>> vecPlan;

	cin >> iNum;
	vecPlan.resize(iNum);

	for (int i = 0; i < iNum; i++)
	{
		cin >> strName >> strStart >> strTime;
		vecPlan[i].push_back(strName);
		vecPlan[i].push_back(strStart);
		vecPlan[i].push_back(strTime);
	}

	vector<string> vecResult = solution(vecPlan);

	for (int i = 0; i < vecResult.size(); i++)
		cout << vecResult[i] << "\n";

	return 0;
}

int ConvertToMinute(const string& strTime)
{
	string strHour = strTime.substr(0, 2);
	string strMinute = strTime.substr(3);

	int iTime = stoi(strHour) * 60 + stoi(strMinute);

	return iTime;
}

vector<string> solution(vector<vector<string>> plans)
{
	vector<string> answer;

	vector<Task> vecTask;
	stack<Task> stTask;

	for (auto plan : plans)
		vecTask.push_back({ plan[0], ConvertToMinute(plan[1]), stoi(plan[2]) });

	sort(vecTask.begin(), vecTask.end(), [](const Task& tA, const Task& tB) {
		return tA.iStart < tB.iStart;
		});

	for (int i = 0; i < vecTask.size(); i++)
	{
		Task tCurrTask = vecTask[i];

		int iCurrEndTime = tCurrTask.iStart + tCurrTask.iTime;
		int iNextStartTime = vecTask[i + 1].iStart;


	}

	while (!stTask.empty() && stTask.size() != 1)
	{
		Task tCurrTask = stTask.top();
		stTask.pop();
		Task tNextTask = stTask.top();

		int iCurrEndTime = tCurrTask.iStart + tCurrTask.iTime;
		int iNextStartTime = tNextTask.iStart;

		if (iCurrEndTime > iNextStartTime)
		{
			tCurrTask.iTime = iNextStartTime - tCurrTask.iStart;
			tCurrTask.iStart = iNextStartTime;

			stTask.push(tCurrTask);
		}
		else
			answer.push_back(tCurrTask.strName);
	}

	answer.push_back(stTask.top().strName);

	return answer;
}