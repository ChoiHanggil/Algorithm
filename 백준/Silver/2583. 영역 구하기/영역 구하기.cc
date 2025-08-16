
#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
#include<cmath>
#include <limits>
#include <unordered_set>

using namespace std;

int BFS(vector<vector<bool>>& grid, int i, int j)
{
    int dx[4] = { -1, 0, 1, 0 };
    int dy[4] = { 0, -1, 0, 1 };
    int cnt = 1;
    queue<pair<int, int>> q;
    q.push({ i,j });

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx < 0 || nx >= grid.size() || ny < 0 || ny >= grid[0].size())continue;
            if (grid[nx][ny] == false)
            {
                q.push({ nx,ny });
                grid[nx][ny] = true;
                cnt++;
            }

        }
    }
    return cnt;
}

int main()
{
    int m, n, k;
    cin >> m >> n >> k;
    int a1, a2, b1, b2;
    vector<vector<bool>> grid(n, vector<bool>(m, false));
    for (int i = 0; i < k; i++)
    {
        cin >> a1 >> a2 >> b1 >> b2;
        for (int i = a1; i < b1; i++)
        {
            for (int j = a2; j < b2; j++)
            {
                grid[i][j] = true;
            }
        }
    }

    vector<int> ret;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == false)
            {
               grid[i][j] = true;
               ret.push_back(BFS(grid, i, j));
              
            }
        }
    }
    cout << ret.size() << '\n';
    sort(ret.begin(), ret.end());
    for (auto e : ret)
    {
        cout << e << " ";
    }
}


