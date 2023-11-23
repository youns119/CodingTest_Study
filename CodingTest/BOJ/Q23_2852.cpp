#include <iostream>
#include <vector>
#include <string>

using namespace std;

int ToInt(string time);
void BB(vector<pair<int, int>>& scores);

int main()
{
	int N;
	vector<pair<int, int>> scores;

	cin >> N;
	scores.assign(N, { 0,0 });
	
	for (int i = 0; i < N; i++)
	{
		string s;
		int time;

		cin >> scores[i].first;
		cin >> s;

		time = ToInt(s);
		scores[i].second = time;
	}

	BB(scores);

	return 0;
}

int ToInt(string time)
{
	string str_m = time.substr(0, 2);
	string str_s = time.substr(3, 2);

	int m = stoi(str_m);
	int s = stoi(str_s);

	int result = m * 60 + s;
	return result;
}

void BB(vector<pair<int, int>>& scores)
{
	int size = scores.size();
	int lastTime;
	vector<int> score(2, 0);
	vector<int> result(2, 0);

	score[scores[0].first - 1]++;
	lastTime = scores[0].second;

	for (int i = 1; i < size; i++)
	{
		int currTeam = scores[i].first;
		int currTime = scores[i].second;

		for (int j = 0; j < 2; j++)
			if (score[j] > score[(j + 1) % 2])
				result[j] += currTime - lastTime;

		score[currTeam - 1]++;
		lastTime = scores[i].second;
	}

	for (int i = 0; i < 2; i++)
	{
		if (score[i] > score[(i + 1) % 2])
			result[i] += 48 * 60 - lastTime;

		printf("%02d:%02d\n", result[i] / 60, result[i] % 60);
	}
}