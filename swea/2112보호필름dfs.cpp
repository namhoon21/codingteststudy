///////////////////////////////////////////////////////////////////////////////////////////////
//// �⺻ �����ڵ�� ���� �����ص� ���� �����ϴ�. ��, ����� ���� ����
//// �Ʒ� ǥ�� ����� ���� �ʿ�� �����ϼ���.
//// ǥ�� �Է� ����
//// int a;
//// float b, c;
//// double d, e, f;
//// char g;
//// char var[256];
//// long long AB;
//// cin >> a;                            // int ���� 1�� �Է¹޴� ����
//// cin >> b >> c;                       // float ���� 2�� �Է¹޴� ���� 
//// cin >> d >> e >> f;                  // double ���� 3�� �Է¹޴� ����
//// cin >> g;                            // char ���� 1�� �Է¹޴� ����
//// cin >> var;                          // ���ڿ� 1�� �Է¹޴� ����
//// cin >> AB;                           // long long ���� 1�� �Է¹޴� ����
///////////////////////////////////////////////////////////////////////////////////////////////
//// ǥ�� ��� ����
//// int a = 0;                            
//// float b = 1.0, c = 2.0;               
//// double d = 3.0, e = 0.0; f = 1.0;
//// char g = 'b';
//// char var[256] = "ABCDEFG";
//// long long AB = 12345678901234567L;
//// cout << a;                           // int ���� 1�� ����ϴ� ����
//// cout << b << " " << c;               // float ���� 2�� ����ϴ� ����
//// cout << d << " " << e << " " << f;   // double ���� 3�� ����ϴ� ����
//// cout << g;                           // char ���� 1�� ����ϴ� ����
//// cout << var;                         // ���ڿ� 1�� ����ϴ� ����
//// cout << AB;                          // long long ���� 1�� ����ϴ� ����
///////////////////////////////////////////////////////////////////////////////////////////////
//
//#include<iostream>
//#include<vector>
//#include <queue>
//#include <cstring>
//using namespace std;
//
//int D, W, K;
//int film[13][20];
//int path[13];
//int arr0[20] = { 0, };
//int arr1[20] = { 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 };
//int minn;
//
//typedef struct _node {
//	int n;
//	int film[13][20];
//	//int applied[13];
//	int last;
//}node;
//queue<node> q;
//int accepted(int film[][20])
//{
//	int flag = 0;
//	for (int i = 0; i < W; i++)
//	{
//		int cnt = 1;
//		for (int j = 0; j < D - 1; j++)
//		{
//			if (film[j][i] == film[j + 1][i])
//			{
//				cnt++;
//			}
//			else
//			{
//				cnt = 1;
//			}
//			if (cnt == K)
//				break;
//
//		}
//		//cout << cnt << endl;
//		if (cnt < K)
//			return 0;
//	}
//	return 1;
//}
//
//void dfs(int row, int yak)
//{
//	if (yak > minn)
//		return;
//	if (row == D)
//	{
//		int temp[13][20];
//		memcpy(temp, film, 4*13 * 20);
//		for (int i = 0; i < D; i++)
//		{
//			if (path[i] == 1)
//			{
//				memcpy(film[i], arr0, 4*20);
//			}
//			else if (path[i] == 2)
//				memcpy(film[i], arr1, 4*20);
//
//		}
//		if (accepted(film))
//		{
//			if (yak < minn)
//				minn = yak;
//		}
//		memcpy(film, temp, 4*13 * 20);
//		return;
//	}
//	
//
//	for (int i = 0; i < 3; i++)
//	{
//		path[row] = i;
//		dfs(row + 1, i == 0 ? yak : yak + 1);
//	}
//}
//
//
//int main(int argc, char** argv)
//{
//	int test_case;
//	int T;
//	freopen("Text.txt", "r", stdin);
//	cin >> T;
//	/*
//	   ���� ���� �׽�Ʈ ���̽��� �־����Ƿ�, ������ ó���մϴ�.
//	*/
//	for (test_case = 1; test_case <= T; ++test_case)
//	{
//		minn = 21e8;
//
//		cin >> D >> W >> K;
//
//
//		for (int i = 0; i < D; i++)
//			for (int j = 0; j < W; j++)
//				cin >> film[i][j];
//
//		if (K == 1)
//		{
//			cout << "#" << test_case << " " << 0 << endl;
//			continue;
//		}
//		dfs(0,0);
//		cout << "#" << test_case << " " << minn << endl;
//		while (!q.empty())
//			q.pop();
//	}
//	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
//}