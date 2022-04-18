#include <iostream>
#include <vector>
using namespace std;

int N;
vector<vector<char>> map;
int dir[4][2] = { 0,1,1,0,0,-1,-1,0 };
bool findstudent(int y, int x)
{
	for (int i = 0; i < 4; i++)
	{
		int ny, nx;
		int cy, cx;
		cy = y;
		cx = x;
		while (1)
		{
			nx = cx + dir[i][1];
			ny = cy + dir[i][0];
			if (nx < 0 || nx >= N) break;
			if (ny < 0 || ny >= N) break;
			if (map[ny][nx] == 'S') return true;
			else if (map[ny][nx] == 'O' || map[ny][nx]=='T') break;
			//else if (map[ny][nx] == 'X') continue;
			cx = nx;
			cy = ny;
		}
		

	}
	return false;
}


bool ishidden()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (map[i][j] == 'T')
			{
				if (findstudent(i, j))
					return false;
			}
		}
	}


	return true;
}


int main()
{
	freopen("t.txt", "r",stdin );
	cin >> N;
	map.resize(N, vector<char>(N));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> map[i][j];

	for (int i = 0; i < (N * N)-2; i++)
	{
		for (int j = i+1; j < (N * N)-1; j++)
		{
			for (int k = j+1; k < N * N; k++)
			{
				vector<vector<char>> temp=map;
				if (map[i / N][i % N] != 'X') continue;
				if (map[j / N][j % N] != 'X') continue;
				if (map[k / N][k % N] != 'X') continue;
				map[i / N][i % N] = 'O';
				map[j / N][j % N] = 'O';
				map[k / N][k % N] = 'O';
				if (ishidden())
				{
					cout << "YES";
					return 0;
				}
				map = temp;
			}
		}
	}
	cout << "NO";
	return 0;
}