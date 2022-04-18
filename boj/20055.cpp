#include <iostream>
#include <vector>
#include <list>
using namespace std;
int N, K;


typedef struct _belt {
	int rob;
	int place;
	int dur;
	//struct _belt* next;
} belt;

vector<belt> b;

int main()
{
	freopen("t.txt", "r", stdin);
	
	cin >> N >> K;
	b.resize(2 * N);
	for (int i = 0; i < 2 * N; i++)
	{
		cin >> b[i].dur;
		b[i].place = i;
		b[i].rob = 0;
		
	}
	int step = 1;
	int upidx=2*N-1;
	int downidx=N-2;
	while (1)
	{
		
		for (int i = 0; i < 2 * N; i++)
		{
			b[i].place = (b[i].place + 1) % (2 * N);	//회전

			

		}
		if (b[downidx].rob == 1) 
			b[downidx].rob = 0; 
	
		int curidx = downidx-1;
		if (curidx == -1) curidx = 2 * N - 1;
		int leftidx;
		int rightidx;

		while(1)	//로봇이동
		{
			if (curidx == 0)
				leftidx = 2 * N - 1;
			else
				leftidx = curidx - 1;
			rightidx = (curidx + 1) % (2 * N);
			if (curidx==upidx) break;
			if (b[curidx].rob == 1 && b[rightidx].rob == 0 && b[rightidx].dur != 0)
			{
				b[curidx].rob = 0;
				b[rightidx].rob = 1;
				b[rightidx].dur--;
				if (rightidx == downidx)
				{
					b[rightidx].rob = 0;
					//break;
				}
				
				
			}
			curidx = leftidx;
			
		}
		if (b[upidx].rob == 0 && b[upidx].dur != 0)	//올리는위치에 로봇올리기
		{
			b[upidx].rob = 1;
			b[upidx].dur--;
		}
		int count = 0;

		for (int i = 0; i < 2 * N; i++)
		{
			if (b[i].dur == 0) count++;
		}
		//cout << count << endl;
		if (count >= K) 
			break;
		step++;
		if (upidx == 0) upidx = 2 * N - 1;
		else upidx = (upidx - 1);

		if (downidx == 0) downidx = 2 * N - 1;
		else downidx = (downidx - 1);
		//downidx = (downidx - 1) % (2 * N);
	}

	cout << step;


	return 0;
}