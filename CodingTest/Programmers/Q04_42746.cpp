#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

// �켱���� ť�� cmp�� ����ü�� ����� ����Ѵ�.
// ���� return ���� vector�� ���� �迭�� ���ٴ� ���� ����
struct cmp
{
	bool operator()(string a, string b)
	{
		return a + b < b + a;
	}
};

string solution(vector<int> numbers);

int main()
{
	int size, num;
	vector<int> numbers;
	string result;

	cin >> size;
	numbers.assign(size, 0);

	for (int i = 0; i < size; i++)
		cin >> numbers[i];

	result = solution(numbers);
	cout << result;

	return 0;
}

string solution(vector<int> numbers)
{
	string answer = "";
	priority_queue<string, vector<string>, cmp> q;

	for (int number : numbers)
		q.push(to_string(number));

	// result�� 0�� ����� ���� ó���� �ؾ���... ��ģ����
	for (int i = 0; i < numbers.size(); i++)
	{
		if (answer == "0")
			answer = q.top();
		else
			answer += q.top();

		q.pop();
	}

	return answer;
}

// ��� ���� ���̽� ������ �����...
//string solution(vector<int> numbers)
//{
//	string answer = "";
//	int len_max = to_string(1000).length();
//	priority_queue<pair<string, int>, vector<pair<string,int>>, cmp> q;
//
//	for (int i = 0; i < numbers.size(); i++)
//	{
//		string s = "";
//		pair<string, int> p;
//		int len = len_max - to_string(numbers[i]).length();
//
//		s += to_string(numbers[i]);
//
//		for (int j = 0; j < len; j++)
//			s += s[0];
//
//		p = { s, numbers[i] };
//		q.push(p);
//	}
//
//	for (int i = 0; i < numbers.size(); i++)
//	{
//		answer += to_string(q.top().second);
//		q.pop();
//	}
//
//	return answer;
//}