#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int size, result;
	vector<int> cards;
	vector<int> max;

	cin >> size;
	cards.assign(size + 1, 0);
	max.assign(size + 1, 0);

	for (int i = 1; i <= size; i++)
	{
		cin >> cards[i];

		for (int j = 1; j <= i; j++)
			max[i] = max[i] > max[i - j] + cards[j] ? max[i] : max[i - j] + cards[j];
	}

	cout << max[size];

	return 0;
}