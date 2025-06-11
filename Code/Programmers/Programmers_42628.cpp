#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

vector<int> solution(vector<string> operations);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int iCnt{};

	cin >> iCnt;
	cin.ignore();
	vector<string> vecOp(iCnt);

	for (int i = 0; i < iCnt; ++i)
	{
		string strOp{};

		getline(cin, strOp);
		vecOp[i] = strOp;
	}

	vector<int> vecResult = solution(vecOp);
	cout << vecResult[0] << " " << vecResult[1];

	return 0;
}

vector<int> solution(vector<string> operations) 
{
	vector<int> answer;
	answer.assign(2, 0);

	multiset<int> setNum;

	for (string& strOp : operations)
	{
		char chOp = strOp[0];
		int iNum = stoi(strOp.substr(2));

		if (chOp == 'I')
			setNum.insert(iNum);
		else if (chOp == 'D' && !setNum.empty())
		{
			if (iNum == 1)
				setNum.erase(--setNum.end());
			else if(iNum == -1)
				setNum.erase(setNum.begin());
		}
	}

	if (!setNum.empty())
	{
		answer[0] = *(--setNum.end());
		answer[1] = *setNum.begin();
	}

	return answer;
}

// priority_queue를 활용하는 풀이
// 처음으로 내가 생각해냈던 풀이였는데 오름차순이나 내림차순으로 정렬이 가능한 대신에
// 순회가 불가능하기 때문에 최대/최소값을 동시에 다루는게 좀 성가실 것 같아서 포기한 풀이다
// 중복값 포함에 최대/최소를 동시에 다루는 경우엔 multiset이 더 좋은 풀이인듯

#ifdef _RELEASE

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cstring>
#include <functional>

using namespace std;

priority_queue<int, vector<int>, greater<int>> min_heap;
priority_queue<int> max_heap;

vector<int> solution(vector<string> arguments) {
    vector<int> answer;

    for (int i = 0; i < arguments.size(); i++)
    {
        string a = arguments[i];
        char o = a[0];
        int n = atoi(a.substr(2).c_str());

        if (o == 'I')
        {
            min_heap.push(n);
            max_heap.push(n);
        }
        else if (o == 'D' && n == 1)
        {
            if (max_heap.empty()) continue;
            if (max_heap.top() == min_heap.top()) min_heap.pop();
            max_heap.pop();
        }
        else if (o == 'D' && n == -1)
        {
            if (min_heap.empty()) continue;
            if (max_heap.top() == min_heap.top()) max_heap.pop();
            min_heap.pop();
        }

        if (max_heap.top() < min_heap.top())
        {
            while (!min_heap.empty()) min_heap.pop();
            while (!max_heap.empty()) max_heap.pop();
        }
    }

    if (min_heap.empty())
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    else
    {
        answer.push_back(max_heap.top());
        answer.push_back(min_heap.top());
    }

    return answer;
}

#endif

// deque를 사용한 풀이
// 처음과 끝의 값을 쉽게 뺄 수 있다는 점에서 priority_queue 다음으로 생각해봤던 풀이
// 그러나 자동정렬을 제공하지 않아서 계속해서 sort를 해줘야하기 때문에 성능 상 별로일 것 같아서 안했다
// 의외로 priority_queue를 사용하는 경우보다 코드 자체는 더 깔끔해진다

#ifdef _RELEASE

#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

vector<int> solution(vector<string> arguments) {
    vector<int> answer;
    answer.resize(2);

    deque<int> dq;

    for (int i = 0; i < arguments.size(); ++i)
    {
        if (dq.size() > 0)
        {
            if ('D' == arguments[i][0])
            {
                int iTemp = atoi(arguments[i].substr(2, arguments[i].size() - 2 + 1).c_str());
                if (iTemp > 0)
                {
                    dq.pop_back();
                }
                else
                {
                    dq.pop_front();
                }

            }
        }

        if (dq.size() >= 0)
        {
            if ('I' == arguments[i][0])
            {
                int iTemp = atoi(arguments[i].substr(2, arguments[i].size() - 2 + 1).c_str());

                dq.push_back(iTemp);
                sort(dq.begin(), dq.end());
            }
        }
    }

    if (false == dq.empty())
    {
        answer[0] = dq.back();
        answer[1] = dq.front();
    }

    return answer;
}

#endif