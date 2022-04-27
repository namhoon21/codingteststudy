#include <iostream>
#include <vector>
using namespace std;
int arr[16];
int N;
vector<vector<int>> map;
int cnt;
int path[16];

bool isattack(pair<int,int> a, pair<int, int> b)
{
	if (a.first == b.first) return true;
	if (a.second == b.second) return true;
	if ((a.first - b.first) == (a.second - b.second)) return true;
	if ((a.first - b.first + a.second - b.second )== 0) return true;
	return false;
}




void dfs(int level)
{
	if (level == N)
	{
		cnt++;
		return;
	}

	for (int i = 0; i < N; i++)
	{
		int togo = 1;
		for (int j = 0; j < level; j++)
		{
			if (isattack({ j,path[j] }, { level,i }))
			{
				togo = 0;
				break;
			}
			
		}
		if (togo == 1)
		{
			path[level] = i;
			dfs(level + 1);
		}
		
	}
}

int main()
{
	freopen("Text.txt", "r", stdin);
	
	cin >> N;
	map.resize(N, vector<int>(N));

	
	dfs(0);
	cout << cnt;
	




	return 0;
}