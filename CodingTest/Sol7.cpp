#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int Game(int size, vector<pair<int, int>>& apples, vector<pair<int, string>>& dirChange);

enum class Dir
{
	R,
	D,
	L,
	U
};

int main()
{
	int size;
	int appleCount;
	int dirCount;
	int result;

	vector<pair<int, int>> apples;
	vector<pair<int, string>> dirChange;

	cin >> size;
	cin >> appleCount;

	for (int i = 0; i < appleCount; i++)
	{
		int x, y;

		cin >> x >> y;
		apples.push_back(make_pair(y, x));
	}

	cin >> dirCount;

	for (int i = 0; i < dirCount; i++)
	{
		int sec;
		string dir;

		cin >> sec >> dir;
		dirChange.push_back(make_pair(sec, dir));
	}

	result = Game(size, apples, dirChange);

	cout << result;

	return 0;
}

int Game(int size, vector<pair<int, int>>& apples, vector<pair<int, string>>& dirChange)
{
	int sec = 0;
	int dirCount = dirChange.size();
	int countNow = 0;
	int appleCount = apples.size();
	int valx, valy;
	int x, y;
	bool hit = false;
	Dir dir = Dir::R;
	deque<pair<int, int>> snake(1, make_pair(1, 1));

	while (true)
	{
		sec++;

		switch (dir)
		{
		case Dir::R :
			valx = 1;
			valy = 0;
			break;

		case Dir::L :
			valx = -1;
			valy = 0;
			break;

		case Dir::U :
			valx = 0;
			valy = -1;
			break;

		case Dir::D :
			valx = 0;
			valy = 1;
			break;
		}

		x = snake.front().first + valx;
		y = snake.front().second + valy;

		for (auto body : snake)
		{
			if (body.first == x && body.second == y)
				return sec;
		}

		if (x == size + 1 ||
			x == 0 ||
			y == size + 1 ||
			y == 0)
			return sec;

		for (int i = 0; i < apples.size(); i++)
			if (snake.front() == apples[i])
			{
				hit = true;
				apples.erase(apples.begin() + i);
				break;
			}

		snake.push_front(make_pair(snake.front().first + valx, snake.front().second + valy));

		if (!hit)
			snake.pop_back();

		hit = false;

		if (countNow != dirChange.size() &&
			sec == dirChange[countNow].first)
		{
			if (!dirChange[countNow].second.compare("D"))
			{
				switch (dir)
				{
				case Dir::R :
					dir = Dir::D;
					break;

				case Dir::D :
					dir = Dir::L;
					break;

				case Dir::L :
					dir = Dir::U;
					break;
				
				case Dir::U :
					dir = Dir::R;
					break;
				}
			}
			else if (!dirChange[countNow].second.compare("L"))
			{
				switch (dir)
				{
				case Dir::R:
					dir = Dir::U;
					break;

				case Dir::U:
					dir = Dir::L;
					break;

				case Dir::L:
					dir = Dir::D;
					break;

				case Dir::D:
					dir = Dir::R;
					break;
				}
			}

			countNow++;
		}
	}
}