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

// GPT�� �̾��� stack�� �̿��� Ǯ���ε� ��� ������� �ִ�
// stack�� push�� top�� �̿��� ���� �ٷ� �־������ ��� ���� ���
// string�� ���̸�ŭ �̸� reserve�� capacity�� �Ҵ��صθ� ���� �� ������ �ִ�
// ��ó�� ���� ���ÿ� �� ���Ƴְ� �ѹ��� ������ ���ڿ��� �ٿ��ִ°� �ƴ϶� �ѹ� reverse�� ������ �������! �ȶ��ϳ�

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

	// ���� ���ÿ��� ���ڿ��� �ű�� (��������)
	string res;
	res.reserve(left.size() + right.size());
	while (!left.empty()) {
		res += left.top();
		left.pop();
	}
	reverse(res.begin(), res.end());

	// ������ ���� �̾���̱�
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

// list�� �̿��� Ǯ�̹�
// list�� iterator �ϳ��� �ΰ� ��ġ�� �Űܰ��鼭 ����/�����ϴ� ���ε� ���ú��� ����� ���δ�
// string�� ���� ��� �����ڷ� list�� ���ڵ��� �����ϴ� ����� ó�� ���µ� �ű��ϴ�

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

	// list �� string���� ��ȯ
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