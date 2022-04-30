//복잡한 시뮬레이션의 경우 실수주의
//시계반댸방향은 시계방향 3번한것과 같다

#include<iostream>
#include <iomanip>
#include <cstring>
#include <vector>
#include <string>
using namespace std;


vector<vector<char>> upf(3, vector<char>(3,'w'));
vector<vector<char>> downf(3, vector<char>(3, 'y'));
vector<vector<char>> frontf(3, vector<char>(3, 'r'));
vector<vector<char>> backf(3, vector<char>(3, 'o'));
vector<vector<char>> rightf(3, vector<char>(3, 'b'));
vector<vector<char>> leftf(3, vector<char>(3, 'g'));

void cw(vector<vector<char>> &a)
{
	vector<vector<char>> b(3, vector<char>(3));
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			b[i][j] = a[2-j][i];
		}
	}
	a = b;
}

void ccw(vector<vector<char>> &a)
{
	vector<vector<char>> b(3, vector<char>(3));
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			b[i][j] = a[j][2-i];
		}
	}
	a = b;
}

void showcube()
{
	for (int i = 0; i < 3; i++) {
		cout << "     ";
		for (int j = 0; j < 3; j++)
		{
			cout << upf[i][j];
		}
		cout << endl;
	}
	cout << endl;

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
		{
			cout << leftf[i][j];
		}
		cout << "  ";
		for (int j = 0; j < 3; j++)
		{
			cout << frontf[i][j];
		}
		cout << "  ";
		for (int j = 0; j < 3; j++)
		{
			cout << rightf[i][j];
		}
		cout << "  ";
		for (int j = 0; j < 3; j++)
		{
			cout << backf[i][j];
		}
		cout << endl;
	}
	

	
	cout << endl;

	for (int i = 0; i < 3; i++) {
		cout << "     ";
		for (int j = 0; j < 3; j++)
		{
			cout << downf[2-i][2-j];
		}
		cout << endl;
	}
	cout << endl;
}

void cuberotate(char face,char dir)
{
	if (face == 'L')
	{
		if (dir == '+')
		{
			cw(leftf);
			vector<char> temp(3);
			for (int i = 0; i < 3; i++)
			{
				temp[i] = upf[i][0];
				upf[i][0] = backf[2-i][2];
				backf[2-i][2] = downf[2-i][2];
				downf[2-i][2] = frontf[i][0];
				frontf[i][0] = temp[i];
			}
		}
		else if (dir == '-')
		{
			ccw(leftf);
			vector<char> temp(3);
			for (int i = 0; i < 3; i++)
			{
				temp[i] = upf[i][0];
				upf[i][0] = frontf[i][0];
				frontf[i][0] = downf[2 - i][2];
				downf[2 - i][2] = backf[2 - i][2];
				backf[2 - i][2] = temp[i];				
			}
		}
	}
	else if (face == 'R')
	{
		if (dir == '-')
		{
			ccw(rightf);
			vector<char> temp(3);
			for (int i = 0; i < 3; i++)
			{
				temp[i] = upf[i][2];
				upf[i][2] = backf[2 - i][0];
				backf[2-i][0] = downf[2-i][0];
				downf[2-i][0] = frontf[i][2];
				frontf[i][2] = temp[i];
			}
		}
		else if (dir == '+')
		{
			cw(rightf);
			vector<char> temp(3);
			for (int i = 0; i < 3; i++)
			{
				temp[i] = upf[i][2];
				upf[i][2] = frontf[i][2];
				frontf[i][2] = downf[2 - i][0];
				downf[2 - i][0] = backf[2 - i][0];
				backf[2 - i][0] = temp[i];
			}
		}
	}
	else if (face == 'F')
	{
		if (dir == '+')
		{
			cw(frontf);
			vector<char> temp(3);
			for (int i = 0; i < 3; i++)
			{
				temp[i] = upf[2][i];
				upf[2][i] = leftf[2 - i][2];
				leftf[2 - i][2] = downf[2][i];
				downf[2][i] = rightf[i][0];
				rightf[i][0] = temp[i];
			}
		}
		else if (dir == '-')
		{
			ccw(frontf);
			vector<char> temp(3);
			for (int i = 0; i < 3; i++)
			{
				temp[i] = upf[2][i];
				upf[2][i] = rightf[i][0];
				rightf[i][0] = downf[2][i];
				downf[2][i] = leftf[2-i][2];
				leftf[2 - i][2] = temp[i];

			}
		}
	}
	else if (face == 'B')
	{
		if (dir == '-')
		{
			ccw(backf);
			vector<char> temp(3);
			for (int i = 0; i < 3; i++)
			{
				temp[i] = upf[0][i];
				upf[0][i] = leftf[2 - i][0];
				leftf[2 - i][0] = downf[0][i];
				downf[0][i] = rightf[i][2];
				rightf[i][2] = temp[i];
			}
		}
		else if (dir == '+')
		{
			cw(backf);
			vector<char> temp(3);
			for (int i = 0; i < 3; i++)
			{
				temp[i] = upf[0][i];
				upf[0][i] = rightf[i][2];
				rightf[i][2] = downf[0][i];
				downf[0][i] = leftf[2 - i][0];
				leftf[2 - i][0] = temp[i];

			}
		}
	}
	else if (face == 'U')
	{
	if (dir == '-')
	{
		ccw(upf);
		vector<char> temp(3);
		for (int i = 0; i < 3; i++)
		{
			temp[i] =frontf[0][i];
			frontf[0][i] = leftf[0][i];
			leftf[0][i] = backf[0][i];
			backf[0][i] = rightf[0][i];
			rightf[0][i] = temp[i];
		
		}
	}
	else if (dir == '+')
	{
		cw(upf);
		vector<char> temp(3);
		for (int i = 0; i < 3; i++)
		{
			temp[i] = frontf[0][i];
			frontf[0][i] = rightf[0][i];
			rightf[0][i] = backf[0][i];
			backf[0][i] = leftf[0][i];
			leftf[0][i] = temp[i];

		}
	}
	}
	else if (face == 'D')
	{
	if (dir == '+')
	{
		cw(downf);
		vector<char> temp(3);
		for (int i = 0; i < 3; i++)
		{
			temp[i] = frontf[2][i];
			frontf[2][i] = leftf[2][i];
			leftf[2][i] = backf[2][i];
			backf[2][i] = rightf[2][i];
			rightf[2][i] = temp[i];

		}
	}
	else if (dir == '-')
	{
		ccw(downf);
		vector<char> temp(3);
		for (int i = 0; i < 3; i++)
		{
			temp[i] = frontf[2][i];
			frontf[2][i] = rightf[2][i];
			rightf[2][i] = backf[2][i];
			backf[2][i] = leftf[2][i];
			leftf[2][i] = temp[i];

		}
	}
	}
	
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	freopen("input.txt", "r", stdin);
	cin >> T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n;
		cin >> n;
		upf.clear();
		downf.clear();
		frontf.clear();
		backf.clear();
		leftf.clear();
		rightf.clear();
		upf.resize(3, vector<char>(3,'w'));
		downf.resize(3, vector<char>(3,'y'));
		frontf.resize(3, vector<char>(3,'r'));
		backf.resize(3, vector<char>(3,'o'));
		leftf.resize(3, vector<char>(3,'g'));
		rightf.resize(3, vector<char>(3,'b'));
		showcube();
		for (int i = 0; i < n; i++)
		{
			string s;
			cin >> s;
			//cout << s << endl;
			char face = s[0];
			char dir = s[1];
			
			//cout << endl;
			cout << face << ' ' << dir << endl;
			cuberotate(face, dir);
			//cuberotate('L', '+');
			showcube();
			
		}
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
				cout << upf[i][j];
			cout << endl;
		}
		
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}