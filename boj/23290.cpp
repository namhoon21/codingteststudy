#include <iostream>
#include <vector>

using namespace std;

typedef struct _node {
	int y;
	int x;
	int dir;
}node;
int M, S, d;
int maxx;
vector<vector<vector<int>>> map;
vector<vector<int>> smell1;
vector<vector<int>> smell2;
vector<vector<int>> smell3;
vector<node> temp;
int dir[9][2] = { 0,0,0,-1,-1,-1,-1,0,-1,1,0,1,1,1,1,0,1,-1 };
int sdir[4][2] = { -1,0,0,-1,1,0,0,1 };	//문제조건 신경쓰기
int sy, sx;
vector<pair<int, int>> path;
vector<pair<int, int>> spath;


void showmap()
{
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			//if (map[i][j].size() == 0) cout << 0;
			for (int k = 0; k < 10; k++)
			{
				if (k < map[i][j].size()) {
					if (map[i][j][k] == 1)
						cout << "←" << ' ';
					else if (map[i][j][k] == 2)
						cout << "↖" << ' ';
					else if (map[i][j][k] == 3)
						cout << "↑" << ' ';
					else if (map[i][j][k] == 4)
						cout << "↗" << ' ';
					else if (map[i][j][k] == 5)
						cout << "→" << ' ';
					else if (map[i][j][k] == 6)
						cout << "↘" << ' ';
					else if (map[i][j][k] == 7)
						cout << "↓" << ' ';
					else if (map[i][j][k] == 8)
						cout << "↙" << ' ';
				}
				else
					cout << "   ";
				//cout << dirsym[2*map[i][j][k]] << ' ';
			}
				
			cout << "|";
		}
		cout << "\n----------------------------------------------------------------------------------------------------------------------------\n";
		//cout << '\n';
	}
	cout << "\n\n\n\n";
}

void showsmell()
{
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			
			if (smell1[i][j] == 1) cout << 2;
			else if (smell2[i][j] == 1) cout << 1;
			else cout << 0;
			

			cout << " ";
		}
		cout << '\n';
	}
	cout << '\n';
}

void bokfirst()
{
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			for (int k = 0; k < map[i][j].size(); k++)
			{
				temp.push_back({ i,j,map[i][j][k] });
			}
		}
	}
}

void movefish()
{
	vector<vector<vector<int>>> newmap(6, vector<vector<int>>(6));
	for (int i = 1; i <= 4; i++)
	{
		for (int j = 1; j <= 4; j++)
		{
			for (int k = 0; k < map[i][j].size(); k++)
			{
				int ismove = 0;
				int ny, nx;
				for(int l=0;l<8;l++)
				{
					
					ny = i + dir[map[i][j][k]][0];
					nx = j + dir[map[i][j][k]][1];
					if (ny >= 1 && ny <= 4 && nx >= 1 && nx <= 4 && smell1[ny][nx]==0 && smell2[ny][nx]==0 &&  (ny!=sy || nx!=sx))
					{
						ismove = 1;
						break;
					}
					map[i][j][k] = (map[i][j][k] + 6) % 8 +1;	//0으로 안되게 조심 
				}
				if (ismove == 0) {
					newmap[i][j].push_back(map[i][j][k]);
					continue;
				}

				newmap[ny][nx].push_back(map[i][j][k]);

			}
		}
	}
	map = newmap;
}

void sharkmove(int step, int fish)
{
	if (step == 3)
	{
		/*int removedfish = 0;
		for (int i = 0; i < 3; i++)
			removedfish += map[path[i].first][path[i].second].size();*/
		if (fish > maxx)
		{
			spath = path;
			maxx = fish;
		}
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		sy = sy + sdir[i][0];
		sx = sx + sdir[i][1];
		
		if (sy < 1 || sy > 4 || sx < 1 || sx > 4)
		{
			sy = sy - sdir[i][0];	//원위치하기 continue하더라도
			sx = sx - sdir[i][1];
			continue;
		}
		vector<vector<vector<int>>> temp = map;
		path.push_back({ sy,sx });
		int curfish = map[sy][sx].size();
		map[sy][sx].clear();
		sharkmove(step + 1, fish+curfish);
		map = temp;
		path.pop_back();
		sy = sy - sdir[i][0];
		sx = sx - sdir[i][1];
	}
}
void boksecond()
{
	for (int i = 0; i < temp.size(); i++)
		map[temp[i].y][temp[i].x].push_back(temp[i].dir);
}
int main()
{
	freopen("Text.txt", "r", stdin);
	//cout << dirsym;
	cin >> M >> S;
	map.clear();
	temp.clear();
	map.resize(6, vector<vector<int>>(6));
	smell1.resize(6, vector<int>(6));
	smell2.resize(6, vector<int>(6));
	smell3.resize(6, vector<int>(6));
	for (int i = 0; i < M; i++)
	{
		int fx, fy,dir;
		cin >> fy >> fx>>dir;
		map[fy][fx].push_back(dir);

	}
	
	cin >> sy >> sx;
	//showmap();
	for (int i = 0; i < S; i++)
	{
		// <<"step: "<<i<< "\nsy: " << sy << " sx: " << sx << endl;
		if (i == 3)
			int de = -1;
		spath.clear();
		path.clear();
		temp.clear();
		bokfirst();
		//cout << "초기:\n";
		//showmap();
		//cout << "냄새맵:\n";
		//showsmell();
	
		
		movefish();
		
		//cout << "이동후:\n";
		//showmap();
		maxx = -1;	//경로 물고기 최댓값 0일수도 있음
		sharkmove(0,0);
		//cout << "sharkpath: " << spath[0].first << spath[0].second << " " << spath[1].first << spath[1].second << " " << spath[2].first << spath[2].second << endl;
		smell3 = smell2;
		smell2 = smell1;
		smell1.clear();
		smell1.resize(6, vector<int>(6));
		for (int j = 0; j < 3; j++)
		{
			if (map[spath[j].first][spath[j].second].size() == 0) continue;
			map[spath[j].first][spath[j].second].clear();
			smell1[spath[j].first][spath[j].second] = 1;
		}
		sy = spath[2].first;
		sx = spath[2].second;
		//cout << "잡아먹고:\n";
		//showmap();

		boksecond();
		//cout << "복제후:\n";
		//showmap();
		//int fishcount = 0;
		//for (int k = 1; k <= 4; k++)
		//	for (int j = 1; j <= 4; j++)
		//		fishcount += map[k][j].size();
		//cout << "fishcount: "<<fishcount<<endl<<endl;
	
	}
	int fishcount = 0;
	for (int k = 1; k <= 4; k++)
		for (int j = 1; j <= 4; j++)
			fishcount += map[k][j].size();
	cout << fishcount;
	



	return 0;
}