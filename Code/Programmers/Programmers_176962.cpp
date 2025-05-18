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
	int iDuration{};
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int iNum{};
	string strName{}, strStart{}, strDuration{};
	vector<vector<string>> vecPlan;

	cin >> iNum;
	vecPlan.resize(iNum);

	for (int i = 0; i < iNum; i++)
	{
		cin >> strName >> strStart >> strDuration;
		vecPlan[i].push_back(strName);
		vecPlan[i].push_back(strStart);
		vecPlan[i].push_back(strDuration);
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

	int iCurrTime{};
	for (auto tTask : vecTask)
	{
		int iDist = tTask.iStart - iCurrTime;

		while (!stTask.empty() && iDist > 0)
		{
			Task tLastTask = stTask.top();
			tLastTask.iDuration -= iDist;
			stTask.pop();

			iDist = -1 * tLastTask.iDuration;

			if (tLastTask.iDuration <= 0)
				answer.push_back(tLastTask.strName);
			else stTask.push(tLastTask);
		}

		iCurrTime = tTask.iStart;
		stTask.push(tTask);
	}

	while (!stTask.empty())
	{
		answer.push_back(stTask.top().strName);
		stTask.pop();
	}

	return answer;
}

// unordered_map, vector, stack 모두 사용하는 풀이
// 와... 봐도 잘 모르겠다... 문제 자체가 너무 헷갈림...
// 특이점이라면 시간을 1씩 계속 증가시키는 방법을 사용한다는 것

#ifdef _RELEASE

#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <unordered_map>
#include <iostream>

using namespace std;

bool comp(vector<string> a, vector<string> b) {
	return a[1] < b[1];
}

int getTime(string s) {
	int h = stoi(s.substr(0, 2));
	int m = stoi(s.substr(3));
	return h * 60 + m;
}

vector<string> solution(vector<vector<string>> plans) {
	sort(plans.begin(), plans.end(), comp);


	unordered_map<string, int> m;
	for (vector<string> plan : plans) m[plan[0]] = stoi(plan[2]);

	stack<vector<string>> st;
	st.push(plans[0]);

	int idx = 1;
	int time = getTime(plans[0][1]);

	vector<string> answer;
	while (!st.empty()) {
		time++;
		string sub = st.top()[0];
		m[sub]--;

		if (m[sub] == 0) {
			st.pop();
			answer.push_back(sub);
		}

		if (idx < plans.size() && (time == getTime(plans[idx][1]) || st.empty())) {
			st.push(plans[idx]);
			time = getTime(plans[idx][1]);
			idx++;
		}
	}
	return answer;
}

#endif