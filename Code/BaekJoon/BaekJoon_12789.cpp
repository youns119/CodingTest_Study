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

// queue, stack�� ȥ���ؼ� ����ϴ� Ǯ��
// vector ��� queue�� ����ϴ� �� �� �������̱��ϴ�
// ���� ��쿡�� vector�� ���� ���ϰ� �� �Ŀ� stack�� ������ while���� ���� �������ν�
// �� �ݺ������� stack�� �� �о�������� �� Ǯ���� ��쿡�� while �ݺ��� �ȿ��� �� ������ ���ϰ�
// �������� while�� �� ������ stack�� �ʹ� ���

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