///////////////////////////////////////////////////////////////////////////////////////////////
//// 기본 제공코드는 임의 수정해도 관계 없습니다. 단, 입출력 포맷 주의
//// 아래 표준 입출력 예제 필요시 참고하세요.
//// 표준 입력 예제
//// int a;
//// float b, c;
//// double d, e, f;
//// char g;
//// char var[256];
//// long long AB;
//// cin >> a;                            // int 변수 1개 입력받는 예제
//// cin >> b >> c;                       // float 변수 2개 입력받는 예제 
//// cin >> d >> e >> f;                  // double 변수 3개 입력받는 예제
//// cin >> g;                            // char 변수 1개 입력받는 예제
//// cin >> var;                          // 문자열 1개 입력받는 예제
//// cin >> AB;                           // long long 변수 1개 입력받는 예제
///////////////////////////////////////////////////////////////////////////////////////////////
//// 표준 출력 예제
//// int a = 0;                            
//// float b = 1.0, c = 2.0;               
//// double d = 3.0, e = 0.0; f = 1.0;
//// char g = 'b';
//// char var[256] = "ABCDEFG";
//// long long AB = 12345678901234567L;
//// cout << a;                           // int 변수 1개 출력하는 예제
//// cout << b << " " << c;               // float 변수 2개 출력하는 예제
//// cout << d << " " << e << " " << f;   // double 변수 3개 출력하는 예제
//// cout << g;                           // char 변수 1개 출력하는 예제
//// cout << var;                         // 문자열 1개 출력하는 예제
//// cout << AB;                          // long long 변수 1개 출력하는 예제
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
//	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
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
//	return 0;//정상종료시 반드시 0을 리턴해야합니다.
//}