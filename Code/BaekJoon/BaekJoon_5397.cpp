#include <iostream>
#include <vector>
#include <string>
#include <stack>

using namespace std;

string KeyLogger(string& strPassword);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int iCnt{};

	cin >> iCnt;
	vector<string> vecPassword(iCnt);

	for (int i = 0; i < iCnt; i++)
	{
		string strPassword;

		cin >> strPassword;
		vecPassword[i] = KeyLogger(strPassword);
	}

	for (string Password : vecPassword)
		cout << Password << "\n";

	return 0;
}

string KeyLogger(string& strPassword)
{
	string strResult{};
	stack<char> stStack1, stStack2;

	for (char chWord : strPassword)
	{
		if (chWord == '<')
		{
			if (!stStack1.empty())
			{
				char chTop = stStack1.top();
				stStack1.pop();
				stStack2.push(chTop);
			}
			else continue;
		}
		else if (chWord == '>')
		{
			if (!stStack2.empty())
			{
				char chTop = stStack2.top();
				stStack2.pop();
				stStack1.push(chTop);
			}
			else continue;
		}
		else if (chWord == '-')
		{
			if (!stStack1.empty())
				stStack1.pop();
			else continue;
		}
		else
			stStack1.push(chWord);
	}

	while (!stStack1.empty())
	{
		char chTop = stStack1.top();
		stStack1.pop();
		stStack2.push(chTop);
	}

	while (!stStack2.empty())
	{
		strResult += stStack2.top();
		stStack2.pop();
	}

	return strResult;
}

// GPT가 뽑아준 stack을 이용한 풀이인데 몇몇 배울점이 있다
// stack의 push에 top을 이용한 값을 바로 넣어버리는 방법 맘에 든다
// string의 길이만큼 미리 reserve로 capacity를 할당해두면 성능 상 이점이 있다
// 나처럼 한쪽 스택에 다 몰아넣고 한번에 꺼내서 문자열에 붙여주는게 아니라 한번 reverse로 반전을 시켜줬다! 똑똑하네

#ifdef _RELEASE

#include <bits/stdc++.h>
using namespace std;

string solve(const string& s) {
	stack<char> left, right;

	for (char c : s) {
		if (c == '<') {
			if (!left.empty()) {
				right.push(left.top());
				left.pop();
			}
		}
		else if (c == '>') {
			if (!right.empty()) {
				left.push(right.top());
				right.pop();
			}
		}
		else if (c == '-') {
			if (!left.empty()) {
				left.pop();
			}
		}
		else {
			left.push(c);
		}
	}

	// 왼쪽 스택에서 문자열로 옮기기 (역순으로)
	string res;
	res.reserve(left.size() + right.size());
	while (!left.empty()) {
		res += left.top();
		left.pop();
	}
	reverse(res.begin(), res.end());

	// 오른쪽 스택 이어붙이기
	while (!right.empty()) {
		res += right.top();
		right.pop();
	}

	return res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		string input;
		cin >> input;
		cout << solve(input) << '\n';
	}

	return 0;
}

#endif

// list를 이용한 풀이법
// list의 iterator 하나를 두고 위치를 옮겨가면서 삽입/삭제하는 식인데 스택보다 깔끔해 보인다
// string의 범위 기반 생성자로 list의 문자들을 복사하는 방식은 처음 보는데 신기하다

#ifdef _RELEASE

#include <iostream>
#include <list>
#include <string>
using namespace std;

string solve(const string& s) {
	list<char> text;
	auto cursor = text.begin();

	for (char ch : s) {
		if (ch == '<') {
			if (cursor != text.begin()) --cursor;
		}
		else if (ch == '>') {
			if (cursor != text.end()) ++cursor;
		}
		else if (ch == '-') {
			if (cursor != text.begin()) {
				cursor = text.erase(--cursor);
			}
		}
		else {
			text.insert(cursor, ch);
		}
	}

	// list → string으로 변환
	return string(text.begin(), text.end());
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		string input;
		cin >> input;
		cout << solve(input) << '\n';
	}

	return 0;
}

#endif