#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int Rain(vector<int>& blocks);

int main()
{
	int H, W, result;
	vector<int> blocks;

	cin >> H >> W;
	blocks.assign(W, H);

	for (int i = 0; i < W; i++)
		cin >> blocks[i];

	result = Rain(blocks);
	cout << result;

	return 0;
}

int Rain(vector<int>& blocks)
{
	int result = 0;

	for (int i = 1; i < blocks.size() - 1; i++)
	{
		int l, r;
		int curr = blocks[i];
		int rain;

		l = *max_element(blocks.begin(), blocks.begin() + i);
		r = *max_element(blocks.begin() + i + 1, blocks.end());
		rain = min(l, r) - curr;

		if(rain > 0)
			result += rain;
	}

	return result;
}