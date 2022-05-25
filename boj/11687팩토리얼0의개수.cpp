#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

int aaa(int n)
{
	int cnt = 0;
	while (n % 5 == 0)
	{
		n = n / 5;
		cnt++;
	}
	return cnt;
}

int main()
{
	freopen("test.txt", "r", stdin);
	int M;

	cin >> M;
	int n=1;
	int m = 1;
	while (1)
	{
		
		if (m > M)
		{
			cout << -1;
			break;
		}
		if (m == M)
		{
			cout << n * 5;
			break;
		}
		n++;
		m += aaa(n) + 1;
	}


	return 0;
}