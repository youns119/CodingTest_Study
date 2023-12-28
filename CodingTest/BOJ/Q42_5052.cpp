#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>

using namespace std;

void IsConsist(vector<string>& numbers, vector<string>& answers);

int main()
{
	int t, n;
	string num;
	vector<string> numbers;
	vector<string> answers;

	cin >> t;
	while (t--)
	{
		cin >> n;
		numbers.assign(n, "");
		for (int i = 0; i < n; i++)
			cin >> numbers[i];
		
		IsConsist(numbers, answers);
		numbers.clear();
		numbers.shrink_to_fit();
	}

	for (auto answer : answers)
		cout << answer << "\n";

	return 0;
}

void IsConsist(vector<string>& numbers, vector<string>& answers)
{
	int size = numbers.size();
	bool bFind = false;
	unordered_set<string> us;

	sort(numbers.begin(), numbers.end());
	for (int i = 0; i < size; i++)
	{
		string s = "";
		for (int j = 0; j < numbers[i].length() - 1; j++)
		{
			s += numbers[i][j];
			if (us.find(s) != us.end()) { bFind = true; break; }
		}

		if (bFind) { answers.push_back("NO"); break; }
		else us.insert(numbers[i]);
	}

	if (!bFind) answers.push_back("YES");
}

// 문자열 인덱스 비교를 통한 풀이
//int main() {
//	int tc;
//	string str;
//	cin >> tc;
//	while (tc--) {
//		int n;
//		cin >> n;
//		vector<string> book;
//		for (int i = 0; i < n; i++) {
//			cin >> str;
//			book.push_back(str);
//		}
//
//		sort(book.begin(), book.end());
//
//		bool flag = false;
//		for (int i = 0; i < n - 1; i++) {
//			string a = book.at(i), b = book.at(i + 1);
//
//			if (a.size() >= b.size()) continue;
//			if (a == b.substr(0, a.size())) {
//				cout << "NO" << "\n";
//				flag = true;
//				break;
//			}
//		}
//		if (!flag) cout << "YES" << "\n";
//	}
//
//	return 0;
//}