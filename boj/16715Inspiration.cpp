#include <iostream>
#include <cmath>
using namespace std;

int digitsum(int n, int jin)
{
	int s = 0;
	while (n > 0)
	{
		s += n % jin;
		n /= jin;
	}
	return s;
}

int main()
{
	freopen("test.txt", "r", stdin);
	int N;
	cin >> N;
	int maxx = 0;
	int index = 0;
	//long long i = 2;
	long long initN = N;
	//cout << sqrt(N);
	for (int i = 2; i <= N ; i++)
	{
		//cout << i<<':'<<digitsum(N, i) << endl;
		int ds = digitsum(N, i);
		if (ds > maxx)
		{
			maxx = ds;
			index = i;

		}
	}
	cout << maxx << ' ' << index;



	return 0;
}