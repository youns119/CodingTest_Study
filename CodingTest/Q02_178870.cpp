#include <iostream>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k);

int main()
{
	int size;
	int k;
	vector<int> sequence;
	vector<int> answer;

	cin >> size >> k;

	sequence.assign(size, 0);

	for (int i = 0; i < size; i++)
		cin >> sequence[i];

	answer = solution(sequence, k);

	cout << answer[0] << " " << answer[1];

	return 0;
}

vector<int> solution(vector<int> sequence, int k)
{
	int size = sequence.size();
	int start = 0, end = 0;
	int start_final, end_final;
	int sum = sequence[0];
	int length = 1000001;
	vector<int> answer;

	while (end < size)
	{
		if (sum < k)
		{
			end++;

			if (end < size)
				sum += sequence[end];
		}
		else if (sum > k)
		{
			sum -= sequence[start];
			start++;
		}
		else
		{
			int len = end - start;

			if (len < length)
			{
				length = len;
				start_final = start;
				end_final = end;
			}

			sum -= sequence[start];
			start++;
			end++;

			if (end < size)
				sum += sequence[end];
		}
	}

	answer.push_back(start_final);
	answer.push_back(end_final);

	return answer;
}

// ÄÚµå ³Ê¹« ±ò²ûÇÑµí
//#include <vector>
//
//using namespace std;
//
//vector<int> solution(vector<int> sequence, int k)
//{
//	vector<int> answer;
//
//	int srt = 0, end = 0, sum = 0;
//
//	for (int i = 0; i < sequence.size(); i++)
//	{
//		end = i;
//		sum += sequence[end];
//
//		while (sum > k)
//			sum -= sequence[srt++];
//
//		if (sum == k)
//			if (answer.empty() || end - srt < answer[1] - answer[0])
//				answer = { srt, end };
//	}
//
//	return answer;
//}