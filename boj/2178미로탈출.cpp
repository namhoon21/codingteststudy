#include <iostream>
#include <cmath>
#include <queue>
using namespace std;

int N, M;
char map[100][101];
int visited[100][100];
int dir[4][2] = { 0,1,1,0,0,-1,-1,0 };
typedef struct _node {
	int y;
	int x;
	int count;
} node;

int main()
{
	freopen("test.txt", "r", stdin);
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> map[i];
	queue<node> q;
	q.push({ 0,0,1 });
	visited[0][0] = 1;
	while (!q.empty())
	{
		int cury = q.front().y;
		int curx = q.front().x;
		int c = q.front().count;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = cury + dir[i][0];
			int nx = curx + dir[i][1];
			if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
			if (map[ny][nx] == '0') continue;
			if (visited[ny][nx] == 1) continue;
			if ((ny == N - 1) && (nx == M - 1))
			{
				cout << c+1;
				return 0;
			}
			q.push({ ny,nx,c + 1 });
			visited[ny][nx] = 1;
		}

	}
	cout << -1;
	return 0;
}