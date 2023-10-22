#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>

using namespace std;

struct MinMax
{
	int xmin;
	int ymin;
	int xmax;
	int ymax;
};

void AddToDot(vector<string>& nums, vector<vector<int>>& dot);
bool Check(MinMax board, vector<vector<int>>& dot);
void Quad(vector<vector<int>>& dot);

int main()
{
	int size;
	string num;
	string result;
	vector<vector<int>> dot;
	vector<string> nums;

	cin >> size;
	dot.assign(size, vector<int>(size, 0));
	nums.assign(size, "");

	for (int i = 0; i < size; i++)
	{
		cin >> num;
		nums[i] = num;
	}

	AddToDot(nums, dot);
	Quad(dot);

	return 0;
}

void AddToDot(vector<string>& nums, vector<vector<int>>& dot)
{
	stack<int> st;

	for (int i = 0; i < dot.size(); i++)
	{
		for (int j = 0; j < dot[i].size(); j++)
		{
			int singleNum;
			string singleChar;

			singleChar = nums[i].substr(j, 1);
			singleNum = stoi(singleChar);

			dot[j][i] = singleNum;
		}
	}
}

bool Check(MinMax board, vector<vector<int>>& dot)
{
	int prime = dot[board.xmin][board.ymin];

	for (int i = board.ymin; i < board.ymax; i++)
	{
		for (int j = board.xmin; j < board.xmax; j++)
		{
			if (dot[j][i] != prime)
				return false;
		}
	}

	return true;
}

void Quad(vector<vector<int>>& dot)
{
	MinMax board = { 0, 0, dot.size(), dot[0].size() };
	stack<MinMax> st;

	st.push(board);

	while (!st.empty())
	{
		MinMax curr = st.top();
		int xhalf = curr.xmin + (curr.xmax - curr.xmin) / 2;
		int yhalf = curr.ymin + (curr.ymax - curr.ymin) / 2;

		st.pop();

		if (Check(curr, dot))
		{
			cout << dot[curr.xmin][curr.ymin];

			if (curr.xmax % 2 == 0 &&
				curr.ymax % 2 == 0)
				cout << ")";
		}
		else
		{
			cout << "(";
			
			MinMax temp = { xhalf, yhalf, curr.xmax, curr.ymax };
			st.push(temp);
			temp = { curr.xmin, yhalf, xhalf, curr.ymax };
			st.push(temp);
			temp = { xhalf, curr.ymin, curr.xmax, yhalf };
			st.push(temp);
			temp = { curr.xmin, curr.ymin, xhalf, yhalf };
			st.push(temp);
		}
	}
}