#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;
int N, K;
vector<vector<int>> aqua;

void showaqua()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << setw(6)<<aqua[i][j];
		}
		cout << endl;

	}
	cout << endl;
}

void addleast()
{
	int minn = 21e8;
	vector<int> leastwhich;
	for (int i = 0; i < N; i++)
	{
		if (aqua[N - 1][i] < minn)
		{
			leastwhich.clear();
			leastwhich.push_back(i);
			minn = aqua[N - 1][i];
		}
		else if (aqua[N-1][i] == minn)
		{
			leastwhich.push_back(i);
		}

	}
	for (int i = 0; i < leastwhich.size(); i++)
		aqua[N - 1][leastwhich[i]]++;
}

void ssat()
{
	int idx = 0;
	int eidx = 0;
	while (1)
	{
		if (idx > N - 1 || eidx > N - 1) 
			break;
		vector<vector<int>> temp(N, vector<int>(N));
		int cnt;
		for (int j = idx; j <= eidx; j++) {
			cnt = 0;
			for (int i = N - 1; i >= 0; i--)
			{
				if (aqua[i][idx] == 0) break;
				if (eidx + N - i > N - 1) return;
				temp[N - (eidx - idx)+j-idx-2][eidx + N - i] = aqua[i][j];
				cnt++;
			}
		}
		for (int i = eidx + 1; i < N; i++)
			temp[N - 1][i] = aqua[N - 1][i];
		idx = eidx + 1;
		eidx = idx + cnt-1;
		
		aqua = temp;
		//showaqua();
	}
}

void movefish()
{
	vector<vector<int>> temp(N, vector<int>(N));
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (aqua[i][j] == 0) continue;
			int ny = i + 1;
			int nx = j;
			if (ny < N && nx < N) {
				if (aqua[ny][nx] != 0)
				{
					if (aqua[ny][nx] > aqua[i][j])
					{
						int n = (aqua[ny][nx] - aqua[i][j]) / 5;
						temp[ny][nx] -= n;
						temp[i][j] += n;
					}
					else if (aqua[ny][nx] < aqua[i][j])
					{
						int n = (aqua[i][j] - aqua[ny][nx]) / 5;
						temp[ny][nx] += n;
						temp[i][j] -= n;
					}
				}
			}
			ny = i;
			nx = j+1;
			if (ny < N && nx < N) {
				if (aqua[ny][nx] != 0)
				{
					if (aqua[ny][nx] > aqua[i][j])
					{
						int n = (aqua[ny][nx] - aqua[i][j]) / 5;
						temp[ny][nx] -= n;
						temp[i][j] += n;
					}
					else if (aqua[ny][nx] < aqua[i][j])
					{
						int n = (aqua[i][j] - aqua[ny][nx]) / 5;
						temp[ny][nx] += n;
						temp[i][j] -= n;
					}
				}
			}
		}
	}
	for (int i = 0; i < N;i++)
		for (int j = 0; j < N; j++)
			aqua[i][j] += temp[i][j];
}

void flatten()
{
	vector<vector<int>> temp(N, vector<int>(N));
	int idx = 0;
	for (int j = 0; j < N ; j++)
	{
		for (int i = N - 1; i >= 0; i--)
		{
			if (aqua[i][j] == 0)
				continue;
			temp[N - 1][idx++] = aqua[i][j];

		}
	}
	aqua = temp;
}

void airbon()
{
	vector<vector<int>> temp(N, vector<int>(N));
	for (int i = N / 2; i < N; i++)
	{
		temp[N - 2][i] = aqua[N - 1][N-1-i];
		temp[N - 1][i] = aqua[N - 1][i];
	}
	aqua = temp;
//	showaqua();
	vector<vector<int>> temp2(N, vector<int>(N));
	for (int i = N * 3 / 4; i < N; i++)
	{
		temp2[N - 4][i] = aqua[N - 1][3*N/2 - 1 - i];
		temp2[N - 3][i] = aqua[N - 2][3*N/2-1-i];
		temp2[N - 2][i] = aqua[N - 2][i];
		temp2[N - 1][i] = aqua[N - 1][i];
	}
	aqua = temp2;

}

int numaqua()
{
	int maxx = 0;
	int minn = 100000;
	for (int i = 0; i < N; i++)
	{
		if (aqua[N - 1][i] > maxx) maxx = aqua[N - 1][i];
		if (aqua[N - 1][i] < minn) minn = aqua[N - 1][i];
	}
	return maxx - minn;
}


int main()
{
	freopen("test.txt", "r", stdin);
	cin >> N >> K;
	aqua.resize(N, vector<int>(N));
	for (int i = 0; i < N; i++)
		cin >> aqua[aqua.size()-1][i];
	showaqua();
	int cnt = 0;
	while (1)
	{
		if (numaqua() <= K)
		{
			break;
		}
		cnt++;
		addleast();
		showaqua();
		ssat();
		showaqua();
		movefish();
		showaqua();
		flatten();
		showaqua();
		airbon();
		showaqua();
		movefish();
		showaqua();
		flatten();
		showaqua();
		
		continue;
	}
	cout << cnt;
	

	return 0;
}