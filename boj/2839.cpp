#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
	//freopen("t.txt", "r", stdin);
	int N;
	cin >> N;
	for (int i = 0; i <= N/3; i++)
	{
		if ((N - 3 * i) % 5 == 0)
		{
			cout << (i + (N - 3 * i) / 5);
			return 0;
		}
	}
	cout << -1;


	return 0;
}