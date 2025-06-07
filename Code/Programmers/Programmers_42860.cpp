#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int AlphaDist(char chDst);
int solution(string name);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	string strName{};

	cin >> strName;
	cout << solution(strName);

	return 0;
}

int AlphaDist(char chDst)
{
	return min(chDst - 'A', 'Z' - chDst + 1);
}

int ReIndex(int iIndex, int iLen)
{
	iIndex = iIndex >= 0 ? (iIndex) % iLen : iLen + iIndex;

	return iIndex;
}

int solution(string name) 
{
	int answer = 0;

	for (int i = 0; i < name.length(); i++)
		answer += AlphaDist(name[i]);

	int len = name.length();
	int move = len - 1;
	for (int i = 0; i < len; i++) {
		int next = i + 1;
		// 다음 변경할 필요 있는 위치 찾기
		while (next < len && name[next] == 'A')
			++next;
		// i까지 가고 -> 뒤로 돌아가고 -> next로 가는 방식 중 최소
		move = min(move, i + len - next + min(i, len - next));
	}

	return answer;
}