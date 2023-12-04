#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int Comp(vector<int>& cards);

int main()
{
	int N, result;
	vector<int> cards;

	cin >> N;
	cards.assign(N, 0);

	for (int i = 0; i < N; i++)
		cin >> cards[i];

	result = Comp(cards);
	cout << result;

	return 0;
}

int Comp(vector<int>& cards)
{
	int result = 0;
	priority_queue<int, vector<int>, greater<int>> pq;

	for (auto card : cards)
		pq.push(card);

	while (pq.size() != 1)
	{
		int num1, num2, sum;

		num1 = pq.top();
		pq.pop();
		num2 = pq.top();
		pq.pop();

		sum = num1 + num2;
		pq.push(sum);

		result += sum;
	}

	return result;
}