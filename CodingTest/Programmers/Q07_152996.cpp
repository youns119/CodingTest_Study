#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;

void Input(int N, vector<int>& weights);
long long solution(vector<int> weights);

int main()
{
	int N = 0;
	long long result = 0;
	vector<int> weights;

	Input(N, weights);
	result = solution(weights);

	cout << result;

	return 0;
}

void Input(int N, vector<int>& weights)
{
	cin >> N;
	weights.assign(N, 0);

	for (int i = 0; i < N; i++)
		cin >> weights[i];
}

// 시간 초과. 처음엔 이 방향 밖에 생각이 안났지만 3중 반복문인만큼 시간 초과가 될 거라 예상은 했다.
//long long solution(vector<int> weights)
//{
//	int size = weights.size();
//	vector<int> v = { 4, 3, 2 };
//	long long result = 0;
//
//	sort(weights.begin(), weights.end());
//
//	for (int i = 0; i < size - 1; i++)
//	{
//		for (int j = i + 1; j < size; j++)
//			for (int k = 0; k < v.size(); k++)
//			{
//				int weight = weights[i] * v[k];
//				
//				if (weight % weights[j] == 0)
//				{
//					int dis = weight / weights[j];
//
//					if(dis == v[0] || dis == v[1] || dis == v[2])
//					{
//						result++;
//						break;
//					}
//				}
//			}
//	}
//
//	return result;
//}

// 가장 문제가 의도한대로 푼 듯한 풀이다.
//long long solution(vector<int> weights)
//{
//    long long answer = 0;
//    vector<pair<int, int>> v = { {4,2}, {4,3}, {3,2} };
//    int size = weights.size();
//    unordered_map<int, long long> m;
//    set<int> s;
//
//    sort(weights.begin(), weights.end());
//
//    for (int i = 0; i < size; i++)
//    {
//        m[weights[i]]++;
//        s.insert(weights[i]);
//    }
//
//    for (auto weight : m)
//        answer += (weight.second) * (weight.second - 1) / 2;
//
//    for (auto weight : s)
//    {
//        for (int i = 0; i < v.size(); i++)
//        {
//            int w = weight * v[i].first;
//
//            if (w % v[i].second != 0)
//                continue;
//
//            int c = w / v[i].second;
//            answer += m[weight] * m[c];
//        }
//    }
//
//    return answer;
//}

// 가장 획기적이고 깔끔한 풀이. 생각도 못한 풀이라 보고 공부가 많이 됐다.
long long solution(vector<int> weights) {

    long long answer = 0;
    vector<long long> arr(2001, 0);

    for (const auto v : weights)
        arr[v]++;

    for (int i = 100; i <= 1000; ++i)
    {
        if (arr[i] == 0)
            continue;

        answer += arr[i] * (arr[i] - 1) / 2;
        answer += arr[i] * arr[2 * i];

        if ((i * 3) % 2 == 0)
            answer += arr[i] * arr[i * 3 / 2];

        if ((i * 4) % 3 == 0)
            answer += arr[i] * arr[i * 4 / 3];
    }

    return answer;
}