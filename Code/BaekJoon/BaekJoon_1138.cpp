#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	vector<int> vecHeight;
	int iCount{};

	cin >> iCount;
	vecHeight.resize(iCount);

	for (int i = 0; i < iCount; i++)
	{
		int iEmpty{};
		int iBigger{};

		cin >> iBigger;

		for (int j = 0; j < iCount; j++)
		{
			if (vecHeight[j] == 0)
			{
				if (iEmpty == iBigger)
				{
					vecHeight[j] = i + 1;
					break;
				}
				else iEmpty++;
			}
		}
	}

	for (int iHeight : vecHeight)
		cout << iHeight << " ";

	return 0;
}

// vector 컨테이너를 여러개 써서 해결한 풀이
// vector를 하나만 쓰는 풀이보다 쓸 데 없이 더 복잡해진 것 같다

#ifdef _RELEASE

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> result(N);
    vector<bool> used(N, false);
    vector<int> tallerCount(N);

    for (int i = 0; i < N; i++) {
        cin >> tallerCount[i];
    }

    for (int i = 0; i < N; i++) {
        int tallerRequired = tallerCount[i];
        int count = 0;

        for (int j = 0; j < N; j++) {
            if (!used[j]) {
                if (count == tallerRequired) {
                    result[j] = i + 1;
                    used[j] = true;
                    break;
                }
                count++;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}

#endif