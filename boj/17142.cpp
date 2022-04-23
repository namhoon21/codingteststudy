#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N, M;
vector<vector<int>> map;
vector<pair<int, int>> virus;
vector<pair<int, int>> avirus;
int dir[4][2] = {0,1,1,0,0,-1,-1,0};
int used[20];
int minn = 21e8;
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
bool isvirused()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (map[i][j] == 0)
				return false;
	return true;
}

int vtime()
{
	int time=0;
	vector<vector<int>> temp=map;
	vector<vector<int>> checked(N, vector<int>(N));
	queue<vector<int>> q;
	for (int i = 0; i < avirus.size(); i++)
	{
		q.push({ avirus[i].first, avirus[i].second, 0 });
		map[avirus[i].first][avirus[i].second] = 3;
	}
	//cout << 0 << endl;
	//showmap();
	while (!q.empty())
	{
		
		int y = q.front()[0];
		int x = q.front()[1];
		int t = q.front()[2];
		if (t != time)
		{
			if (isvirused()) break;
		}
		q.pop();
		if (y >= N || y < 0 || x >= N || x < 0) continue;
		if (map[y][x] == 1) continue;	//벽
		if (checked[y][x] == 1) continue;	//이미지난곳
		map[y][x] = 3;
		checked[y][x] = 1;
		time = t;
		for (int i = 0; i < 4; i++)
		{
			int ny = y + dir[i][0];
			int nx = x + dir[i][1];
			if (ny >= N || ny < 0 || nx >= N || nx < 0) continue;
			if (map[ny][nx] == 1) continue;	//벽
			if (checked[ny][nx] == 1) continue;	//이미지난곳
			//넣기 전에 검사하지 않으면 시간초과
			q.push({ y + dir[i][0], x + dir[i][1], t + 1 });
		}
			
		//cout << t << endl;
		//showmap();
		
		
	}
	//map = temp; map 다시 되롤리는 타이밍 조심
	if (!isvirused())
	{
		map = temp;
		return -1;
	}
	map = temp;
	
	return time;
}

void dfs(int level, int c)
{
	if (level == M)
	{
		/*for (int i = 0; i < avirus.size(); i++)
		{
			cout << avirus[i].first << ' ' << avirus[i].second << "   ";
		}
		cout << endl;*/
		
		int ttime = vtime();
		//cout << ttime << endl;
		//showmap();
	
		if (ttime < minn && ttime!=-1) minn=ttime;	//최소값 구할때 -1인경우 조심
		return;
	}

	for (int i = c; i < virus.size(); i++)
	{
		if (used[i] == 1) continue;
		//used[i] = 1;
		avirus.push_back(virus[i]);
		dfs(level + 1,i+1);
		avirus.pop_back();
		

	}
}



int main()
{
	freopen("t.txt", "r", stdin);
	cin >> N >> M;
	map.resize(N, vector<int>(N));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 2)
			{
				virus.push_back({ i,j });
			}
		}
	}

	//avirus.push_back(virus[0]);
	//avirus.push_back(virus[4]);
	//avirus.push_back(virus[6]);
	//avirus.push_back(virus[3]);
	dfs(0,0);
	if (minn == 21e8)
		cout << -1;
	else
		cout << minn;
	//cout << vtime();
	
	return 0;
}