#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dice[6] = { 1,6,2,3,5,4 };	//ÇÏ´Ã ¶¥ À§ ¿À¸¥ ¾Æ·¡ ¿Þ
vector<vector<int>> map;
int N, M, K;

void flipdice(int dir)
{
	if (dir == 0)
	{
		int temp = dice[1];
		dice[1] = dice[2];
		dice[2] = dice[0];
		dice[0] = dice[4];
		dice[4] = temp;
	}
	else if (dir == 2)
	{
		int temp = dice[1];
		dice[1] = dice[4];
		dice[4] = dice[0];
		dice[0] = dice[2];
		dice[2] = temp;
	}
	else if (dir == 1)
	{
		int temp = dice[1];
		dice[1] = dice[3];
		dice[3] = dice[0];
		dice[0] = dice[5];
		dice[5] = temp;
	}
	else if (dir == 3)
	{
		int temp = dice[1];
		dice[1] = dice[5];
		dice[5] = dice[0];
		dice[0] = dice[3];
		dice[3] = temp;
	}

}

int kanscore(int i, int j)
{
	vector<vector<int>> used(N+2, vector<int>(M+2));
	queue<pair<int, int>> q;
	int n = map[i][j];
	int ans=0;
	q.push({ i,j });
	while (!q.empty())
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		if (y == 5)
			int asd = -1;
		if (used[y][x] == 1) continue;
		if (map[y][x] != n) continue;
		used[y][x] = 1;
		if (map[y][x] == n)
		{
			ans++;
			q.push({ y + 1, x });
			q.push({ y - 1, x });
			q.push({ y, x + 1 });
			q.push({ y, x - 1 });
		}
		

	}
	return ans;
}



int main()
{
	freopen("t.txt", "r", stdin);
	cin >> N >> M >> K;
	map.resize(N+2, vector<int>(M+2,999));
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++)
			cin >> map[i][j];
	pair<int, int> cur = {1,1};
	int dir=1;	//À§:0 ¿À¸¥:1 ¾Æ·¡:2 ¿Þ:3
	int score = 0;
	//cout << ' ' << dice[2] << '\n' << dice[5] << dice[0] << dice[3] << "\n" << ' ' << dice[4] << "\n " << dice[1] << "\n\n";
	for (int i = 0; i < K; i++)
	{
		if (dir == 1)
		{
			if (map[cur.first][cur.second + 1] == 999)
			{
				dir = 3;
				cur.second--;
			}
			else
				cur.second++;
		}
		else if (dir == 2)
		{
			if (map[cur.first+1][cur.second] == 999)
			{
				dir = 0;
				cur.first--;
			}
			else
				cur.first++;
		}
		else if (dir == 3)
		{
			if (map[cur.first][cur.second-1] == 999)
			{
				dir = 1;
				cur.second++;
			}
			else
				cur.second--;
		}
		else if (dir == 0)
		{
			if (map[cur.first-1][cur.second] == 999)
			{
				dir = 2;
				cur.first++;
			}
			else
				cur.first--;
		}
		flipdice(dir);
		score += map[cur.first][cur.second] *kanscore(cur.first, cur.second);
		if (dice[1] > map[cur.first][cur.second])
		{
			dir = (dir + 1) % 4;
		}
		else if (dice[1] < map[cur.first][cur.second])
		{
			dir = (dir + 3) % 4;
		}


		//cout << i << ' ' << score<<endl;
		//cout <<dir<<'\n'<< ' ' << dice[2] << '\n' << dice[5] << dice[0] << dice[3] << "\n" << ' ' << dice[4] << "\n " << dice[1]<<"\n\n";

	}

	cout << score;


	return 0;
}