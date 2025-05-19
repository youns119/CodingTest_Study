#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> vecLine;
	stack<int> stLine;
	int iCount{};

	cin >> iCount;

	for (int i = 0; i < iCount; i++)
	{
		int iNum{};

		cin >> iNum;
		vecLine.push_back(iNum);
	}

	int iCurr{ 1 };
	for (int i = 0; i < vecLine.size(); i++)
	{
		if (vecLine[i] == iCurr)
			iCurr++;
		else
			stLine.push(vecLine[i]);

		while (!stLine.empty())
		{
			if (stLine.top() == iCurr)
			{
				stLine.pop();
				iCurr++;
			}
			else break;
		}
	}

	if (!stLine.empty()) cout << "Sad";
	else cout << "Nice";

	return 0;
}

// queue, stack을 혼합해서 사용하는 풀이
// vector 대신 queue를 사용하는 게 더 직관적이긴하다
// 나의 경우에는 vector의 값을 비교하고 그 후에 stack의 값들을 while문을 통해 비교함으로써
// 한 반복문에서 stack을 다 털어버리지만 이 풀이의 경우에는 while 반복문 안에서 한 번씩만 비교하고
// 마지막에 while문 한 번으로 stack을 터는 방식

#ifdef _RELEASE

#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main() {
    int N;
    cin >> N;

    queue<int> line;
    for (int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        line.push(num);
    }

    stack<int> waiting;
    int order = 1;

    while (!line.empty()) {
        if (line.front() == order) {
            line.pop();
            ++order;
        }
        else if (!waiting.empty() && waiting.top() == order) {
            waiting.pop();
            ++order;
        }
        else {
            waiting.push(line.front());
            line.pop();
        }
    }

    while (!waiting.empty()) {
        if (waiting.top() == order) {
            waiting.pop();
            ++order;
        }
        else {
            break;
        }
    }

    if (waiting.empty()) cout << "Nice\n";
    else cout << "Sad\n";

    return 0;
}

#endif