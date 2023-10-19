#include <iostream>
#include <vector>
#include <stack>

using namespace std;

bool Check(int column, vector<int>& board);
//void NQueen(int count, vector<int>& board, int& result);
void NQueen(vector<int>& board);

int main()
{
	int result = 0;
	int line = 0;
	vector<int> board;

	cin >> line;

	board.assign(line, 0);

	cout << result;

	return 0;
}

bool Check(int column, vector<int>& board)
{
	bool isGood = true;

	for (int i = 0; i < column; i++)
		if (board[i] == board[column] ||
			(column - i) == abs(board[column] - board[i]))
		{
			isGood = false;
			break;
		}

	return isGood;
}

// 재귀식
//void NQueen(int count, vector<int>& board, int& result)
//{
//	if (count == board.size())
//	{
//		result++;
//		return;
//	}
//
//	for (int i = 0; i < board.size(); i++)
//	{
//		board[count] = i;
//
//		if (Check(count, board))
//			NQueen(count + 1, board, result);
//	}
//}

// Stack식
void NQueen(vector<int>& board)
{
	stack<int> st;

	st.push(0);

	while (!st.empty())
	{
		int current = st.top();

		st.pop();

		for (int i = board.size() - 1; i >= 0; i++)
		{
			board[current] = i;

			if (Check(current, board))
			{
				st.push(i);

			}
		}
	}
}

// Stack으로도 구현해볼 것