#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<bool> vecQS;
	deque<int> dqQS;
	int iCount{};

	cin >> iCount;
	vecQS.resize(iCount);

	for (int i = 0; i < vecQS.size(); i++)
	{
		int iQS{};

		cin >> iQS;
		if (iQS == 0)
			vecQS[i] = true;
	}

	for (int i = 0; i < vecQS.size(); i++)
	{
		int iNum{};

		cin >> iNum;
		if(vecQS[i])
			dqQS.push_back(iNum);
	}

	cin >> iCount;
	for (int i = 0; i < iCount; i++)
	{
		int iNum{};

		cin >> iNum;
		dqQS.push_front(iNum);
		cout << dqQS.back() << " ";
		dqQS.pop_back();
	}

	return 0;
}

// vector만을 사용한 풀이
// deque를 쓰는게 더 편할 것 같다

#ifdef _RELEASE

#include <iostream>
#include <vector>

using namespace std;

void QueueStack(vector<pair<int, int>>& vecQS, int iNum);

int main() {
    int iCount;
    cin >> iCount;

    vector<pair<int, int>> vecQS(iCount);

    for (int i = 0; i < iCount; i++) {
        int iQS;
        cin >> iQS;
        vecQS[i].first = iQS;
    }

    for (int i = 0; i < iCount; i++) {
        int iNum;
        cin >> iNum;
        vecQS[i].second = iNum;
    }

    int qCount;
    cin >> qCount;

    for (int i = 0; i < qCount; i++) {
        int iNum;
        cin >> iNum;
        QueueStack(vecQS, iNum);
    }

    return 0;
}

void QueueStack(vector<pair<int, int>>& vecQS, int iNum) {
    vector<int> stack;
    vector<int> queue;

    for (auto& qs : vecQS) {
        if (qs.first == iNum) {
            stack.push_back(qs.second);
        }
    }

    for (int i = 0; i < stack.size(); i++) {
        queue.push_back(stack[i]);
    }

    for (int i = 0; i < queue.size(); i++) {
        cout << queue[i] << " ";
    }
    cout << endl;
}

#endif