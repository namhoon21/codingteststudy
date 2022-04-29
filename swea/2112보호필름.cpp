//bfs로 푸는 방식
//bfs로 풀 경우 로컬에서는 통과되나 
//swea 서버에서는 런타임 에러
//메모리때문인걸로 예상->dfs로 풀었더니 통과

#include<iostream>
#include<vector>
#include <queue>
using namespace std;

int D, W, K;
int film[13][20];


typedef struct _node {
	int n;
	int film[13][20];
	//int applied[13];
	int last;
}node;
queue<node> q;
int accepted(int film[][20])
{
	int flag = 0;
	for (int i = 0; i < W; i++)
	{
		int cnt = 1;
		for (int j = 0; j < D - 1 ; j++)
		{
			if (film[j][i] == film[j + 1][i])
			{
				cnt++;
			}
			else
			{
				cnt = 1;
			}
			if (cnt == K) 
				break;

		}
		//cout << cnt << endl;
		if (cnt < K)
			return 0;
	}
	return 1;
}

int bfs()
{
	
	node asd;
	//for (int i = 0; i < D; i++)
		//asd.applied[i] = 0;
	
	for (int i = 0; i < D; i++)
		for (int j = 0; j < W; j++)
			asd.film[i][j] = film[i][j];

	
	asd.n = 0;
	asd.last = -1;

	q.push(asd);
	
	while (!q.empty())
	{
		node cur = q.front();
		q.pop();
		
		if (accepted(cur.film) == 1)
		{
			while (!q.empty())
				q.pop();
			return cur.n;
		}		
		
		for (int i = cur.last+1; i < D; i++)
		{
			//if (cur.applied[i] == 1) continue;
			node next1;
			node next2;
			next1.n = cur.n + 1;
			next2.n = cur.n + 1;
			next1.last = i;
			next2.last = i;
			for (int i = 0; i < D; i++)
				for (int j = 0; j < W; j++) {
					next1.film[i][j] = cur.film[i][j];
					next2.film[i][j] = cur.film[i][j];
				}
			//for (int j = 0; j < D; j++) {
				//next1.applied[j] = cur.applied[j];
				//next2.applied[j] = cur.applied[j];
			//}
			
			
			int temp[20];
			for(int j=0;j<W;j++)
				temp[i]=cur.film[i][j];
			for (int j = 0; j < W; j++)
			{
				next1.film[i][j] = 0;
				next2.film[i][j] = 1;
			}
				
			//curfilm[i] = vector<int>(W, 0);
			//next1.applied[i] = 1;
			//next2.applied[i] = 1;
			if (accepted(next1.film) == 1)
			{
				while (!q.empty())
					q.pop();
				return cur.n+1;
			}
			if (accepted(next2.film) == 1)
			{
				while (!q.empty())
					q.pop();
				return cur.n+1;
			}
			q.push(next1);
			//curfilm[i] = vector<int>(W, 1);
			
			
			q.push(next2);
			//curfilm[i] = temp;
			/*for (int j = 0; j < W; j++)
				curfilm[i][j] = temp[j];*/
			
			
		}
	}
}


int main(int argc, char** argv)
{
	int test_case;
	int T;
	freopen("Text.txt", "r", stdin);
	cin >> T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		
	
		cin >> D >> W >> K;
		
	
		for (int i = 0; i < D; i++)
			for (int j = 0; j < W; j++)
				cin >> film[i][j];

		if (K == 1)
		{
			cout << "#" << test_case << " " << 0 << endl;
			continue;
		}

		cout << "#"<<test_case<<" "<<bfs() << endl;
		while (!q.empty())
			q.pop();
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}