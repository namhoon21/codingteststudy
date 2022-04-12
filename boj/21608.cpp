#include <iostream>
#include <queue>
#include <vector>

using namespace std;

vector<vector<int>> map;
int dir[4][2] = { 1,0,0,1,-1,0,0,-1 };
int jopoint(int num, vector<int> arr, int r, int c)
{
    int ans = 0;
    for (int i = 0; i < 4; i++)
    {
        if (map[r + dir[i][0]][c + dir[i][1]] == arr[0] || map[r + dir[i][0]][c + dir[i][1]] == arr[1] || map[r + dir[i][0]][c + dir[i][1]] == arr[2] || map[r + dir[i][0]][c + dir[i][1]] == arr[3])
            ans++;
    }
    return ans;
}

int binpoint(int num, int r, int c)
{
    int ans = 0;
    for (int i = 0; i < 4; i++)
    {
        if (map[r + dir[i][0]][c + dir[i][1]] ==0)
            ans++;
    }
    return ans;
}


int main()
{
    freopen("t.txt", "r", stdin);
    int N;
    cin >> N;
    map.resize(N+2, vector<int>(N+2));
    for (int i = 0; i < N + 2; i++)
    {
        map[i][0] = 999;
        map[i][N + 1] = 999;
        map[0][i] = 999;
        map[N + 1][i] = 999;
    }

    vector<vector<int>> tabe(N*N+1, vector<int>(4));

    for (int student = 0; student < N*N; student++)
    {
        int num;
        vector<int> arr(4);
        cin >> num;
        for (int j = 0; j < 4; j++)
            cin >> arr[j];
        tabe[num] = arr;
        int jomax = -1;
        vector<pair<int, int>> jidx;
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (map[i][j] != 0) continue;
                int jp = jopoint(num, arr, i, j);
                if ( jp> jomax)
                {
                    jomax = jp;
                    jidx.clear();
                    jidx.push_back({ i,j });
                }
                else if (jp == jomax)
                {
                    jidx.push_back({ i,j });
                }
            }
        }
        int binmax = -1;
        int bidx[2];
        if (jidx.empty())
        {
            bidx[0] = 2;
            bidx[1] = 2;
        }
        else {
            for (int i = 0; i < jidx.size(); i++)
            {
                int bp = binpoint(num, jidx[i].first, jidx[i].second);
                if (bp > binmax)
                {
                    binmax = bp;
                    bidx[0] = jidx[i].first;
                    bidx[1] = jidx[i].second;
                }
            }
        }
        map[bidx[0]][bidx[1]] = num;

    }
    int sco = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            //cout << map[i][j] << " ";
            int cnt = 0;
            for (int k = 0; k < 4; k++)
            {
                if (map[i + dir[k][0]][j + dir[k][1]] == tabe[map[i][j]][0] || map[i + dir[k][0]][j + dir[k][1]] == tabe[map[i][j]][1] || map[i + dir[k][0]][j + dir[k][1]] == tabe[map[i][j]][2] || map[i + dir[k][0]][j + dir[k][1]] == tabe[map[i][j]][3])
                    cnt++;
            }
            if (cnt == 0) continue;
            else if (cnt == 1) sco += 1;
            else if (cnt == 2) sco += 10;
            else if (cnt == 3) sco += 100;
            else if (cnt == 4) sco += 1000;
        }
        //cout << '\n';
    }
    
    cout << sco;
    return 0;
}