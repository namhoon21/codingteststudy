#include <iostream>
#include <vector>
using namespace std;

int A[51][51];
//int cloudwhici[4][2];
vector<pair<int,int>> cloudwhici;
int d[100];
int s[100];
int N, M;
int dir[9][2] = { 0,0,0,-1,-1,-1,-1,0,-1,1,0,1,1,1,1,0,1,-1 };

void cloudmove(int di, int si)
{
	
	
	for (int i = 0; i < cloudwhici.size(); i++)
	{
		for (int j = 0; j < si; j++)
		{
			cloudwhici[i].first = (cloudwhici[i].first + dir[di][0]+N-1) % N + 1;
			cloudwhici[i].second = (cloudwhici[i].second + dir[di][1] + N-1) % N + 1;
		}
	}

}

void rain()
{
	for (int i = 0; i < cloudwhici.size(); i++)
	{
		A[cloudwhici[i].first][cloudwhici[i].second]++;
	}
}

void mulbok()
{
	for (int i = 0; i < cloudwhici.size(); i++)
	{
		for (int j = 2; j <= 8; j += 2)
		{
			int ny = cloudwhici[i].first + dir[j][0];
			int nx = cloudwhici[i].second + dir[j][1];
			if (ny<1 || ny>N || nx<1 || nx>N || A[ny][nx]==0)
				continue;
			A[cloudwhici[i].first][cloudwhici[i].second]+=1;
		}
	}
}

void createcloud()
{
	int cloudcheck[51][51] = { 0, };
	for (int i = 0; i < cloudwhici.size(); i++)
		cloudcheck[cloudwhici[i].first][cloudwhici[i].second] = 1;
	cloudwhici.clear();
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (A[i][j] >= 2 && cloudcheck[i][j]!=1)
			{
				cloudwhici.push_back({ i,j });
				A[i][j] -= 2;
			}
		}
	}
}


int main() {
	freopen("Text.txt", "r", stdin);
	//memcpy(cloudwhici, cloudwhiciinit, sizeof(int) * 4 * 2);
	

	cin >> N >> M;
	
	for (int i = 1; i < N+1; i++)
		for (int j = 1; j < N+1; j++)
			cin >> A[i][j];

	for (int i = 0; i < M; i++)
		cin >> d[i] >> s[i];



	cloudwhici.push_back({ N,1 });
	cloudwhici.push_back({ N,2 });
	cloudwhici.push_back({ N - 1,1 });
	cloudwhici.push_back({ N - 1,2 });

	for (int i = 0; i < M; i++)
	{
		cloudmove(d[i], s[i]);
		rain();
		mulbok();
		createcloud();

	}
	int cnt = 0;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cnt += A[i][j];
	cout << cnt;

	return 0;
}