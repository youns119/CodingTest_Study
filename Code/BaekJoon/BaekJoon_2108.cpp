#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>

using namespace std;

void Print_Average(vector<int>& vecNumber);
void Print_Center(vector<int>& vecNumber);
void Print_Mode(vector<int>& vecNumber);
void Print_Range(vector<int>& vecNumber);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> vecNumber;

	int iCount{}, iNum{};

	cin >> iCount;

	for (int i = 0; i < iCount; i++)
	{
		cin >> iNum;
		vecNumber.push_back(iNum);
	}

	sort(vecNumber.begin(), vecNumber.end());

	Print_Average(vecNumber);
	Print_Center(vecNumber);
	Print_Mode(vecNumber);
	Print_Range(vecNumber);

	return 0;
}

void Print_Average(vector<int>& vecNumber)
{
	int iAvg{};

	for (int iNum : vecNumber)
		iAvg += iNum;

	iAvg = round((float)iAvg / vecNumber.size());

	cout << iAvg << "\n";
}

void Print_Center(vector<int>& vecNumber)
{
	cout << vecNumber[vecNumber.size() / 2] << "\n";
}

void Print_Mode(vector<int>& vecNumber)
{
	map<int, int> mapNumber;
	int iMost{};

	for (int iNum : vecNumber)
	{
		mapNumber[iNum]++;
		if (mapNumber[iNum] > iMost) iMost = mapNumber[iNum];
	}

	vector<int> vecMost;

	for (auto Pair : mapNumber)
		if (Pair.second == iMost)
			vecMost.push_back(Pair.first);

	sort(vecMost.begin(), vecMost.end());

	if (vecMost.size() > 1)
		cout << vecMost[1] << "\n";
	else
		cout << vecMost[0] << "\n";
}

void Print_Range(vector<int>& vecNumber)
{
	cout << vecNumber[vecNumber.size() - 1] - vecNumber[0] << "\n";
}

// 그냥 한 번에 vector랑 map에 값을 다 입력받는 방법
// 가독성은 좀 떨어지지만 확실히 더 빠르긴하다

#ifdef _RELEASE

#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> numbers(N);
    map<int, int> freq_map;

    for (int i = 0; i < N; i++) {
        cin >> numbers[i];
        freq_map[numbers[i]]++;
    }

    sort(numbers.begin(), numbers.end());

    int sum = 0;
    for (int num : numbers) {
        sum += num;
    }
    int average = round((float)sum / N);

    int median = numbers[N / 2];

    int mode = numbers[0];
    int max_count = 1;
    bool second_mode = false;
    for (auto& entry : freq_map) {
        if (entry.second > max_count) {
            max_count = entry.second;
            mode = entry.first;
            second_mode = false;
        }
        else if (entry.second == max_count && !second_mode) {
            mode = entry.first;
            second_mode = true;
        }
    }

    int range = numbers[N - 1] - numbers[0];

    cout << average << endl;
    cout << median << endl;
    cout << mode << endl;
    cout << range << endl;

    return 0;
}

#endif