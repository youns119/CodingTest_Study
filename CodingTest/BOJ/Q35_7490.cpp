#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

bool Check(string result);
void Print(vector<int> TC);

int main()
{
	int N;
	vector<int> TC;

	cin >> N;
	TC.assign(N, 0);

	for (int i = 0; i < N; i++)
		cin >> TC[i];

	Print(TC);

	return 0;
}

bool Check(string result)
{
	int sum = 0;
	int num = 0;
	char op = '+';

	result.erase(remove(result.begin(), result.end(), ' '), result.end());

	for (int i = 0; i <= result.length(); i++)
	{
		if (result[i] >= '1' && result[i] <= '9')
			num = num * 10 + result[i] - '0';
		else
		{
			if (op == '+') { sum += num; num = 0; }
			else if (op == '-') { sum -= num; num = 0; }
			op = result[i];
		}
	}

	return sum == 0;
}

void Print(vector<int> TC)
{
	string result = "";
	stack<pair<int, string>> st;

	for (auto t : TC)
	{
		bool isFinished = false;

		st.push(make_pair(1, ""));

		while (!st.empty())
		{
			int num = st.top().first;
			string op = st.top().second;

			st.pop();
			result += op + to_string(num);

			if (num == t)
			{
				if (Check(result))
					cout << result << "\n";

				while (op == "-")
				{
					result.erase(result.end() - 2, result.end());

					if (result.length() <= 1)
					{
						isFinished = true;
						break;
					}

					op = result.substr(result.length() - 2, 1);
				}

				if (isFinished)
					continue;

				result.erase(result.end() - 2, result.end());
				continue;
			}

			st.push(make_pair(num + 1, "-"));
			st.push(make_pair(num + 1, "+"));
			st.push(make_pair(num + 1, " "));
		}

		result = "";
		cout << "\n";
	}
}