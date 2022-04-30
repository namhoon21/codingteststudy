#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> map;
int N, M;
vector<int> curR(2);
vector<int> curB(2);
int dir[4][2] = { 0,1,1,0,0,-1,-1,0 };
int ans = 15;
vector<int> path;

void showmap()
{
	for (int i = 0; i < N; i++)
		cout << map[i] << endl;
	cout << endl;
}

int tilt(int d)
{
	int red=0;
	int blue=0;
	if (d == 0)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = M-2; j >=0; j--)
			{
				if (map[i][j] == 'R' || map[i][j] == 'B')
				{
					for (int k = j; k < M-1; k++)
					{
						if (map[i][k + 1] != '.') {

							if (map[i][k+1] == 'O')
							{
								if (map[i][k] == 'R')
								{
									red = 1;
									map[i][k] = '.';
								}
								else if (map[i][k] == 'B')
								{
									blue = 1;
								}
							}
							break;
							
						}
						map[i][k + 1] = map[i][k];
						map[i][k] = '.';
					}
				}
			}
		}
	}
	if (d == 1)
	{
		for (int i = 0; i < M; i++)
		{
			for (int j = N-2; j >= 0; j--)
			{
				if (map[j][i] == 'R' || map[j][i] == 'B')
				{
					for (int k = j; k < M-1; k++)
					{
						if (map[k + 1][i] != '.') {
							if (map[k + 1][i] == 'O')
							{
								if (map[k][i] == 'R')
								{
									red = 1;
									map[k][i] = '.';
								}
								else if (map[k][i] == 'B')
								{
									blue = 1;
								}
							}
							break;
						}
						map[k+1][i] = map[k][i];
						map[k][i] = '.';
					}
				}
			}
		}
	}
	if (d == 2)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 1; j <M; j++)
			{
				if (map[i][j] == 'R' || map[i][j] == 'B')
				{
					for (int k = j; k >0; k--)
					{
						if (map[i][k - 1] != '.') {
							if (map[i][k - 1] == 'O')
							{
								if (map[i][k] == 'R')
								{
									red = 1;
									map[i][k] = '.';
								}
								else if (map[i][k] == 'B')
								{
									blue = 1;
								}
							}
							break;

						}
						map[i][k - 1] = map[i][k];
						map[i][k] = '.';
					}
				}
			}
		}
	}
	if (d == 3)
	{
		for (int i = 0; i < M; i++)
		{
			for (int j = 1; j <N; j++)
			{
				if (map[j][i] == 'R' || map[j][i] == 'B')
				{
					for (int k = j; k >0; k--)
					{
						if (map[k - 1][i] != '.') {
							if (map[k + 1][i] == 'O')
							{
								if (map[k][i] == 'R')
								{
									red = 1;
									map[k][i] = '.';
								}
								else if (map[k][i] == 'B')
								{
									blue = 1;
								}
							}
							break;
						}
						map[k - 1][i] = map[k][i];
						map[k][i] = '.';
					}
				}
			}
		}
	}
	if (blue) return -1;
	else if(red) return 1;
	else return 0;
}

void gogo(int level)
{
	//for (int i = 0; i < path.size(); i++)
		//cout << path[i] << ' ';
	//cout << endl;
	//showmap();

	if (level == 10) {
		return;
	}
	if (level > ans)
		return;

	for (int i = 0; i < 4; i++)
	{
		vector<string> temp = map;
		vector<int> tempR = curR;
		vector<int> tempB = curB;
		int n = tilt(i);

		if (n == 0) {
			if (map == temp)
			{
				curR = tempR;
				curB = tempB;
				continue;
			}
			path.push_back(i);
			gogo(level + 1);
			path.pop_back();
			curR = tempR;
			curB = tempB;
			map = temp;
		}
		else if (n == -1) {
			map = temp;
			curR = tempR;
			curB = tempB;
			continue;
		}
		else if (n == 1) {
			if (level + 1 < ans) ans = level + 1;
			map = temp;
			curR = tempR;
			curB = tempB;
			continue;
		}

	}
}


int main()
{
	freopen("test.txt", "r", stdin);
	cin >> N >> M;
	map.resize(N);
	for (int i = 0; i < N; i++)
		cin >> map[i];
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (map[i][j] == 'R')
			{
				curR = { i,j };
			}
			if (map[i][j] == 'B')
			{
				curB = { i,j };
			}
		}
	}


	/*for (int i = 0; i < N; i++)
		cout << map[i] << endl;
	cout << endl;*/

	/*int n= tilt(1);
	for (int i = 0; i < N; i++)
		cout << map[i] << endl;
	cout << endl << n<<endl;*/
	gogo(0);
	if (ans == 15) ans = -1;
	cout << ans;
	//int n=tilt(3);
	//cout << n << endl;
	

	return 0;
}