//swea 서버에서 돌릴경우에는 showmap 함수 삭제
//디버깅할 때 cout 형식 지정하는거 보기

#include<iostream>
#include <iomanip>
#include <cstring>
using namespace std;

struct node {
	int dir;
	unsigned int num;
	int th;
};

int N, M, K;
node map[101][101];
int dir[5][2] = { 0,0,-1,0,1,0,0,-1,0,1 };

//void showmap()
//{
//	for (int i = 0; i < N ; i++)
//	{
//		for (int j = 0; j < N ; j++)
//		{
//			cout << setw(5)<<map[i][j].num << " ";
//			if (map[i][j].dir == 1)
//				cout << "↑";
//			else if (map[i][j].dir == 2)
//				cout << "↓";
//			else if (map[i][j].dir == 3)
//				cout << "←";
//			else if (map[i][j].dir == 4)
//				cout << "→";
//			else if (map[i][j].dir == 0)
//				cout << "▼";
//			cout << " ";
//		}
//		cout << '\n';
//
//	}
//	cout << '\n';
//}


int main(int argc, char** argv)
{
	int test_case;
	int T;
	/*
	   아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
	   앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
	   //여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
	   freopen 함수를 이용하면 이후 cin 을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
	   따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
	   freopen 함수를 사용하기 위해서는 #include <cstdio>, 혹은 #include <stdio.h> 가 필요합니다.
	   단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
	*/
	freopen("input.txt", "r", stdin);
	cin >> T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{

		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
			 이 부분에 여러분의 알고리즘 구현이 들어갑니다.
		 */
		 /////////////////////////////////////////////////////////////////////////////////////////////
		cin >> N >> M >> K;
	
		memset(map, 0, sizeof(node) * 101 * 101);
		for (int i = 0; i < K; i++)
		{
			int y, x;
			cin >> y >> x;
			cin >> map[y][x].num >> map[y][x].dir;
			map[y][x].th = map[y][x].num;
		}

		//showmap();
		for (int t = 0; t < M; t++)
		{
			node temp[101][101];
			memset(temp, 0, sizeof(node) * 101 * 101);
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j < N; j++)
				{
					if (map[i][j].num > 0)
					{
						int ny = i + dir[map[i][j].dir][0];
						int nx = j + dir[map[i][j].dir][1];
						if (ny == 0 || ny == N - 1 || nx == 0 || nx==N - 1)
						{							
							temp[ny][nx].num = map[i][j].num / 2;
							if (temp[ny][nx].num == 0)
							{
								temp[ny][nx].dir = 0;
								temp[ny][nx].th = 0;
							}								
							else
							{
								temp[ny][nx].dir = (map[i][j].dir % 2 == 1) ? map[i][j].dir + 1 : map[i][j].dir - 1;
								temp[ny][nx].th = temp[ny][nx].num;
							}
								
						}
						else if (temp[ny][nx].num == 0)
						{
							temp[ny][nx].num += map[i][j].num;
							temp[ny][nx].dir = map[i][j].dir;
							temp[ny][nx].th = map[i][j].num;
						}
						else
						{
							temp[ny][nx].num += map[i][j].num;
							if (temp[ny][nx].th < map[i][j].num)
							{
								temp[ny][nx].dir = map[i][j].dir;
								temp[ny][nx].th = map[i][j].num;
							}
						}
						
					}
				}
			}
			memcpy(map, temp, sizeof(node) * 101 * 101);
			for (int i = 0; i < N ; i++)
				for (int j = 0; j < N; j++)
				{
					map[i][j].th = map[i][j].num;
					if (map[i][j].num > 0 && map[i][j].dir == 0)
						int de = -1;
					if (map[i][j].num == 0 && map[i][j].dir > 0)
						int de = -1;
				}
					
			//showmap();
		}
		int cnt = 0;
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				cnt += map[i][j].num;
			}
		}
		cout << '#'<<test_case<<' '<<cnt << '\n';
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}