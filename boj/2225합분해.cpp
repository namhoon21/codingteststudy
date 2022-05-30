#include <iostream>

using namespace std;
int N, K;
int sum = 0;
int cnt = 0;
int arr[201][201];
//long long factorial(int n)
//{
//	if (n == 1) return 1;
//	else return n*factorial(n - 1);
//}
//
//long long H(int n, int k)
//{
//	return (factorial(n + k - 1) / factorial(k)) / factorial(n - 1);
//}


int answer(int N, int K)
{
	if (K == 1) return 1;
	else if (K == 2) return N+1;
	else
	{
		int sum = 0;
		for (int i = 0; i <= N; i++)
		{
			sum += answer(i, K-1);
		}
		return sum;
	}

}

void init()
{
	for (int x = 1; x <= 200; x++)
	{

		for (int y = 0; y <= 200; y++)
		{
			if (x == 1) arr[y][x] = 1;
			else if (y == 0) arr[y][x] = 1;
			else
			{
				int sum = 0;
				for (int k = 0; k <= y; k++)
					sum = (sum+arr[k][x-1])%1000000000;
				arr[y][x] = sum;
			}

		}
	}
}

int main()
{
	freopen("test.txt", "r", stdin);
	
	cin >> N >> K;
	/*cout << H(K, N);
	for (int i = 1; i < 20; i++)
		cout << factorial(i) << endl;*/
	//dfs(0, 0);
	init();
	cout << arr[N][K];


	return 0;
}