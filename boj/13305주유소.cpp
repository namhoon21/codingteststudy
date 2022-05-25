#include <iostream>
#include <cmath>
using namespace std;



int main()
{
	freopen("test.txt", "r", stdin);
	int N;
	int doro[100000];
	int price[100000];
	cin >> N;
	for (int i = 0; i < N-1; i++)
		cin >> doro[i];
	for (int i = 0; i < N; i++)
		cin >> price[i];

	int minn = 21e8;
	int sum = 0;
	for (int i = 0; i < N-1; i++)
	{
		if (minn > price[i])
			minn = price[i];
		sum += minn * doro[i];
	}
	cout << sum;


	return 0;
}