#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int Pop(deque<int>& dq, vector<int>& nums);

int main()
{
	int N, M, result;
	deque<int> dq;
	vector<int> nums;

	cin >> N >> M;

	for (int i = 0; i < N; i++)
		dq.push_back(i + 1);

	nums.assign(M, 0);
	for (int i = 0; i < M; i++)
		cin >> nums[i];

	result = Pop(dq, nums);
	cout << result;

	return 0;
}

int Pop(deque<int>& dq, vector<int>& nums)
{
	int result = 0;

	for (auto num : nums)
	{
		int temp;

		while (dq.front() != num)
		{
			int index;
			for (int i = 0; i < dq.size(); i++)
				if (dq[i] == num)
				{
					index = i + 1; 
					break;
				}

			if (index <= (dq.size() + 1) / 2)
			{
				temp = dq.front();
				dq.pop_front();
				dq.push_back(temp);
			}
			else
			{
				temp = dq.back();
				dq.pop_back();
				dq.push_front(temp);
			}

			result++;
		}

		if (dq.front() == num)
			dq.pop_front();
	}

	return result;
}