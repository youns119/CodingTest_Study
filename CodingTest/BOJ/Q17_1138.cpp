#include <iostream>
#include <map>

using namespace std;

void Arrange(map<int, int>& lines, int N);

int main()
{
	int N;
	map<int, int> lines;

	cin >> N;

	Arrange(lines, N);

	for (auto it : lines)
		cout << it.second << " ";

	return 0;
}

void Arrange(map<int, int>& lines, int N)
{
	for (int i = 0; i < N; i++)
	{
		int height = i + 1;
		int c = 0;
		int num;

		cin >> num;

		for (int j = 0; j < N; j++)
		{
			if (lines[j] == 0)
				c++;
			else
				continue;

			if (c == num + 1)
				lines[j] = height;
		}
	}
}