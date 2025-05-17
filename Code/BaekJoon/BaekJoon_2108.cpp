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