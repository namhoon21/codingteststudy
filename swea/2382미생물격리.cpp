//swea �������� ������쿡�� showmap �Լ� ����
//������� �� cout ���� �����ϴ°� ����

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
//				cout << "��";
//			else if (map[i][j].dir == 2)
//				cout << "��";
//			else if (map[i][j].dir == 3)
//				cout << "��";
//			else if (map[i][j].dir == 4)
//				cout << "��";
//			else if (map[i][j].dir == 0)
//				cout << "��";
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
	   �Ʒ��� freopen �Լ��� input.txt �� read only �������� �� ��,
	   ������ ǥ�� �Է�(Ű����) ��� input.txt ���Ϸκ��� �о���ڴٴ� �ǹ��� �ڵ��Դϴ�.
	   //�������� �ۼ��� �ڵ带 �׽�Ʈ �� ��, ���Ǹ� ���ؼ� input.txt�� �Է��� ������ ��,
	   freopen �Լ��� �̿��ϸ� ���� cin �� ������ �� ǥ�� �Է� ��� ���Ϸκ��� �Է��� �޾ƿ� �� �ֽ��ϴ�.
	   ���� �׽�Ʈ�� ������ ������ �Ʒ� �ּ��� ����� �� �Լ��� ����ϼŵ� �����ϴ�.
	   freopen �Լ��� ����ϱ� ���ؼ��� #include <cstdio>, Ȥ�� #include <stdio.h> �� �ʿ��մϴ�.
	   ��, ä���� ���� �ڵ带 �����Ͻ� ������ �ݵ�� freopen �Լ��� ����ų� �ּ� ó�� �ϼž� �մϴ�.
	*/
	freopen("input.txt", "r", stdin);
	cin >> T;
	/*
	   ���� ���� �׽�Ʈ ���̽��� �־����Ƿ�, ������ ó���մϴ�.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{

		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
			 �� �κп� �������� �˰��� ������ ���ϴ�.
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
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}