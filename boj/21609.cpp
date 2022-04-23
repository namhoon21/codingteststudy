#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N, M;
int e = 10;
vector<vector<int>> map;
int dir[4][2] = {0,1,1,0,0,-1,-1,0};



int erasebig()
{
	vector<vector<int>> checked(N, vector<int>(N));
	vector<vector<int>> toerase;
	int max = 0;
	int maxr = 0;
	int maxy = 0;
	int maxx = 0;
	for (int i=0;i<N;i++)
	{
		for (int j=0;j<N;j++)
		{
			
			/*for (int k = 0; k < N; k++)
			{
				for (int l = 0; l < N; l++)
				{
					cout << checked[k][l] << ' ';
				}
				cout << '\n';
			}
			cout << '\n';*/


			
			vector<vector<int>> c;
			queue<vector<int>> q;
			if (checked[i][j] == 1) continue;
			if (map[i][j] == -1 || map[i][j] == 0 || map[i][j]==e) continue;
			//c.push_back({ i,j });
			q.push({ i,j });
			int n = map[i][j];
			int size = 0;
			int rainbow=0;
		
			vector<vector<int>> checked2(N, vector<int>(N));
			while (!q.empty())
			{
				int y = q.front()[0];
				int x = q.front()[1];
				if (y == 4 && x == 1)
					int de = -1;
				
				q.pop();
				if (y < 0 || y >= N || x < 0 || x >= N) 
					continue;
				if (map[y][x] == -1 || map[y][x]==e) 
					continue;
				if (map[y][x] != n && map[y][x] != 0) 
					continue;
				if (checked2[y][x] == 1)
					continue;
				if (map[y][x] != 0) 
					checked[y][x] = 1;
				if (map[y][x] == 0)
					rainbow++;
				size++;
				checked2[y][x] = 1;
	
				c.push_back({ y,x });
				for (int i = 0; i < 4; i++)
					q.push({ y + dir[i][0],x + dir[i][1] });
				
				
			}
			

	
			if (size > max || (size==max && rainbow>maxr) || (size==max && rainbow==maxr && c[0][0]>maxy)||(size==max && rainbow==maxr && c[0][0]==maxy && c[0][1]>maxx))
			{
				max = size;
				toerase.clear();
				toerase = c;
				maxr = rainbow;
				maxx = c[0][1];
				maxy = c[0][0];
			}
			

		}
	}
	if (max != 1)
	{
		for (int i = 0; i < toerase.size(); i++)
			map[toerase[i][0]][toerase[i][1]] = e;
	}
	

	return max;





}

void showmap()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << map[i][j] << ' ';
	
		}
		cout << '\n';
	}
	cout << '\n';

}

void rotate() {
	vector<vector<int>> r(N,vector<int>(N));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			r[i][j] = map[j][N-1-i];
		}
	}
	map = r;
}

//0,N -> N,N
//0,0->0,N
//N,N->N,0
//N,0->0,0

void gravity() {
	//vector<vector<int>> graved(N,vector<int>(N));
	for (int j = 0; j < N; j++)
	{
		//int i = N-1;
		
		int idx = 0;
		for(int i=N-1;i>=0;i--)
		{
			if (map[i][j] == e || map[i][j] == -1) continue;
			for (int k = i; k < N-1; k++)
			{
				if (map[k + 1][j] == e)
				{
					map[k + 1][j] = map[k][j];
					map[k][j] = e;
				}
				else
					break;

			}
		}
		

	}
	//map = graved;
}

int main()
{
	freopen("t.txt", "r", stdin);
	cin >> N >> M;
	
	map.resize(N, vector<int>(N));
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> map[i][j];
	//showmap();
	//rotate();
	int score = 0;
	while (1)
	{
		int n=erasebig();
		//cout << n << endl;
		if (n == 1 || n==0) break;
		score += n * n;
		gravity();
		rotate();
		gravity();
		//showmap();
	}
	cout << score;
	/*erasebig();
	showmap();

	gravity();
	showmap();*/


	return 0;
}