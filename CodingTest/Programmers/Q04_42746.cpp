#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

// 우선순위 큐는 cmp를 구조체를 만들어 써야한다.
// 또한 return 값이 vector의 뒤쪽 배열로 들어간다는 것을 유의
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

	// result가 0일 경우의 예외 처리도 해야함... 무친문제
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

// 몇몇 예외 케이스 때문에 불통과...
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