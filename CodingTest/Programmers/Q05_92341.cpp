#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records);

int main()
{
	vector<int> fees;
	fees.push_back(180);
	fees.push_back(5000);
	fees.push_back(10);
	fees.push_back(600);

	vector<string> records;
	records.push_back("05:34 5961 IN");
	records.push_back("06:00 0000 IN");
	records.push_back("06:34 0000 OUT");
	records.push_back("07:59 5961 OUT");
	records.push_back("07:59 0148 IN");
	records.push_back("18:59 0000 IN");
	records.push_back("19:09 0148 OUT");
	records.push_back("22:59 5961 IN");
	records.push_back("23:00 5961 OUT");
	
	solution(fees, records);

	return 0;
}

vector<int> solution(vector<int> fees, vector<string> records)
{
	vector<int> answer;
	map<int, pair<int, string>> m;

	for (int i = 0; i < records.size(); i++)
	{
		int hour;
		int min;
		int time;
		int car;
		string s = "";
		vector<string> v;

		for (int j = 0; j < records[i].size() + 1; j++)
		{
			if (records[i][j] == 32 || records[i][j] == '\0')
			{
				v.push_back(s);
				s = "";

				continue;
			}

			s += records[i][j];
		}

		hour = stoi(v[0].substr(0, 2));
		min = stoi(v[0].substr(3, 2));
		car = stoi(v[1]);

		time = hour * 60 + min;

		if (v[2] == "IN")
			m[car].first -= time;
		else
			m[car].first += time;

		m[car].second = v[2];
	}
	
	for (auto list : m)
	{
		int time = list.second.first;

		if (list.second.second == "IN")
			time += 23 * 60 + 59;

		if (time < fees[0])
			answer.push_back(fees[1]);
		else
		{
			int temp = (time - fees[0]) % fees[2];

			if (temp)
				time = (time - fees[0]) / fees[2] + 1;
			else
				time = (time - fees[0]) / fees[2];
			
			int fee = fees[1] + time * fees[3];

			answer.push_back(fee);
		}
	}

	return answer;
}

// 다른 사람의 풀이. 너무 깔끔하다
//int conv(string& t) {
//	int h = (t[0] - 48) * 10 + t[1] - 48;
//	int m = (t[3] - 48) * 10 + t[4] - 48;
//	return h * 60 + m;
//}
//
//vector<int> solution(vector<int> fees, vector<string> records) {
//	vector<int> vec[10000];
//	for (auto& record : records) {
//		stringstream ss(record);
//		string a, b, c;
//		ss >> a >> b >> c;
//		vec[stoi(b)].push_back(conv(a));
//	}
//
//	vector<int> ans;
//	for (int i = 0; i < 10000; ++i) if (!vec[i].empty()) {
//		if (vec[i].size() & 1) vec[i].push_back(23 * 60 + 59);
//
//		int sum = 0;
//		for (int j = 1; j < vec[i].size(); j += 2) sum += vec[i][j] - vec[i][j - 1];
//
//		int val = fees[1];
//		if (sum > fees[0]) val += (sum - fees[0] + fees[2] - 1) / fees[2] * fees[3];
//
//		ans.push_back(val);
//	}
//
//	return ans;
//}