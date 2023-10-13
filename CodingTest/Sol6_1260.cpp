#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int num;
	queue<int> cards;

	cin >> num;

	for (int i = 1; i <= num; i++)
		cards.push(i);

	while (cards.size() != 1)
	{
		int top;

		cards.pop();
		top = cards.front();

		cards.pop();
		cards.push(top);
	}

	cout << cards.front();

	return 0;
}