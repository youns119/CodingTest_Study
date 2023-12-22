#include <iostream>
#include <vector>

using namespace std;

void Input(vector<int>& A, vector<int>& B);
int Sol(vector<int>& A, vector<int>& B, int T);

int main()
{
	int T, result;
	vector<int> A;
	vector<int> B;

	cin >> T;
	Input(A, B);

	result = Sol(A, B, T);
	cout << result;

	return 0;
}

void Input(vector<int>& A, vector<int>& B)
{
	int n, m;

	cin >> n;
	A.assign(n, 0);
	for (int i = 0; i < n; i++)
		cin >> A[i];

	cin >> m;
	B.assign(m, 0);
	for (int i = 0; i < m; i++)
		cin >> B[i];
}

int Sol(vector<int>& A, vector<int>& B, int T)
{
	int result = 0;



	return result;
}